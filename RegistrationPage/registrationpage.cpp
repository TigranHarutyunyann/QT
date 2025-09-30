#include "registrationpage.h"
#include "mainwindow.h"


#include <QMessageBox>
#include <QHBoxLayout>
#include <QRegularExpression>


RegistrationPage::RegistrationPage(QWidget *parent)
    :QDialog(parent) {

    resize(200,200);
    setWindowTitle("Registrarion page");

    reg_Registration_Button = new QPushButton("Register", this);
    reg_userName_LineEdit = new QLineEdit(this);
    reg_userName_LineEdit->setPlaceholderText("Username");

    reg_Password_LineEdit = new QLineEdit(this);
    reg_Password_LineEdit->setPlaceholderText("Password");
    reg_Password_LineEdit->setEchoMode(QLineEdit::Password);

    status = new QLabel;

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(reg_userName_LineEdit);
    vLayout->addWidget(reg_Password_LineEdit);
    vLayout->addWidget(status);
    vLayout->addWidget(reg_Registration_Button, 0, Qt::AlignCenter);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addStretch(1);
    hLayout->addLayout(vLayout);
    hLayout->addStretch(1);
    setLayout(hLayout);

    connect(reg_Registration_Button, &QPushButton::clicked, this, &RegistrationPage::checkingPassAndUserN);
}

void RegistrationPage::checkingPassAndUserN(){
    static const QRegularExpression Reg_userRe("^[A-Za-z0-9_]{3,16}$");
    static const QRegularExpression Reg_passRe("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d).{8,}$");

    QString userInput = reg_userName_LineEdit->text();
    QString passInput = reg_Password_LineEdit->text();

    // Username must be valid AND not already taken

    if (!Reg_userRe.match(userInput).hasMatch() || username == userInput) {
        status->setText("Invalid username or already in use");
    }
    else if (!Reg_passRe.match(passInput).hasMatch()) {
        status->setText("Invalid password");
    }
    else {
        status->setText("Success");
        QMessageBox::information(this, "Success", "You have successfully registration");

        username = userInput;
        password = passInput;
        reg_userName_LineEdit->clear();
        reg_Password_LineEdit->clear();
        accept();
    }
}
