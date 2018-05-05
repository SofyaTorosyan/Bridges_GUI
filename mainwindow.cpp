//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "Header.h"
#include <QDesktopWidget>
#include<QPushButton>
#include<QScrollArea>
#include<QFileDialog>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include<QVideoWidget>
//#include "Header.cpp"
//#include "Header.h"
//Matrix<Vertex*> m;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     *
     *
     *  How add scrollarea??????
      QScrollArea *scrollarea = new QScrollArea(this);
   // this->setCentralWidget(scrollarea);
      scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
   // scrollarea->setWidgetResizable(false);
   *
   *
   *
   */

}

MainWindow::~MainWindow()
{
    delete ui;
}


class Painter:public QWidget
{

    public:
    void paint()
    {
        QPainter painter(this);

        QPen redPen(Qt::red);
        redPen.setWidth(2);

        QPen whitePen(Qt::white);
        whitePen.setWidth(2);

        QPen greenPen(Qt::green);
        greenPen.setWidth(2);

        QRect rec(10, 10, 10, 10);
    //    painter.setPen(redPen);
    //    painter.drawEllipse(rec);
        int y = 10;


        for (int j = 0; j < m.cols(); j++)
        {
            for (int i = 0; i < m.rows() ; i++)
            {
                if (m(i, j) == nullptr)
                {
                    painter.setPen(whitePen);
                    QRect rect(rec.x()+(i+1)*10, y, 10,10);
                    painter.drawEllipse(rect);
                }
                else
                {
                    if ((*m(i, j)).is_on_bridge)
                    {
                        painter.setPen(greenPen);
                        QRect rect(rec.x()+(i+1)*10, y, 5,5);
                        painter.drawEllipse(rect);
                    }
                    else
                    {
                        painter.setPen(redPen);
                        QRect rect(rec.x()+(i+1)*10, y, 10,10);
                        painter.drawEllipse(rect);
                    }
                }
            }
        y+=10;
        }
    }
};



