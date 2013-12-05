#ifndef DBINSTRUCTOR_H
#define DBINSTRUCTOR_H

#include <string>

class Instructor;
class QSqlQuery;
class DatabaseManager;

using namespace std;

class DBInstructor
{
public:
    DBInstructor(DatabaseManager&);

    Instructor getInstructor(string email);

private:
   QSqlQuery getInstructorQuery(string);

   DatabaseManager& db;

};

#endif // DBINSTRUCTOR_H
