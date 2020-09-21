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
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::decimalClicked);
    connect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::signClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*      -- Digit Clicked  --          */
/*------------------------------------*/
void MainWindow::digitClicked()
{

    double labelNumber=0;
    QString labelString;

    qDebug() << "a digit was clicked";
    QPushButton* digitButton = (QPushButton*)sender();


    if (ui->label->text().contains('.') && (digitButton->text() == "0")) //if multiple zeros follow after decimal point, just update the string
    {
        qDebug() << "zero was clicked after decimal point";
        labelString = ui->label->text() + "0";
    }
    else
    {
        // append digit and convert to number
        labelNumber = (ui->label->text() + digitButton->text()).toDouble();
        labelString = QString::number(labelNumber,'g',15);
    }
    ui->label->setText(labelString);
}

/*      -- Decimal Clicked  --          */
/*------------------------------------*/
void MainWindow::decimalClicked()
{

    qDebug() << "decimal was clicked";
    // get current text and update label with current text + decimal point
    ui->label->setText(ui->label->text()  + ".");
}

/*      -- Sign Clicked  --          */
/*------------------------------------*/
void MainWindow::signClicked()
{
    double labelNumber, newLabelNumber;
    QString labelString;

    qDebug() << "sign was clicked";

    labelNumber = (ui->label->text()).toDouble();           // this number display function is always the same!
    newLabelNumber = labelNumber * -1;
    labelString = QString::number(newLabelNumber,'g',15);
    ui->label->setText(labelString);

}
