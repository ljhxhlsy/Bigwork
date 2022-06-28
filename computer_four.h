#ifndef COMPUTER_FOUR_H
#define COMPUTER_FOUR_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class computer_four;
}

class computer_four : public QWidget
{
    Q_OBJECT

public:
    explicit computer_four(QWidget *parent = nullptr);
    ~computer_four();
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
private:
    Ui::computer_four *ui;
};

#endif // COMPUTER_FOUR_H
