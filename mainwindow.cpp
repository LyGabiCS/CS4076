#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include "item.h"
#include "Wordle.h"

#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QInputDialog>
#include <QTextStream>

Wordle wordle;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    wordle.loadWords("words5.txt");

    ui->statusbar->showMessage("Try to loot as fast as possible!");

    //ui->RoomWindow->setText(QString::fromStdString(zork->currentItems()));

    ui->Map->setVisible(0);

    ui->TextWindow->append(QString::fromStdString(zork->printWelcome()));

    ui->CoinCollected->setValue(1);

    time.setHMS(0,7,0);
    ui->TimeLeft->setText(time.toString("hh::mm::ss"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete zork;
}

void MainWindow::timerUpdate()
{
    time = time.addSecs(-1);
    ui->TimeLeft->setText(time.toString("hh::mm::ss"));
}

void MainWindow::stringtoQ(string s)
{
    QString qstr = QString::fromStdString(s);
}

/*
void MainWindow::playWordle()
{
    QString solution = QString::fromStdString(wordle.pickRandom());
    QString input = QInputDialog::getText((this),  "Wordle", "Enter a 5-letter word: ");

    wordle.compareWords(input.toStdString(), solution.toStdString());
}
*/

void MainWindow::on_North_clicked()
{
    direction = "north";
    ui->TextWindow->append(QString::fromStdString(zork->goRoom(direction)));


}


void MainWindow::on_South_clicked()
{
    direction = "south";
    ui->TextWindow->append(QString::fromStdString(zork->goRoom(direction)));

}


void MainWindow::on_East_clicked()
{
    direction = "east";
    ui->TextWindow->append(QString::fromStdString(zork->goRoom(direction)));

}


void MainWindow::on_West_clicked()
{
    direction = "west";
    ui->TextWindow->append(QString::fromStdString(zork->goRoom(direction)));

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



void MainWindow::on_Map_Button_clicked()
{
    if(ui->Map->isVisible() == 0)
    {
        ui->Map->show();
    }
    else if(ui->Map->isVisible() == 1)
    {
        ui->Map->hide();
    }
}

void MainWindow::on_Take_Button_clicked()
{
    QString item = QInputDialog::getText(this, "Pick an Item", "Item name: ");
    string name  = item.toStdString();
    if(wordle.winWordle() == true)
    {
    zork->addToInventory(name);
    }
    else
    {

    }
}

void MainWindow::on_Help_Button_clicked()
{
    ui->TextWindow->append(QString::fromStdString(zork->printHelp()));
}

