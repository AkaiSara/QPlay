#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QDialog>
#include <QWidget>
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

#include "documentary.h"
#include "movie.h"
#include "tvserie.h"
#include "deepptr.h"

class EditWidget : public QDialog
{
    Q_OBJECT

private:
    /*QRadioButton * doc; //li teniamo sti cosi?
    QRadioButton * mov;
    QRadioButton * tvs;*/

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
    QLineEdit * frameRate;

    QLineEdit * docNarr;
    QLineEdit * docTopic;

    QTextEdit * cast;
    QComboBox * genre;
    QComboBox * rating;

    QLineEdit * tvSeason;
    QLineEdit * tvEpisode;
    QCheckBox * tvEnded;

    QPushButton * edit;
    QPushButton * cancel;

    QWidget * docMenu;
    QWidget * movMenu;
    QWidget * tvsMenu;

    QVBoxLayout * mainBox;

    DeepPtr<AudioVisual> edited;
    DeepPtr<AudioVisual> avPtr;
    QWidget * parent;
public:
    explicit EditWidget(DeepPtr<AudioVisual> , QWidget * = nullptr);
    DeepPtr<AudioVisual> getEdited();

signals:
    //void edited(DeepPtr<AudioVisual>);

private slots:
    //void showDocWidget(bool);
    //void showMovWidget(bool);
    //void showTvSWidget(bool);
    void modifyItem();
};

#endif // EDITWIDGET_H
