#ifndef GAME_THREE_H
#define GAME_THREE_H

#include <QWidget>
#include<pawn.h>
#include<game_two.h>
namespace Ui {
class game_three;
}


class game_three : public QWidget
{
    Q_OBJECT

public:
    bool alreadyMove=0;
    bool comboJump=0;
    explicit game_three(QWidget *parent = nullptr);
    ~game_three();
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
    int trackingNum2[2];
    Pawn *toPawn[25][17];
    int direction;
    int stepCount;
    int teamNum;
    bool gameEnd;
    //记录所有人信息
    QString player_name[3];
    QString player_area[3];
    QString self_name;
    QString self_area;
    //记录当前操作信息
    QString temp_area;
    int auto_symbol=0;
    void auto_walk();
    QList<zuobiao> move_zuobiao;
    bool avaiJump[25][17];
    void makeback(QString a);
    void daojishi(QString a);

    void moveOperation(int x1,int y1);
signals:
    void is_over();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::game_three *ui;
};

#endif // GAME_THREE_H
