#include "serve.h"
#include "ui_serve.h"
#include<QDebug>
#include<QTcpServer>
#include<networkdata.h>
#include<QtNetwork>
#include <QWidget>
#include<networkserver.h>
#include <QTcpSocket>
#include <QString>
#include <QList>
#include <QStandardItemModel>
#include <cstdlib>
#include <QHostAddress>
#include <QTimer>
#include <QEventLoop>
serve::serve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serve)
{
    ui->setupUi(this);
    this->server->listen(QHostAddress::Any,1888);
    temp_now_area='A';
    connect(this->server, &NetworkServer::receive, this, &serve::receive);
    //倒计时
    connect(my_timer,&QTimer::timeout,this,&serve::timercountdown);
}

void serve::receive(QTcpSocket *client, NetworkData data)
{
    local=client;
    qDebug()<<"serve has receive"<<QString::number((int)data.op);
    //处理结束的时候，记得把data2设置为“000000”，有几名玩家设置几个0，用来计数
    if(data.op==OPCODE::JOIN_ROOM_OP)
    {
       //房间不存在
        if(this->name.isEmpty())
       {
          this->name=data.data1;
          room_name[0]=data.data2;
          num_roomlist+=1;
          qDebug()<<"num_roomlist="<<num_roomlist;
          roomlist[0]=client;
          player_sit[0]='0';
          NetworkData send_join_room_op(OPCODE::JOIN_ROOM_REPLY_OP,0,0);
          this->server->send(client,send_join_room_op);
       }
       //房间已存在
        else
       {
          qDebug()<<"房间存在";
            //房间已开始游戏
           if(situation==true)
          {
             NetworkData send_join_1(OPCODE::ERROR_OP,QString::number((int)ERRCODE::INVALID_JOIN),0);
             this->server->send(client,send_join_1);
          }
          //房间未开始
           else
          {
             //检查重名
              int flag_join_1=0;
              for(int i=0;i<num_roomlist;i++)
              {
                if(room_name[i]==data.data2)
                {
                    flag_join_1=1;
                    NetworkData send_join_1(OPCODE::ERROR_OP,QString::number((int)ERRCODE::INVALID_JOIN),0);
                    this->server->send(client,send_join_1);
                    break;
                }
              }
             //检查通过，合法
              if(flag_join_1==0)
              {
                 QString temp_data1=0;
                 QString temp_data2=0;
                 for(int j=0;j<num_roomlist;j++)
                 {
                    temp_data1=temp_data1+room_name[j]+' ';  //改成加法
                    temp_data2=temp_data2+player_sit[j];
                 }

                 //开始向其他人发送新玩家的消息
                 NetworkData send_join_2(OPCODE::JOIN_ROOM_OP,data.data2,0);
                 for(int i=0;i<num_roomlist;i++)
                 {
                    this->server->send(roomlist[i],send_join_2);
                 }

                 //把新玩家的信息加入房间

                 room_name[num_roomlist]=data.data2;
                 roomlist[num_roomlist]=client;
                 player_sit[num_roomlist]='0';
                 num_roomlist+=1;
                 NetworkData send_join_room_op(OPCODE::JOIN_ROOM_REPLY_OP,temp_data1,temp_data2);
                 this->server->send(client,send_join_room_op);

              }
          }
       }
    }
    else if(data.op==OPCODE::JOIN_ROOM_REPLY_OP)
    {
       //好像什么都不需要干
    }
    else if(data.op==OPCODE::PLAYER_READY_OP)
    {
        NetworkData send_play_1(OPCODE::PLAYER_READY_OP,data.data1,0);
        for(int j=0;j<num_roomlist;j++)
       {
           this->server->send(roomlist[j],send_play_1);
       }
        //将对应对象的状态改为就绪
        for(int i=0;i<num_roomlist;i++)
        {
            if(room_name[i]==data.data1)
            {
                player_sit[i]='1';
                break;
            }
        }
        //检查游戏是否可以开始
       if(this->num_roomlist>=2)
       {
          int flag_playready=1;
          for(int i=0;i<num_roomlist;i++)
          {
             if(player_sit[i]=='0')
             {
                 flag_playready=0;
                 break;
             }
          }
          //符合条件，可以开始
          if(flag_playready==1)
          {
              QString temp_data1=0;
              QString temp_data2=0;
              //记录用户名
              for(int j=0;j<num_roomlist;j++)
              {
                 temp_data1=temp_data1+room_name[j]+' ';  //改成加法
              }
              //记录区域
              if(num_roomlist==2)
              {
                  temp_data2="A D";
                  player_area[0]='A';
                  player_area[1]='D';
              }
              else if(num_roomlist==3)
              {
                  temp_data2="B D F";
                  player_area[0]='B';
                  player_area[1]='D';
                  player_area[2]='F';
              }
              else if(num_roomlist==4)
              {
                  temp_data2="A B D E";
                  player_area[0]='A';
                  player_area[1]='B';
                  player_area[2]='D';
                  player_area[3]='E';
              }
              else if(num_roomlist==6)
              {
                  temp_data2="A B C D E F";
                  player_area[0]='A';
                  player_area[1]='B';
                  player_area[2]='C';
                  player_area[3]='D';
                  player_area[4]='E';
                  player_area[5]='F';
              }

              //发送给所有人
              num_total_room=num_roomlist;
              NetworkData send_play_ready(OPCODE::START_GAME_OP,temp_data1,temp_data2);
              for(int i=0;i<num_roomlist;i++)
             {
                 this->server->send(roomlist[i],send_play_ready);
             }
              //开始运行游戏

              makegame();
          }
       }
    }
    else if(data.op==OPCODE::LEAVE_ROOM_OP)
    {
       for(int i=0;i<num_roomlist;i++)
       {
          if(roomlist[i]==client)
          {
             for(int j=i;j<6;j++)
             {
                roomlist[j]=roomlist[j+1];
                room_name[j]=room_name[j+1];
                player_sit[j]=player_sit[j+1];
             }
             break;
          }
       }
       for(int i=0;i<6;i++)
         qDebug()<<player_sit[i];
       roomlist[5]=NULL;
       room_name[5]=0;
       player_sit[5]=0;
       num_roomlist-=1;
       NetworkData send_leave(OPCODE::LEAVE_ROOM_OP,data.data2,0);
       for(int i=0;i<num_roomlist;i++)
       {
           this->server->send(roomlist[i],send_leave);
       }
    }
    else if(data.op==OPCODE::MOVE_OP)
    {
       if(data.data1==temp_now_area)
       {
           //表示收到了信息
          //重置倒计时
          /*timer_max=15;
          my_timer->setInterval(1000);
          my_timer->start();
          symbol=true;*/
          //给其他玩家转发move_op请求
          NetworkData send_turn_op2(OPCODE::START_TURN_OP,"D","i hate you");
           for(int i=0;i<num_roomlist;i++)
          {
           if(roomlist[i]!=local)
           {
               this->server->send(roomlist[i],data);
               //this->server->send(roomlist[i],send_turn_op2);
           }
          }
          //判断该玩家是否结束游戏
            //将其player_area改为0；

          //进行下一名玩家的start_turn_op
            //找到符合条件的玩家

           //this->server->send(roomlist[1],send_turn_op2);

          do
          {
             temp_now_player+=1;
             if(temp_now_player==num_roomlist)
               temp_now_player=0;
          }while(player_area[temp_now_player].isEmpty());
            //构造data并发送

          temp_now_area=player_area[temp_now_player];
          qDebug()<<"temp_now_area="<<temp_now_area;
          NetworkData send_turn_op(OPCODE::START_TURN_OP,temp_now_area,0);


          for(int i=0;i<num_roomlist;i++)
          {
            if(!player_area[i].isEmpty())
            {
               qDebug()<<player_area[i];
               this->server->send(roomlist[i],send_turn_op);
               //roomlist[i]->flush();
            }
          }

       }
    }

}

