#include "lianjie_two.h"
#include "ui_lianjie_two.h"
#include<lianji_one.h>
#include<QDebug>
#include<client.h>
lianjie_two::lianjie_two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lianjie_two)
{
    ui->setupUi(this);

    //获取地址与端口号
    ui->lineEdit->setPlaceholderText("默认IPv4地址：10.47.6.194");
    ui->lineEdit_2->setPlaceholderText("默认端口号：1888");

    //点击“连接到网络”
    connect(ui->pushButton,&QPushButton::clicked,[=](){

        //获取地址
        QString host;
        //地址栏为空
        if(ui->lineEdit->text().isEmpty())
        {
           ui->lineEdit->setText("0000");
           host=ui->lineEdit->text();
        }
        //地址栏不为空
        else
        {
            host=ui->lineEdit->text();
        }


        //获取端口号
        quint16 port;
        QString port_temp;
        bool isok;
        //端口栏为空
        if(ui->lineEdit_2->text().isEmpty())
        {
            ui->lineEdit_2->setText("0000");
            port_temp=ui->lineEdit_2->text();
            port=port_temp.toUShort(&isok);
        }
        //端口栏不为空
        else
        {
            port_temp=ui->lineEdit_2->text();
            port=port_temp.toUShort(&isok);
        }



        //建立连接
        client *next=new client();
        next->host=host;
        next->port=port;
        this->close();
        next->show();
        next->socket->hello(host,port);
    });


}

lianjie_two::~lianjie_two()
{
    delete ui;
}

void lianjie_two::on_pushButton_2_clicked()
{
    lianji_one *next=new lianji_one();
    this->close();
    next->show();
}


void lianjie_two::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("192.168.0.113");
}


void lianjie_two::on_pushButton_4_clicked()
{
    ui->lineEdit_2->setText("1888");
}

