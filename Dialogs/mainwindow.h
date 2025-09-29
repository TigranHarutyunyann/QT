#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDialog();
    void updateLabel(const QString &text);

private:
    QLabel *label;
    QLabel *imageLabel;
    QPushButton *openDialogButton;
};

#endif // MAINWINDOW_H
