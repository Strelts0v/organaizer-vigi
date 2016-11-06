#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

#include <QString>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace app {

class DatabaseDriver;
const QString DATABASE_PATH = "../ViGi/database/database.sqlite";

}

class DatabaseDriver
{
private:

    static QSqlDatabase database;

public:

    static void executeQuery(QString queryBody);

    static QStringList getRecordsAccordingTopic(QString topicName);

    static QStringList findInformation(QString queryBody);

private:

    static QStringList parseQueryBusinessRecords(QSqlQuery resultQuery);

    static QStringList parseQueryContactsRecords(QSqlQuery resultQuery);

    static QStringList parseQueryNotesRecords(QSqlQuery resultQuery);
};

#endif // DATABASEDRIVER_H
