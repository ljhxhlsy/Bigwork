#include "computer_two.h"
#include "ui_computer_two.h"
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QBrush>
#include "pawn.h"
#include <QWidget>
#include <QString>
#include <QFont>
#include<four.h>
#include<QColorDialog>
#include <QTimer>
#include <QEventLoop>
#include<computer.h>
#include<math.h>
computer_two::computer_two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computer_two)
{
    ui->setupUi(this);
    resize(850,600);
    setMouseTracking(true);
    tracking=0;
    trackingNum[0]=trackingNum[1]=-1;
    direction=0;
    stepCount=0;
    teamNum=2;
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
    pawn[1][0].x=12*20;pawn[1][0].y=0*30;pawn[1][0].id=1;board[12][0]=1;toPawn[12][0]=&pawn[1][0];
    pawn[1][1].x=11*20;pawn[1][1].y=1*30;pawn[1][1].id=1;board[11][1]=1;toPawn[11][1]=&pawn[1][1];
    pawn[1][2].x=13*20;pawn[1][2].y=1*30;pawn[1][2].id=1;board[13][1]=1;toPawn[13][1]=&pawn[1][2];
    pawn[1][3].x=10*20;pawn[1][3].y=2*30;pawn[1][3].id=1;board[10][2]=1;toPawn[10][2]=&pawn[1][3];
    pawn[1][4].x=12*20;pawn[1][4].y=2*30;pawn[1][4].id=1;board[12][2]=1;toPawn[12][2]=&pawn[1][4];
    pawn[1][5].x=14*20;pawn[1][5].y=2*30;pawn[1][5].id=1;board[14][2]=1;toPawn[14][2]=&pawn[1][5];
    pawn[1][6].x= 9*20;pawn[1][6].y=3*30;pawn[1][6].id=1;board[ 9][3]=1;toPawn[ 9][3]=&pawn[1][6];
    pawn[1][7].x=11*20;pawn[1][7].y=3*30;pawn[1][7].id=1;board[11][3]=1;toPawn[11][3]=&pawn[1][7];
    pawn[1][8].x=13*20;pawn[1][8].y=3*30;pawn[1][8].id=1;board[13][3]=1;toPawn[13][3]=&pawn[1][8];
    pawn[1][9].x=15*20;pawn[1][9].y=3*30;pawn[1][9].id=1;board[15][3]=1;toPawn[15][3]=&pawn[1][9];



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
}

computer_two::~computer_two()
{
    delete ui;
}

void computer_two::paintEvent(QPaintEvent *ev)
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

    QPoint points_pan[6]={QPoint(8*20,4*30),QPoint(4*20,8*30),QPoint(8*20,12*30),QPoint(16*20,12*30),QPoint(20*20,8*30),QPoint(16*20,4*30)};
    brush2.setColor(QColor(237,237,237));
    painter.setBrush(brush2);
    painter.drawPolygon(points_pan,6);


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
    drawPawn(painter,pawn[1][i].x,pawn[1][i].y,pawn[1][i].idToColor(1));}
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

void computer_two::drawPawn(QPainter &painter, int x, int y, QColor color)
{
    painter.setBrush(QBrush(color));
    painter.drawEllipse(x-7,y-7,14,14);
}

