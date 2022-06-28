#ifndef TWO_H
#define TWO_H

#include <QWidget>

namespace Ui {
class two;
}

class two : public QWidget
{
    Q_OBJECT

public:
    explicit two(QWidget *parent = nullptr);
    ~two();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::two *ui;
};

#endif // TWO_H
