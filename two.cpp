#include "two.h"
#include "ui_two.h"
#include<one.h>
#include<three.h>
#include<lianji_one.h>
two::two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::two)
{
    ui->setupUi(this);
}

two::~two()
{
    delete ui;
}

void two::on_pushButton_4_clicked()
{
    this->close();
}


void two::on_pushButton_3_clicked()
{
    one *up=new one();
    this->close();
    up->show();
}


void two::on_pushButton_clicked()
{
    three *next=new three ();
    this->close();
    next->show();
}


void two::on_pushButton_2_clicked()
{
    lianji_one *next =new lianji_one ();
    this->close();
    next->show();
}

