#include "computer.h"
#include "ui_computer.h"
#include<three.h>
#include<computer_two.h>
#include<computer_three.h>
#include<computer_four.h>
#include<computer_six.h>
computer::computer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computer)
{
    ui->setupUi(this);
}

computer::~computer()
{
    delete ui;
}

void computer::on_pushButton_6_clicked()
{
    three *next=new three();
    this->close();
    next->show();
}


void computer::on_pushButton_5_clicked()
{
    this->close();
}


void computer::on_pushButton_clicked()
{
    computer_two *next=new computer_two();
    this->close();
    next->show();
}


void computer::on_pushButton_2_clicked()
{
    computer_three *next=new computer_three();
    next->show();
    this->close();
}


void computer::on_pushButton_3_clicked()
{
    computer_four *next=new computer_four();
    this->close();
    next->show();
}


void computer::on_pushButton_4_clicked()
{
    computer_six *next=new computer_six();
    this->close();
    next->show();
}

