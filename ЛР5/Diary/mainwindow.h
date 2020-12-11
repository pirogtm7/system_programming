#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calendarWidget_selectionChanged();

    void on_SaveButton_clicked();

    void on_loadFromCloudButton_clicked();

    void on_pushToCloudButton_clicked();

private:
    Ui::MainWindow *ui;
    Database db;
};
#endif // MAINWINDOW_H
