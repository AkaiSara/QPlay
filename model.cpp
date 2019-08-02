#include "model.h"

void Model::save(const std::string & path) const {
    Xmlio input = Xmlio(path);
    input.write(list);
}

void Model::load(const std::string & path) {
    Xmlio output = Xmlio(path);
    output.read();
}

void Model::add(const AudioVisual &a) {
    list.push_back(DeepPtr<AudioVisual>(&a));
}
