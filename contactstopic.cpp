#include "contactstopic.h"
#include "sqlstoredprocedures.h"

ContactsTopic::ContactsTopic() : Topic::Topic()
{}

ContactsTopic::ContactsTopic(QString topicName, int rowCount, int columnCount,
              QStringList columnHeaders):
    Topic(topicName, rowCount, columnCount, columnHeaders)
{}

ContactsTopic::~ContactsTopic()
{}

void ContactsTopic::addItem(QStringList data)
{
    QString fullName = data[0];
    QString phoneNumbers = data[1];
    QString email = data[2];
    SqlStoredProcedures::addContactsItem(fullName, phoneNumbers, email);
}

void ContactsTopic::updateItems(QStringList dataList)
{

    for(int i = 0; i < dataList.size(); ){
        QString fullName = dataList[i++];
        QString phoneNumbers = dataList[i++];
        QString email = dataList[i++];
        bool ok;
        int contactId = dataList[i++].toInt(&ok, 10);
        if(ok){
            SqlStoredProcedures::updateContactsItem(fullName, phoneNumbers, email, contactId);
        }
    }
}

void ContactsTopic::deleteItem(int contactId)
{
    SqlStoredProcedures::deleteContactsItem(contactId);
}

QStringList ContactsTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList ContactsTopic::getTopicContent()
{
    return SqlStoredProcedures::getContactsContent();
}

