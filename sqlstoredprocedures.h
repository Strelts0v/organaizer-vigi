#ifndef SQLSTOREDPROCEDURES_H
#define SQLSTOREDPROCEDURES_H

#include <QString>
#include <QStringList>

namespace app {

class SqlStoredProcedures;

}

class SqlStoredProcedures
{
public:

    static void addBusinessItem(QString head, QString deadline,
                         QString description, int priority);

    static void updateBusinessItem(QString head, QString deadline,
                            QString description, int priority, int rowId);

    static void deleteBusinessItem(int rowId);

    static QStringList getBusinessContent();

    static void addContactsItem(QString fullName, QString phoneNumbers, QString email);

    static void updateContactsItem(QString fullName, QString phoneNumbers, QString email, int rowId);

    static void deleteContactsItem(int rowId);

    static QStringList getContactsContent();

    static void addNotesItem(QString head, QString description);

    static void updateNotesItem(QString head, QString description, int rowId);

    static void deleteNotesItem(int rowId);

    static QStringList getNotesContent();

    static QStringList findDataInTopic(QString pattern, QString topicName);

};

#endif // SQLSTOREDPROCEDURES_H
