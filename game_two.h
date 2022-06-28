#ifndef GAME_TWO_H
#define GAME_TWO_H

#include <QWidget>
#include<pawn.h>
namespace Ui {
class game_two;
}
class zuobiao
{
public:
    int x;
    int y;
};

class game_two : public QWidget
{
    Q_OBJECT

public:
    bool alreadyMove=0;
    bool comboJump=0;
    explicit game_two(QWidget *parent = nullptr);
    ~game_two();
    void drawPawn(QPainter & painter,int x,int y,QColor color);
    void mouseReleaseEvent(QMouseEvent *ev);
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
    int trackingNum2[2];
    Pawn *toPawn[25][17];
    int direction;
    int stepCount;
    int teamNum;
    bool gameEnd;
    QList<zuobiao> move_zuobiao;
    bool avaiJump[25][17];
    bool availableJump3(int x,int y);
    void paintEvent(QPaintEvent *ev);
    void daojishi(QString a);
    //记录行棋结束与否；
    bool zhuangtai=0;
    void moveOperation(int x1,int y1);
    void clear_pawn(int temp_id);
    void game_over();
    //记录所有人信息
    QString player_name[2];
    QString player_area[2];
    QString self_name;
    QString self_area;
    //记录当前操作信息
    QString temp_area;
    void makeback(QString a);
    int ai_symbol=0;

    void auto_walk();
signals:
    void is_over();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::game_two *ui;
};

#endif // GAME_TWO_H
