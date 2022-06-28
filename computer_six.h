#ifndef COMPUTER_SIX_H
#define COMPUTER_SIX_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class computer_six;
}

class computer_six : public QWidget
{
    Q_OBJECT

public:
    explicit computer_six(QWidget *parent = nullptr);
    ~computer_six();
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
    Ui::computer_six *ui;
};

#endif // COMPUTER_SIX_H
