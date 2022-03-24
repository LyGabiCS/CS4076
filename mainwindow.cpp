#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QElapsedTimer>

//I will use this in the future for images
#include <QPixmap>
//QFile reads and writes to files
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //This will access a png of the game map when i have it ready
    //QPixmap pix(link to the map png will go here);
    //int w = ui->Map->width();
    //int h = ui->Map->height();
    //ui->Map->setPixmap(pix.scaled(w, h, QT::KeepAspectRatio));
}
//Useful little code:
// ui->statusBar->showMessage("    ");
//This means any message will be displayed on bottom on screen not pop up

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_Quit_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                                                             "Quit Game", "Are you sure?",
                                                             QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else {
    }
}

//Will record how much money you collected. Will write this soon
//void MainWindow::on_MoneyCollected_valueChanged(int value)
//{

//}

void MainWindow::timeLeft()
{

}

