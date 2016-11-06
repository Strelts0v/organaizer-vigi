#include "databasedriver.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QDebug>

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
        dataList = parseQueryContactsRecords(query);
    } else {
        qDebug() << "Error! Invalid name of topic...";
    }
}

QStringList DatabaseDriver::findInformation(QString queryBody)
{

}

QStringList DatabaseDriver::parseQueryBusinessRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("id_business")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("head")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("deadline")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("description")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("priority")).toString());
    }
    return dataList;
}

QStringList DatabaseDriver::parseQueryContactsRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("id_contact")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("full_name")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("phone_numbers")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("email")).toString());
    }
    return dataList;
}

QStringList DatabaseDriver::parseQueryNotesRecords(QSqlQuery resultQuery)
{
    QSqlRecord record = resultQuery.record();
    QStringList dataList;
    while(resultQuery.next()){
        dataList.push_back(resultQuery.value(record.indexOf("id_note")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("head")).toString());
        dataList.push_back(resultQuery.value(record.indexOf("description")).toString());
    }
    return dataList;
}
