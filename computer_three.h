#ifndef COMPUTER_THREE_H
#define COMPUTER_THREE_H
#include<pawn.h>
#include <QWidget>

namespace Ui {
class computer_three;
}

class computer_three : public QWidget
{
    Q_OBJECT

public:
    explicit computer_three(QWidget *parent = nullptr);
    ~computer_three();
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
    Pawn pawn[3][10];
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
    Ui::computer_three *ui;
};

#endif // COMPUTER_THREE_H
