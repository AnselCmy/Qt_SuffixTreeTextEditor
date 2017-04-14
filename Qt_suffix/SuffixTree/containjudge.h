#ifndef CONTAINJUDGE_H
#define CONTAINJUDGE_H

#include <QDialog>

namespace Ui {
class containjudge;
}

class containjudge : public QDialog
{
    Q_OBJECT

public:
    explicit containjudge(QWidget *parent = 0);
    ~containjudge();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::containjudge *ui;
};

#endif // CONTAINJUDGE_H
