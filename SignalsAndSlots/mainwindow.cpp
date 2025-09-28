#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pressCount(0)
{
    ui->setupUi(this);
    resize(300,300);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);


    QVBoxLayout* layout = new QVBoxLayout(central);

    button = new QPushButton("click me", this);
    //button->move(150,150);
    label = new QLabel("count", this);
    /*label->resize(100,100);
    label->move(10,10);*/


    layout->addWidget(button);
    layout->addWidget(label);
    this->setLayout(layout);
    connect(button, &QPushButton::clicked, this, &MainWindow::slotButtonClicked);
    connect(this, &MainWindow::signalUpdateCount, this, &MainWindow::slotUpdateLabel);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButtonClicked(){
    ++pressCount;
    emit signalUpdateCount(pressCount);
}

void MainWindow::slotUpdateLabel(int count){
    label->setText(QString("Pressed %1 time").arg(count));
}
