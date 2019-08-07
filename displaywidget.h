#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "deepptr.h"
#include "audiovisual.h"
#include "documentary.h"
#include "movie.h"
#include "tvserie.h"

class DisplayWidget : public QWidget
{
    Q_OBJECT

private:
    DeepPtr<AudioVisual> avPtr;

    QLabel * titolo;
    QLabel * tipo;
    QLabel * anno;
    QLabel * dir;
    QLabel * fav;
    QLabel * tempo;
    QLabel * img;

    QLabel * descr;

    QLabel * fps;
    QLabel * ris;
    QLabel * audio;

    QLabel * narratore;
    QLabel * topic;
    QLabel * cast;
    QLabel * rating;
    QLabel * genere;
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
