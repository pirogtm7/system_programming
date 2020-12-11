#include "note.h"

Note::Note()
{
    date = QDate::currentDate();
}

Note::Note(QDate date)
{
    this->date = date;
}
