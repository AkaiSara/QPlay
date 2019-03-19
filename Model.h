#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "AudioVisual.h"

#include <iostream>
using std::cout;

class Model{
public:
    Model();
    Container<AudioVisual> qualcosa;
    void f(){
        for( Container<AudioVisual>::Iterator it = qualcosa.begin() ; it != qualcosa.end(); it++){
            cout << 'k';
        }
    }
};

#endif // MODEL_H
