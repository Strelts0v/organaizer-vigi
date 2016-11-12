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

void NotesTopic::updateItems(QStringList dataList)
{
    for(int i = 0; i < dataList.size(); ){
        QString head = dataList[i++];
        QString description = dataList[i++];
        bool ok;
        int idNote = dataList[i++].toInt(&ok, 10);
        if(ok){
            SqlStoredProcedures::updateNotesItem(head, description, idNote);
        }
    }
}

void NotesTopic::deleteItem(int idNote)
{
    SqlStoredProcedures::deleteNotesItem(idNote);
}

QStringList NotesTopic::find(QString pattern)
{
    return SqlStoredProcedures::findDataInTopic(pattern, getTopicName());
}

QStringList NotesTopic::getTopicContent()
{
    return SqlStoredProcedures::getNotesContent();
}
