#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void inputToCommand(string input);


private slots:
    void on_North_clicked();

    void on_South_clicked();

    void on_East_clicked();

    void on_West_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
