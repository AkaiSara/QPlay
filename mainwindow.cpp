#include "mainwindow.h"
#include "adddialog.h"

MainWindow::MainWindow(QMainWindow *parent): QMainWindow(parent){
    setWindowTitle(tr("Finestra principale"));
    mainWidget = new MainWidget;
    setCentralWidget(mainWidget);

    //----------------[Menu]
    fileMenu = menuBar()->addMenu(tr("&File"));

    openAct = new QAction(tr("&Open..."), this);
    fileMenu->addAction(openAct);
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAct = new QAction(tr("&Save"), this);
    fileMenu->addAction(saveAct);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));

    fileMenu->addSeparator();

    exitAct = new QAction(tr("&Exit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    //----------------[]
}

void MainWindow::openFile(){}
void MainWindow::saveFile(){}

QSize MainWindow::sizeHint() const{
    return QSize(450,350);
}

MainWindow::~MainWindow(){}
