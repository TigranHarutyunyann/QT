#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect digits
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    // Connect operators
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString text = ui->output_show->text();

    if (text == "0" || text.isEmpty()) {
        text = button->text();
    } else {
        text += button->text();
    }

    ui->output_show->setText(text);
}

void MainWindow::math_operations()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    num_first = ui->output_show->text().toDouble();
    pending_operator = button->text();
    ui->output_show->setText("");
}

void MainWindow::on_pushButton_result_clicked()
{
    double num_second = ui->output_show->text().toDouble();
    double result = 0;

    if (pending_operator == "+") result = num_first + num_second;
    else if (pending_operator == "-") result = num_first - num_second;
    else if (pending_operator == "*") result = num_first * num_second;
    else if (pending_operator == "/") {
        if (num_second == 0) {
            ui->output_show->setText("Error");
            return;
        } else {
            result = num_first / num_second;
        }
    }

    ui->output_show->setText(QString::number(result, 'g', 15));
    pending_operator.clear();
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->output_show->setText("0");
    num_first = 0;
    pending_operator.clear();
}
