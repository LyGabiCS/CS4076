#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void inputToCommand(string input){


}


void MainWindow::on_North_clicked()
{
}


void MainWindow::on_South_clicked()
{

}


void MainWindow::on_East_clicked()
{

}


void MainWindow::on_West_clicked()
{

}

