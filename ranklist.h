#ifndef RANKLIST_H
#define RANKLIST_H

#include <QWidget>
#include<networkdata.h>
namespace Ui {
class ranklist;
}

class ranklist : public QWidget
{
    Q_OBJECT

public:
    explicit ranklist(QWidget *parent = nullptr);
    void makelist(NetworkData &a);
    ~ranklist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ranklist *ui;
};

#endif // RANKLIST_H
