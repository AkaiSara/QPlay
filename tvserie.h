#ifndef TVSERIE_H
#define TVSERIE_H

#include "audiovisual.h"
#include <string>

class TvSerie : public AudioVisual{
    private:
        unsigned int season;
        unsigned int episode;
        std::string cast;
        Genre genre; //enum Genere
        bool ended; //serie conclusa
        Rating rating; //enum Rating
    protected:
    public:
        //--------costruttori------
        TvSerie(std::string, std::string, unsigned int, std::string, std::string, bool, unsigned int = 1, unsigned int = 1, std::string = "None", Genre = Unknown, bool = true, Rating = All);

        //---------metodo per la copia profonda----
        virtual TvSerie* clone() const ;
        
        //------distruttore----
        virtual ~TvSerie();
};

#endif 
