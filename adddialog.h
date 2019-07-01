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
#include <QWidget>


class AddDialog : public QDialog {
    Q_OBJECT

private:
    MainWidget *parent;

    QRadioButton * doc;
    QRadioButton * mov;
    QRadioButton * tvs;

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

    QLineEdit * docNarr;
    QLineEdit * docTopic;

    QTextEdit * cast;
    QComboBox * genre;
    QComboBox * rating;

    QLineEdit * movColl; ////////////////// INUTILIZZATO

    QLineEdit * tvSeason;
    QLineEdit * tvEpisode;
    QCheckBox * tvEnded;

    QPushButton * add;
    QPushButton * cancel;

    QWidget * docMenu;
    QWidget * movMenu;
    QWidget * tvSMenu;

    QVBoxLayout * mainBox;
public:
    AddDialog(MainWidget * = nullptr);

private slots:
    void showDocWidget(bool);
    void showMovWidget(bool);
    void showTvSWidget(bool);

};

#endif // ADDDIALOG_H
