#ifndef NOTE_H
#define NOTE_H
#include <QString>
#include <QDate>


class Note
{
public:
    Note();
    Note(QDate date);
    QString name, text;
    QDate date;
};

#endif // NOTE_H
