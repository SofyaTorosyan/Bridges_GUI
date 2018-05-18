#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);// {scene =  new QGraphicsScene();}
    ~MainWindow();
    void RefreshValues(int i, int j);
    //QGraphicsScene* scene;// =  new QGraphicsScene();
private:
     Ui::MainWindow *ui;
     QGraphicsScene* scene;
     QGraphicsEllipseItem* item;
protected:
    void paintEvent     (QPaintEvent*);
private slots:
    void on_actionDraw_triggered();
};

#endif // MAINWINDOW_H
