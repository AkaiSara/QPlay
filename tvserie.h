#ifndef TVSERIE_H
#define TVSERIE_H

#include "audiovisual.h"

class TvSerie : public AudioVisual{
    private:
        unsigned int season;
        unsigned int episode;
        std::string cast;
        std::string genre;
        bool ended;
        std::string rating;
    public:
        TvSerie(const std::string &, const std::string &, unsigned int, const std::string &, bool, const std::string &, unsigned int, bool, unsigned int, unsigned int, unsigned int, unsigned int, const std::string &, const std::string &, bool, const std::string &);

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

        void setCast(const std::string &);
        void setRating(const std::string &);
        void setGenre(const std::string &);
        void setEnded(bool);
        void setSeason(unsigned int);
        void setEpisode(unsigned int);
};

#endif 
