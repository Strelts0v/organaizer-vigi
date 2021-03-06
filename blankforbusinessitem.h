#ifndef BLANKFORBUSINESSITEM_H
#define BLANKFORBUSINESSITEM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QRadioButton>
#include <QWidget>
#include <QTextEdit>
#include <QButtonGroup>

namespace app {
class BlankForBusinessItem;
}

class BlankForBusinessItem : public QDialog
{
    Q_OBJECT                // макрос, для обработки класса метаобъектным компилятором Qt,
                            // т.к не вся информация, может быт обработана компилятором c++
private:

    // виджеты для бланка заполнения данных
    QLabel* headerLabel;
    QLineEdit* headEdit;
    QLabel* headLabel;
    QDateEdit* deadlineEdit;
    QLabel* deadlineLabel;
    QTextEdit* descriptionEdit;
    QLabel* descriptionLabel;
    QButtonGroup* priority;
    QLabel* priorityLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;

public:

    BlankForBusinessItem(QWidget *parent = NULL);       // можем присвоить окну родителя,
                                                        // если его не будет, то по умолчанию NULL
public slots:

    void okClickedSlot();

signals:

    void sendDataforNewBusiness(QStringList);
};

#endif // BLANKFORBUSINESSITEM_H
