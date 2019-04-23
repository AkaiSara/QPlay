#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "audiovisual.h"

#include <iostream>
#include <chrono>

// std::chrono::duration_cast<std::chrono::hours>(variabile); //conversione
// typedef chrono::duration<chrono::hours::rep, ratio<86400,1>> day; //dichiaro un tipo giorno
// metodo count() per visualizzare il tempo della variabile
/*
using std::cout;

class Model{
public:
    Model();
    Container<AudioVisual> qualcosa;
    void f(){
        for( Container<AudioVisual>::Iterator it = qualcosa.begin() ; it != qualcosa.end(); it++){
            cout << 'k';
        }
    }
};*/

class Model
{
private:
	Container<AudioVisual> list;

	//static const std::vector<std::string> types;
public:
	Model() = default;
	explicit Model(const std::string &,
				   const std::string &);

	void save(const std::string &,
			  const std::string &) const;
	void load(const std::string &,
			  const std::string &);

	void addAudioVisual(const std::string &);
	bool empty() const;

	//static const std::vector<std::string> &getTypes();
};

#endif // MODEL_H
