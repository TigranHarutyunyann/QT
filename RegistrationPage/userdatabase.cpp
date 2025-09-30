#include "userdatabase.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

UserDatabase::UserDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT)");
}

UserDatabase::~UserDatabase()
{
    db.close();
}

bool UserDatabase::addUser(const QString &username, const QString &password)
{
    if (usernameExists(username))
        return false;

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    return query.exec();
}

bool UserDatabase::checkUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username=? AND password=?");
    query.addBindValue(username);
    query.addBindValue(password);
    query.exec();
    return query.next(); // true if a row exists
}

bool UserDatabase::usernameExists(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username=?");
    query.addBindValue(username);
    query.exec();
    return query.next();
}
