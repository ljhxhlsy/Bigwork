#ifndef CLIENT_ROOM_H
#define CLIENT_ROOM_H

#include <QWidget>
#include<client.h>
#include<networkdata.h>
#include<networksocket.h>
#include<QDebug>
#include<game_two.h>


namespace Ui {
class client_room;
}

class client_room : public QWidget
{
    Q_OBJECT

public:
    explicit client_room(QWidget *parent = nullptr);
    ~client_room();
    NetworkSocket *socket =new NetworkSocket(new QTcpSocket(),this);
    void receive(NetworkData a);
    QString name;
    QString house;
    bool zhunbei;
    int player_number;
    QTimer *my_timer;
    int timer_max;
    //记录区域
    QString area;
    //记录行棋结束与否
    int flag=0;
    void timercountdown();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::client_room *ui;
};

#endif // CLIENT_ROOM_H
