#include "mainwindow.h"
#include<sanren.h>
#include<liuren.h>
#include<siren.h>
#include<one.h>
#include <QApplication>
#include<ranklist.h>
#include<client_room.h>
#include<game_two.h>
#include<game_three.h>
#include<game_four.h>
#include<game_six.h>
client_room * room;
game_two * game_two_room;
game_three *game_three_room;
game_four *game_four_room;
game_six *game_six_room;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    sanren x;
    liuren y;
    siren z;
    room = new client_room;
    game_two_room=new game_two;
    game_three_room=new game_three;
    game_four_room=new game_four;
    game_six_room=new game_six;
    one m;
    ranklist rank;
    //game_two_room->show();
    m.show();
    return a.exec();
}
