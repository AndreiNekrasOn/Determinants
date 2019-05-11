#include "mainwindow.h"
#include <math_functions.h>
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->detTable->horizontalHeader()->hide();
    ui->detTable->verticalHeader()->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString current_move = ui->moveLabel->text();

    int **newtable = convertQTableToMatrix(ui->detTable);
    int det = determinant(newtable, ui->detTable->rowCount());


    ui->debugLabel->setText(QString::number(det));

    if(QString::compare(current_move, "Ход игрока 1") == 0)
    {
        ui->moveLabel->setText("Ход игрока 2");
        int score = ui->scoreTable->item(0, 0)->text().toInt();
        score += det;
        ui->scoreTable->item(0, 0)->setText(QString::number(score));

    }
    else
    {
        ui->moveLabel->setText("Ход игрока 1");
        int score = ui->scoreTable->item(1, 0)->text().toInt();
        score += det;
        ui->scoreTable->item(1, 0)->setText(QString::number(score));
    }

    for(int i = 0; i < ui->detTable->rowCount(); i++)
        delete newtable[i];
    delete[] newtable;
}
