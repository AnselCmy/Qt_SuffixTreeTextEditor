#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "containjudge.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ContainJudgeButton_clicked()
{
    containjudge *containJudgeWindow = new containjudge();
    containJudgeWindow->show();
}
