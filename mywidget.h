#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>


class MainWidget : public QWidget {
       Q_OBJECT

private:
    QHBoxLayout *internalUpperHorizontalLayout;
    QLabel *nickName;
    QLabel *proPic;
    QLabel * totalTime;

    QLineEdit* searchbar;
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

#endif // MYWIDGET_H
