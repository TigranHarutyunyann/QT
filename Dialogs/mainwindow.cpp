#include "mainwindow.h"
#include "dialog.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);

    label = new QLabel("Your text will appear here", this);
    openDialogButton = new QPushButton("Open Dialog", this);
    imageLabel = new QLabel(this);

    QPixmap pixmap(":/img/img/pngtree-armenia-flag-transparent-watercolor-painted-brush-png-image_2150398.png");
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true);
    imageLabel->setFixedSize(200, 200);

    layout->addWidget(label);
    layout->addWidget(openDialogButton);
    layout->addWidget(imageLabel);

    connect(openDialogButton, &QPushButton::clicked, this, &MainWindow::openDialog);
}

MainWindow::~MainWindow() {}

void MainWindow::openDialog() {
    Dialog *dialog = new Dialog(this);
    connect(dialog, &Dialog::textEntered, this, &MainWindow::updateLabel);
    dialog->exec(); // modal
}

void MainWindow::updateLabel(const QString &text) {
    label->setText(text);
}
