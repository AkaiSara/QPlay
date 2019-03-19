#ifndef MOVIE_H
#define MOVIE_H

#include "AudioVisual.h"
#include <string>

class Movie: public AudioVisual{
    private:
        std::string cast; 
        Genre genre; //enum Genere
        Rating rating; //enum Rating
        bool collezione; //fa parte di una collezione di film
    protected:
    public:
        //--------costruttori------
        Movie(std::string, std::string, unsigned int, std::string, std::string, bool, std::string = "None", Genre = Unknown, Rating = All, bool = false);

        //---------metodo per la copia profonda----
        virtual Movie* clone() const;

        //------distruttore----
        virtual ~Movie();
};

#endif
