#ifndef DOCUMENTARY_H
#define DOCUMENTARY_H

#include "audiovisual.h"

class Documentary: public AudioVisual{
    private:
        std::string narrator;
        std::string topic;
    public:
        Documentary(const std::string &, const std::string &, unsigned int, const std::string &, bool,const std::string &, unsigned int, bool, unsigned int, unsigned int, const std::string &, const std::string &);

        virtual bool operator==(const AudioVisual&) const override;

        virtual ~Documentary() override;

        virtual Documentary* clone() const override;

        virtual unsigned int getTotalRunningTime() const override;
        virtual std::string getType() const override;
        virtual bool isHighQuality() const override;
        virtual bool matureContent() const override;

        //getter n setter
        std::string getNarrator() const;
        std::string getTopic() const;

        void setNarrator(const std::string &);
        void setTopic(const std::string &);
};

#endif
