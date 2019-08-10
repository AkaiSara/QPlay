#include "model.h"
#include <QMessageBox>

Model::Model(){

}

Model::~Model(){

}

void Model::save(const std::string & path) const {
    Xmlio savePath = Xmlio(path);
    savePath.write(list);
}

void Model::load(const std::string & path) {
    Xmlio loadPath = Xmlio(path);
    list = loadPath.read();
}

void Model::add(const AudioVisual & a) {
    list.push_back(DeepPtr<AudioVisual>(&a));

    QMessageBox msgBox;
    msgBox.setText("Aggiunto con successo.");
    msgBox.exec();
}

void Model::remove(DeepPtr<AudioVisual> a){
    list.erase(a);
    QMessageBox msgBox;
    msgBox.setText("Eliminato con successo.");
    msgBox.exec();
    //delete &a fa crashare
}

void Model::edit(DeepPtr<AudioVisual> a, DeepPtr<AudioVisual> b){
    list.swapInfo(a, b); //devo passare il nodo da modificare e la roba da assegnarci
}

void Model::clearAll(){
    list.clear();
    QMessageBox msgBox;
    msgBox.setText("Cancellato con successo.");
    msgBox.exec();
}

Container<DeepPtr<AudioVisual>> Model::getList(){
    return list;
}
