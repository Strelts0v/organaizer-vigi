#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

#include <QString>
#include <QStringList>
#include <QtSql/QSqlDatabase>

namespace app {

class DatabaseDriver;
const QString DATABASE_PATH = "../ViGi/database/database.sqlite";

}

class DatabaseDriver
{
private:

    static QSqlDatabase database;

public:

    static void executeQuery(QString query);

    static QStringList getRecordsAccordingTopic(QString topicName);

    static QStringList findInformation(QString queryBody);

};

#endif // DATABASEDRIVER_H
