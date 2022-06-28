#include "liuren.h"
#include "ui_liuren.h"
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QBrush>
#include "pawn.h"
#include <QWidget>
#include <QString>
#include <QFont>
#include<four.h>
liuren::liuren(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::liuren)
{
    ui->setupUi(this);
    resize(850,600);
    setMouseTracking(true);
    tracking=0;
    trackingNum[0]=trackingNum[1]=-1;
    direction=0;
    stepCount=0;
    teamNum=6;
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
    //第三组
    pawn[2][0].x= 0*20;pawn[2][0].y=4*30;pawn[2][0].id=2;board[0][4]=1;toPawn[0][4]=&pawn[2][0];
    pawn[2][1].x= 1*20;pawn[2][1].y=5*30;pawn[2][1].id=2;board[1][5]=1;toPawn[1][5]=&pawn[2][1];
    pawn[2][2].x= 2*20;pawn[2][2].y=4*30;pawn[2][2].id=2;board[2][4]=1;toPawn[2][4]=&pawn[2][2];
    pawn[2][3].x= 2*20;pawn[2][3].y=6*30;pawn[2][3].id=2;board[2][6]=1;toPawn[2][6]=&pawn[2][3];
    pawn[2][4].x= 3*20;pawn[2][4].y=5*30;pawn[2][4].id=2;board[3][5]=1;toPawn[3][5]=&pawn[2][4];
    pawn[2][5].x= 3*20;pawn[2][5].y=7*30;pawn[2][5].id=2;board[3][7]=1;toPawn[3][7]=&pawn[2][5];
    pawn[2][6].x= 4*20;pawn[2][6].y=4*30;pawn[2][6].id=2;board[4][4]=1;toPawn[4][4]=&pawn[2][6];
    pawn[2][7].x= 4*20;pawn[2][7].y=6*30;pawn[2][7].id=2;board[4][6]=1;toPawn[4][6]=&pawn[2][7];
    pawn[2][8].x= 5*20;pawn[2][8].y=5*30;pawn[2][8].id=2;board[5][5]=1;toPawn[5][5]=&pawn[2][8];
    pawn[2][9].x= 6*20;pawn[2][9].y=4*30;pawn[2][9].id=2;board[6][4]=1;toPawn[6][4]=&pawn[2][9];
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
    //第五组
    pawn[4][0].x=18*20;pawn[4][0].y=4*30;pawn[4][0].id=4;board[18][4]=1;toPawn[18][4]=&pawn[4][0];
    pawn[4][1].x=19*20;pawn[4][1].y=5*30;pawn[4][1].id=4;board[19][5]=1;toPawn[19][5]=&pawn[4][1];
    pawn[4][2].x=20*20;pawn[4][2].y=4*30;pawn[4][2].id=4;board[20][4]=1;toPawn[20][4]=&pawn[4][2];
    pawn[4][3].x=20*20;pawn[4][3].y=6*30;pawn[4][3].id=4;board[20][6]=1;toPawn[20][6]=&pawn[4][3];
    pawn[4][4].x=21*20;pawn[4][4].y=5*30;pawn[4][4].id=4;board[21][5]=1;toPawn[21][5]=&pawn[4][4];
    pawn[4][5].x=21*20;pawn[4][5].y=7*30;pawn[4][5].id=4;board[21][7]=1;toPawn[21][7]=&pawn[4][5];
    pawn[4][6].x=22*20;pawn[4][6].y=4*30;pawn[4][6].id=4;board[22][4]=1;toPawn[22][4]=&pawn[4][6];
    pawn[4][7].x=22*20;pawn[4][7].y=6*30;pawn[4][7].id=4;board[22][6]=1;toPawn[22][6]=&pawn[4][7];
    pawn[4][8].x=23*20;pawn[4][8].y=5*30;pawn[4][8].id=4;board[23][5]=1;toPawn[23][5]=&pawn[4][8];
    pawn[4][9].x=24*20;pawn[4][9].y=4*30;pawn[4][9].id=4;board[24][4]=1;toPawn[24][4]=&pawn[4][9];
    //第二组
    pawn[1][0].x=0*20;pawn[1][0].y=12*30;pawn[1][0].id=1;board[0][12]=1;toPawn[0][12]=&pawn[1][0];
    pawn[1][1].x=1*20;pawn[1][1].y=11*30;pawn[1][1].id=1;board[1][11]=1;toPawn[1][11]=&pawn[1][1];
    pawn[1][2].x=2*20;pawn[1][2].y=10*30;pawn[1][2].id=1;board[2][10]=1;toPawn[2][10]=&pawn[1][2];
    pawn[1][3].x=2*20;pawn[1][3].y=12*30;pawn[1][3].id=1;board[2][12]=1;toPawn[2][12]=&pawn[1][3];
    pawn[1][4].x=3*20;pawn[1][4].y= 9*30;pawn[1][4].id=1;board[3][ 9]=1;toPawn[3][ 9]=&pawn[1][4];
    pawn[1][5].x=3*20;pawn[1][5].y=11*30;pawn[1][5].id=1;board[3][11]=1;toPawn[3][11]=&pawn[1][5];
    pawn[1][6].x=4*20;pawn[1][6].y=10*30;pawn[1][6].id=1;board[4][10]=1;toPawn[4][10]=&pawn[1][6];
    pawn[1][7].x=4*20;pawn[1][7].y=12*30;pawn[1][7].id=1;board[4][12]=1;toPawn[4][12]=&pawn[1][7];
    pawn[1][8].x=5*20;pawn[1][8].y=11*30;pawn[1][8].id=1;board[5][11]=1;toPawn[5][11]=&pawn[1][8];
    pawn[1][9].x=6*20;pawn[1][9].y=12*30;pawn[1][9].id=1;board[6][12]=1;toPawn[6][12]=&pawn[1][9];
    //第四组
    pawn[3][0].x=12*20;pawn[3][0].y=0*30;pawn[3][0].id=3;board[12][0]=1;toPawn[12][0]=&pawn[3][0];
    pawn[3][1].x=11*20;pawn[3][1].y=1*30;pawn[3][1].id=3;board[11][1]=1;toPawn[11][1]=&pawn[3][1];
    pawn[3][2].x=13*20;pawn[3][2].y=1*30;pawn[3][2].id=3;board[13][1]=1;toPawn[13][1]=&pawn[3][2];
    pawn[3][3].x=10*20;pawn[3][3].y=2*30;pawn[3][3].id=3;board[10][2]=1;toPawn[10][2]=&pawn[3][3];
    pawn[3][4].x=12*20;pawn[3][4].y=2*30;pawn[3][4].id=3;board[12][2]=1;toPawn[12][2]=&pawn[3][4];
    pawn[3][5].x=14*20;pawn[3][5].y=2*30;pawn[3][5].id=3;board[14][2]=1;toPawn[14][2]=&pawn[3][5];
    pawn[3][6].x= 9*20;pawn[3][6].y=3*30;pawn[3][6].id=3;board[ 9][3]=1;toPawn[ 9][3]=&pawn[3][6];
    pawn[3][7].x=11*20;pawn[3][7].y=3*30;pawn[3][7].id=3;board[11][3]=1;toPawn[11][3]=&pawn[3][7];
    pawn[3][8].x=13*20;pawn[3][8].y=3*30;pawn[3][8].id=3;board[13][3]=1;toPawn[13][3]=&pawn[3][8];
    pawn[3][9].x=15*20;pawn[3][9].y=3*30;pawn[3][9].id=3;board[15][3]=1;toPawn[15][3]=&pawn[3][9];
    //第六组
    pawn[5][0].x=18*20;pawn[5][0].y=12*30;pawn[5][0].id=5;board[18][12]=1;toPawn[18][12]=&pawn[5][0];
    pawn[5][1].x=19*20;pawn[5][1].y=11*30;pawn[5][1].id=5;board[19][11]=1;toPawn[19][11]=&pawn[5][1];
    pawn[5][2].x=20*20;pawn[5][2].y=10*30;pawn[5][2].id=5;board[20][10]=1;toPawn[20][10]=&pawn[5][2];
    pawn[5][3].x=20*20;pawn[5][3].y=12*30;pawn[5][3].id=5;board[20][12]=1;toPawn[20][12]=&pawn[5][3];
    pawn[5][4].x=21*20;pawn[5][4].y= 9*30;pawn[5][4].id=5;board[21][ 9]=1;toPawn[21][ 9]=&pawn[5][4];
    pawn[5][5].x=21*20;pawn[5][5].y=11*30;pawn[5][5].id=5;board[21][11]=1;toPawn[21][11]=&pawn[5][5];
    pawn[5][6].x=22*20;pawn[5][6].y=10*30;pawn[5][6].id=5;board[22][10]=1;toPawn[22][10]=&pawn[5][6];
    pawn[5][7].x=22*20;pawn[5][7].y=12*30;pawn[5][7].id=5;board[22][12]=1;toPawn[22][12]=&pawn[5][7];
    pawn[5][8].x=23*20;pawn[5][8].y=11*30;pawn[5][8].id=5;board[23][11]=1;toPawn[23][11]=&pawn[5][8];
    pawn[5][9].x=24*20;pawn[5][9].y=12*30;pawn[5][9].id=5;board[24][12]=1;toPawn[24][12]=&pawn[5][9];
}

