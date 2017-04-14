#include "containjudge.h"
#include "ui_containjudge.h"
#include "suffixtree.h"
#include "sidefuncs.h"
#include "QMessageBox"
#include "string"

containjudge::containjudge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::containjudge)
{
    ui->setupUi(this);
}

containjudge::~containjudge()
{
    delete ui;
}

void containjudge::on_pushButton_3_clicked()
{
    string s = q2s(ui->stringS->text());
    string t = q2s(ui->stringT->text());
    string rst = "";
    if(isContain(s, t))
        rst = "String S contains string T!";
    else
        rst = "String S not contains string T!";
    QMessageBox::information(this, s2q("Containing Judge"), s2q(rst));
}
