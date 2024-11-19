#include "database.h"
#include "config.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace DataB
{
    bool DBConnect(Connection &C)
    {
        if (!QSqlDatabase::contains(MYSQL_CONNECTION))
        {
            C.db = QSqlDatabase::addDatabase("QMYSQL", MYSQL_CONNECTION);

            C.db.setHostName(MYSQL_HOSTNAME);
            C.db.setDatabaseName(MYSQL_DATABASE);
            C.db.setUserName(MYSQL_USERNAME);
            C.db.setPassword(MYSQL_PASSWORD);

            if (!C.db.open())
            {
                qDebug() << "La connexion à la base de données a échoué."
                         << "|error=" << C.db.lastError().text();
                C.connected = false;
                return C.connected;
            }

            qDebug() << "La connexion à la base de données a réussi.";
        }

        C.connected = true;
        return C.connected;
    }

    bool cUsrPas(Query Input, QSqlDatabase db)
    {
        QSqlQuery Q(db);
        QString select;
        bool valid = true;

        select = "SELECT _username FROM _users WHERE _username='" + Input.uName + "' AND _password=SHA1('" + Input.pass + "')";

        if (!Q.exec(select))
        {
            qDebug() << "L'exécution de la requête a échoué."
                     << "|error=" << Q.lastError().text();
            return false;
        }

        if (Q.size() != 1)
        {
            qDebug() << "L'utilisateur n'a pas été trouvé."
                     << "|username=" << Input.uName;
            return false;
        }
        else
        {
            qDebug() << "L'utilisateur a été trouvé."
                     << "|username=" << Input.uName;
            return valid;
        }
    }
}
