#ifndef FOUR_H
#define FOUR_H

#include <QWidget>

namespace Ui {
class four;
}

class four : public QWidget
{
    Q_OBJECT

public:
    explicit four(QWidget *parent = nullptr);
    ~four();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::four *ui;
};

#endif // FOUR_H
