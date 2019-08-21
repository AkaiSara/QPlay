#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

#include "deepptr.h"
#include "audiovisual.h"
#include "documentary.h"
#include "movie.h"
#include "tvserie.h"

class DisplayWidget : public QWidget {
    Q_OBJECT

private:
    DeepPtr<AudioVisual> avPtr;

    QLabel * title;
    QLabel * type;
    QLabel * year;
    QLabel * dir;
    QLabel * fav;
    QLabel * time;
    QLabel * img;

    QLabel * descr;

    QLabel * frame;
    QLabel * res;
    QLabel * audio;

    QLabel * narrator;
    QLabel * topic;
    QLabel * cast;
    QLabel * rating;
    QLabel * genre;
    QLabel * ep;
    QLabel * st;
    QLabel * end;

    QWidget * parent;
public:
    explicit DisplayWidget(DeepPtr<AudioVisual>, QWidget * = nullptr);

signals:

public slots:
};

#endif // DISPLAYWIDGET_H
