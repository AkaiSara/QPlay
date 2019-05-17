#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class MainWidget : public QWidget {
       Q_OBJECT

private:
    QHBoxLayout *internalUpperHorizontalLayout;
    QLabel *nickName;
    QLabel *proPic;
    QLabel * totalTime;

    QHBoxLayout *internalLowerHorizontalLayout;
    QPushButton *showAddDialog;
    QPushButton *exitBtn;

    QVBoxLayout *mainLayout;
public:
    MainWidget();

private slots:
    void showDialog();
public slots:
    QPushButton * getExitBtn();
};

#endif // WIDGET_H
