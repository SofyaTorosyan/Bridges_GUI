#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent* e);
private slots:
    void on_actionDraw_triggered();
};

#endif // MAINWINDOW_H
