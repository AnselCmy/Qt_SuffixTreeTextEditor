#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "suffixtree.h"
#include "sidefuncs.h"
#include "QMessageBox"
#include "string"
#include "sstream"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void HighLight(string* s, int pos, int len);
    void on_ContainJudgeButton_clicked();
    void on_RepeatingCountButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
