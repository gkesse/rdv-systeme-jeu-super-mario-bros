#pragma once

#include <QSqlDatabase>

struct Connection;

namespace DataB
{
    bool DBConnect(Connection);
}

struct Connection
{
    QSqlDatabase db;
    bool connected;
};
