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
    bool audio_compression;
    unsigned int image_resolution;
    unsigned int fps;
public:
    //--------costruttori------
    AudioVisual(const std::string &, const std::string &, unsigned int, const std::string &, bool, const std::string &, unsigned int, bool, unsigned int, unsigned int);

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

    void setFavorite(bool);
    void setPath(const std::string &);
    void setTitle(const std::string &);
    void setDescription(const std::string &);
    void setRelease_date(unsigned int);
    void setDirector(const std::string &);
    void setRunning_time(unsigned int);
    void setAudioComp(bool);
    void setImage_resolution(unsigned int);
    void setFps(unsigned int);
};


#endif //AUDIOVISUAL_H
