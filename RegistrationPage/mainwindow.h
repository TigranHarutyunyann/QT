#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

extern QString username;
extern QString password;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotSignIn_ButtonClicked();
    void slotRegistration_ButtonClicked();

private:
    Ui::MainWindow *ui;
    QPushButton *SignIn_Button;
    QPushButton *registration_Button;
    QLineEdit *userName_LineEdit;
    QLineEdit *password_LineEdit;
    QVBoxLayout *layout;
    QLabel * labelLogo;
    QWidget *central;
    QLabel *status;



};

#endif // MAINWINDOW_H
