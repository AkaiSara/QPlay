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
    loadPath.read();
}

void Model::add(const AudioVisual & a) {
    list.push_back(DeepPtr<AudioVisual>(&a));

    QMessageBox msgBox;
    msgBox.setText("Aggiunto con successo.");
    msgBox.exec();
    /*if(!list.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("c'è qualcosa");
        msgBox.exec();
    }*/
}

void Model::remove(){ //da modificare, pop non va bene
    list.pop_back();
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
