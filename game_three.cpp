#include "game_three.h"
#include "ui_game_three.h"
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QBrush>
#include "pawn.h"
#include <QWidget>
#include <QString>
#include <QFont>
#include<four.h>
#include<QTimer>
game_three::game_three(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_three)
{
    ui->setupUi(this);
    resize(850,600);
    setMouseTracking(true);
    tracking=0;
    trackingNum[0]=trackingNum[1]=-1;
    direction=0;
    stepCount=0;
    teamNum=3;
    nullPawn.chosen=0;
    nullPawn.id=-1;
    nullPawn.x=-1;
    nullPawn.y=-1;
    gameEnd=0;
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<16;j++)
        {
            board[i][j]=0;
            toPawn[i][j]=&nullPawn;
            avaiOnBoard[i][j]=0;
            mem[i][j]=0;
        }
    }
    //第二组
    pawn[1][0].x= 0*20;pawn[1][0].y=4*30;pawn[1][0].id=1;board[0][4]=1;toPawn[0][4]=&pawn[1][0];
    pawn[1][1].x= 1*20;pawn[1][1].y=5*30;pawn[1][1].id=1;board[1][5]=1;toPawn[1][5]=&pawn[1][1];
    pawn[1][2].x= 2*20;pawn[1][2].y=4*30;pawn[1][2].id=1;board[2][4]=1;toPawn[2][4]=&pawn[1][2];
    pawn[1][3].x= 2*20;pawn[1][3].y=6*30;pawn[1][3].id=1;board[2][6]=1;toPawn[2][6]=&pawn[1][3];
    pawn[1][4].x= 3*20;pawn[1][4].y=5*30;pawn[1][4].id=1;board[3][5]=1;toPawn[3][5]=&pawn[1][4];
    pawn[1][5].x= 3*20;pawn[1][5].y=7*30;pawn[1][5].id=1;board[3][7]=1;toPawn[3][7]=&pawn[1][5];
    pawn[1][6].x= 4*20;pawn[1][6].y=4*30;pawn[1][6].id=1;board[4][4]=1;toPawn[4][4]=&pawn[1][6];
    pawn[1][7].x= 4*20;pawn[1][7].y=6*30;pawn[1][7].id=1;board[4][6]=1;toPawn[4][6]=&pawn[1][7];
    pawn[1][8].x= 5*20;pawn[1][8].y=5*30;pawn[1][8].id=1;board[5][5]=1;toPawn[5][5]=&pawn[1][8];
    pawn[1][9].x= 6*20;pawn[1][9].y=4*30;pawn[1][9].id=1;board[6][4]=1;toPawn[6][4]=&pawn[1][9];
    //第一组
    pawn[0][0].x=12*20;pawn[0][0].y=16*30;pawn[0][0].id=0;board[12][16]=1;toPawn[12][16]=&pawn[0][0];
    pawn[0][1].x=11*20;pawn[0][1].y=15*30;pawn[0][1].id=0;board[11][15]=1;toPawn[11][15]=&pawn[0][1];
    pawn[0][2].x=13*20;pawn[0][2].y=15*30;pawn[0][2].id=0;board[13][15]=1;toPawn[13][15]=&pawn[0][2];
    pawn[0][3].x=10*20;pawn[0][3].y=14*30;pawn[0][3].id=0;board[10][14]=1;toPawn[10][14]=&pawn[0][3];
    pawn[0][4].x=12*20;pawn[0][4].y=14*30;pawn[0][4].id=0;board[12][14]=1;toPawn[12][14]=&pawn[0][4];
    pawn[0][5].x=14*20;pawn[0][5].y=14*30;pawn[0][5].id=0;board[14][14]=1;toPawn[14][14]=&pawn[0][5];
    pawn[0][6].x= 9*20;pawn[0][6].y=13*30;pawn[0][6].id=0;board[ 9][13]=1;toPawn[ 9][13]=&pawn[0][6];
    pawn[0][7].x=11*20;pawn[0][7].y=13*30;pawn[0][7].id=0;board[11][13]=1;toPawn[11][13]=&pawn[0][7];
    pawn[0][8].x=13*20;pawn[0][8].y=13*30;pawn[0][8].id=0;board[13][13]=1;toPawn[13][13]=&pawn[0][8];
    pawn[0][9].x=15*20;pawn[0][9].y=13*30;pawn[0][9].id=0;board[15][13]=1;toPawn[15][13]=&pawn[0][9];
    //第三组
    pawn[2][0].x=18*20;pawn[2][0].y=4*30;pawn[2][0].id=2;board[18][4]=1;toPawn[18][4]=&pawn[2][0];
    pawn[2][1].x=19*20;pawn[2][1].y=5*30;pawn[2][1].id=2;board[19][5]=1;toPawn[19][5]=&pawn[2][1];
    pawn[2][2].x=20*20;pawn[2][2].y=4*30;pawn[2][2].id=2;board[20][4]=1;toPawn[20][4]=&pawn[2][2];
    pawn[2][3].x=20*20;pawn[2][3].y=6*30;pawn[2][3].id=2;board[20][6]=1;toPawn[20][6]=&pawn[2][3];
    pawn[2][4].x=21*20;pawn[2][4].y=5*30;pawn[2][4].id=2;board[21][5]=1;toPawn[21][5]=&pawn[2][4];
    pawn[2][5].x=21*20;pawn[2][5].y=7*30;pawn[2][5].id=2;board[21][7]=1;toPawn[21][7]=&pawn[2][5];
    pawn[2][6].x=22*20;pawn[2][6].y=4*30;pawn[2][6].id=2;board[22][4]=1;toPawn[22][4]=&pawn[2][6];
    pawn[2][7].x=22*20;pawn[2][7].y=6*30;pawn[2][7].id=2;board[22][6]=1;toPawn[22][6]=&pawn[2][7];
    pawn[2][8].x=23*20;pawn[2][8].y=5*30;pawn[2][8].id=2;board[23][5]=1;toPawn[23][5]=&pawn[2][8];
    pawn[2][9].x=24*20;pawn[2][9].y=4*30;pawn[2][9].id=2;board[24][4]=1;toPawn[24][4]=&pawn[2][9];
}

