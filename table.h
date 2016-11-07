#ifndef TABLE_H
#define TABLE_H

#include <QString>
#include <QStringList>
#include <QTableWidget>
#include "topic.h"

namespace app {

class Table;

}

class Table
{
private:

    Topic* topic;

    QTableWidget* tableWidget;

public:

    Table(QTableWidget* tableWidget);

    ~Table();

    Topic* getTopic();

    void setTopic(Topic* topic);

    void addRow(QStringList dataList);

    void updateRow(QStringList dataList, int rowId);

    void deleteRow(int rowId);

    QStringList find(QString pattern);

private:

    void refreshTableContent();

};

#endif // TABLE_H
