#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->doubleSpinBox_gasPrice, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::onInputValueChanged);
    connect(ui->doubleSpinBox_litrePerHundred, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::onInputValueChanged);
    connect(ui->doubleSpinBox_distance, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::onInputValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::performCalculation()
{
    qDebug() << Q_FUNC_INFO;
    const double gasPrice = ui->doubleSpinBox_gasPrice->value();
    const double litrePerHunred = ui->doubleSpinBox_litrePerHundred->value();
    const double distance = ui->doubleSpinBox_distance->value();


    const double dollarPerKm = gasPrice * litrePerHunred / 10000;
    const double totalCost = dollarPerKm * distance;

    ui->lineEdit_dollarPerKm->setText(QString::number(dollarPerKm, 'f', 3));
    ui->lineEdit_totalCost->setText(QString::number(totalCost, 'f', 2));
}

void MainWindow::on_pushButton_calculate_clicked()
{
    performCalculation();
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->doubleSpinBox_gasPrice->setValue(0);
    ui->doubleSpinBox_litrePerHundred->setValue(0);
    ui->doubleSpinBox_distance->setValue(0);

    ui->lineEdit_dollarPerKm->setText("");
    ui->lineEdit_totalCost->setText("");
}

void MainWindow::onInputValueChanged(double val)
{
    performCalculation();
}

