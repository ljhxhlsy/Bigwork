#include "client.h"
#include "ui_client.h"
#include<lianji_one.h>
#include<lianjie_two.h>
#include<QDebug>
#include<client_room.h>
#include<networkdata.h>
#include<networksocket.h>
extern client_room * room;
client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入房间号");
    ui->lineEdit_2->setPlaceholderText("请输入用户名");
    connect(socket->base(),&QAbstractSocket::errorOccurred,this,&client::displayError);
    connect(socket->base(), &QAbstractSocket::connected, this, &client::connected);
    //connect(socket,&NetworkSocket::receive,this,&client::receive);
    connect(socket,SIGNAL(receive(NetworkData)),this,SLOT(receive(NetworkData)));
    connect(socket->base(),&QAbstractSocket::disconnected,[=](){
    QMessageBox::critical(this,tr("Connection lost"),tr("Connection to server has closed"));
    });
}

client::~client()
{
    delete ui;
}

void client::connected()
{
   QMessageBox::about(NULL,"提示","连接成功");
}

void client::displayError()
{
    int b;
    b=QMessageBox::critical(NULL,"提示","网络连接未成功，请检查重试",QMessageBox::Yes,QMessageBox::Yes);
    if(b)
    {
        lianjie_two *next=new lianjie_two();
        this->close();
        next->show();
    }
}

void client::on_pushButton_2_clicked()
{
    lianjie_two *next=new lianjie_two();
    this->close();
    next->show();
}

void client::receive(NetworkData a)
{
    qDebug()<<"client has received"<<a.data1<<a.data2;
    if(a.op!=OPCODE::ERROR_OP)
    {
       room->receive(a);
       room->show();
    }
    else
    {
        room->receive(a);
        if(a.data1==QString::number((int)ERRCODE::INVALID_JOIN))
        {
            this->show();
        }
    }

}
void client::on_pushButton_clicked()
{
    //发送请求
    QString a,b;
    a=ui->lineEdit->text();
    b=ui->lineEdit_2->text();
    this->home=a;
    this->name=b;
    NetworkData first(OPCODE::JOIN_ROOM_OP,a,b);
    room->house=a;
    room->name=b;
    room->socket=this->socket;
    this->socket->send(first);
    qDebug()<<"client has send";
    qDebug()<<"client_room has send";
    this->hide();
}

