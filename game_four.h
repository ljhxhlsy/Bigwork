#ifndef GAME_FOUR_H
#define GAME_FOUR_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class game_four;
}

class game_four : public QWidget
{
    Q_OBJECT

public:
    explicit game_four(QWidget *parent = nullptr);
    ~game_four();
    void paintEvent(QPaintEvent *ev);
    void drawPawn(QPainter & painter,int x,int y,QColor color);
    void mouseReleaseEvent(QMouseEvent *ev);
    void availableMove(int x,int y);
    bool availableMove2(int x,int y);
    void availableJump(int x,int y);
    void availableJump2(int x,int y);
    bool in(int x,int y);
    bool win(int id);
    Pawn nullPawn;
    Pawn pawn[6][10];
    bool board[25][17];
    bool avaiOnBoard[25][17];
    bool mem[25][17];
    bool tracking;
    int trackingNum[2];
    Pawn *toPawn[25][17];
    int direction;
    int stepCount;
    int teamNum;
    bool gameEnd;
    //记录所有人信息
    QString player_name[4];
    QString player_area[4];
    QString self_name;
    QString self_area;
    //记录当前操作信息
    QString temp_area;
private:
    Ui::game_four *ui;
};

#endif // GAME_FOUR_H
