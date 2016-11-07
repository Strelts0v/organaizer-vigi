#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_businessButton_clicked();

    void on_contactsButton_clicked();

    void on_deleteButton_clicked();

    void on_exitButton_clicked();

    void on_notesButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
