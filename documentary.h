#ifndef DOCUMENTARY_H
#define DOCUMENTARY_H

#include "audiovisual.h"
#include <string>

class Documentary: public AudioVisual{
    private:
        std::string narrator;
        std::string topic; //scientifico, storico, naturalistico, biografia
    public:
        Documentary(std::string, std::string, unsigned int, std::chrono::minutes, std::string, bool, bool, unsigned int, unsigned int, std::string = "None", std::string = "None");

        virtual Documentary* clone() const override;

        virtual std::chrono::minutes getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool getQuality() const override;
        virtual bool matureContent() const override;

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Documentary() override;
};

#endif
