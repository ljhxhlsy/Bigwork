#ifndef SERVE_H
#define SERVE_H

#include <QWidget>
#include<networkserver.h>
#include <QTcpSocket>
#include <QString>
#include <QList>
#include <QTcpServer>
#include <QStandardItemModel>
#include <cstdlib>
#include <QDebug>
#include <QHostAddress>
namespace Ui {
class serve;
}

class room
{
    public:
      QString name;
      QTcpSocket *local;
      /*QList<QTcpSocket *> roomList;
      QList<QTcpSocket *> rankList;*/
      QTcpSocket * roomlist[6];
      QTcpSocket * ranklist[6];
      QList<QString> room_name;
      QList<QString> list_name;
      bool situation;
      int num_roomlist=0;
      int num_ranklist=0;
private:


};

class serve : public QWidget
{
    Q_OBJECT

public:
    explicit serve(QWidget *parent = nullptr);
    NetworkServer *server=new NetworkServer(this);
    void receive(QTcpSocket* client, NetworkData data);
    void makegame();
    //room player[20];
    QString name;
    QTcpSocket *local;
    QTcpSocket * roomlist[6];
    QTcpSocket * ranklist[6];
    //每个人的名字
    QString room_name[6];
    //每个人的状态
    QString player_sit[6];
    //每个人的区域
    QString player_area[6];
    //当前区域
    QString temp_now_area;
    //当前操作人
    int temp_now_player;
    //排名列表
    QString list_name[6];
    //赢者列表
    QString winner_list_name[6];
    int num_winner=0;
    //输者列表
    QString loser_list_name[6];
    int num_loser=0;

    bool situation=0;
    int num_roomlist=0;
    int num_ranklist=0;
    int num_total_room=0;
    int finished=0;
    //倒计时组件
    QTimer * my_timer=new QTimer(this);
    int timer_max=60;
    void timercountdown();
    bool symbol=0;
    bool symbol_flag=0;
    ~serve();


private:

    Ui::serve *ui;
};



#endif // SERVE_H
