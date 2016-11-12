#include "databasedriver.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QDebug>

DatabaseDriver* DatabaseDriver::driver = NULL;

DatabaseDriver* DatabaseDriver::getDatabaseDriver()
{
    if(!driver){
        //const QString databasePath = "..\\ViGi\\database\\database.sqlite";
        driver = new DatabaseDriver();
    }
    return DatabaseDriver::driver;
}

void DatabaseDriver::executeQuery(QString queryBody)
{
    QSqlQuery query;
    if(!query.exec(queryBody)){
        qDebug() << "Error! Cannot complete query...";
    }
}

QStringList DatabaseDriver::getRecordsAccordingTopic(QString topicName)
{
    QString queryBody = "select * from %1";
    queryBody = queryBody.arg(topicName);
    QSqlQuery query;
    if(!query.exec(queryBody)){
        qDebug() << "Error! Cannot complete SELECT...";
    }
    QStringList dataList;

    if(QString::compare(topicName, "business") == 0){
        dataList = parseQueryBusinessRecords(query);
    }else if(QString::compare(topicName, "contacts") == 0){
        dataList = parseQueryContactsRecords(query);
    }else if(QString::compare(topicName, "notes") == 0){
        dataList = parseQueryNotesRecords(query);
    }else {
        qDebug() << "Error! Invalid name of topic...";
    }
    return dataList;
}

QStringList DatabaseDriver::findInformation(QString queryBody)
{

}

DatabaseDriver::DatabaseDriver()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("..\\ViGi\\database\\database.sqlite");
    if(!database.open()){
        qDebug() << "Не удаётся подключится к базе данных.";
    }
}

QStringList DatabaseDriver::parseQueryBusinessRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("head")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("deadline")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("description")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("priority")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("id_business")).toString());
    }
    return dataList;
}

QStringList DatabaseDriver::parseQueryContactsRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("full_name")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("phone_numbers")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("email")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("id_contact")).toString());
    }
    return dataList;
}

QStringList DatabaseDriver::parseQueryNotesRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("head")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("description")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("id_note")).toString());
    }
    return dataList;
}
