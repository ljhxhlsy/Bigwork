#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include<networksocket.h>
#include<QMessageBox>
#include<client_room.h>


namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    NetworkSocket * socket=new NetworkSocket(new QTcpSocket(),this);

    //连接成功或失败
    void connected();
    void displayError();


    QString host;
    quint16 port;
    QString home;
    QString name;
    ~client();

private slots:
    void on_pushButton_2_clicked();
    void receive(NetworkData a);
    void on_pushButton_clicked();


private:
    Ui::client *ui;
};




#endif // CLIENT_H
