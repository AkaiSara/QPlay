#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QScrollArea>

#include "adddialog.h"
#include "audiovisualitem.h"


class MainWidget : public QWidget {
       Q_OBJECT

private:
    QLabel *nickName;
    QLabel *proPic;
    QLabel * totalTime;

    QLineEdit* searchbar;

    QScrollArea * scrollArea;
    QList<AudioVisualItem *> listWidget;
    QHBoxLayout * listBoxLayout;

    QPushButton *showAddDialog;
    QPushButton *clearListBtn;
    QPushButton *exitBtn;

    AddDialog * addDialog;
    QWidget * parent;

public:
    MainWidget(QWidget * = nullptr);

signals:
    void itemFromDialog(AudioVisual*);

private slots:
    void showDialog();
    void update(Container<DeepPtr<AudioVisual>>);
};

#endif // MAINWIDGET_H
