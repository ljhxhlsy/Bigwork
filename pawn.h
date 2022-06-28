#ifndef PAWN_H
#define PAWN_H

#include <QColor>


class Pawn
{
public:
    Pawn();
    int x;
    int y;
    int id;
    bool chosen=0;
    QColor idToColor(int id);
    bool zhuangtai=true;
};

#endif // PAWN_H
