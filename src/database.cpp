#include "database.h"
#include <sqlite3.h>
#include <iostream>

bool Database::openDatabase(const std::string &dbName)
{
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Database::closeDatabase()
{
    if (db)
    {
        sqlite3_close(db);
    }
}

bool Database::executeQuery(const std::string &query)
{
    char *errMsg = nullptr;
    if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Error executing query: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
bool Database::addEmployee(const std::string &name, const std::string &position, const std::string &department, const std::string &contact)
{
    std::string sql = "INSERT INTO employees (name, position, department, contact) VALUES ('" + name + "', '" + position + "', '" + department + "', '" + contact + "');";
    return executeQuery(sql);
}

// Other CRUD operations...
 ⁠
