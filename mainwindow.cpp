#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include "item.h"

#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QListView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , zork(new ZorkUL())
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Try to loot as fast as possible!");
    // I will set map to hidden so the user can set it visible/invisible at their will
    ui->Map->setVisible(0);

   // Set the list widget to the current room items

    ui->TextWindow->append(QString::fromStdString(zork->printWelcome()));

    time.setHMS(0,1,0);
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

void MainWindow::on_North_clicked()
{
    direction = "north";
    ui->TextWindow->append(QString::fromStdString(zork->go(direction)));


}


void MainWindow::on_South_clicked()
{
    direction = "south";
    zork->go(direction);
    ui->TextWindow->append(QString::fromStdString(zork->go(direction)));

}


void MainWindow::on_East_clicked()
{
    direction = "east";
    zork->go(direction);
    ui->TextWindow->append(QString::fromStdString(zork->go(direction)));

}


void MainWindow::on_West_clicked()
{
    direction = "west";
    zork->go(direction);
    ui->TextWindow->append(QString::fromStdString(zork->go(direction)));

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

}

