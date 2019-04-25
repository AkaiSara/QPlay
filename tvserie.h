#ifndef TVSERIE_H
#define TVSERIE_H

#include "audiovisual.h"

class TvSerie : public AudioVisual{
    private:
        unsigned int season;
        unsigned int episode;
        std::string cast;
        Genre genre; //enum Genere
        bool ended; //serie conclusa
        Rating rating; //enum Rating
    public:
        TvSerie(std::string, std::string, unsigned int, std::chrono::minutes, std::string, bool, bool, unsigned int, unsigned int, unsigned int = 1, unsigned int = 1, std::string = "None", Genre = Unknown, bool = true, Rating = All);

        virtual TvSerie* clone() const override;
        
        virtual std::chrono::minutes getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~TvSerie() override;
};

#endif 
