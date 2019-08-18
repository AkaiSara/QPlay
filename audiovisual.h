/*
                AudioVisual
                    
    SerieTV         Film        Documentario
    
*/
#ifndef AUDIOVISUAL_H
#define AUDIOVISUAL_H

#include <string>
#include <vector>

class AudioVisual{ 
public:
    static const std::vector<std::string> Rating;
    static const std::vector<std::string> Genre;

private: //-----campi dati-----
    std::string title;
    std::string description;
    unsigned int release_date;
    std::string director;
    bool favorite;
    std::string pathImg;
protected:
    unsigned int running_time;
    bool audio_compression; //perdita di informazioni, se compresso
    unsigned int image_resolution;//video -> 4k, 144p etc in pixel
    unsigned int fps; //frame per secondo
public:
    //--------costruttori------
    AudioVisual(std::string, std::string, unsigned int, std::string, bool, std::string, unsigned int, bool, unsigned int, unsigned int);

    //------distruttore----
    virtual ~AudioVisual();
        
    //--------confronto-----
    virtual bool operator==(const AudioVisual&) const;
    bool operator!=(const AudioVisual&) const;

    //---------metodo per la copia profonda----
    virtual AudioVisual* clone() const =0;

    //---------metodi virtuali puri------------
    virtual unsigned int getTotalRunningTime() const =0;
    virtual std::string getType() const =0;
    virtual bool isHighQuality() const =0;
    virtual bool matureContent() const =0;

    //getter & setter
    bool isFavorite() const;
    std::string getPath() const;
    std::string getTitle() const;
    std::string getDescription() const;
    unsigned int getRelease_date() const;
    std::string getDirector() const;
    unsigned int getRunning_time() const;
    bool isAudioComp() const;
    unsigned int getImage_resolution() const;
    unsigned int getFps() const;

    void setFavorite(const bool);
    void setPath(const std::string &);
    void setTitle(const std::string &);
    void setDescription(const std::string &);
    void setRelease_date(const unsigned int);
    void setDirector(const std::string &);
    void setRunning_time(const unsigned int);
    void setAudioComp(const bool);
    void setImage_resolution(const unsigned int);
    void setFps(const unsigned int);
};


#endif //AUDIOVISUAL_H
