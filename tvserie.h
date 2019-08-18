#ifndef TVSERIE_H
#define TVSERIE_H

#include "audiovisual.h"

class TvSerie : public AudioVisual{
    private:
        unsigned int season;
        unsigned int episode;
        std::string cast;
        std::string genre; //enum Genere
        bool ended; //serie conclusa
        std::string rating; //enum Rating
    public:
        TvSerie(std::string, std::string, unsigned int, std::string, bool, std::string, unsigned int, bool, unsigned int, unsigned int, unsigned int, unsigned int, std::string, std::string, bool, std::string);

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~TvSerie() override;

        virtual TvSerie* clone() const override;
        
        virtual unsigned int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool isHighQuality() const override;
        virtual bool matureContent() const override;

        //getter e setter
        std::string getCast() const;
        std::string getGenre() const;
        std::string getRating() const;
        bool isEnded() const;
        unsigned int getSeason() const;
        unsigned int getEpisode() const;

        void setCast(std::string);
        void setRating(std::string);
        void setGenre(std::string);
        void setEnded(bool);
        void setSeason(unsigned int);
        void setEpisode(unsigned int);
};

#endif 
