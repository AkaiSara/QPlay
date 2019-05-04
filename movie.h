#ifndef MOVIE_H
#define MOVIE_H

#include "audiovisual.h"

class Movie: public AudioVisual{
    private:
        std::string cast; 
        Genre genre; //enum Genere
        Rating rating; //enum Rating
        unsigned int collection; //fa parte di una collezione di film
    public:
        Movie(std::string, std::string, unsigned int, std::chrono::minutes, std::string, bool, bool, unsigned int, unsigned int, std::string = "None", Genre = Unknown, Rating = All, unsigned int = 1);

        virtual Movie* clone() const override;

        virtual std::chrono::minutes getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Movie() override;
};

#endif
