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
#include <QFileDialog>

#include "documentary.h"
#include "movie.h"
#include "tvserie.h"
#include "deepptr.h"

class EditWidget : public QDialog {
    Q_OBJECT

private:
    QLineEdit * titleEdit;
    QTextEdit * descr;
    QLineEdit * dateEdit;
    QLineEdit * directorEdit;
    QCheckBox * fav;

    QPushButton * selectImgBtn;
    QLabel * imgLabel;
    QString imgPath;

    QLineEdit * rtEdit;
    QCheckBox * ac;
    QLineEdit * imgresEdit;
    QLineEdit * frameRateEdit;

    QLineEdit * docNarrEdit;
    QLineEdit * docTopicEdit;

    QTextEdit * cast;
    QComboBox * genre;
    QComboBox * rating;

    QLineEdit * tvSeasonEdit;
    QLineEdit * tvEpisodeEdit;
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

private slots:
    void modifyItem();
    void selectImg();
};

#endif // EDITWIDGET_H