void computer_two::mouseReleaseEvent(QMouseEvent *ev)
{
    static bool alreadyMove=0;
    static bool comboJump=0;

    if(!tracking)
    {
        if((board[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30])&&((*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).id==(stepCount%teamNum)))
        {
            if(stepCount%teamNum==0)
            {
               ui->label_8->setText("玩家");
               ui->label_10->setText("D");
                (*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).chosen=1;
               trackingNum[0]=(ev->pos().x()+10-100)/20;
               trackingNum[1]=(ev->pos().y()+15-30)/30;
               tracking=1;
               availableMove(trackingNum[0],trackingNum[1]);
               availableJump(trackingNum[0],trackingNum[1]);
               avaiOnBoard[trackingNum[0]][trackingNum[1]]=0;
               QEventLoop eventloop;
                        QTimer::singleShot(500,&eventloop,SLOT(quit()));
                        eventloop.exec();
               QWidget::repaint();
            }
            else
            {
                ui->label_8->setText("电脑");
                ui->label_10->setText("A");
                auto_walk();
                stepCount++;
                QWidget::repaint();
            }
        }
    }
    else
    {
        if((((ev->pos().x()-100+10)/20)==trackingNum[0])&&(((ev->pos().y()+15-30)/30)==trackingNum[1]))
        {
            if(!alreadyMove)
            {
            (*toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]).chosen=0;
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
            QWidget::repaint();}
            else
            {
                alreadyMove=0;
                tracking=0;
                (*toPawn[trackingNum[0]][trackingNum[1]]).chosen=0;
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
                stepCount++;
                QWidget::repaint();
            }
        }
        else if(avaiOnBoard[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30])
        {
            if(!alreadyMove)
            {
            mem[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=1;
            alreadyMove=1;
            board[trackingNum[0]][trackingNum[1]]=0;
            (*toPawn[trackingNum[0]][trackingNum[1]]).x=((ev->pos().x()+10-100)/20)*20;
            (*toPawn[trackingNum[0]][trackingNum[1]]).y=((ev->pos().y()+15-30)/30)*30;
            //(*toPawn[trackingNum[0]][trackingNum[1]]).chosen=0;
            board[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=1;
            toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=toPawn[trackingNum[0]][trackingNum[1]];
            toPawn[trackingNum[0]][trackingNum[1]]=&nullPawn;
            trackingNum[0]=(ev->pos().x()+10-100)/20;
            trackingNum[1]=(ev->pos().y()+15-30)/30;
            //tracking=0;



            if(avaiJump[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30])
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
                availableJump(trackingNum[0],trackingNum[1]);
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
            avaiOnBoard[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=0;

            QWidget::repaint();
            //stepCount++;
            }
            else if(comboJump)
            {
                mem[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=1;
                board[trackingNum[0]][trackingNum[1]]=0;
                (*toPawn[trackingNum[0]][trackingNum[1]]).x=((ev->pos().x()+10-100)/20)*20;
                (*toPawn[trackingNum[0]][trackingNum[1]]).y=((ev->pos().y()+15-30)/30)*30;
                board[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=1;
                toPawn[(ev->pos().x()+10-100)/20][(ev->pos().y()+15-30)/30]=toPawn[trackingNum[0]][trackingNum[1]];
                toPawn[trackingNum[0]][trackingNum[1]]=&nullPawn;
                trackingNum[0]=(ev->pos().x()+10-100)/20;
                trackingNum[1]=(ev->pos().y()+15-30)/30;

                for(int i=0;i<25;i++)
                {
                    for(int j=0;j<17;j++)
                    {
                        avaiOnBoard[i][j]=0;
                        avaiJump[i][j]=0;
                    }
                }

                availableJump(trackingNum[0],trackingNum[1]);
                avaiOnBoard[trackingNum[0]][trackingNum[1]]=0;

                QWidget::repaint();
            }
        }
    }

}

void computer_two::availableMove(int x, int y)
{
    availableMove2(x+2,y);
    availableMove2(x-2,y);
    availableMove2(x+1,y+1);
    availableMove2(x-1,y-1);
    availableMove2(x+1,y-1);
    availableMove2(x-1,y+1);
}

bool computer_two::availableMove2(int x, int y)
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

bool computer_two::availableJump3(int x, int y)
{
    if((!mem[x][y])&&(!board[x][y])&&(in(x,y)))
    {
        avaiOnBoard[x][y]=1;
        avaiJump[x][y]=1;
        return true;
    }
    else
    {
        return false;
    }
}

void computer_two::availableJump2(int x, int y)
{
    if((board[x][y])&&(in(x,y)))
    {
        switch(direction)
        {
        case 2:availableJump3(x+1,y-1);
            break;
        case 3:availableJump3(x+2,y);
            break;
        case 4:availableJump3(x+1,y+1);
            break;
        case 6:availableJump3(x-1,y+1);
            break;
        case 7:availableJump3(x-2,y);
            break;
        case 8:availableJump3(x-1,y-1);
            break;
        default:break;
        }
    }
}

void computer_two::availableJump(int x, int y)
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

bool computer_two::in(int x, int y)
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

void computer_two::on_pushButton_clicked()
{
    computer *next=new computer();
    this->close();
    next->show();
}

void computer_two::on_pushButton_2_clicked()
{
    this->close();
}

void computer_two::auto_availablejump2(int x, int y)
{
    if((!mem[x][y])&&(board[x][y])&&(in(x,y)))
    {
        switch(direction)
        {
        case 2:if(availableMove2(x+1,y-1))
                auto_availablejump(x+1,y-1);
            break;
        case 3:if(availableMove2(x+2,y))
                auto_availablejump(x+2,y);
            break;
        case 4:if(availableMove2(x+1,y+1))
                auto_availablejump(x+1,y+1);
            break;
        case 6:if(availableMove2(x-1,y+1))
                auto_availablejump(x-1,y+1);
            break;
        case 7:if(availableMove2(x-2,y))
                auto_availablejump(x-2,y);
            break;
        case 8:if(availableMove2(x-1,y-1))
                auto_availablejump(x-1,y-1);
            break;
        default:break;
        }
    }
}

void computer_two::auto_availablejump(int x, int y)
{
    mem[x][y]=1;
    direction=2;
    auto_availablejump2(x+1,y-1);
    direction=3;
    auto_availablejump2(x+2,y);
    direction=4;
    auto_availablejump2(x+1,y+1);
    direction=6;
    auto_availablejump2(x-1,y+1);
    direction=7;
    auto_availablejump2(x-2,y);
    direction=8;
    auto_availablejump2(x-1,y-1);
}
void computer_two::auto_walk()
{
    //开始搜索该方十个棋子的所有合法情况
      //电脑方棋子的id是1
    double length[10]={0};
    for(int i=0;i<10;i++)
    {
       qDebug()<<"开始运算第"<<i+1<<"个棋子的情况";
       availableMove(pawn[1][i].x/20,pawn[1][i].y/30);
       auto_availablejump(pawn[1][i].x/20,pawn[1][i].y/30);
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
          auto_availablejump(pawn[1][member[0]].x/20,pawn[1][member[0]].y/30);
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
        auto_availablejump(x_temp,y_temp);
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
        pawn[1][temp_final_max_num].x=max_x*20;
        pawn[1][temp_final_max_num].y=max_y*30;


      }


    //行棋

}



void computer_two::auto_walk2()
{
    //搜索当前十个棋子的合法情况
      //为每个棋子建立链表，储存合法走法
      QList<zuobiao> availbmove[10];
      for(int i=0;i<10;i++)
      {
         //找到当前棋子走的最多的那一种走法
         //每一次深搜回来，与当前最大值比较，如果出现更大值，则替换

      }
    //第一个原则，比较距离的远近
    //第二个原则，位置靠后的先走
    //行棋
}












