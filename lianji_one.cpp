#include "lianji_one.h"
#include "ui_lianji_one.h"
#include<two.h>
#include<client.h>
#include<lianjie_two.h>
#include<serve.h>
lianji_one::lianji_one(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lianji_one)
{
    ui->setupUi(this);
}

lianji_one::~lianji_one()
{
    delete ui;
}

void lianji_one::on_pushButton_3_clicked()
{
    two *next=new two();
    this->close();
    next->show();
}


void lianji_one::on_pushButton_4_clicked()
{
    this->close();
}


void lianji_one::on_pushButton_2_clicked()
{
    lianjie_two *next=new lianjie_two();
    this->close();
    next->show();
}


void lianji_one::on_pushButton_clicked()
{
    serve *next=new serve();
    this->close();
    next->show();
}

