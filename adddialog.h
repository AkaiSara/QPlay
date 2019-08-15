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
#include <QFileDialog>

#include "documentary.h"
#include "movie.h"
#include "tvserie.h"

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

    QPushButton * selectImgBtn;
    QLabel * imgLabel;
    QString imgPath;

    QLineEdit * rt;
    QCheckBox * ac;
    QLineEdit * imgres;
    QLineEdit * frameRate;

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

    QWidget * parent;
public:
    AddDialog(QWidget * = nullptr);

signals:
    void created(AudioVisual *);

private slots:
    void showDocWidget(bool);
    void showMovWidget(bool);
    void showTvSWidget(bool);
    void selectImg();
    void addNewItem();
};

#endif // ADDDIALOG_H
