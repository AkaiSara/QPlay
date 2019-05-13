#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "mainwidget.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>

class AddDialog : public QDialog {
    Q_OBJECT

private:
    MainWidget *parent;

    QRadioButton * type1;
    QRadioButton * type2;
    QRadioButton * type3;
    QVBoxLayout * radioListBox;
    QGroupBox * upperRadioButtonsGroup;

    QPushButton * add;
    QPushButton * cancel;
    QHBoxLayout * lowerButtonsBox;

    QVBoxLayout * mainBox;
public:
    AddDialog(MainWidget * = nullptr);
};

#endif // ADDDIALOG_H
