#include "ranklist.h"
#include "ui_ranklist.h"
#include<client.h>
#include<QDebug>
ranklist::ranklist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ranklist)
{
    ui->setupUi(this);

}

ranklist::~ranklist()
{
    delete ui;
}

void ranklist::on_pushButton_clicked()
{
    client *next=new client();
    this->close();
    next->show();
}
void ranklist::makelist(NetworkData &a)
{
   QString player_1,player_2,player_3;
   QString player_4,player_5,player_6;
   QString zong;
   zong=a.data1;
   int num=1;
   for(int i=0;i<a.data1.length();i++)
   {
      if(a.data1[i]==' ')
        num+=1;
   }
   if(num==2)
   {
       player_1=zong.section(' ',0,0);
       player_2=zong.section(' ',1,1);
       ui->textBrowser->setText(player_1);
       ui->textBrowser_2->setText(player_2);
   }
   else if(num==3)
   {
       player_1=zong.section(' ',0,0);
       player_2=zong.section(' ',1,1);
       player_3=zong.section(' ',2,2);
       ui->textBrowser->setText(player_1);
       ui->textBrowser_2->setText(player_2);
       ui->textBrowser_3->setText(player_3);
   }
   else if(num==4)
   {
       player_1=zong.section(' ',0,0);
       player_2=zong.section(' ',1,1);
       player_3=zong.section(' ',2,2);
       player_4=zong.section(' ',3,3);
       ui->textBrowser->setText(player_1);
       ui->textBrowser_2->setText(player_2);
       ui->textBrowser_3->setText(player_3);
       ui->textBrowser_4->setText(player_4);
   }
   else if(num==5)
   {
       player_1=zong.section(' ',0,0);
       player_2=zong.section(' ',1,1);
       player_3=zong.section(' ',2,2);
       player_4=zong.section(' ',3,3);
       player_5=zong.section(' ',4,4);
       ui->textBrowser->setText(player_1);
       ui->textBrowser_2->setText(player_2);
       ui->textBrowser_3->setText(player_3);
       ui->textBrowser_4->setText(player_4);
       ui->textBrowser_5->setText(player_5);
   }
   else if(num==6)
   {
       player_1=zong.section(' ',0,0);
       player_2=zong.section(' ',1,1);
       player_3=zong.section(' ',2,2);
       player_4=zong.section(' ',3,3);
       player_5=zong.section(' ',4,4);
       player_6=zong.section(' ',5,5);
       ui->textBrowser->setText(player_1);
       ui->textBrowser_2->setText(player_2);
       ui->textBrowser_3->setText(player_3);
       ui->textBrowser_4->setText(player_4);
       ui->textBrowser_5->setText(player_5);
       ui->textBrowser_6->setText(player_6);
   }

}
