#include "dialog.h"
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    lineEdit = new QLineEdit(this);
    button = new QPushButton("Send Text", this);

    layout->addWidget(lineEdit);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &Dialog::handleButton);
}

void Dialog::handleButton() {
    emit textEntered(lineEdit->text());
    close();
}
