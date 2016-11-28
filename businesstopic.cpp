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
        bool ok;
        int priority = convertPriorityToInteger(dataList[i++]);
        int businessId = dataList[i++].toInt(&ok, 10);
        if(ok){
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
    return SqlStoredProcedures::findDataInBusinessTopic(pattern);
}

QStringList BusinessTopic::getTopicContent()
{
    return SqlStoredProcedures::getBusinessContent();
}

int BusinessTopic::convertPriorityToInteger(QString priority)
{
    int priorityInIntegerFormat = 0;
    const int HIGH_PRIORITY = 1;
    const int MEDIUM_PRIORITY = 2;
    const int LOW_PRIORITY = 3;
    if(QString::compare(priority, "high") == 0){
        priorityInIntegerFormat = HIGH_PRIORITY;
    }else if(QString::compare(priority, "medium") == 0){
        priorityInIntegerFormat = MEDIUM_PRIORITY;
    }else if(QString::compare(priority, "low") == 0){
        priorityInIntegerFormat = LOW_PRIORITY;
    }else{
       // exception
    }
    return priorityInIntegerFormat;
}
