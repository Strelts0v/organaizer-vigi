#ifndef BLANKFORNOTESITEM_H
#define BLANKFORNOTESITEM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>

namespace app {
class BlankForNotesItem;
}

class BlankForNotesItem : public QDialog
{
    Q_OBJECT

private:

    QLabel* headerLabel;
    QLineEdit* headEdit;
    QLabel* headLabel;
    QTextEdit* descriptionEdit;
    QLabel* descriptionLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;

public:
    BlankForNotesItem(QWidget* parent = NULL);

public slots:

    void okClickedSlot();

signals:

    void sendDataforNewNote(QStringList);
};

#endif // BLANKFORNOTESITEM_H
