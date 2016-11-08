#ifndef BLANKFORCONTACTSITEM_H
#define BLANKFORCONTACTSITEM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>

namespace app {
class BlankForContactsItem;
}

class BlankForContactsItem : public QDialog
{
    Q_OBJECT

private:

    QLabel* headerLabel;
    QLineEdit* fullNameEdit;
    QLabel* fullNameLabel;
    QLineEdit* phoneNumbersEdit;
    QLabel* phoneNumbersLabel;
    QLineEdit* emailEdit;
    QLabel* emailLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;

public:

    BlankForContactsItem(QWidget *parent = NULL);

};

#endif // BLANKFORCONTACTSITEM_H
