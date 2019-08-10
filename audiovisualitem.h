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
    QFrame * line;

    DisplayWidget * displayWidget;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

public:
    AudioVisualItem(DeepPtr<AudioVisual> , QWidget * = nullptr, QFrame * = nullptr);
    DeepPtr<AudioVisual> getAvPtr() const;
    void setLine(bool);

signals:
    void editAnItem(DeepPtr<AudioVisual>);
    void deleteAnItem(DeepPtr<AudioVisual>);

public slots:

};

#endif // AUDIOVISUALITEM_H
