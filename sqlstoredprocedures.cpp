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
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::updateBusinessItem(QString head, QString deadline,
                        QString description, int priority, int businessId)
{
    QString queryBody = "update business "
                    "set head = '%1', deadline = '%2', description = '%3', "
                    "priority = %4 where id_business = %5";
    queryBody = queryBody.arg(head)
            .arg(deadline)
            .arg(description)
            .arg(priority)
            .arg(businessId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::deleteBusinessItem(int businessId)
{
    QString queryBody = "delete from business "
                        "where id_business = %1";
    queryBody = queryBody.arg(businessId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getBusinessContent()
{
    QString topicName = "business";
    return DatabaseDriver::getDatabaseDriver()->getRecordsAccordingTopic(topicName);
}

void SqlStoredProcedures::addContactsItem(QString fullName, QString phoneNumbers, QString email)
{
    QString queryBody = "insert into contacts"
                    "(full_name, phone_numbers, email) values"
                    "('%1', '%2', '%3')";
    queryBody = queryBody.arg(fullName)
            .arg(phoneNumbers)
            .arg(email);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::updateContactsItem(QString fullName, QString phoneNumbers, QString email, int contactId)
{
    QString queryBody = "update contacts "
                    "set full_name = '%1', phone_numbers = '%2', email = '%3' "
                    "where id_contact = %4";
    queryBody = queryBody.arg(fullName)
            .arg(phoneNumbers)
            .arg(email)
            .arg(contactId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::deleteContactsItem(int contactId)
{
    QString queryBody = "delete from contacts "
                        "where id_contact = %1";
    queryBody = queryBody.arg(contactId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getContactsContent()
{
    QString topicName = "contacts";
    return DatabaseDriver::getDatabaseDriver()->getRecordsAccordingTopic(topicName);
}

void SqlStoredProcedures::addNotesItem(QString head, QString description)
{
    QString queryBody = "insert into notes"
                    "(head, description) values"
                    "('%1', '%2')";
    queryBody = queryBody.arg(head)
            .arg(description);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::updateNotesItem(QString head, QString description, int noteId)
{
    QString queryBody = "update notes "
                    "set head = '%1', description = '%2' "
                    "where id_note = %3";
    queryBody = queryBody.arg(head)
            .arg(description)
            .arg(noteId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

void SqlStoredProcedures::deleteNotesItem(int noteId)
{
    QString queryBody = "delete from notes "
                        "where id_note = %1";
    queryBody = queryBody.arg(noteId);
    DatabaseDriver::getDatabaseDriver()->executeQuery(queryBody);
}

QStringList SqlStoredProcedures::getNotesContent()
{
    QString topicName = "notes";
    return DatabaseDriver::getDatabaseDriver()->getRecordsAccordingTopic(topicName);
}

QStringList SqlStoredProcedures::findDataInBusinessTopic(QString pattern)
{
    QString queryBody = "select * from business "
            "where head like '%%1%' or deadline like  '%%1%'"
            "or description like  '%%1%'";
    queryBody = queryBody.arg(pattern);
    return  DatabaseDriver::getDatabaseDriver()->getRecordsAccordingPattern(queryBody);
}

QStringList SqlStoredProcedures::findDataInContactsTopic(QString pattern)
{
    QString queryBody = "select * from contacts "
            "where full_name like '%%1%' or phone_numbers like  '%%1%'"
            "or email like  '%%1%'";
    queryBody = queryBody.arg(pattern);
    return  DatabaseDriver::getDatabaseDriver()->getRecordsAccordingPattern(queryBody);
}

QStringList SqlStoredProcedures::findDataInNotesTopic(QString pattern)
{
    QString queryBody = "select * from notes "
            "where head like '%%1%' or description like  '%%1%'";
    queryBody = queryBody.arg(pattern);
    return  DatabaseDriver::getDatabaseDriver()->getRecordsAccordingPattern(queryBody);
}
