#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mywidget.h"
#include "model.h"

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

    /*QMenu * toolMenu;
    QAction * addAct;
    QAction * editAct;
    QAction * removeAct;*/

    MainWidget * myWidget;
public:
    Model * model;
    MainWindow();
    QSize sizeHint() const override;
    ~MainWindow() override;

signals:
    void listChanged(Container<DeepPtr<AudioVisual>>);

private slots:
    void openFile();
    void saveFile();

    void clearList();
    void addItem(AudioVisual*);
    void deleteItem(DeepPtr<AudioVisual>);
    void editItem(DeepPtr<AudioVisual>);
};

#endif // MAINWINDOW_H
