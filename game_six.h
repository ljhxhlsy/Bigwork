#ifndef GAME_SIX_H
#define GAME_SIX_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class game_six;
}

class game_six : public QWidget
{
    Q_OBJECT

public:
    explicit game_six(QWidget *parent = nullptr);
    ~game_six();
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
    QString player_name[6];
    QString player_area[6];
    QString self_name;
    QString self_area;
    //记录当前操作信息
    QString temp_area;
private:
    Ui::game_six *ui;
};

#endif // GAME_SIX_H
