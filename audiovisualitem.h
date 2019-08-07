#ifndef AUDIOVISUALITEM_H
#define AUDIOVISUALITEM_H

#include <QWidget>
#include <QPushButton>
#include "audiovisual.h"
#include "deepptr.h"
#include "displaywidget.h"

class AudioVisualItem : public QWidget {
    Q_OBJECT

private:
    DeepPtr<AudioVisual> avPtr;
    QPushButton * editBtn;
    QPushButton * deleteBtn;
    QWidget * parent;

    DisplayWidget * displayWidget;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

public:
    AudioVisualItem(DeepPtr<AudioVisual> , QWidget * = nullptr);

signals:
    void modifyItem(DeepPtr<AudioVisual>);
    void deleteItem(DeepPtr<AudioVisual>);

public slots:

};

#endif // AUDIOVISUALITEM_H
