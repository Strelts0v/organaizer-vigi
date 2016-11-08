#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <table.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    Table* table;

    Ui::MainWindow *ui;

public:

    explicit MainWindow(QWidget *parent = 0, Table* table = 0);

    ~MainWindow();

    Table getTable();

    void setTable(Table* table);

private slots:
    void on_addButton_clicked();

    void on_businessButton_clicked();

    void on_contactsButton_clicked();

    void on_deleteButton_clicked();

    void on_exitButton_clicked();

    void on_notesButton_clicked();

    void on_updateButton_clicked();

private:

    //int getTableTopic();
};

#endif // MAINWINDOW_H
