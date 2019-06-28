#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>

class MainWidget : public QWidget {
       Q_OBJECT

private:
    QHBoxLayout *internalUpperHorizontalLayout;
    QLabel *nickName;
    QLabel *proPic;
    QLabel * totalTime;

    QListWidget * listWidget;

    QHBoxLayout *internalLowerHorizontalLayout;
    QPushButton *showAddDialog;
    QPushButton *exitBtn;

    QVBoxLayout *mainLayout;
public:
    MainWidget();
    QPushButton * getExitBtn();

private slots:
    void showDialog();

};

#endif // WIDGET_H