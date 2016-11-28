#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table.h"
#include "applicationcontext.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    Table* table;

    Ui::MainWindow* ui;

    ApplicationContext* context;

    bool isButtonsEnable;

public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void addNewTopicItem(QStringList dataList);

    void updateTopicItems(QStringList dataList);

    void deleteTopicItem(int id);

    void on_addButton_clicked();

    void on_businessButton_clicked();

    void on_contactsButton_clicked();

    void on_deleteButton_clicked();

    void on_exitButton_clicked();

    void on_notesButton_clicked();

    void on_updateButton_clicked();

    void on_findButton_clicked();

    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

    void on_actionUpdate_triggered();

private:

    void enableTableButtons();

    void disableTableButtons();
};

#endif // MAINWINDOW_H
