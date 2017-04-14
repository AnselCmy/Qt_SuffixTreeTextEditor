#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::HighLight(string* sPtr, int pos, int len)
{
    string s = *sPtr;
    *sPtr = s.substr(0, pos) + string("<b><font color=\"blue\">") + s.substr(pos, len) + string("</font></b>") + s.substr(pos+len, s.size());
}

void MainWindow::on_ContainJudgeButton_clicked()
{
    // Do suffix containing judge by suffix tree
    string s = q2s(ui->stringS->toPlainText());
    string t = q2s(ui->stringT->toPlainText());
    string rst = s;
    string rstPre = "";
    // containRst is the first idx of the containing in string S
    int containRst = isContain(s, t);
    if(containRst != -1)
    {
        HighLight(&rst, containRst, t.size());
        rstPre = "\"String S\" contains the \"String T\"";
    }
    else
    {
        rst = s;
        rstPre = "\"String S\" not contains the \"String T\"";
    }
    // Reset the document with the highlight
    ui->stringS->document()->setHtml(s2q(rst));
    // Show the direction
    string direction = "Direction:\n\tJudge if the \"String T\" is the containing part of the \"String S\", "
                        "if is containing, highlighted \"String T\" will be presented in the \"String S\"";
    ui->Direction->setWordWrap(true);
    ui->Direction->setAlignment(Qt::AlignTop);
    ui->Direction->setText(s2q(direction));
    // Show the result
    string result = "Result:\n\t" + rstPre;
    ui->Result->setWordWrap(true);
    ui->Result->setAlignment(Qt::AlignTop);
    ui->Result->setText(s2q(result));
}

void MainWindow::on_RepeatingCountButton_clicked()
{
    string s = q2s(ui->stringS->toPlainText());
    string t = q2s(ui->stringT->toPlainText());
    string rst = s;
    vector<int> repeatVec = findRepeatNum(s, t);
    // It's importent to sort the vector, or it will error in HighLight()
    sort(repeatVec.begin(), repeatVec.end(), greater<int>());
    int repeatNum = repeatVec.size();
    string repeatNumStr;
    stringstream stream;
    stream << repeatNum;
    stream >> repeatNumStr;
    // Using for loop to highlight every String T in String S
    if(repeatNum != 0)
    {
        for(vecIter i=repeatVec.begin(); i!=repeatVec.end(); i++)
        {
            HighLight(&rst, *i, t.size());
        }
    }
    ui->stringS->document()->setHtml(s2q(rst));
    // Show the direction
    string direction = "Direction:\n\tIf \"String S\" contains \"String T\", "
                       "the corresponding part in \"String S\" will be highlighted";
    ui->Direction->setWordWrap(true);
    ui->Direction->setAlignment(Qt::AlignTop);
    ui->Direction->setText(s2q(direction));
    // Show the result
    string result = "Result:\n\t\"String T\" repeats " + repeatNumStr + " times in \"String S\"";
    ui->Result->setWordWrap(true);
    ui->Result->setAlignment(Qt::AlignTop);
    ui->Result->setText(s2q(result));
}