game_three::~game_three()
{
    delete ui;
}

void game_three::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.translate(100,30);


    QBrush brush2(Qt::red);
    painter.setBrush(brush2);
    QPoint points_1[3]={QPoint(12*20,0),QPoint(8*20,4*30),QPoint(16*20,4*30)};
    painter.drawPolygon(points_1,3);

    QPoint points_2[3]={QPoint(0*20,4*30),QPoint(8*20,4*30),QPoint(4*20,8*30)};
    brush2.setColor(QColor(255,102,0));
    painter.setBrush(brush2);
    painter.drawPolygon(points_2,3);

    QPoint points_3[3]={QPoint(4*20,8*30),QPoint(0*20,12*30),QPoint(8*20,12*30)};
    brush2.setColor(Qt::yellow);
    painter.setBrush(brush2);
    painter.drawPolygon(points_3,3);

    QPoint points_4[3]={QPoint(8*20,12*30),QPoint(12*20,16*30),QPoint(16*20,12*30)};
    brush2.setColor(QColor(195,89,206));
    painter.setBrush(brush2);
    painter.drawPolygon(points_4,3);

    QPoint points_5[3]={QPoint(16*20,12*30),QPoint(24*20,12*30),QPoint(20*20,8*30)};
    brush2.setColor(QColor(255,40,168));
    painter.setBrush(brush2);
    painter.drawPolygon(points_5,3);

    QPoint points_6[3]={QPoint(20*20,8*30),QPoint(24*20,4*30),QPoint(16*20,4*30)};
    brush2.setColor(QColor(153,153,204));
    painter.setBrush(brush2);
    painter.drawPolygon(points_6,3);


    for(int i=0;i<=12;i++)
    {
        painter.drawLine(240-i*20,i*30,240+i*20,i*30);
        painter.drawLine(240-i*20,480-i*30,240+i*20,480-i*30);
    }
    for(int i=0;i<=12;i++)
    {
        painter.drawLine(i*40,120,i*20,120+i*30);
        painter.drawLine(i*40,360,i*20,360-i*30);
        painter.drawLine(480-i*40,120,480-i*20,120+i*30);
        painter.drawLine(480-i*40,360,480-i*20,360-i*30);
    }
    QBrush brush(Qt::white);
           painter.setBrush(brush);
           for(int i=0;i<=12;i++)
           {
             for(int j=12-i,m=0;m<=i;j=j+2,m++)
             {
                painter.drawEllipse(QPoint(j*20,i*30),10,10);
                painter.drawEllipse(QPoint(j*20,(16-i)*30),10,10);
             }
           }
    for(int i=0;i<10;i++)
    {
    drawPawn(painter,pawn[0][i].x,pawn[0][i].y,pawn[0][i].idToColor(0));
    drawPawn(painter,pawn[1][i].x,pawn[1][i].y,pawn[1][i].idToColor(1));
    drawPawn(painter,pawn[2][i].x,pawn[2][i].y,pawn[2][i].idToColor(2));
    }
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(avaiOnBoard[i][j])
            {
                painter.setPen(Qt::DashDotLine);
                brush.setColor(Qt::magenta);
                painter.setBrush(brush);
                painter.drawEllipse(i*20-7,j*30-7,14,14);
            }
        }
    }
}

