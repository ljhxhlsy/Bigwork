#ifndef COMPUTER_H
#define COMPUTER_H

#include <QWidget>

namespace Ui {
class computer;
}

class computer : public QWidget
{
    Q_OBJECT

public:
    explicit computer(QWidget *parent = nullptr);
    ~computer();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::computer *ui;
};

#endif // COMPUTER_H
