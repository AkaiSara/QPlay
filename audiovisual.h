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
    std::chrono::minutes running_time; //durata
    std::string director;
    bool favorite; // contenuto nei preferiti
	//audio
	//video -> 4k, 144p etc

    //lingua originale
    //sottotitoli?
    //distributor = netflix, etc..
    //immagine
public:
    //--------costruttori------
    AudioVisual(std::string = "None", std::string = "No description", unsigned int = 0, std::string = "None", bool = false );

    //------distruttore----
    virtual ~AudioVisual() = default;
        
    //--------confronto-----
    virtual bool operator==(const AudioVisual&) const =0;
    virtual bool operator!=(const AudioVisual&) const =0;

    //---------metodo per la copia profonda----
    virtual AudioVisual* clone() const =0;

    //---------metodi virtuali puri------------
    virtual std::chrono::minutes getTotalRunningTime() const =0;
    virtual AudioVisual* getType() const =0;
    virtual bool getQuality() const =0;


    bool isFavorite() const;
};

#endif //AUDIOVISUAL_H
