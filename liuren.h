#ifndef LIUREN_H
#define LIUREN_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class liuren;
}

class liuren : public QWidget
{
    Q_OBJECT

public:
    explicit liuren(QWidget *parent = nullptr);
    ~liuren();
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
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::liuren *ui;
};

#endif // LIUREN_H
