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
                     << "|username=" << Input.uName
                     << "|password=" << Input.pass;
            return false;
        }
        else
        {
            qDebug() << "L'utilisateur a été trouvé."
                     << "|username=" << Input.uName
                     << "|password=" << Input.pass;
            return valid;
        }
    }

    bool regUsr(Query Input, QSqlDatabase db)
    {
        QString insert;
        QSqlQuery Q(db);

        if (chkUsr(Input, db))
        {
            insert = "INSERT INTO _users (_username, _password) VALUES "
                     "('" +
                     Input.uName + "', SHA1('" + Input.pass + "'))";

            if (!Q.exec(insert))
            {
                qDebug() << "L'exécution de la requête a échoué."
                         << "|error=" << Q.lastError().text();
                return false;
            }

            db.close();
            return true;
        }
        else
        {
            db.close();
            return false;
        }
    }

    bool chkUsr(Query Input, QSqlDatabase db)
    {
        QSqlQuery Q(db);
        QString select;
        bool valid = true;
        select = "SELECT _username FROM ready_mario_db WHERE _username='" + Input.uName + "'";

        if (!Q.exec(select))
        {
            qDebug() << "L'exécution de la requête a échoué."
                     << "|error=" << Q.lastError().text();
            return true;
        }
        if (Q.size() == 1)
        {
            return false;
        }
        else
        {
            return valid;
        }
    }
}
