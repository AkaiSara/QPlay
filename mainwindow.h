#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include "adddialog.h"
#include "editwidget.h"
#include "audiovisualitem.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QComboBox>
#include <QScrollArea>
#include <QMessageBox>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QMenu * fileMenu;
    QAction * openAct;
    QAction * saveAct;
    QAction * exitAct;

    QLabel * nickName;
    QLabel * proPic;
    QLabel * totalTime;

    QLineEdit * searchbar;
    QComboBox * searchAttribute;
    QCheckBox * searchCheckBox;
    QList<AudioVisualItem *> listSearchResult;

    QScrollArea * scrollArea;
    QList<AudioVisualItem *> listWidget;
    QHBoxLayout * listBoxLayout;

    QPushButton * showAddDialog;
    QPushButton * clearListBtn;
    QPushButton * exitBtn;

    EditWidget * editWidget;

    QWidget * mainWidget;
public:
    Model * model;
    MainWindow();
    QSize sizeHint() const override;
    ~MainWindow() override;

signals:
    void listChanged();

private slots:
    void openFile();
    void saveFile();

    void openAddDialog();
    void addItem(AudioVisual*);

    void clearList();

    void deleteItem(DeepPtr<AudioVisual>);
    void editItem(DeepPtr<AudioVisual>);

    void update();

    void search();
    void showSearchDetail(const QString &);
};

#endif // MAINWINDOW_H
