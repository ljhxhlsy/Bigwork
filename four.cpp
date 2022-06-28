#include "four.h"
#include "ui_four.h"
#include<three.h>
#include<mainwindow.h>
#include<sanren.h>
#include<siren.h>
#include<liuren.h>
four::four(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::four)
{
    ui->setupUi(this);

}

four::~four()
{
    delete ui;
}

void four::on_pushButton_6_clicked()
{
    this->close();
}


void four::on_pushButton_5_clicked()
{
    three *up=new three();
    this->close();
    up->show();
}


void four::on_pushButton_clicked()
{
    MainWindow *next=new MainWindow();
    this->close();
    next->show();
}


void four::on_pushButton_2_clicked()
{
    sanren *next=new sanren();
    this->close();
    next->show();
}


void four::on_pushButton_3_clicked()
{
    siren *next=new siren();
    this->close();
    next->show();
}


void four::on_pushButton_4_clicked()
{
    liuren *next=new liuren();
    this->close();
    next->show();
}

