#ifndef MOVIE_H
#define MOVIE_H

#include "audiovisual.h"

class Movie: public AudioVisual{
    private:
        std::string cast; 
        std::string  genre;
        std::string  rating;
    public:
        Movie(const std::string &, const std::string &, unsigned int, const std::string &, bool, const std::string &, unsigned int, bool, unsigned int, unsigned int, const std::string &, const std::string &, const std::string &);

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Movie() override;

        virtual Movie* clone() const override;

        virtual unsigned int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool isHighQuality() const override;
        virtual bool matureContent() const override;

        std::string getCast() const;
        std::string getGenre() const;
        std::string getRating() const;

        void setCast(const std::string &);
        void setRating(const std::string &);
        void setGenre(const std::string &);
};

#endif
