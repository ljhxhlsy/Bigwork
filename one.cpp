#include "one.h"
#include "ui_one.h"
#include<two.h>
#include<QPushButton>
one::one(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::one)
{
    ui->setupUi(this);
    //ui->label_2->setPixmap(QPixmap(":/pic.png"));
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
        two *next=new two();
        next->show();
    });
}

one::~one()
{
    delete ui;
}

void one::on_pushButton_2_clicked()
{
    this->close();
}

