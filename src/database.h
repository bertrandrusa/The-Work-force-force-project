#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database
{
public:
    bool openDatabase(const std::string &dbName);
    void closeDatabase();
    bool addEmployee(const std::string &name, const std::string &position, const std::string &department, const std::string &contact);
    // Other CRUD operations...

private:
    sqlite3 *db = nullptr;
    bool executeQuery(const std::string &query);
};

#endif // DATABASE_H
