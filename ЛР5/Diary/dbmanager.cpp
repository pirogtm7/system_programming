#include "dbmanager.h"

#include <iostream>
#include <qlogging.h>
#include <QSqlError>
#include <QVariant>


Database::Database (QString ip, uint16_t port,
                    QString name,
                    QString user, QString pwd) :
DB_IP(ip), DB_PORT(port), DB_NAME(name), DB_USER(user), DB_PASSWORD(pwd)
{
    std::cout << "DATABASE CONSTRUCT" << std::endl;
    db_info();

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(this->DB_IP);
    db.setDatabaseName(this->DB_NAME);
    db.setUserName(this->DB_USER);
    db.setPassword(this->DB_PASSWORD);
    db.setPort(this->DB_PORT);
}

Database::~Database() {
    disconnect();
}

bool Database::check_con() {
    return db.isOpen();
}

bool Database::connect_to_db() {
    if (db.open()){
        std::cout << "Connection ok!"<<std::endl;
        return true;
    }
    else{
        std::cout << "Connection Failed!"<<std::endl;
        return false;
    }
}

void Database::db_info() {
    std::cout<<"User: "<< this->DB_USER.toStdString()<<std::endl
             <<"Database name: "<< this->DB_NAME.toStdString()<<std::endl
             <<"Database port: "<< this->DB_PORT<<std::endl
             <<"Database host: "<< this->DB_IP.toStdString()<<std::endl;
}

void Database::disconnect()
{
    db.close();
}

bool Database::UserIsInBD(QString name)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "select name from users where users.name = '" + name + "' limit 1;";

    QSqlQuery query;
    QString output;
    if(query.exec(qstr))
    {
        if(query.size()== -1)
        {
            std::cout << "UserIsInBD error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();

            throw new std::exception();
        }

        if(query.size()>0 && query.next())
        {
            std::wcout << query.value(0).toString().toStdWString() << std::endl;
            query.finish();
            return true;
        }
    } else {
        std::cout << "UserIsInBD error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
    return false;
}

void Database::addUserToDB(QString name)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "insert into users (name) values ('" + name + "');";

    QSqlQuery query;
    QString output;
    if(!query.exec(qstr))
    {
        std::cout << "UserIsInBD error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
}

bool Database::is_note_exists(QDate date)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "select name, text from notes where notes.date = '" + date.toString() + "' limit 1;";

    QSqlQuery query;
    QString output;
    if(query.exec(qstr))
    {
        if(query.size()== -1)
        {
            std::cout << "select date error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();

            throw new std::exception();
        }

        if(query.size()>0 && query.next())
        {
            QString name = query.value(0).toString();
            QString text = query.value(1).toString();

//            std::cout << name.toStdString() << std::endl;
//            std::cout << text.toStdString() << std::endl;

            query.finish();
            return true;
        }
    } else {
        std::cout << "note read error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
    return false;
}

bool Database::add_note(Note note, QDate date)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "insert into notes (name, text, date) values ('" + note.name + "', '"+ note.text + "', '" + date.toString() + "');";

    QSqlQuery query;
    QString output;
    if(!query.exec(qstr))
    {
        std::cout << "add note error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
}

Note Database::read_note(QDate note_date)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "select name, text from notes where notes.date = '" + note_date.toString() + "' limit 1;";

    QSqlQuery query;
    QString output;
    if(query.exec(qstr))
    {
        if(query.size()== -1)
        {
            std::cout << "select date error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();

            throw new std::exception();
        }

        if(query.size()>0 && query.next())
        {
            QString name = query.value(0).toString();
            QString text = query.value(1).toString();

            std::cout << name.toStdString() << std::endl;
            std::cout << text.toStdString() << std::endl;

            query.finish();
            return Note(name, text);
        }
    } else {
        std::cout << "note read error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
    return Note();
}

void Database::update_note(Note note, QDate date)
{
    if(!this->check_con())
    {
        if(!this->connect_to_db()){
            throw new std::exception();
        }
    }
    QString qstr = "update notes set name = '" + note.name + "', text = '"+ note.text + "', date = '" + date.toString() + "' where date = '" + date.toString() + "';";

    QSqlQuery query;
    QString output;
    if(!query.exec(qstr))
    {
        std::cout << "add note error:" << query.lastError().text().toStdString() << ", SqLite error code:" << query.lastError().number();
    }
}








