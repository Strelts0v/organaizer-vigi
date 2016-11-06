#ifndef TABLE_H
#define TABLE_H

#include <QString>
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

    void updateRow(QStringList dataList, int id);

    void deleteRow(int id);

    void find(QString info);

private:

    void refreshTableContent();

};

#endif // TABLE_H
