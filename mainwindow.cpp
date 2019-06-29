#include "mainwindow.h"

MainWindow::MainWindow(){
    setWindowTitle(tr("Finestra principale"));
    //setWindowIcon(QIcon(":/icon.svg"));
    myWidget = new MainWidget;
    setCentralWidget(myWidget);

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

    connect(myWidget->getExitBtn(), SIGNAL(clicked()), this, SLOT(close())); //quando il bottone di exit di mywidget viene cliccato chiude anche mainwindow
}

void MainWindow::openFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::ExistingFile);
    choose.setWindowTitle("Load Lineup");
    choose.setNameFilter("XML file (*.xml)");

    /*if (choose.exec())
        model->load(choose.selectedFiles()[0].toStdString());*/
}
void MainWindow::saveFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::AnyFile);
    choose.setWindowTitle("Save Lineup");
    choose.setNameFilter("XML file (*.xml)");

    /*if (choose.exec())
        model->save(choose.selectedFiles()[0].toStdString());*/
}

QSize MainWindow::sizeHint() const{
    return QSize(450,350);
}

MainWindow::~MainWindow(){}
