#include "sqlstoredprocedures.h"
#include "databasedriver.h"

void SqlStoredProcedures::addBusinessItem(QString head, QString deadline,
                     QString description, int priority)
{
    QString queryBody = "insert into business"
                    "(head, deadline, description, priority) values"
                    "('%1', '%2', '%3', %4)";
    queryBody = queryBody.arg(head)
            .arg(deadline)
            .arg(description)
            .arg(priority);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::updateBusinessItem(QString head, QString deadline,
                        QString description, int priority, int rowId)
{
    QString queryBody = "update business"
                    "set head = '%1', deadline = '%2', description = '%3', "
                    "priority = %4 where rowId = %5";
    queryBody = queryBody.arg(head)
            .arg(deadline)
            .arg(description)
            .arg(priority)
            .arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::deleteBusinessItem(int rowId)
{
    QString queryBody = "delete from business"
                        "where rowId = %1";
    queryBody = queryBody.arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getBusinessContent()
{
    QString topicName = "business";
    return DatabaseDriver::getRecordsAccordingTopic(topicName);
}

void SqlStoredProcedures::addContactsItem(QString fullName, QString phoneNumbers, QString email)
{
    QString queryBody = "insert into contacts"
                    "(full_name, phone_numbers, email) values"
                    "('%1', '%2', '%3')";
    queryBody = queryBody.arg(fullName)
            .arg(phoneNumbers)
            .arg(email);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::updateContactsItem(QString fullName, QString phoneNumbers, QString email, int rowId)
{
    QString queryBody = "update contacts"
                    "set full_name = '%1', phone_numbers = '%2', email = '%3' "
                    "where rowId = %4";
    queryBody = queryBody.arg(fullName)
            .arg(phoneNumbers)
            .arg(email)
            .arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::deleteContactsItem(int rowId)
{
    QString queryBody = "delete from contacts"
                        "where rowId = %1";
    queryBody = queryBody.arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getContactsContent()
{
    QString topicName = "contacts";
    return DatabaseDriver::getRecordsAccordingTopic(topicName);
}

void SqlStoredProcedures::addNotesItem(QString head, QString description)
{
    QString queryBody = "insert into notes"
                    "(head, description) values"
                    "('%1', '%2')";
    queryBody = queryBody.arg(head)
            .arg(description);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::updateNotesItem(QString head, QString description, int rowId)
{
    QString queryBody = "update notes"
                    "set head = '%1', description = '%2' "
                    "where rowId = %3";
    queryBody = queryBody.arg(head)
            .arg(description)
            .arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

void SqlStoredProcedures::deleteNotesItem(int rowId)
{
    QString queryBody = "delete from notes"
                        "where rowId = %1";
    queryBody = queryBody.arg(rowId);
    DatabaseDriver::executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getNotesContent()
{
    QString topicName = "notes";
    return DatabaseDriver::getRecordsAccordingTopic(topicName);
}

QStringList SqlStoredProcedures::findDataInTopic(QString pattern, QString topicName)
{

}
