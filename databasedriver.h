#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

#include <QString>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace app {
class DatabaseDriver;
}

class DatabaseDriver
{
private:

    static DatabaseDriver* driver;

    QSqlDatabase database;

public:

    static DatabaseDriver* getDatabaseDriver();

    void executeQuery(QString queryBody);

    QStringList getRecordsAccordingTopic(QString topicName);

    QStringList getRecordsAccordingPattern(QString queryBody);

private:

    DatabaseDriver();

    QStringList parseQueryBusinessRecords(QSqlQuery resultQuery);

    QStringList parseQueryContactsRecords(QSqlQuery resultQuery);

    QStringList parseQueryNotesRecords(QSqlQuery resultQuery);

    QStringList parseFoundRecords(QSqlQuery resultQuery);
};

#endif // DATABASEDRIVER_H
