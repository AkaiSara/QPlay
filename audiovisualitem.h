#ifndef AUDIOVISUALITEM_H
#define AUDIOVISUALITEM_H

#include <QWidget>
#include <QPushButton>
#include "audiovisual.h"
#include "deepptr.h"

class AudioVisualItem : public QWidget {
    Q_OBJECT

private:
    DeepPtr<AudioVisual> avPtr;
    QPushButton * editBtn;
    QPushButton * deleteBtn;
    QWidget * parent;

protected:
    //void mousePressEvent(QMouseEvent *event) override;

public:
    AudioVisualItem(DeepPtr<AudioVisual> , QWidget * = nullptr);

signals:

public slots:

};

#endif // AUDIOVISUALITEM_H
