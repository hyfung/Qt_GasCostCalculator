#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void performCalculation();

private slots:
    void on_pushButton_calculate_clicked();
    void on_pushButton_clear_clicked();
    void onInputValueChanged(double);

    void on_spinBox_odometer_valueChanged(int arg1);

    void on_spinBox_quota_valueChanged(int);

private:
    Ui::MainWindow *ui;
    void on_quota_spinBox();
};
#endif // MAINWINDOW_H
