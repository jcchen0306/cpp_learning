#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include "imgfile.h"
#include <QFileDialog>
#include <QGraphicsPathItem>
#include <opencv2/opencv.hpp>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leftScene = new QGraphicsScene;
    rightScene = new QGraphicsScene;

    leftPixmapItem = new QGraphicsPixmapItem();
    rightPixmapItem = new QGraphicsPixmapItem();


    ui->leftGraphicsView->setScene(leftScene);

    ui->rightGraphicsView->setScene(rightScene);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_readimg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                   this, tr("open image file"),
                   "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    if(fileName.isEmpty())
        return;
    QPixmap leftPixmap(fileName);
    leftPixmapItem = leftScene->addPixmap(leftPixmap);

    QPixmap rightPixmap(fileName);
    rightPixmapItem = rightScene->addPixmap(rightPixmap);

}

void MainWindow::on_btn_canny_clicked()
{

    cv::Mat A = QPixmapToCvMat(leftPixmapItem->pixmap());
    cv::Mat edges;
    cv::Canny(A,edges,50,100);
    QPixmap _pix = cvMatToQPixmap(edges);
    leftPixmapItem = leftScene->addPixmap(_pix);

}
