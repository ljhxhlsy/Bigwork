#ifndef COMPUTER_TWO_H
#define COMPUTER_TWO_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class computer_two;
}

class zuobiao{
public:
    int x;
    int y;
};

class computer_two : public QWidget
{
    Q_OBJECT

public:
    explicit computer_two(QWidget *parent = nullptr);
    ~computer_two();
    void drawPawn(QPainter & painter,int x,int y,QColor color);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
    void availableMove(int x,int y);
    bool availableMove2(int x,int y);
    void availableJump(int x,int y);
    void availableJump2(int x,int y);
    bool in(int x,int y);
    bool win(int id);
    Pawn nullPawn;
    Pawn pawn[2][10];
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

    bool avaiJump[25][17];
    bool availableJump3(int x,int y);
    void auto_walk();
    void auto_walk2();
    void auto_availablejump(int x,int y);
    void auto_availablejump2(int x,int y);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::computer_two *ui;
};

#endif // COMPUTER_TWO_H
