#include "businesstopic.h"
#include "sqlstoredprocedures.h"

BusinessTopic::BusinessTopic() : Topic::Topic()
{}

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

void BusinessTopic::updateItems(QStringList dataList)
{
    for(int i = 0; i < dataList.size();){
        QString head = dataList[i++];
        QString deadline = dataList[i++];
        QString description = dataList[i++];
        bool ok1, ok2;
        int priority = dataList[i++].toInt(&ok1, 10);
        int businessId = dataList[i++].toInt(&ok2, 10);
        if(ok1 && ok2){
            SqlStoredProcedures::updateBusinessItem(head, deadline, description, priority, businessId);
        }
    }
}

void BusinessTopic::deleteItem(int businessId)
{
    SqlStoredProcedures::deleteBusinessItem(businessId);
}

QStringList BusinessTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList BusinessTopic::getTopicContent()
{
    return SqlStoredProcedures::getBusinessContent();
}
