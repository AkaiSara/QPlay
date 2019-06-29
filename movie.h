#ifndef MOVIE_H
#define MOVIE_H

#include "audiovisual.h"

class Movie: public AudioVisual{
    private:
        std::string cast; 
        Genre genre; //enum Genere
        Rating rating; //enum Rating
    public:
        Movie(std::string, std::string, unsigned int, std::string, bool, int, bool, unsigned int, unsigned int, std::string = "None", Genre = Unknown, Rating = All);

        virtual Movie* clone() const override;

        virtual int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Movie() override;

        std::string getCast() const;
        Genre getGenre() const;
        Rating getRating() const;
};

#endif
