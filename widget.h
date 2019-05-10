#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class Widget : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *internalUpperHorizontalLayout;
    QLabel *nickName;
    QLabel *proPic;
    QLabel * totalTime;
    QHBoxLayout *internalLowerHorizontalLayout;
    QPushButton *showAddDialog;
    QPushButton *exit;
    QSize sizeHint() const override;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void showDialog();
};

#endif // WIDGET_H
