#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registrationpage.h"

#include <QMessageBox>
#include <QRegularExpression>

QString username;
QString password;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SignIn_Button = new QPushButton("Sign-in", this);
    registration_Button = new QPushButton("Registration", this);

    userName_LineEdit = new QLineEdit(this);
    userName_LineEdit->setPlaceholderText("username");
    password_LineEdit= new QLineEdit(this);
    password_LineEdit->setPlaceholderText("password");
    password_LineEdit->setEchoMode(QLineEdit::Password);

    QPixmap pixmap (":/image/imgs/download.png");
    labelLogo = new QLabel;
    labelLogo->setPixmap(pixmap);

    status = new QLabel;
    status->setFixedSize(200, 30);

    layout = new QVBoxLayout();
    layout->addWidget(labelLogo);
    layout->addWidget(userName_LineEdit);
    layout->addWidget(password_LineEdit);
    layout->addWidget(status);
    layout->addWidget(SignIn_Button);
    layout->addWidget(registration_Button);

    central = new QWidget(this);
    central->setLayout(layout);
    this->setCentralWidget(central);

    connect(SignIn_Button, &QPushButton::clicked, this, &MainWindow::slotSignIn_ButtonClicked);
    connect(registration_Button, &QPushButton::clicked, this, &MainWindow::slotRegistration_ButtonClicked);
}

void MainWindow::slotSignIn_ButtonClicked(){

    static const QRegularExpression userRe("^[A-Za-z0-9_]{3,16}$");
    static const QRegularExpression passRe("^(?=.*[A-Z])(?=.*[a-z])(?=.*\\d).{8,}$");


    QString userInput = userName_LineEdit->text();
    QString passInput = password_LineEdit->text();

    // Username must be valid AND not already taken
    if(username.isEmpty()){
        status->setText("Please have registration");
        userName_LineEdit->clear();
        password_LineEdit->clear();
    }else{
        if (!userRe.match(userInput).hasMatch() || username != userInput) {
            status->setText("Invalid username or already in use");
        }
        else if (!passRe.match(passInput).hasMatch()) {
            status->setText("Invalid password");
        }
        else {
            status->setText("");
            QMessageBox::information(this, "Success", "You have successfully signed in");

            userName_LineEdit->clear();
            password_LineEdit->clear();
        }
    }
}

void MainWindow::slotRegistration_ButtonClicked(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Question");
    msgBox.setText("Do you want to continue?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.exec();

    RegistrationPage dialog(this);
    dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
