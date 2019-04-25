/*
                AudioVisual
                    
    SerieTV         Film        Documentario
    
*/
#ifndef AUDIOVISUAL_H
#define AUDIOVISUAL_H

#include <string>
#include <chrono>

class AudioVisual{ 
public:
    enum Rating{VM14, VM18, All};
    enum Genre{Action, Adventure, Animation, Comedy, Crime, Drama, Fantasy, Food, Game_Show, Horror, Mystery, Reality, Romance, Science_fiction, Soap, Sport, Talk_show, Thriller, Travel, Unknown, Western};

private: //-----campi dati-----
    std::string title;
    std::string description; //plot
    unsigned int release_date; // data ----- non va bene unsigned int, cambiare
    std::string director;
    bool favorite; // contenuto nei preferiti
    //immagine
protected:
    std::chrono::minutes running_time; //durata
    bool audio_compression; //perdita di informazioni, se compresso
    unsigned int image_resolution;//video -> 4k, 144p etc in pixel
    unsigned int fps; //frame per secondo
public:
    //--------costruttori------
    AudioVisual(std::string = "None", std::string = "No description", unsigned int = 0, std::chrono::minutes = std::chrono::duration<std::chrono::minutes::rep, std::ratio<60,1>>(0), std::string = "None", bool = false, bool = true, unsigned int = 0, unsigned int = 0);

    //------distruttore----
    virtual ~AudioVisual() = default;
        
    //--------confronto-----
    virtual bool operator==(const AudioVisual&) const;
    bool operator!=(const AudioVisual&) const;

    //---------metodo per la copia profonda----
    virtual AudioVisual* clone() const =0;

    //---------metodi virtuali puri------------
    virtual std::chrono::minutes getTotalRunningTime() const =0;
    virtual std::string getType() const =0;
    virtual bool getQuality() const =0;
    virtual bool matureContent() const =0;

    bool isFavorite() const;
};

#endif //AUDIOVISUAL_H
