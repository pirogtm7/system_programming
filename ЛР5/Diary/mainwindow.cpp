#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <map>

#include "fileworker.h"
#include "note.h"

std::map<QDate, Note> date_to_note;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), db("165.232.107.123", 5432, "tesst", "postgres", "1")
{
    ui->setupUi(this);

    QDate date(2020, 11, 10);

    date_to_note[date].name = "Test";
    date_to_note[date].text = "Test Text";

    db.connect_to_db();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calendarWidget_selectionChanged()
{
    auto date = ui->calendarWidget->selectedDate();
    Note note;

    try
    {
        note = FileWorker::read((date));
    }
    catch (...)
    {
        if(date_to_note.find(date) != date_to_note.end())
        {
            note = date_to_note[date];
        }
        else
        {
            ui->NoteNameLineEdit->clear();
            ui->tNoteTxtEdit->clear();
            return;
        }
    }

    ui->NoteNameLineEdit->setText(note.name);
    ui->tNoteTxtEdit->setText(note.text);
}

void MainWindow::on_SaveButton_clicked()
{
    auto date = ui->calendarWidget->selectedDate();
     date_to_note[date].name = ui->NoteNameLineEdit->text();
     date_to_note[date].text = ui->tNoteTxtEdit->toPlainText();

    FileWorker::writeOut(date_to_note[date], ui->calendarWidget->selectedDate());
}

void MainWindow::on_loadFromCloudButton_clicked()
{
    auto date = ui->calendarWidget->selectedDate();

    auto note = db.read_note(date);
    ui->NoteNameLineEdit->setText(note.name);
    ui->tNoteTxtEdit->setText(note.text);
}

void MainWindow::on_pushToCloudButton_clicked()
{
    auto date = ui->calendarWidget->selectedDate();
    Note new_note(ui->NoteNameLineEdit->text(), ui->tNoteTxtEdit->toPlainText());

    if(db.is_note_exists(date)){
        db.update_note(new_note, date);
    }
    else{
        db.add_note(new_note, date);
    }
}


