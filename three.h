#ifndef THREE_H
#define THREE_H

#include <QWidget>

namespace Ui {
class three;
}

class three : public QWidget
{
    Q_OBJECT

public:
    explicit three(QWidget *parent = nullptr);
    ~three();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::three *ui;
};

#endif // THREE_H
