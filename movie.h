#ifndef MOVIE_H
#define MOVIE_H

#include "audiovisual.h"

class Movie: public AudioVisual{
    private:
        std::string cast; 
        std::string  genre; //enum Genere
        std::string  rating; //enum Rating
    public:
        Movie(std::string, std::string, unsigned int, std::string, bool, int, bool, unsigned int, unsigned int, std::string, std::string, std::string);

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Movie() override;

        virtual Movie* clone() const override;

        virtual int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        std::string getCast() const;
        std::string getGenre() const;
        std::string getRating() const;

        void setCast(std::string);
        void setRating(std::string);
        void setGenre(std::string);
};

#endif
