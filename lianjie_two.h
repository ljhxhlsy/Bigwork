#ifndef LIANJIE_TWO_H
#define LIANJIE_TWO_H

#include <QWidget>

namespace Ui {
class lianjie_two;
}

class lianjie_two : public QWidget
{
    Q_OBJECT

public:
    explicit lianjie_two(QWidget *parent = nullptr);
    ~lianjie_two();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::lianjie_two *ui;
};

#endif // LIANJIE_TWO_H
