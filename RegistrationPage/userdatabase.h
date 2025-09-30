#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QString>
#include <QMap>

class UserDatabase {
public:
    UserDatabase() {}

    bool addUser(const QString& username, const QString& password) {
        if(db.contains(username)) return false;
        db[username] = password;
        return true;
    }

    bool checkUser(const QString& username, const QString& password) {
        return db.contains(username) && db[username] == password;
    }

    bool usernameExists(const QString& username) {
        return db.contains(username);
    }

private:
    QMap<QString, QString> db; // username -> password
};

#endif // USERDATABASE_H
