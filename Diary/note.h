#ifndef NOTE_H
#define NOTE_H
#include <QString>
#include <QDate>



class Note
{
public:
    Note();
    Note(QString name, QString text);
    QString name, text;
};

#endif // NOTE_H
