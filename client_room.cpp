#include "client_room.h"
#include "ui_client_room.h"
#include<client.h>
#include<ranklist.h>
#include<networkdata.h>
#include<QString>
#include<QDebug>
#include<lianjie_two.h>
#include<game_two.h>
#include<game_three.h>
#include<game_four.h>
#include<game_six.h>
#include<QTimer>
extern game_two *game_two_room;
extern game_three *game_three_room;
extern game_four *game_four_room;
extern game_six *game_six_room;
client_room::client_room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client_room)
{
    ui->setupUi(this);
    my_timer = new QTimer(this);
    connect(my_timer,&QTimer::timeout,this,&client_room::timercountdown);
}

client_room::~client_room()
{
    delete ui;
}

void client_room::receive(NetworkData a)
{
    qDebug()<<"client_room has receive"<<a.data1<<a.data2;
    if(a.op==OPCODE::END_GAME_OP)
    {
        //展示排名列表
        ranklist *final=new ranklist();
        final->makelist(a);
        final->show();
        //退出游戏界面
        this->close();
    }
    else if(a.op==OPCODE::END_TURN_OP)
    {
        //提示胜利
        QMessageBox::about(this,"游戏结束提示","恭喜您，您已经完成比赛");
        //移出游戏列表

        //顺序加入排名列表

    }
    else if(a.op==OPCODE::JOIN_ROOM_OP)
    {
       qDebug()<<"player_number="<<player_number;
        //更新房间状态，新加入一名玩家
        if(this->player_number==1)
        {
           ui->textBrowser_B->setText(a.data1);
        }
        else if(this->player_number==2)
        {
           ui->textBrowser_C->setText(a.data1);
        }
        else if(this->player_number==3)
        {
          ui->textBrowser_D->setText(a.data1);
        }
        else if(this->player_number==4)
        {
           ui->textBrowser_E->setText(a.data1);
        }
        else if(this->player_number==5)
        {
           ui->textBrowser_F->setText(a.data1);
        }
        player_number+=1;
    }
    else if(a.op==OPCODE::JOIN_ROOM_REPLY_OP)
    {
        //加入房间
           //已经加入了，不成功会返回上一个界面,用错误函数处理
        //解析数据
        int num,i;
        num=a.data2.length();
        this->player_number=num+1;
        QString player[7];
        for(i=1;i<=num;i++)
        {
           player[i]=a.data1.section(' ',i-1,i-1);
        }
        //更新房间状态
        if(num==0)
        {
           //第一个人
           ui->textBrowser_A->setText(this->name);
           if(this->zhunbei)
           {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
           }
           else
               ui->label_A_2->clear();

        }
        else if(num==1)
        {
            //第一个人
            ui->textBrowser_A->setText(player[1]);
            if(a.data2[0]=='1')
            {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
            }
            else
            {
               ui->label_A_2->clear();
            }
            //第二个人
            ui->textBrowser_B->setText(this->name);
            if(this->zhunbei)
            {
                ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_B_2->setScaledContents(true);
            }
            else
                ui->label_B_2->clear();
        }
        else if(num==2)
        {
            //第一个人
            ui->textBrowser_A->setText(player[1]);
            if(a.data2[0]=='1')
            {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
            }
            else
            {
               ui->label_A_2->clear();
            }
            //第二个人
            ui->textBrowser_B->setText(player[2]);
            if(a.data2[1]=='1')
            {
               ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_B_2->setScaledContents(true);
            }
            else
            {
               ui->label_B_2->clear();
            }
            //第三个人
            ui->textBrowser_C->setText(this->name);
            if(this->zhunbei)
            {
                ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_C_2->setScaledContents(true);
            }
            else
                ui->label_C_2->clear();
        }
        else if(num==3)
        {
            //第一个人
            ui->textBrowser_A->setText(player[1]);
            if(a.data2[0]=='1')
            {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
            }
            else
            {
               ui->label_A_2->clear();
            }
            //第二个人
            ui->textBrowser_B->setText(player[2]);
            if(a.data2[1]=='1')
            {
               ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_B_2->setScaledContents(true);
            }
            else
            {
               ui->label_B_2->clear();
            }
            //第三个人
            ui->textBrowser_C->setText(player[3]);
            if(a.data2[2]=='1')
            {
               ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_C_2->setScaledContents(true);
            }
            else
            {
               ui->label_C_2->clear();
            }
            //第四个人
            ui->textBrowser_D->setText(this->name);
            if(this->zhunbei)
            {
                ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_D_2->setScaledContents(true);
            }
            else
                ui->label_D_2->clear();
        }
        else if(num==4)
        {
            //第一个人
            ui->textBrowser_A->setText(player[1]);
            if(a.data2[0]=='1')
            {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
            }
            else
            {
               ui->label_A_2->clear();
            }
            //第二个人
            ui->textBrowser_B->setText(player[2]);
            if(a.data2[1]=='1')
            {
               ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_B_2->setScaledContents(true);
            }
            else
            {
               ui->label_B_2->clear();
            }
            //第三个人
            ui->textBrowser_C->setText(player[3]);
            if(a.data2[2]=='1')
            {
               ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_C_2->setScaledContents(true);
            }
            else
            {
               ui->label_C_2->clear();
            }
            //第四个人
            ui->textBrowser_D->setText(player[4]);
            if(a.data2[3]=='1')
            {
               ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_D_2->setScaledContents(true);
            }
            else
            {
               ui->label_D_2->clear();
            }
            //第五个人
            ui->textBrowser_E->setText(this->name);
            if(this->zhunbei)
            {
                ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_E_2->setScaledContents(true);
            }
            else
                ui->label_E_2->clear();
        }
        else if(num==5)
        {
            //第一个人
            ui->textBrowser_A->setText(player[1]);
            if(a.data2[0]=='1')
            {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
            }
            else
            {
               ui->label_A_2->clear();
            }
            //第二个人
            ui->textBrowser_B->setText(player[2]);
            if(a.data2[1]=='1')
            {
               ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_B_2->setScaledContents(true);
            }
            else
            {
               ui->label_B_2->clear();
            }
            //第三个人
            ui->textBrowser_C->setText(player[3]);
            if(a.data2[2]=='1')
            {
               ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_C_2->setScaledContents(true);
            }
            else
            {
               ui->label_C_2->clear();
            }
            //第四个人
            ui->textBrowser_D->setText(player[4]);
            if(a.data2[3]=='1')
            {
               ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_D_2->setScaledContents(true);
            }
            else
            {
               ui->label_D_2->clear();
            }
            //第五个人
            ui->textBrowser_E->setText(player[5]);
            if(a.data2[4]=='1')
            {
               ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_E_2->setScaledContents(true);
            }
            else
            {
               ui->label_E_2->clear();
            }
            //第六个人
            ui->textBrowser_F->setText(this->name);
            if(this->zhunbei)
            {
                ui->label_F_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_F_2->setScaledContents(true);
            }
            else
                ui->label_F_2->clear();
        }

    }
    else if(a.op==OPCODE::LEAVE_ROOM_OP)
    {
        //更新房间列表
        //清除离开玩家
        if(a.data1==ui->textBrowser_A->toPlainText())
        {
           ui->textBrowser_A->setText(0);
           ui->label_A_2->clear();
           //将第二个框向前移动
           ui->textBrowser_A->setText(ui->textBrowser_B->toPlainText());
           if(!ui->label_B_2->pixmap().isNull())
           {
               ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_A_2->setScaledContents(true);
               ui->label_B_2->clear();
           }
           //将第三个框向前移动
           ui->textBrowser_B->setText(ui->textBrowser_C->toPlainText());
           if(!ui->label_C_2->pixmap().isNull())
           {
               ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_B_2->setScaledContents(true);
               ui->label_C_2->clear();
           }
           //将第四个框向前移动
           ui->textBrowser_C->setText(ui->textBrowser_D->toPlainText());
           if(!ui->label_D_2->pixmap().isNull())
           {
               ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_C_2->setScaledContents(true);
               ui->label_D_2->clear();
           }
           //将第五个框向前移动
           ui->textBrowser_D->setText(ui->textBrowser_E->toPlainText());
           if(!ui->label_E_2->pixmap().isNull())
           {
               ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_D_2->setScaledContents(true);
               ui->label_E_2->clear();
           }
           //将第六个框向前移动
           ui->textBrowser_E->setText(ui->textBrowser_F->toPlainText());
           if(!ui->label_F_2->pixmap().isNull())
           {
               ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
               ui->label_E_2->setScaledContents(true);
               ui->label_F_2->clear();
           }
        }
        else if(a.data1==ui->textBrowser_B->toPlainText())
        {
            ui->textBrowser_B->setText(0);
            ui->label_B_2->clear();
            //将第三个框向前移动
            ui->textBrowser_B->setText(ui->textBrowser_C->toPlainText());
            if(!ui->label_C_2->pixmap().isNull())
            {
                ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_B_2->setScaledContents(true);
                ui->label_C_2->clear();
            }
            //将第四个框向前移动
            ui->textBrowser_C->setText(ui->textBrowser_D->toPlainText());
            if(!ui->label_D_2->pixmap().isNull())
            {
                ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_C_2->setScaledContents(true);
                ui->label_D_2->clear();
            }
            //将第五个框向前移动
            ui->textBrowser_D->setText(ui->textBrowser_E->toPlainText());
            if(!ui->label_E_2->pixmap().isNull())
            {
                ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_D_2->setScaledContents(true);
                ui->label_E_2->clear();
            }
            //将第六个框向前移动
            ui->textBrowser_E->setText(ui->textBrowser_F->toPlainText());
            if(!ui->label_F_2->pixmap().isNull())
            {
                ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_E_2->setScaledContents(true);
                ui->label_F_2->clear();
            }
        }
        else if(a.data1==ui->textBrowser_C->toPlainText())
        {
            ui->textBrowser_C->setText(0);
            ui->label_C_2->clear();
            //将第四个框向前移动
            ui->textBrowser_C->setText(ui->textBrowser_D->toPlainText());
            if(!ui->label_D_2->pixmap().isNull())
            {
                ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_C_2->setScaledContents(true);
                ui->label_D_2->clear();
            }
            //将第五个框向前移动
            ui->textBrowser_D->setText(ui->textBrowser_E->toPlainText());
            if(!ui->label_E_2->pixmap().isNull())
            {
                ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_D_2->setScaledContents(true);
                ui->label_E_2->clear();
            }
            //将第六个框向前移动
            ui->textBrowser_E->setText(ui->textBrowser_F->toPlainText());
            if(!ui->label_F_2->pixmap().isNull())
            {
                ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_E_2->setScaledContents(true);
                ui->label_F_2->clear();
            }
        }
        else if(a.data1==ui->textBrowser_D->toPlainText())
        {
            ui->textBrowser_D->setText(0);
            ui->label_D_2->clear();
            //将第五个框向前移动
            ui->textBrowser_D->setText(ui->textBrowser_E->toPlainText());
            if(!ui->label_E_2->pixmap().isNull())
            {
                ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_D_2->setScaledContents(true);
                ui->label_E_2->clear();
            }
            //将第六个框向前移动
            ui->textBrowser_E->setText(ui->textBrowser_F->toPlainText());
            if(!ui->label_F_2->pixmap().isNull())
            {
                ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_E_2->setScaledContents(true);
                ui->label_F_2->clear();
            }
        }
        else if(a.data1==ui->textBrowser_E->toPlainText())
        {
            ui->textBrowser_E->setText(0);
            ui->label_E_2->clear();
            //将第六个框向前移动
            ui->textBrowser_E->setText(ui->textBrowser_F->toPlainText());
            if(!ui->label_F_2->pixmap().isNull())
            {
                ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
                ui->label_E_2->setScaledContents(true);
                ui->label_F_2->clear();
            }
        }
        else if(a.data1==ui->textBrowser_F->toPlainText())
        {
            ui->textBrowser_F->setText(0);
            ui->label_F_2->clear();
        }
        player_number-=1;
    }
    else if(a.op==OPCODE::MOVE_OP)
    {
        //超时判负
        if(a.data2=="-1")
        {
           //更新游戏列表
           //更新排名列表
           //更新棋盘
             //找到id编号
            int temp_clear_id=0;
            if(player_number==2)
             {
                 if(a.data1=='A')
                   temp_clear_id=0;
                 else if(a.data1=='D')
                     temp_clear_id=1;
             }
            else if(player_number==3)
             {
                if(a.data1=='D')
                  temp_clear_id=0;
                else if(a.data1=='F')
                    temp_clear_id=1;
                else if(a.data1=='B')
                    temp_clear_id=2;
             }
            else if(player_number==4)
             {
                if(a.data1=='A')
                  temp_clear_id=0;
                else if(a.data1=='B')
                    temp_clear_id=1;
                else if(a.data1=='D')
                    temp_clear_id=2;
                else if(a.data1=='E')
                    temp_clear_id=3;
             }
            else if(player_number==6)
             {
                if(a.data1=='A')
                  temp_clear_id=0;
                else if(a.data1=='B')
                    temp_clear_id=1;
                else if(a.data1=='C')
                    temp_clear_id=2;
                else if(a.data1=='D')
                    temp_clear_id=3;
                else if(a.data1=='E')
                    temp_clear_id=4;
                else if(a.data1=='F')
                    temp_clear_id=5;
             }
            game_two_room->clear_pawn(temp_clear_id);
            if(this->area==a.data1)
            {
                game_two_room->game_over();
            }
        }
        //更新棋盘状态
        else
        {
            if(player_number==2)
            {
               int temp_len=0;
               for(int i=0;i<a.data2.length();i++)
              {
                 if(a.data2[i]==' ')
                   temp_len+=1;
              }
              //一共有temp_len个数
              //自己的客户端要删去这个+1
               temp_len+=1;

               int x1,y1;
              //自己的客户端是temp_len-4,第四组的要改成temp_len-2
              for(int j=0;j<=temp_len-2;j=j+2)
              {
                //提取坐标
                x1=a.data2.section(' ',j+0,j+0).toInt();
                y1=a.data2.section(' ',j+1,j+1).toInt();
                //转化坐标
                x1=12+2*x1+y1;
                y1=8-y1;
                //移动坐标
                qDebug()<<"x1="<<x1<<"y1="<<y1;
                game_two_room->moveOperation(x1,y1);

              }
              game_two_room->moveOperation(x1,y1);
              qDebug()<<"has moved";
              qDebug()<<"x1="<<x1<<"y1="<<y1;
            }
            else if(player_number==3)
            {

            }
            else if(player_number==4)
            {

            }
            else if(player_number==6)
            {

            }
        }

    }
    else if(a.op==OPCODE::PLAYER_READY_OP)
    {
        qDebug()<<"client room has receive player ready op"<<a.data1;
        //更新房间状态
        if(a.data1==ui->textBrowser_A->toPlainText())
        {
           ui->label_A_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_A_2->setScaledContents(true);
        }
        else if(a.data1==ui->textBrowser_B->toPlainText())
        {
           ui->label_B_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_B_2->setScaledContents(true);
        }
        else if(a.data1==ui->textBrowser_C->toPlainText())
        {
           ui->label_C_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_C_2->setScaledContents(true);
        }
        else if(a.data1==ui->textBrowser_D->toPlainText())
        {
           ui->label_D_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_D_2->setScaledContents(true);
        }
        else if(a.data1==ui->textBrowser_E->toPlainText())
        {
           ui->label_E_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_E_2->setScaledContents(true);
        }
        else if(a.data1==ui->textBrowser_F->toPlainText())
        {
           ui->label_F_2->setPixmap(QPixmap(":/pic_2.png"));
           ui->label_F_2->setScaledContents(true);
        }
    }
    else if(a.op==OPCODE::START_GAME_OP)
    {
        //游戏开始，创建棋盘界面
        if(this->player_number==2)
        {
           this->hide();
           game_two_room->setWindowTitle(this->name);
           game_two_room->show();
           //记住区域
           QString area_temp;
           QString area_temp_2;
           area_temp=a.data1.section(' ',0,0);
           area_temp_2=a.data1.section(' ',1,1);
           //导入所有玩家信息
           game_two_room->player_name[0]=area_temp;
           game_two_room->player_area[0]='A';
           game_two_room->player_name[1]=area_temp_2;
           game_two_room->player_area[1]='D';
           if(area_temp==this->name)
           {
               this->area='A';
               game_two_room->self_name=area_temp;
               game_two_room->self_area='A';
           }
           else
           {
               this->area='D';
               game_two_room->self_name=area_temp_2;
               game_two_room->self_area='D';
           }
        }
        else if(this->player_number==3)
        {
            this->hide();
            game_three_room->setWindowTitle(this->name);
            game_three_room->show();
            //记住信息
            QString name_temp_1;
            QString name_temp_2;
            QString name_temp_3;
            QString area_temp_1;
            QString area_temp_2;
            QString area_temp_3;
            //记录名字
            name_temp_1=a.data1.section(' ',0,0);
            name_temp_2=a.data1.section(' ',1,1);
            name_temp_3=a.data1.section(' ',2,2);
            //记录区域
            area_temp_1=a.data2.section(' ',0,0);
            area_temp_2=a.data2.section(' ',1,1);
            area_temp_3=a.data2.section(' ',2,2);
            //导入玩家信息
            game_three_room->player_name[0]=name_temp_1;
            game_three_room->player_area[0]=area_temp_1;
            game_three_room->player_name[1]=name_temp_2;
            game_three_room->player_area[1]=area_temp_2;
            game_three_room->player_name[2]=name_temp_3;
            game_three_room->player_area[2]=area_temp_3;
            //记录本地消息
            if(name_temp_1==this->name)
            {
                this->area=area_temp_1;
                game_three_room->self_name=name_temp_1;
                game_three_room->self_area=area_temp_1;
            }
            else if(name_temp_2==this->name)
            {
                this->area=area_temp_2;
                game_three_room->self_name=name_temp_2;
                game_three_room->self_area=area_temp_2;
            }
            else if(name_temp_3==this->name)
            {
                this->area=area_temp_3;
                game_three_room->self_name=name_temp_3;
                game_three_room->self_area=area_temp_3;
            }
        }
        else if(this->player_number==4)
        {
            this->hide();
            game_four_room->setWindowTitle(this->name);
            game_four_room->show();
            //记住信息
            QString name_temp_1;
            QString name_temp_2;
            QString name_temp_3;
            QString name_temp_4;
            QString area_temp_1;
            QString area_temp_2;
            QString area_temp_3;
            QString area_temp_4;
            //记录名字
            name_temp_1=a.data1.section(' ',0,0);
            name_temp_2=a.data1.section(' ',1,1);
            name_temp_3=a.data1.section(' ',2,2);
            name_temp_4=a.data1.section(' ',3,3);
            //记录区域
            area_temp_1=a.data2.section(' ',0,0);
            area_temp_2=a.data2.section(' ',1,1);
            area_temp_3=a.data2.section(' ',2,2);
            area_temp_4=a.data2.section(' ',3,3);
            //导入玩家信息
            game_four_room->player_name[0]=name_temp_1;
            game_four_room->player_area[0]=area_temp_1;
            game_four_room->player_name[1]=name_temp_2;
            game_four_room->player_area[1]=area_temp_2;
            game_four_room->player_name[2]=name_temp_3;
            game_four_room->player_area[2]=area_temp_3;
            game_four_room->player_name[3]=name_temp_4;
            game_four_room->player_area[3]=area_temp_4;
            //记录本地消息
            if(name_temp_1==this->name)
            {
                this->area=area_temp_1;
                game_four_room->self_name=name_temp_1;
                game_four_room->self_area=area_temp_1;
            }
            else if(name_temp_2==this->name)
            {
                this->area=area_temp_2;
                game_four_room->self_name=name_temp_2;
                game_four_room->self_area=area_temp_2;
            }
            else if(name_temp_3==this->name)
            {
                this->area=area_temp_3;
                game_four_room->self_name=name_temp_3;
                game_four_room->self_area=area_temp_3;
            }
            else if(name_temp_4==this->name)
            {
                this->area=area_temp_4;
                game_four_room->self_name=name_temp_4;
                game_four_room->self_area=area_temp_4;
            }
        }
        else if(this->player_number==6)
        {
            this->hide();
            game_six_room->setWindowTitle(this->name);
            game_six_room->show();
            //记住信息
            QString name_temp_1;
            QString name_temp_2;
            QString name_temp_3;
            QString name_temp_4;
            QString name_temp_5;
            QString name_temp_6;
            QString area_temp_1;
            QString area_temp_2;
            QString area_temp_3;
            QString area_temp_4;
            QString area_temp_5;
            QString area_temp_6;
            //记录名字
            name_temp_1=a.data1.section(' ',0,0);
            name_temp_2=a.data1.section(' ',1,1);
            name_temp_3=a.data1.section(' ',2,2);
            name_temp_4=a.data1.section(' ',3,3);
            name_temp_5=a.data1.section(' ',4,4);
            name_temp_6=a.data1.section(' ',5,5);
            //记录区域
            area_temp_1=a.data2.section(' ',0,0);
            area_temp_2=a.data2.section(' ',1,1);
            area_temp_3=a.data2.section(' ',2,2);
            area_temp_4=a.data2.section(' ',3,3);
            area_temp_5=a.data2.section(' ',4,4);
            area_temp_6=a.data2.section(' ',5,5);
            //导入玩家信息
            game_six_room->player_name[0]=name_temp_1;
            game_six_room->player_area[0]=area_temp_1;
            game_six_room->player_name[1]=name_temp_2;
            game_six_room->player_area[1]=area_temp_2;
            game_six_room->player_name[2]=name_temp_3;
            game_six_room->player_area[2]=area_temp_3;
            game_six_room->player_name[3]=name_temp_4;
            game_six_room->player_area[3]=area_temp_4;
            game_six_room->player_name[4]=name_temp_5;
            game_six_room->player_area[4]=area_temp_5;
            game_six_room->player_name[5]=name_temp_6;
            game_six_room->player_area[5]=area_temp_6;
            //记录本地消息
            if(name_temp_1==this->name)
            {
                this->area=area_temp_1;
                game_six_room->self_name=name_temp_1;
                game_six_room->self_area=area_temp_1;
            }
            else if(name_temp_2==this->name)
            {
                this->area=area_temp_2;
                game_six_room->self_name=name_temp_2;
                game_six_room->self_area=area_temp_2;
            }
            else if(name_temp_3==this->name)
            {
                this->area=area_temp_3;
                game_six_room->self_name=name_temp_3;
                game_six_room->self_area=area_temp_3;
            }
            else if(name_temp_4==this->name)
            {
                this->area=area_temp_4;
                game_six_room->self_name=name_temp_4;
                game_six_room->self_area=area_temp_4;
            }
            else if(name_temp_5==this->name)
            {
                this->area=area_temp_5;
                game_six_room->self_name=name_temp_5;
                game_six_room->self_area=area_temp_5;
            }
            else if(name_temp_6==this->name)
            {
                this->area=area_temp_6;
                game_six_room->self_name=name_temp_6;
                game_six_room->self_area=area_temp_6;
            }
        }
        //建立游戏列表

        //更新棋盘界面

    }
    else if(a.op==OPCODE::START_TURN_OP)
    {
        if(player_number==2)
        {
           game_two_room->temp_area=a.data1;
           game_two_room->makeback(a.data1);
           //开始倒计时
           timer_max=15;
           if(my_timer->isActive()==false)
           {
              my_timer->start(1000);
           }
           else
           {
            my_timer->setInterval(1000);
            my_timer->start();
           }

           /*if(a.data1==game_two_room->self_area)
           {*/
              //获取鼠标点击位置
              connect(game_two_room,&game_two::is_over,[=](){
                //构造数据结构
                QString track=0;
               //第四组的时候要记得减一
               int final=game_two_room->move_zuobiao.size()-2;
                for(int i=0;i<game_two_room->move_zuobiao.size()-2;i++)
               {
                 track=track+QString::number(game_two_room->move_zuobiao[i].x)+' '+QString::number(game_two_room->move_zuobiao[i].y)+' ';
               //自己的服务端需要加的东西。
               /*if(i==(game_two_room->move_zuobiao.size()-1))
               {
               track=track+QString::number(game_two_room->move_zuobiao[i].x)+' '+QString::number(game_two_room->move_zuobiao[i].y)+' ';
               }*/
               }
               track=track+QString::number(game_two_room->move_zuobiao[final].x)+' '+QString::number(game_two_room->move_zuobiao[final].y);
              //顺序清除链表所有坐标数据
              for(int i=game_two_room->move_zuobiao.size()-1;i>=0;i--)
              {
                 game_two_room->move_zuobiao.removeAt(i);
              }
              NetworkData send_move_op(OPCODE::MOVE_OP,this->area,track);
              this->socket->send(send_move_op);
              });
           //}
        }
        else if(player_number==3)
        {
            game_three_room->temp_area=a.data1;
            game_three_room->makeback(a.data1);
            //开始倒计时
            timer_max=15;
            if(my_timer->isActive()==false)
            {
               my_timer->start(1000);
            }
            else
            {
             my_timer->setInterval(1000);
             my_timer->start();
            }

            /*if(a.data1==game_two_room->self_area)
            {*/
               //获取鼠标点击位置
               connect(game_three_room,&game_three::is_over,[=](){
                 //构造数据结构
                 QString track=0;
                //第四组的时候要记得减一
                int final=game_three_room->move_zuobiao.size()-2;
                 for(int i=0;i<game_three_room->move_zuobiao.size()-2;i++)
                {
                  track=track+QString::number(game_three_room->move_zuobiao[i].x)+' '+QString::number(game_three_room->move_zuobiao[i].y)+' ';
                //自己的服务端需要加的东西。
                /*if(i==(game_two_room->move_zuobiao.size()-1))
                {
                track=track+QString::number(game_two_room->move_zuobiao[i].x)+' '+QString::number(game_two_room->move_zuobiao[i].y)+' ';
                }*/
                }
                track=track+QString::number(game_three_room->move_zuobiao[final].x)+' '+QString::number(game_three_room->move_zuobiao[final].y);
               //顺序清除链表所有坐标数据
               for(int i=game_three_room->move_zuobiao.size()-1;i>=0;i--)
               {
                  game_three_room->move_zuobiao.removeAt(i);
               }
               NetworkData send_move_op(OPCODE::MOVE_OP,this->area,track);
               this->socket->send(send_move_op);
               });
        }
        else if(player_number==4)
        {

        }
        else if(player_number==6)
        {

        }
    }
    else if(a.op==OPCODE::ERROR_OP)
    {
       //加入房间错误
       if(QString::number((int)ERRCODE::INVALID_JOIN)==a.data1)
       {
           QMessageBox::critical(NULL,"提示","加入房间失败，请您检查重试",QMessageBox::Yes,QMessageBox::Yes);
       }
       //
    }
}

void client_room::timercountdown()
{
    timer_max-=1;
    //显示倒计时
    game_two_room->daojishi(QString::number(timer_max));
    //到达计时终点
    if(timer_max==0)
    {
       my_timer->stop();
    }
}

void client_room::on_pushButton_2_clicked()
{
    //离开房间
    this->zhunbei=0;
    NetworkData leave(OPCODE::LEAVE_ROOM_OP,this->house,this->name);
    this->socket->send(leave);
    lianjie_two *next=new lianjie_two();
    this->close();
    next->show();
}


void client_room::on_pushButton_clicked()
{
    //点击按钮，准备就绪，发送请求
    NetworkData temp(OPCODE::PLAYER_READY_OP,this->name,0);
    this->socket->send(temp);
    this->zhunbei=true;
}

