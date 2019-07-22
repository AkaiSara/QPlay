#ifndef ADDDIALOG_H
#define ADDDIALOG_H

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
#include <QSize>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

//#include<QtWidgets>


class AddDialog : public QDialog {
    Q_OBJECT

private:
    QRadioButton * doc;
    QRadioButton * mov;
    QRadioButton * tvs;

    QLineEdit * title;
    QTextEdit * descr;
    QLineEdit * date;
    QLineEdit * director;
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

    QLineEdit * tvSeason;
    QLineEdit * tvEpisode;
    QCheckBox * tvEnded;

    QPushButton * add;
    QPushButton * cancel;

    QWidget * docMenu;
    QWidget * movMenu;
    QWidget * tvsMenu;

    QVBoxLayout * mainBox;
public:
    AddDialog();

private slots:
    void showDocWidget(bool);
    void showMovWidget(bool);
    void showTvSWidget(bool);
    void addItem();
};

#endif // ADDDIALOG_H
