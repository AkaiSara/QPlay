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

    QLineEdit * movColl;

    QLineEdit * tvSeason;
    QLineEdit * tvEpisode;
    QCheckBox * tvEnded;

    QPushButton * add;
    QPushButton * cancel;

    QHBoxLayout * hBox;
    QVBoxLayout * mainBox;
public:
    AddDialog(MainWidget * = nullptr);

private slots:
    void showDocWidget();
    void showMovWidget();
    void showTvSWidget();

};

#endif // ADDDIALOG_H
