#include "notestopic.h"
#include "sqlstoredprocedures.h"

NotesTopic::NotesTopic() : Topic::Topic()
{}

NotesTopic::NotesTopic(QString topicName, int rowCount, int columnCount,
              QStringList columnHeaders):
    Topic(topicName, rowCount, columnCount, columnHeaders)
{}

NotesTopic::~NotesTopic()
{}

void NotesTopic::addItem(QStringList data)
{
    QString head = data[0];
    QString description = data[1];
    SqlStoredProcedures::addNotesItem(head, description);
}

void NotesTopic::updateItem(QStringList data, int rowId)
{
    QString head = data[0];
    QString description = data[1];
    SqlStoredProcedures::updateNotesItem(head, description, rowId);
}

void NotesTopic::deleteItem(int rowId)
{
    SqlStoredProcedures::deleteNotesItem(rowId);
}

QStringList NotesTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList NotesTopic::getTopicContent()
{
    return SqlStoredProcedures::getNotesContent();
}
