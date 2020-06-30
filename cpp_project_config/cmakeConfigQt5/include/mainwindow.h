#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "graphicsview.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_readimg_clicked();

    void on_btn_canny_clicked();

private:
    QGraphicsScene  *leftScene;
    QGraphicsScene  *rightScene;
    QGraphicsPixmapItem* leftPixmapItem;
    QGraphicsPixmapItem* rightPixmapItem;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
