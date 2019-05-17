#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mywidget.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QMenu * fileMenu;
    QAction * openAct;
    QAction * saveAct;
    QAction * exitAct;
    QMenu * toolMenu;
    QAction * addAct;
    QAction * editAct;
    QAction * removeAct;
    MainWidget * myWidget;
public:
    MainWindow();
    QSize sizeHint() const override;
    ~MainWindow() override;
private slots:
    void openFile();
    void saveFile();
};

#endif // MAINWINDOW_H
