#ifndef DOCUMENTARY_H
#define DOCUMENTARY_H

#include "AudioVisual.h"
#include <string>

class Documentary: public AudioVisual{
    private:
        std::string narrator;
        std::string topic; //scientifico, storico, naturalistico, biografia
    public:
        //--------costruttori------
        Documentary(std::string, std::string, unsigned int, std::string, bool, std::string = "None", std::string = "None");

        //---------metodo per la copia profonda----
        virtual Documentary* clone() const;

        //------distruttore----
        virtual ~Documentary();
};

#endif
