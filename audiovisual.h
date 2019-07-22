/*
                AudioVisual
                    
    SerieTV         Film        Documentario
    
*/
#ifndef AUDIOVISUAL_H
#define AUDIOVISUAL_H

#include <string>
#include <vector>

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class AudioVisual{ 
public:
    static const std::vector<std::string> Rating;
    static const std::vector<std::string> Genre;

private: //-----campi dati-----
    std::string title;
    std::string description; //plot
    unsigned int release_date; // data
    std::string director;
    bool favorite; // contenuto nei preferiti
    //immagine
protected:
    int running_time; //durata
    bool audio_compression; //perdita di informazioni, se compresso
    unsigned int image_resolution;//video -> 4k, 144p etc in pixel
    unsigned int fps; //frame per secondo
public:
    //--------costruttori------
    AudioVisual(std::string = "None", std::string = "No description", unsigned int = 0, std::string = "None", bool = false, int = 0, bool = true, unsigned int = 0, unsigned int = 0);

    //------distruttore----
    virtual ~AudioVisual() = default;
        
    //--------confronto-----
    virtual bool operator==(const AudioVisual&) const;
    bool operator!=(const AudioVisual&) const;

    //---------metodo per la copia profonda----
    virtual AudioVisual* clone() const =0;

    //---------metodi virtuali puri------------
    virtual int getTotalRunningTime() const =0;
    virtual std::string getType() const =0;
    virtual bool getQuality() const =0;
    virtual bool matureContent() const =0;

    //static AudioVisual* unserialize(QXmlStreamReader&);
    //virtual void serialize(QXmlStreamWriter&) const = 0;

    //getter & setter
    bool isFavorite() const;
    std::string getTitle() const;
    std::string getDescription() const;
    unsigned int getRelease_date() const;
    std::string getDirector() const;
    int getRunning_time() const;
    bool isAudioComp() const;
    unsigned int getImage_resolution() const;
    unsigned int getFps() const;
};

#endif //AUDIOVISUAL_H
