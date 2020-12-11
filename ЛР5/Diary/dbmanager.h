#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include "note.h"


using namespace std;
//using namespace nlohmann;

class Database {
private:
    QSqlDatabase db;
    bool check_con();


public:
    Database(QString ip, uint16_t port,
             QString name,
             QString user, QString pwd);
    ~Database();

    bool connect_to_db();
    void db_info();
    void disconnect();
    bool UserIsInBD(QString name);
    void addUserToDB(QString name);

    bool is_note_exists(QDate date);

    Note read_note(QDate note_date);
    void update_note(Note note, QDate date);
    bool add_note(Note note, QDate date);


    QString DB_IP;
    uint16_t DB_PORT;
    QString DB_NAME;
    QString DB_USER;
    QString DB_PASSWORD;
};


#endif // DBMANAGER_H
