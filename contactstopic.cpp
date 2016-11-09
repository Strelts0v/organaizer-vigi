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

void ContactsTopic::updateItem(QStringList data, int rowId)
{
    QString fullName = data[0];
    QString phoneNumbers = data[1];
    QString email = data[2];
    SqlStoredProcedures::updateContactsItem(fullName, phoneNumbers, email, rowId);
}

void ContactsTopic::deleteItem(int rowId)
{
    SqlStoredProcedures::deleteContactsItem(rowId);
}

QStringList ContactsTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList ContactsTopic::getTopicContent()
{
    return SqlStoredProcedures::getContactsContent();
}

