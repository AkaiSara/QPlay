/*
                AudioVisual
                    
    SerieTV         Film        Documentario
    
*/
#ifndef AUDIOVISUAL_H
#define AUDIOVISUAL_H

#include <string>

class AudioVisual{ 
public:
    enum Rating{VM14, VM18, All};
    enum Genre{Action, Adventure, Animation, Comedy, Crime, Drama, Fantasy, Food, Game_Show, Horror, Mystery, Reality, Romance, Science_fiction, Soap, Sport, Talk_show, Thriller, Travel, Unknown, Western};
private:
    std::string title;
    std::string description; //plot
    //lingua originale
    //sottotitoli?
    //distributor = netflix, etc..
    //immagine
    unsigned int release_date; // data
    int running_time; //durata
    std::string director;
    std::string producer;
    bool favorite; // contenuto nei preferiti
public:
    //--------costruttori------
    AudioVisual(std::string = "None", std::string = "No description", unsigned int = 0, std::string = "None", std::string = "None", bool = false );

    //------distruttore----
    virtual ~AudioVisual();
        
    //--------confronto-----
    bool operator==(const AudioVisual&) const =0;
    bool operator!=(const AudioVisual&) const =0;

    //---------metodo per la copia profonda----
    virtual AudioVisual* clone() const =0;

    getDurataTotale() const;
    std::string getInfo() const;
    bool isFavorite() const;
};

#endif //AUDIOVISUAL_H
