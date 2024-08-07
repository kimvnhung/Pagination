#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QTimer>
#include <pagination.h>
#include <pagingstyle2.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pagination *pagination = new Pagination();
    pagination->setPagingStyle(new PagingStyle2());
    pagination->setTotalSize(200);
    pagination->setDisplaySize(10);
    pagination->setBoxSpacing(5);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(pagination);
    QWidget *cenral = new QWidget(this);
    cenral->setLayout(layout);
    setCentralWidget(cenral);
    QTimer::singleShot(1000, [pagination](){
        pagination->setCurrentPage(3);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