void game_three::mouseReleaseEvent(QMouseEvent *ev)
{
    if(!tracking)
    {
        if((board[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30])&&((*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).id==(stepCount%teamNum)))
        {
            (*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).chosen=1;
            trackingNum[0]=(ev->pos().x()+10-100)/20;
            trackingNum[1]=(ev->pos().y()+15-30)/30;
            tracking=1;
            availableMove(trackingNum[0],trackingNum[1]);
            availableJump(trackingNum[0],trackingNum[1]);
            avaiOnBoard[trackingNum[0]][trackingNum[1]]=0;
            QWidget::repaint();
        }
    }
    else
    {
        if((((ev->pos().x()-100+10)/20)==trackingNum[0])&&(((ev->pos().y()+15-30)/30)==trackingNum[1]))
        {
            (*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).chosen=0;
            tracking=0;
            for(int i=0;i<24;i++)
            {
                for(int j=0;j<16;j++)
                {
                    avaiOnBoard[i][j]=0;
                    mem[i][j]=0;
                }
            }
            QWidget::repaint();
        }
        else if(avaiOnBoard[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30])
        {
            board[trackingNum[0]][trackingNum[1]]=0;
            (*toPawn[trackingNum[0]][trackingNum[1]]).x=((ev->pos().x()+10-100)/20)*20;
            (*toPawn[trackingNum[0]][trackingNum[1]]).y=((ev->pos().y()+15-30)/30)*30;
            (*toPawn[trackingNum[0]][trackingNum[1]]).chosen=0;
            board[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=1;
            toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=toPawn[trackingNum[0]][trackingNum[1]];
            toPawn[trackingNum[0]][trackingNum[1]]=&nullPawn;
            tracking=0;
            for(int i=0;i<24;i++)
            {
                for(int j=0;j<16;j++)
                {
                    avaiOnBoard[i][j]=0;
                    mem[i][j]=0;
                }
            }

            QWidget::repaint();
            stepCount++;

        }
    }
}

void game_three::availableMove(int x, int y)
{
    availableMove2(x+2,y);
    availableMove2(x-2,y);
    availableMove2(x+1,y+1);
    availableMove2(x-1,y-1);
    availableMove2(x+1,y-1);
    availableMove2(x-1,y+1);
}

bool game_three::availableMove2(int x, int y)
{
    if((!mem[x][y])&&(!board[x][y])&&(in(x,y)))
    {
        avaiOnBoard[x][y]=1;
        return true;
    }
    else
    {
        return false;
    }
}

void game_three::availableJump(int x, int y)
{
    mem[x][y]=1;
    direction=2;
    availableJump2(x+1,y-1);
    direction=3;
    availableJump2(x+2,y);
    direction=4;
    availableJump2(x+1,y+1);
    direction=6;
    availableJump2(x-1,y+1);
    direction=7;
    availableJump2(x-2,y);
    direction=8;
    availableJump2(x-1,y-1);
}

void game_three::availableJump2(int x, int y)
{
    if((!mem[x][y])&&(board[x][y])&&(in(x,y)))
    {
        switch(direction)
        {
        case 2:if(availableMove2(x+1,y-1))
                availableJump(x+1,y-1);
            break;
        case 3:if(availableMove2(x+2,y))
                availableJump(x+2,y);
            break;
        case 4:if(availableMove2(x+1,y+1))
                availableJump(x+1,y+1);
            break;
        case 6:if(availableMove2(x-1,y+1))
                availableJump(x-1,y+1);
            break;
        case 7:if(availableMove2(x-2,y))
                availableJump(x-2,y);
            break;
        case 8:if(availableMove2(x-1,y-1))
                availableJump(x-1,y-1);
            break;
        default:break;
        }
    }
}

bool game_three::in(int x, int y)
{
    if(x<0||x>24||y<0||y>16) return false;
    if((x+y)%2) return false;
    else
    {
        if(((y<=12)&&(y>=9))||((y<=3)&&(y>=0)))
        {
            if((x>(12+y))||(x<(12-y))) return false;
            else return true;
        }
        else
        {
            if((x>(12+(16-y)))||(x<(12-(16-y)))) return false;
            else return true;
        }
    }
}

void game_three::drawPawn(QPainter &painter, int x, int y, QColor color)
{
    painter.setBrush(QBrush(color));
    painter.drawEllipse(x-7,y-7,14,14);
}

void game_three::auto_walk()
{
    if(self_area=='A')
    {
        //开始搜索该方十个棋子的所有合法情况
        //电脑方棋子的id是1
        double length[10]={0};
        for(int i=0;i<10;i++)
        {
           qDebug()<<"开始运算第"<<i+1<<"个棋子的情况";
           availableMove(pawn[1][i].x/20,pawn[1][i].y/30);
           availableJump(pawn[1][i].x/20,pawn[1][i].y/30);
           int x_temp=pawn[1][i].x/20;
           int y_temp=pawn[1][i].y/30;
           for(int j=0;j<25;j++)
           {
             for(int z=0;z<17;z++)
             {
              if(avaiOnBoard[j][z]==1)
              {
                  qDebug()<<"横坐标="<<j<<"  纵坐标="<<z;
                  double temp=0;
                  temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                  if(temp>length[i])
                  {
                      length[i]=temp;
                  }
              }
            }
          }
          for(int i=0;i<24;i++)
          {
            for(int j=0;j<16;j++)
            {
               avaiOnBoard[i][j]=0;
               avaiJump[i][j]=0;
               mem[i][j]=0;
            }
         }
        }
        for(int i=0;i<10;i++)
        {
          qDebug()<<"第"<<i+1<<"个棋子的最远距离="<<length[i];
        }
        //进行所有棋子的比较
          //第一个原则：步数最远的优先
          double max_temp;
          int round_temp=0;
          int flag=0;
          int member[10]={0};
          for(int i=0;i<10;i++)
          {
             if(length[i]>length[round_temp])
           {
              round_temp=i;
              max_temp=length[i];
           }
          }
        qDebug()<<"max_temp="<<max_temp;
        //把距离最远的归队
        for(int i=0;i<10;i++)
        {
           if(fabs(length[i]-max_temp)<1e-3)
          {
            member[flag]=i;
            flag+=1;
          }
        }

        //第二个原则：步数一致时靠后的先行
        qDebug()<<"member[0]="<<member[0];
        if(flag==1)
         {
          int max_x,max_y;
          int x_temp=pawn[1][member[0]].x/20;
          int y_temp=pawn[1][member[0]].y/30;
          availableMove(pawn[1][member[0]].x/20,pawn[1][member[0]].y/30);
          availableJump(pawn[1][member[0]].x/20,pawn[1][member[0]].y/30);
          qDebug()<<"x_temp="<<x_temp<<"y_temp="<<y_temp;
          for(int j=0;j<25;j++)
          {
             for(int z=0;z<17;z++)
             {
                 if(avaiOnBoard[j][z]==1)
                 {
                     double temp=0;
                     temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                     qDebug()<<"temp="<<temp;
                     if(fabs(temp-max_temp)<1e-3)
                     {
                         max_x=j;
                         max_y=z;
                         qDebug()<<"max_x="<<max_x<<"max_y="<<max_y;
                     }
                 }
             }
          }
          //清空判断棋盘的数据状态
          for(int i=0;i<24;i++)
          {
              for(int j=0;j<16;j++)
              {
                  avaiOnBoard[i][j]=0;
                  avaiJump[i][j]=0;
                  mem[i][j]=0;
              }
          }
          qDebug()<<"天选之子的横坐标="<<pawn[1][member[0]].x<<" 天选之子的纵坐标="<<pawn[1][member[0]].y;
          pawn[1][member[0]].x=max_x*20;
          pawn[1][member[0]].y=max_y*30;
          qDebug()<<"天选之子的横坐标="<<pawn[1][member[0]].x<<" 天选之子的纵坐标="<<pawn[1][member[0]].y;
          //将上述过程所有暂时数据清空
          max_temp=0;
          round_temp=0;
          flag=0;
          for(int i=0;i<10;i++)
          {
              member[i]=0;
          }
          max_x=0;
          max_y=0;
      }
      else
      {
        //判断目前谁靠后
        int final_x=12;
        int final_y=17;
        double temp_final[10]={0};
        for(int i=0;i<flag;i++)
        {
           //计算和对角线的终点的距离
            double temp;
            temp=sqrt(pow(pawn[1][member[i]].x/20-final_x,2)+pow(pawn[1][member[i]].y/30-final_y,2));
            temp_final[i]=temp;
            qDebug()<<"temp="<<temp;
        }


        //进行比较
        double temp_final_max;
        int temp_final_max_num;
        temp_final_max=temp_final[0];
        temp_final_max_num=member[0];
        for(int i=0;i<flag;i++)
        {
            if(temp_final[i]>temp_final_max)
            {
                temp_final_max=temp_final[i];
                temp_final_max_num=member[i];
            }
        }
        qDebug()<<"temp_final_max="<<temp_final_max<<"temp_final_max_num="<<temp_final_max_num;

        //计算得出符合条件的棋子为temp_final_max_num;
        int max_x=0,max_y=0;
        int x_temp=pawn[1][temp_final_max_num].x/20;
        int y_temp=pawn[1][temp_final_max_num].y/30;
        availableMove(x_temp,y_temp);
        availableJump(x_temp,y_temp);
        for(int j=0;j<25;j++)
        {
           for(int z=0;z<17;z++)
           {
               if(avaiOnBoard[j][z]==1)
               {
                   qDebug()<<"why??????";
                   double temp=0;
                   temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                   if(fabs(temp-max_temp)<1e-3)
                   {
                       max_x=j;
                       max_y=z;
                   }
               }
           }
        }
        qDebug()<<"max_x="<<max_x<<"max_y="<<max_y;

        //清空判断棋盘的数据状态
        for(int i=0;i<24;i++)
        {
            for(int j=0;j<16;j++)
            {
                avaiOnBoard[i][j]=0;
                avaiJump[i][j]=0;
                mem[i][j]=0;
            }
        }
        //第一个点坐标
        zuobiao temp1;
        temp1.x=pawn[1][temp_final_max_num].x/20;
        temp1.y=pawn[1][temp_final_max_num].y/30;;
        temp1.x=(temp1.x+temp1.y-20)/2;
        temp1.y=8-temp1.y;
        move_zuobiao.append(temp1);


        pawn[1][temp_final_max_num].x=max_x*20;
        pawn[1][temp_final_max_num].y=max_y*30;

        //第二个点坐标
        zuobiao temp;
        temp.x=max_x;
        temp.y=max_y;
        temp.x=(temp.x+temp.y-20)/2;
        temp.y=8-temp.y;
        move_zuobiao.append(temp);
        //发送
        is_over();
      }


      //行棋
    }
    else if(self_area=='D')
    {
        //开始搜索该方十个棋子的所有合法情况
        //电脑方棋子的id是1
        double length[10]={0};
        for(int i=0;i<10;i++)
        {
           qDebug()<<"开始运算第"<<i+1<<"个棋子的情况";
           availableMove(pawn[0][i].x/20,pawn[0][i].y/30);
           availableJump(pawn[0][i].x/20,pawn[0][i].y/30);
           int x_temp=pawn[0][i].x/20;
           int y_temp=pawn[0][i].y/30;
           for(int j=0;j<25;j++)
           {
             for(int z=0;z<17;z++)
             {
              if(avaiOnBoard[j][z]==1)
              {
                  qDebug()<<"横坐标="<<j<<"  纵坐标="<<z;
                  double temp=0;
                  temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                  if(temp>length[i])
                  {
                      length[i]=temp;
                  }
              }
            }
          }
          for(int i=0;i<24;i++)
          {
            for(int j=0;j<16;j++)
            {
               avaiOnBoard[i][j]=0;
               avaiJump[i][j]=0;
               mem[i][j]=0;
            }
         }
        }
        for(int i=0;i<10;i++)
        {
          qDebug()<<"第"<<i+1<<"个棋子的最远距离="<<length[i];
        }
        //进行所有棋子的比较
          //第一个原则：步数最远的优先
          double max_temp;
          int round_temp=0;
          int flag=0;
          int member[10]={0};
          for(int i=0;i<10;i++)
          {
             if(length[i]>length[round_temp])
           {
              round_temp=i;
              max_temp=length[i];
           }
          }
        qDebug()<<"max_temp="<<max_temp;
        //把距离最远的归队
        for(int i=0;i<10;i++)
        {
           if(fabs(length[i]-max_temp)<1e-3)
          {
            member[flag]=i;
            flag+=1;
          }
        }

        //第二个原则：步数一致时靠后的先行
        qDebug()<<"member[0]="<<member[0];
        if(flag==1)
         {
          int max_x,max_y;
          int x_temp=pawn[0][member[0]].x/20;
          int y_temp=pawn[0][member[0]].y/30;
          availableMove(pawn[0][member[0]].x/20,pawn[0][member[0]].y/30);
          availableJump(pawn[0][member[0]].x/20,pawn[0][member[0]].y/30);
          qDebug()<<"x_temp="<<x_temp<<"y_temp="<<y_temp;
          for(int j=0;j<25;j++)
          {
             for(int z=0;z<17;z++)
             {
                 if(avaiOnBoard[j][z]==1)
                 {
                     double temp=0;
                     temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                     qDebug()<<"temp="<<temp;
                     if(fabs(temp-max_temp)<1e-3)
                     {
                         max_x=j;
                         max_y=z;
                         qDebug()<<"max_x="<<max_x<<"max_y="<<max_y;
                     }
                 }
             }
          }
          //清空判断棋盘的数据状态
          for(int i=0;i<24;i++)
          {
              for(int j=0;j<16;j++)
              {
                  avaiOnBoard[i][j]=0;
                  avaiJump[i][j]=0;
                  mem[i][j]=0;
              }
          }
          qDebug()<<"天选之子的横坐标="<<pawn[0][member[0]].x<<" 天选之子的纵坐标="<<pawn[0][member[0]].y;
          pawn[0][member[0]].x=max_x*20;
          pawn[0][member[0]].y=max_y*30;
          qDebug()<<"天选之子的横坐标="<<pawn[0][member[0]].x<<" 天选之子的纵坐标="<<pawn[0][member[0]].y;
          //将上述过程所有暂时数据清空
          max_temp=0;
          round_temp=0;
          flag=0;
          for(int i=0;i<10;i++)
          {
              member[i]=0;
          }
          max_x=0;
          max_y=0;
      }
      else
      {
        //判断目前谁靠后
        int final_x=12;
        int final_y=0;
        double temp_final[10]={0};
        for(int i=0;i<flag;i++)
        {
           //计算和对角线的终点的距离
            double temp;
            temp=sqrt(pow(pawn[0][member[i]].x/20-final_x,2)+pow(pawn[0][member[i]].y/30-final_y,2));
            temp_final[i]=temp;
            qDebug()<<"temp="<<temp;
        }


        //进行比较
        double temp_final_max;
        int temp_final_max_num;
        temp_final_max=temp_final[0];
        temp_final_max_num=member[0];
        for(int i=0;i<flag;i++)
        {
            if(temp_final[i]>temp_final_max)
            {
                temp_final_max=temp_final[i];
                temp_final_max_num=member[i];
            }
        }
        qDebug()<<"temp_final_max="<<temp_final_max<<"temp_final_max_num="<<temp_final_max_num;

        //计算得出符合条件的棋子为temp_final_max_num;
        int max_x=0,max_y=0;
        int x_temp=pawn[0][temp_final_max_num].x/20;
        int y_temp=pawn[0][temp_final_max_num].y/30;
        availableMove(x_temp,y_temp);
        availableJump(x_temp,y_temp);
        for(int j=0;j<25;j++)
        {
           for(int z=0;z<17;z++)
           {
               if(avaiOnBoard[j][z]==1)
               {
                   qDebug()<<"why??????";
                   double temp=0;
                   temp=sqrt(pow(x_temp-j,2)+pow(y_temp-z,2));
                   if(fabs(temp-max_temp)<1e-3)
                   {
                       max_x=j;
                       max_y=z;
                   }
               }
           }
        }
        qDebug()<<"max_x="<<max_x<<"max_y="<<max_y;

        //清空判断棋盘的数据状态
        for(int i=0;i<24;i++)
        {
            for(int j=0;j<16;j++)
            {
                avaiOnBoard[i][j]=0;
                avaiJump[i][j]=0;
                mem[i][j]=0;
            }
        }
        //第一个点坐标
        zuobiao temp1;
        temp1.x=pawn[0][temp_final_max_num].x/20;
        temp1.y=pawn[0][temp_final_max_num].y/30;;
        temp1.x=(temp1.x+temp1.y-20)/2;
        temp1.y=8-temp1.y;
        move_zuobiao.append(temp1);


        pawn[0][temp_final_max_num].x=max_x*20;
        pawn[0][temp_final_max_num].y=max_y*30;

        //第二个点坐标
        zuobiao temp;
        temp.x=max_x;
        temp.y=max_y;
        temp.x=(temp.x+temp.y-20)/2;
        temp.y=8-temp.y;
        move_zuobiao.append(temp);
        //发送
        is_over();
      }


      //行棋
    }
    else if(self_area=='F')
    {

    }
}

void game_three::daojishi(QString a)
{
    QString b;
    if(a.length()==2)
      b="00:";
    else
      b="00:0";
    a=b+a;
    ui->label_7->setText(a);
}

void game_three::makeback(QString a)
{
    ui->label_9->setText(a);
    for(int i=0;i<3;i++)
    {
        if(player_area[i]==temp_area)
        {
            ui->label_11->setText(player_name[i]);
            break;
        }
    }
}

void game_three::on_pushButton_clicked()
{
    auto_symbol=1;
    ui->label_13->setPixmap(QPixmap(":/pic_2.png"));
    ui->label_13->setScaledContents(true);
}


void game_three::on_pushButton_2_clicked()
{
    auto_symbol=0;
    ui->label_13->clear();
}

void game_three::moveOperation(int x1, int y1)
{
    if(!tracking)
    {
        if((board[x1][y1]))
        {
            (*toPawn[x1][y1]).chosen=1;
            trackingNum2[0]=x1;
            trackingNum2[1]=y1;
            tracking=true;
            availableMove(trackingNum2[0],trackingNum2[1]);
            availableJump(trackingNum2[0],trackingNum2[1]);
            avaiOnBoard[trackingNum2[0]][trackingNum2[1]]=0;

            QWidget::repaint();

            QEventLoop evl;
            QTimer::singleShot(500,&evl,SLOT(quit()));
            evl.exec();
        }
    }
    else
    {
        if((x1==trackingNum2[0])&&(y1==trackingNum2[1]))
        {
            if(!alreadyMove)
            {
                (*toPawn[x1][y1]).chosen=0;
                tracking=0;
                for(int i=0;i<24;i++)
                {
                    for(int j=0;j<16;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                        mem[i][j]=0;
                    }
                }

            QWidget::repaint();
            }
            else
            {
                alreadyMove=0;
                tracking=0;
                (*toPawn[x1][y1]).chosen=0;
                for(int i=0;i<24;i++)
                {
                    for(int j=0;j<16;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                        mem[i][j]=0;
                    }
                }
                comboJump=0;
                //stepCount++;

               QWidget::repaint();
            }
        }
        else if(avaiOnBoard[x1][y1])
        {

            if(!alreadyMove)
            {
            mem[x1][y1]=1;
            alreadyMove=1;
            board[trackingNum2[0]][trackingNum2[1]]=0;
            (*toPawn[trackingNum2[0]][trackingNum2[1]]).x=(x1)*20;
            (*toPawn[trackingNum2[0]][trackingNum2[1]]).y=(y1)*30;
            board[x1][y1]=1;
            toPawn[x1][y1]=toPawn[trackingNum2[0]][trackingNum2[1]];
            toPawn[trackingNum2[0]][trackingNum2[1]]=&nullPawn;
            trackingNum2[0]=x1;
            trackingNum2[1]=y1;



            if(avaiJump[x1][y1])
            {
                comboJump=1;
                for(int i=0;i<25;i++)
                {
                    for(int j=0;j<17;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                    }
                }
                availableJump(trackingNum2[0],trackingNum2[1]);
            }
            else
            {
                for(int i=0;i<25;i++)
                {
                    for(int j=0;j<17;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                    }
                }
            }
            avaiOnBoard[x1][y1]=0;

            QWidget::repaint();

            QEventLoop evl;
            QTimer::singleShot(500,&evl,SLOT(quit()));
            evl.exec();
            }
            else if(comboJump)
            {
                mem[x1][y1]=1;
                board[trackingNum2[0]][trackingNum2[1]]=0;
                (*toPawn[trackingNum2[0]][trackingNum2[1]]).x=(x1)*20;
                (*toPawn[trackingNum2[0]][trackingNum2[1]]).y=(y1)*30;
                board[x1][y1]=1;
                toPawn[x1][y1]=toPawn[trackingNum2[0]][trackingNum2[1]];
                toPawn[trackingNum2[0]][trackingNum2[1]]=&nullPawn;
                trackingNum2[0]=x1;
                trackingNum2[1]=y1;

                for(int i=0;i<25;i++)
                {
                    for(int j=0;j<17;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                    }
                }

                availableJump(trackingNum2[0],trackingNum2[1]);
                avaiOnBoard[trackingNum2[0]][trackingNum2[1]]=0;

                QWidget::repaint();
                QEventLoop evl;
                QTimer::singleShot(500,&evl,SLOT(quit()));
                evl.exec();
            }
        }
    }
}
