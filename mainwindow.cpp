#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,    &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_2,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_3,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_4,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_5,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_6,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_7,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_8,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_9,  &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::digitClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{

    qDebug() << "a digit was clicked";

    QPushButton* digitButton = (QPushButton*)sender();

    double labelNumber;
    QString labelString;

    labelNumber = (ui->label->text() + digitButton->text()).toDouble();
    labelString = QString::number(labelNumber,'g',15);
    ui->label->setText(labelString);

}
