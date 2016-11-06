#include "businesstopic.h"
#include "sqlstoredprocedures.h"

BusinessTopic::BusinessTopic(QString topicName, int rowCount, int columnCount,
              QStringList columnHeaders):
    Topic(topicName, rowCount, columnCount, columnHeaders)
{}

BusinessTopic::~BusinessTopic()
{}

void BusinessTopic::addItem(QStringList data)
{
    QString head = data[0];
    QString deadline = data[1];
    QString description = data[2];
    bool ok;
    int priority = data[3].toInt(&ok, 10);
    if(ok){
        SqlStoredProcedures::addBusinessItem(head, deadline, description, priority);
    }
    else {
        // exception
    }
}

void BusinessTopic::updateItem(QStringList data, int rowId)
{
    QString head = data[0];
    QString deadline = data[1];
    QString description = data[2];
    bool ok;
    int priority = data[3].toInt(&ok, 10);
    if(ok){
        SqlStoredProcedures::updateBusinessItem(head, deadline, description, priority, rowId);
    }
}

void BusinessTopic::deleteItem(int rowId)
{
    SqlStoredProcedures::deleteBusinessItem(rowId);
}

QStringList BusinessTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList BusinessTopic::getTopicContent()
{
    return SqlStoredProcedures::getBusinessContent();
}
