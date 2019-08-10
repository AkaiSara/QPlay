#ifndef DOCUMENTARY_H
#define DOCUMENTARY_H

#include "audiovisual.h"

class Documentary: public AudioVisual{
    private:
        std::string narrator;
        std::string topic; //scientifico, storico, naturalistico, biografia
    public:
        Documentary(std::string, std::string, unsigned int, std::string, bool, int, bool, unsigned int, unsigned int, std::string, std::string);

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Documentary() override;

        virtual Documentary* clone() const override;

        virtual int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        //getter n setter
        std::string getNarrator() const;
        std::string getTopic() const;

        void setNarrator(std::string);
        void setTopic(std::string);
};

#endif
