#include "database.h"
#include "config.h"

#include <QSqlError>
#include <QDebug>

namespace DataB
{
    bool DBConnect(Connection C)
    {
        if (QSqlDatabase::contains(MYSQL_CONNECTION))
        {
            C.db = QSqlDatabase::database(MYSQL_CONNECTION);
        }
        else
        {
            C.db = QSqlDatabase::addDatabase("QMYSQL", MYSQL_CONNECTION);

            C.db.setHostName(MYSQL_HOSTNAME);
            C.db.setDatabaseName(MYSQL_DATABASE);
            C.db.setUserName(MYSQL_USERNAME);
            C.db.setPassword(MYSQL_PASSWORD);

            if (!C.db.open())
            {
                qDebug() << "Error lors de la connexion à la base de données.|error=" << C.db.lastError().text();
                C.connected = false;
                return C.connected;
            }

            qDebug() << "La connexion à la base de données a réussi...";
        }

        C.connected = true;
        return C.connected;
    }
}
