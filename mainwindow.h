#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QProgressBar>
#include <QTime>

#include "ZorkUL.h"

using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inputToCommand(string );
    void stringtoQ(string);
    QTime time;




private slots:

    void on_North_clicked();

    void on_South_clicked();

    void on_East_clicked();

    void on_West_clicked();

    void on_Quit_clicked();

    void on_Map_Button_clicked();

    void on_Take_Button_clicked();

    void timerUpdate();

private:

    Ui::MainWindow *ui;
    //Will use this to establish how long a game will last until end
    QTimer *timer;
    // shows how much money collected, will determine if player wins before time
    QProgressBar *progress;
    ZorkUL *zork;
    string direction;

};
#endif // MAINWINDOW_H
