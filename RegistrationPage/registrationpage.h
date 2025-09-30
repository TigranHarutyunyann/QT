#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class RegistrationPage : public QDialog {
    Q_OBJECT
public:
    RegistrationPage(QWidget *parent = nullptr);

private slots:
    void checkingPassAndUserN();

private:
    QPushButton *reg_Registration_Button;
    QLineEdit *reg_userName_LineEdit;
    QLineEdit *reg_Password_LineEdit;
    QVBoxLayout *layout;
    QLabel *status;

};

#endif // REGISTRATIONPAGE_H
