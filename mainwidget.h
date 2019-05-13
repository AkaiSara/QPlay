#ifndef WIDGET_H
#define WIDGET_H

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
};

#endif // WIDGET_H
