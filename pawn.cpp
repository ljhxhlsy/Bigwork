#include "pawn.h"
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QBrush>
#include "pawn.h"
#include <QWidget>
#include <QString>
#include <QFont>
Pawn::Pawn()
{

}
QColor Pawn::idToColor(int id)
{
    QColor color(Qt::black);
    if(chosen)
        return color;
    else
    switch(id)
    {
    case 0:color=(Qt::blue);break;
    case 1:color=(Qt::gray);break;
    case 2:color=(Qt::green);break;
    case 3:color=(Qt::red);break;
    case 4:color=(Qt::yellow);break;
    case 5:color=(Qt::white);break;
    case 6:color=(Qt::cyan);break;
    case 7:color=(Qt::darkBlue);break;
    case 8:color=(Qt::darkRed);break;
    default:break;
    }
    return color;
}
