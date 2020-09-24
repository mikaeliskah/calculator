#include <QDebug>
#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"


double firstCalcNumber, secondCalcNumber = 0;
QString mathOperation;
bool secondNumberEntry = false;
bool mathOpWasClicked = false;

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

    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);

    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);
    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);

//    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::resultClicked);
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::mathOperationClicked);

    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::clearDisplay);
    MainWindow::setWindowTitle("CALCULATOR");

}



MainWindow::~MainWindow()
{
    delete ui;
}


/*------------------------------------*/
/*      -- Digit Clicked  --          */
/*------------------------------------*/
void MainWindow::digitClicked()
{
    double labelNumber=0;
    QString labelString;

    qDebug() << "a digit was clicked";

    if (mathOpWasClicked == true)
    {
        ui->label->setText(""); // clear text once if a math op was clicked previously
        mathOpWasClicked = false;
    }

    // check out which button was cliked
    QPushButton* digitButton = (QPushButton*)sender();

    // check if zero was clicked after comma
    if (ui->label->text().contains('.') && (digitButton->text() == "0"))
    {
        qDebug() << "zero was clicked after decimal point";
        ui->label->setText(ui->label->text() + "0");
    }
    else
    {
        labelNumber = (ui->label->text() + digitButton->text()).toDouble();
        displayNumber(labelNumber);
    }

    // remember first calc number
    if (!secondNumberEntry)
    {
        firstCalcNumber = (ui->label->text()).toDouble();
    }
    else
    {
        secondCalcNumber = (ui->label->text()).toDouble();
    }
}


/*------------------------------------*/
/*      -- Decimal Clicked  --        */
/*------------------------------------*/
void MainWindow::decimalClicked()
{
    qDebug() << "decimal was clicked";
    ui->statusbar->showMessage("decimal clicked",500);

    // add decimal point only if no decimal point is present yet
    if (!ui->label->text().contains('.'))
        ui->label->setText(ui->label->text()  + ".");
    else
        ui->statusbar->showMessage("decimal ignored",500);

}


/*-----------------------------------*/
/*      -- Sign Clicked  --          */
/*-----------------------------------*/
void MainWindow::signClicked()
{
    double labelNumber, newLabelNumber;
    QString labelString;

    qDebug() << "sign was clicked";
    ui->statusbar->showMessage("sign clicked",500);

    labelNumber = (ui->label->text()).toDouble();
    newLabelNumber = labelNumber * -1;
    labelString = QString::number(newLabelNumber,'g',15);
    ui->label->setText(labelString);

    if(secondNumberEntry)
        secondCalcNumber = newLabelNumber;
    else
        firstCalcNumber = newLabelNumber;
}


/*------------------------------------*/
/*  -- math operation Clicked  --     */
/*------------------------------------*/
void MainWindow::mathOperationClicked()
{
    qDebug() << "math Op was clicked";
    qDebug() << "math Op was clicked";
    // clear display
    ui->label->setText("0");

    // check which operation was clicked
    QPushButton* operationButton = (QPushButton*)sender();

    // number to be displayed on label when calculated
    double labelNumber=0;

    // perform the calculations according to button pressed
    if (operationButton->text() == "+")
    {
        mathOperation = "+";
        qDebug() << "adding ...";
        labelNumber = firstCalcNumber + secondCalcNumber;
    }

    else if (operationButton->text() == "-")
    {
        mathOperation = "-";
        qDebug() << "subtract ...";
        labelNumber = firstCalcNumber - secondCalcNumber;
    }

    else if (operationButton->text() == "*")
    {
        mathOperation = "*";
        qDebug() << "multiplying ...";
        if(secondNumberEntry)
            labelNumber = firstCalcNumber * secondCalcNumber;
        else
            labelNumber = firstCalcNumber;
    }

    else if(operationButton->text() == "/")
    {
        mathOperation = "/";
        qDebug() << "dividing ...";
        if(secondNumberEntry)
            labelNumber = firstCalcNumber / secondCalcNumber; // T O D O: div/0  !!
        else
            labelNumber = firstCalcNumber;
    }

    else if(operationButton->text() == "sin")
    {
        mathOperation = "sin";
        qDebug() << "calc sine ...";
        labelNumber = sin(firstCalcNumber);
    }

    else if(operationButton->text() == "cos")
    {
        mathOperation = "cos";
        qDebug() << "calc cosine ...";
        labelNumber = cos(firstCalcNumber);
    }

    else if(operationButton->text() == "sqrt")
    {
        mathOperation = "sqrt";
        qDebug() << "calc sqrt ...";
        labelNumber = sqrt(firstCalcNumber);
    }

    //update label and calc number and state
    secondNumberEntry = true;
    mathOpWasClicked = true;

    if (operationButton->text() == "=")
    {
        qDebug() << "result clicked ... ";
        if (mathOperation == "+")
        {
            labelNumber = firstCalcNumber + secondCalcNumber;
        }

        if (mathOperation == "-")
        {
            labelNumber = firstCalcNumber - secondCalcNumber;
        }

        if (mathOperation == "*")
        {
            labelNumber = firstCalcNumber * secondCalcNumber;
        }

        if (mathOperation == "/")
        {
            labelNumber = firstCalcNumber / secondCalcNumber;
        }

        secondNumberEntry = false;
//        displayNumber(labelNumber);
//        firstCalcNumber = labelNumber;
        secondCalcNumber = 0;
    }
    displayNumber(labelNumber);
    firstCalcNumber = labelNumber;

}


/*------------------------------------*/
/*        -- display number  --       */
/*------------------------------------*/
void MainWindow::displayNumber(double number)
{
    QString labelString;
    qDebug() << "displaying " << number;
    labelString = QString::number(number,'g',15);
    ui->label->setText(labelString);
}


/*------------------------------------*/
/*        -- clear Display  --        */
/*------------------------------------*/
void MainWindow::clearDisplay()
{
    qDebug() << "clear display";

    firstCalcNumber = 0;
    secondCalcNumber = 0;
    mathOperation = "";
    secondNumberEntry = false;
    mathOpWasClicked = false;
    ui->label->setText("0");
}




