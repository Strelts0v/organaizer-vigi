#include "blankfornotesitem.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

QLabel* headerLabel;
QLineEdit* headEdit;
QLabel* headLabel;
QTextEdit* descriptionEdit;
QLabel* descriptionLabel;
QPushButton* okButton;
QPushButton* cancelButton;

BlankForNotesItem::BlankForNotesItem(QWidget *parent) : QDialog(parent)
{
    headerLabel = new QLabel("Input data for new note");

    headLabel = new QLabel("head: ");
    headEdit = new QLineEdit();

    descriptionLabel = new QLabel("description: ");
    descriptionEdit = new QTextEdit();

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    QHBoxLayout* headerLayot = new QHBoxLayout();
    headerLayot->addWidget(headerLabel);

    QHBoxLayout* headLayot = new QHBoxLayout();
    headLayot->addWidget(headLabel);
    headLayot->addWidget(headEdit);

    QHBoxLayout* descriptionLayot = new QHBoxLayout();
    descriptionLayot->addWidget(descriptionLabel);
    descriptionLayot->addWidget(descriptionEdit);

    QHBoxLayout* buttonLayot = new QHBoxLayout();
    buttonLayot->addWidget(okButton);
    buttonLayot->addWidget(cancelButton);

    QVBoxLayout* mainLayot = new QVBoxLayout(this);
    mainLayot->addLayout(headerLayot);
    mainLayot->addLayout(headLayot);
    mainLayot->addLayout(descriptionLayot);
    mainLayot->addLayout(buttonLayot);

    setLayout(mainLayot);
    setWindowTitle("ViGi");

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClickedSlot()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void BlankForNotesItem::okClickedSlot()
{
    QStringList dataList;
    dataList.push_back(headEdit->text());
    dataList.push_back(descriptionEdit->toPlainText());
    emit sendDataforNewNote(dataList);
    this->close();
}
