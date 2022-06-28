#ifndef LIANJI_ONE_H
#define LIANJI_ONE_H

#include <QWidget>

namespace Ui {
class lianji_one;
}

class lianji_one : public QWidget
{
    Q_OBJECT

public:
    explicit lianji_one(QWidget *parent = nullptr);
    ~lianji_one();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::lianji_one *ui;
};

#endif // LIANJI_ONE_H
