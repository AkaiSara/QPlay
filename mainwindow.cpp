#include "mainwindow.h"

void MainWindow::clearList(){
    model->clearAll();
    emit listChanged(model->getList());
}

void MainWindow::addItem(AudioVisual * i){
    model->add(*i);
    emit listChanged(model->getList());
}


MainWindow::MainWindow(): model(new Model()){
    setMaximumSize(QSize(600,600));

    setWindowTitle(tr("Finestra principale"));
    //setWindowIcon(QIcon(":/icon.svg"));
    myWidget = new MainWidget(this);
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

    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    //----------------[]
}

void MainWindow::openFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::ExistingFile);
    choose.setWindowTitle("Load Lineup");
    choose.setNameFilter("XML file (*.xml)");

    if (choose.exec())
        model->load(choose.selectedFiles()[0].toStdString());
    //list changed
}
void MainWindow::saveFile(){
    QFileDialog choose;

    choose.setFileMode(QFileDialog::AnyFile);
    choose.setWindowTitle("Save Lineup");
    choose.setNameFilter("XML file (*.xml)");

    if (choose.exec())
        model->save(choose.selectedFiles()[0].toStdString());
}

QSize MainWindow::sizeHint() const{
    return QSize(450,350);
}

MainWindow::~MainWindow(){}