void serve::makegame()
{
    temp_now_player=0;
    NetworkData send_makegame(OPCODE::START_TURN_OP,player_area[temp_now_player],0);
    for(int i=0;i<num_roomlist;i++)
    {
       this->server->send(roomlist[i],send_makegame);
     }

    /*if(my_timer->isActive()==false)
    {
      my_timer->start(1000);
    }*/
}

void serve::timercountdown()
{
    /*
    timer_max-=1;
    if(timer_max==0)
    {
        QString temp_area_data1;
        int where;
        for(int i=0;i<num_roomlist;i++)
        {
            if(roomlist[i]==this->local)
            {
                where=i;
                break;
            }
        }
        //找到区域
        if(num_roomlist==2)
        {
           if(where==0)
            {
               temp_area_data1='A';
            }
           else
            {
               temp_area_data1='D';
            }
        }
        else if(num_roomlist==3)
        {
            if(where==0)
            {
               temp_area_data1='D';
            }
            else if(where==1)
            {
                temp_area_data1='F';
            }
            else if(where==2)
            {
                temp_area_data1='B';
            }
        }
        else if(num_roomlist==4)
        {
            if(where==0)
            {
               temp_area_data1='A';
            }
            else if(where==1)
            {
                temp_area_data1='B';
            }
            else if(where==2)
            {
                temp_area_data1='D';
            }
            else if(where==3)
            {
                temp_area_data1='E';
            }
        }
        else if(num_roomlist==6)
        {
            if(where==0)
            {
               temp_area_data1='A';
            }
            else if(where==1)
            {
                temp_area_data1='B';
            }
            else if(where==2)
            {
                temp_area_data1='C';
            }
            else if(where==3)
            {
                temp_area_data1='D';
            }
            else if(where==4)
            {
                temp_area_data1='E';
            }
            else if(where==5)
            {
                temp_area_data1='F';
            }
        }
        NetworkData send_move_overtime(OPCODE::MOVE_OP,temp_area_data1,"-1");
        for(int i=0;i<num_roomlist;i++)
        {
            this->server->send(roomlist[i],send_move_overtime);
        }

        //归入失败列表队列
        //找到玩家名字
        for(int j=0;j<num_roomlist;j++)
        {
            if(roomlist[j]==local)
            {
                loser_list_name[num_loser]=room_name[j];
                num_loser+=1;
                player_sit[j]='0';
            }
        }
        //游戏结束
        if(num_roomlist==(num_winner+num_loser+1))
        {
           for(int i=0;i<num_roomlist;i++)
           {
               if(player_sit[i]=='1')
               {
                  winner_list_name[num_winner]=room_name[i];
                  num_winner+=1;
               }
           }
           QString temp_end_data1=0;
           for(int i=0;i<num_winner;i++)
           {
               temp_end_data1=temp_end_data1+winner_list_name[i]+' ';
           }
           for(int i=num_loser-1;i>=0;i--)
           {
               temp_end_data1=temp_end_data1+loser_list_name[i]+' ';
           }
           NetworkData send_end_temp(OPCODE::END_GAME_OP,temp_end_data1,0);
           //通知所有玩家游戏结束
           for(int i=0;i<num_roomlist;i++)
           {
              this->server->send(roomlist[i],send_end_temp);
           }
           //倒计时停止
           my_timer->stop();
        }
    }
    */
}

serve::~serve()
{
    delete ui;
}