void MainWindow::paintEvent(QPaintEvent*)
{
   /*
    *
    *
    *
    *
    QPainter painter(this);

    QPen redPen(Qt::red);
    redPen.setWidth(2);

    QPen whitePen(Qt::white);
    whitePen.setWidth(2);

    QPen greenPen(Qt::green);
    greenPen.setWidth(2);

    QRect rec(10, 10, 10, 10);
//    painter.setPen(redPen);
//    painter.drawEllipse(rec);
    int y = 10;

    for (int j = 0; j < m.hash_dot.length(); j++)
    {
        for (int i = 0; i < m.hash_dot.width(); i++)
        {
            if (m.hash_dot(i, j) == '.')
            {
               // painter.setPen(whitePen);
                //QRect rect(rec.x()+(i+1)*10, y, 10,10);
                //QBrush brush(Qt::white, Qt::SolidPattern);
                // painter.fillRect(rect, brush);
                //painter.drawRect(rect);

                continue;

            }
            else
            {
                painter.setPen(redPen);
                QRect rect(rec.x()+(i+1)*10, y, 10,10);
                QBrush brush(Qt::green, Qt::SolidPattern);
                 painter.fillRect(rect, brush);
                painter.drawRect(rect);

            }
        }
    y+=10;
    }
    *
    *
    *
    *
    */

    int img_idx=0;
    QGraphicsScene scene = new QGraphicsScene();
   // QPainter painter(this);

    QPen redPen(Qt::red);
    redPen.setWidth(2);

    QPen whitePen(Qt::white);
    whitePen.setWidth(2);

    QPen greenPen(Qt::green);
    greenPen.setWidth(2);

    QRect rec(10, 10, 10, 10);

    QPainter painter(this);
    int y = 10;

    for (int j = 0; j < m.hash_dot.length(); j++)
    {
        for (int i = 0; i < m.hash_dot.width(); i++)
        {
            if (m.hash_dot(i, j) == '.')
            {
                continue;
            }
            else
            {
                painter.setPen(redPen);
                QRect rect(rec.x()+(i+1)*10, y, 10,10);
                QBrush brush(Qt::green, Qt::SolidPattern);
                painter.fillRect(rect, brush);
                painter.drawRect(rect);
                scene.addRect(rect,redPen,brush);
                const QString FileName = "Image";
                scene.clearSelection();
                scene.setSceneRect(scene.itemsBoundingRect().marginsAdded(QMarginsF(30, 30, 30, 30)));
                QImage image(scene.sceneRect().size().toSize(), QImage::Format_ARGB32);
                QPainter paint(&image);
                scene.render(&paint);
                image.save(FileName +QString::number(img_idx)+ ".png");
                img_idx++;
            }
        }
    y+=10;
    }
    QPen bluePen(Qt::blue);
    redPen.setWidth(3);

     QPen yellowPen(Qt::yellow);
//    painter.setPen(redPen);
//    painter.drawEllipse(rec);
img_idx = 24;
        QLine line;

        for (int i=0; i<m.bridge_vector.size(); i++)
        {
                // painter.setPen(whitePen);
                // QRect rect(rec.x()+(i+1)*10, y, 10,10);
                // QBrush brush(Qt::white, Qt::SolidPattern);
                // painter.fillRect(rect, brush);
                // painter.drawRect(rect);
               switch((**m.bridge_vector[i].first).bridge_direction)
               {
                  case Left:
                         line.setLine(((**m.bridge_vector[i].first).x+2)*10, ((**m.bridge_vector[i].first).y+1)*10,
                                      ((**m.bridge_vector[i].second).x+2)*10,((**m.bridge_vector[i].second).y+1)*10);
                         break;
                  case Right:
                      line.setLine(((**m.bridge_vector[i].first).x+2)*10, ((**m.bridge_vector[i].first).y+1)*10,
                                   ((**m.bridge_vector[i].second).x+2)*10,((**m.bridge_vector[i].second).y+1)*10);
                   break;
                  case Down:
                      line.setLine(((**m.bridge_vector[i].first).x+2)*10, ((**m.bridge_vector[i].first).y+1)*10,
                                   ((**m.bridge_vector[i].second).x+2)*10,((**m.bridge_vector[i].second).y+1)*10);
                   break;
                  case Up:
                      line.setLine(((**m.bridge_vector[i].first).x+2)*10, ((**m.bridge_vector[i].first).y+1)*10,
                                   ((**m.bridge_vector[i].second).x+2)*10,((**m.bridge_vector[i].second).y+1)*10);
                   break;
               }
                painter.setPen(yellowPen);
                painter.drawLine(line);

                scene.addLine(line,yellowPen);
                const QString FileName = "Image";
                scene.clearSelection();
                scene.setSceneRect(scene.itemsBoundingRect().marginsAdded(QMarginsF(30, 30, 30, 30)));
                QImage image(scene.sceneRect().size().toSize(), QImage::Format_ARGB32);
                QPainter paint(&image);
                scene.render(&paint);
                image.save( "Image.png");
                img_idx++;
                // take an runtime image and save it in file
                painter.setPen(bluePen);
                painter.drawLine(line);
                scene.addLine(line,bluePen);
                scene.clearSelection();
                scene.setSceneRect(scene.itemsBoundingRect().marginsAdded(QMarginsF(30, 30, 30, 30)));
                QImage image1(scene.sceneRect().size().toSize(), QImage::Format_ARGB32);
                QPainter paint1(&image1);
                scene.render(&paint1);
                image1.save(FileName +QString::number(img_idx)+ ".png");
                img_idx++;
            }










}




int main(int argc, char *argv[])
{
    //while (cin.get() != '0')
       cout<<" First";

       const std::string fileName = "My_City150.txt";
       //m.hash_dot.Random_Generate ();
       m.hash_dot.Read_From_File(fileName);
       m.Create_Vertexes();
       m.enumerateBuildings();
       m.Circle();
       m.print();
       cout << "-----------------------\nNumber of bridges.... " << count_of_bridges << endl;
       cout << "Total length......... "                          << bridge_length    << endl;
       cout << "Disconnected groups.. "                          << non_connected_buildings << "\n----------------------- \n";
      // clean_all();

 //  cout <<sizeof(Matrix<Vertex*>);
   // std::system("pause");

    QApplication a(argc, argv);
    QDesktopWidget dw;
    MainWindow w;
    int x=dw.width()*0.9;
    int y=dw.height()*0.9;
    w.setFixedSize(x,y);

    w.show();
   /* QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* video =new QVideoWidget;

    player->setVideoOutput(video);
    player->setMedia(QUrl::fromLocalFile("//C:/Users//admin//Documents//build-Prime_alg-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug//Image"));
    video->setGeometry(100, 100, 300, 400);
    video->show();
    player->play();
    */

    return a.exec();
}


void MainWindow::on_actionDraw_triggered()
{
    // paint bridges when Draw is clicked.
}