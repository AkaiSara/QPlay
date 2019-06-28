#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "mywidget.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>

class AddDialog : public QDialog {
    Q_OBJECT

private:
    MainWidget *parent;

    QRadioButton * doc;
    QRadioButton * mov;
    QRadioButton * tvs;
    QVBoxLayout * radioListBox;
    QGroupBox * upperRadioButtonsGroup;
    QButtonGroup * buttonsGroup;

    QLineEdit * title;
    QTextEdit * descr;
    QLineEdit * date;
    //dir
    QCheckBox * fav;
    QLabel * favLabel;
    //img
    QLineEdit * rt;
    QCheckBox * ac;
    QLineEdit * imgres;
    QLineEdit * frameps;

    QPushButton * add;
    QPushButton * cancel;
    QHBoxLayout * lowerButtonsBox;

    QVBoxLayout * mainBox;
public:
    AddDialog(MainWidget * = nullptr);
};

#endif // ADDDIALOG_H
