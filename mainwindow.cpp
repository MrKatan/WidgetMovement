#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QTimer>
#include <QRandomGenerator>

struct LifeTimeHelper {
    LifeTimeHelper() {std::cout<<"Born "<<this<<std::endl;}
    ~LifeTimeHelper() {std::cout<<"Died "<<this<<std::endl;}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            [cw = ui->centralwidget, outp = ui->label, outp2 = ui->label_2]{
                QString width;
                QString height;
                width = QString::number(cw->geometry().size().width(), 'g', 12);
                height = QString::number(cw->geometry().size().height(), 'g', 12);
                outp->setText(width);
                outp2->setText(height);
            });

}


MainWindow::~MainWindow()
{
    delete ui;
}



