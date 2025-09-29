#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog {
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);

signals:
    void textEntered(const QString &text);

private slots:
    void handleButton();

private:
    QLineEdit *lineEdit;
    QPushButton *button;
};

#endif // DIALOG_H
