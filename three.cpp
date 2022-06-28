#include "three.h"
#include "ui_three.h"
#include<two.h>
#include<four.h>
#include<computer.h>
three::three(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::three)
{
    ui->setupUi(this);
}

three::~three()
{
    delete ui;
}

void three::on_pushButton_4_clicked()
{
    this->close();
}


void three::on_pushButton_3_clicked()
{
    two *up=new two();
    this->close();
    up->show();
}


void three::on_pushButton_clicked()
{
    four *next=new four();
    this->close();
    next->show();
}


void three::on_pushButton_2_clicked()
{
    computer *next=new computer();
    this->close();
    next->show();
}

