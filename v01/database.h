#pragma once

#include <QSqlDatabase>

struct Connection;
struct Query;

namespace DataB
{
    bool DBConnect(Connection &);
    bool cUsrPas(Query, QSqlDatabase);
}

struct Connection
{
    QSqlDatabase db;
    bool connected;
};

struct Query
{
    QString uName;
    QString pass;
};