liuren::~liuren()
{
    delete ui;
}
void liuren::paintEvent(QPaintEvent *ev)
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
    drawPawn(painter,pawn[1][i].x,pawn[1][i].y,pawn[1][i].idToColor(3));
    drawPawn(painter,pawn[2][i].x,pawn[2][i].y,pawn[2][i].idToColor(2));
    drawPawn(painter,pawn[3][i].x,pawn[3][i].y,pawn[3][i].idToColor(1));
    drawPawn(painter,pawn[4][i].x,pawn[4][i].y,pawn[4][i].idToColor(4));
    drawPawn(painter,pawn[5][i].x,pawn[5][i].y,pawn[5][i].idToColor(6));

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

void liuren::mouseReleaseEvent(QMouseEvent *ev)
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


void liuren::availableMove(int x,int y)
{
    availableMove2(x+2,y);
    availableMove2(x-2,y);
    availableMove2(x+1,y+1);
    availableMove2(x-1,y-1);
    availableMove2(x+1,y-1);
    availableMove2(x-1,y+1);
}

bool liuren::availableMove2(int x,int y)
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

void liuren::availableJump(int x,int y)
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

void liuren::availableJump2(int x,int y)
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

bool liuren::in(int x,int y)
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


void liuren::drawPawn(QPainter & painter,int x,int y,QColor color)
{
    painter.setBrush(QBrush(color));
    painter.drawEllipse(x-7,y-7,14,14);
}

void liuren::on_pushButton_2_clicked()
{
    this->close();
}


void liuren::on_pushButton_clicked()
{
    four *next=new four();
    this->close();
    next->show();
}

