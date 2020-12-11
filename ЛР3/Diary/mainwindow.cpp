#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <map>

#include "note.h"

std::map<QDate, Note> date_to_note;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDate date(2020, 11, 10);
    date_to_note[date].name = "Test";
    date_to_note[date].text = "Test Text";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calendarWidget_selectionChanged()
{
    auto date = ui->calendarWidget->selectedDate();

    if(date_to_note.find(date) != date_to_note.end())
    {
        auto note = date_to_note[date];
        ui->NoteNameLineEdit->setText(note.name);
        ui->tNoteTxtEdit->setText(note.text);
    }
    else
    {
        ui->NoteNameLineEdit->clear();
        ui->tNoteTxtEdit->clear();
        date_to_note[date] = Note(date);
    }
}

void MainWindow::on_SaveButton_clicked()
{
    auto date = ui->calendarWidget->selectedDate();
     date_to_note[date].name = ui->NoteNameLineEdit->text();
     date_to_note[date].text = ui->tNoteTxtEdit->toPlainText();
}
