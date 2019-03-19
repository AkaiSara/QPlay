/*
Container<T>
Deve fornire dei metodi: inserimento, rimozione, ricerca.

Iteratori: const iterator per lettura, iterator per lettura scrittura.

Definire un template di classe DeepPtr<T> di puntatori polimorfi “smart” al tipo T.
DeepPtr<T> deve implementare una gestione automatica della memoria “profonda” e polimorfa di puntatori a T richiedendo che T sia
un tipo che supporti la clonazione e la distruziona polimorfa. -> virtual ~T(), T* clone() const, copia profonda, assegnazione profonda
*/ 
#ifndef CONTAINER_H
#define CONTAINER_H
#include "deepPtr.h"

template<class T>
class Container{ //contenitore, double linked list
private:
	class Node{
		public:
		DeepPtr<T> info;
		Node *prev, *next;
		Node(const DeepPtr<T> &, Node* = nullptr, Node* = nullptr);//costuttore
		~Node();
	};
	
public:
	class Iterator{ //template annidato associato
		friend class Container;
	public:
		Node* pos; //campo dati
		Iterator(Node * = nullptr); //costruttore

		Iterator& operator++(); //prefisso
		Iterator operator++(int); //postfisso
		Iterator& operator--();//prefisso
		Iterator operator--(int); //postfisso

		bool operator==(const Iterator & it) const; //uguaglianza
		bool operator!=(const Iterator & it) const; //disuguaglianza

		T& operator*() const; //dereferenziazione
		T* operator->() const; //accesso a membro
	};
private:
	Node * first; //puntatore al primo nodo
	Node * last; //puntatore all'ultimo nodo
	unsigned int size; //contatore nodi
public:
	Container(Node* = nullptr, Node* = nullptr, unsigned int = 0); //costruttore
	Container(unsigned int = 0, const T & = T());
	Container(unsigned int = 0);
	Container(const Container &); //costruttore di copia
	Container& operator=(const Container & c); //assegnazione
	~Container(); //distruttore

	T& front() const;
	T& back() const;
	Iterator begin() const;
	Iterator end() const;

	unsigned int getSize() const;
	bool isEmpty() const;

	Iterator insert(Iterator, T);
	void insert(Iterator, unsigned int, T);
	void push_back(const T &);
	void push_front(const T &);

	Iterator erase(Iterator it);
	Iterator erase(Iterator itb, Iterator ite);
	void clear();
	void pop_back();
	void pop_front();

	//search, find, seek
};
//void merge(list<T>& x) //se le liste sono ordinate unisce le due liste
//void reverse() // rovescia l'ordine di memorizzazione degli elementi last = first, first = last
//void sort() // ordina la lista secondo l'ordinamento < (in modo crescente) -> posso usare la libreria algorithm

//operator == != < <= > >=
//ricerca
//metodo find()



//--------implementazione-------
//------------node---------

template<class T>
Container<T>::Node::Node(const DeepPtr<T> & t, Node* p, Node* n) : info(t), prev(p), next(n) {}//costuttore

template<class T>
Container<T>::Node::~Node() { delete next; }

//-----------iteratore-------

template<class T>
Container<T>::Iterator::Iterator(Node * p) : pos(p) {} //costruttore

template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(){ //prefisso
	pos = pos-> next;
	return *this;
}
template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator++(int){ //postfisso
	Iterator aux(*this);
	operator++();
	return aux;
}
template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--(){//prefisso
	if(pos->prev != nullptr)
		pos = pos->prev;
	return *this;
}
template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator--(int){ //postfisso
	Iterator aux(*this);
	operator--();
	return aux;
}

template<class T>
bool Container<T>::Iterator::operator==(const Iterator & it) const {
	return pos == it.pos;
}

template<class T>
bool Container<T>::Iterator::operator!=(const Iterator & it) const {
	return pos != it.pos;
}

template<class T>
T& Container<T>::Iterator::operator*() const { //dereferenziazione
	return pos->info;
}

template<class T>
T* Container<T>::Iterator::operator->() const {
	return &(pos->info);
}

//-----------container------


template<class T>
Container<T>::Container(Node* f, Node* l, unsigned int s): first(f), last(l), size(s) {} //costruttore di default
	
//costruisce c con n copie inizializzate a t
template<class T>
Container<T>::Container(unsigned int size, const T & t){
	if (size){
		Node * first = new Node(t, nullptr, nullptr);
		size--;
	}
	while(size > 0){

	}
}

//costruisce c con n elementi con valore di default -> T deve avere un costruttore di default
template<class T>
Container<T>::Container(unsigned int size){
	if(size) Node * first = new Node(t);
	while(size > 0){

	}
}

//inserisce l'elemento t nella sequenza c prima dell'elemento puntato da it e ritorna un iteratore che punta all'elemento appena inserito
template<class T>
typename Container<T>::Iterator Container<T>::insert(Iterator it, T t){
	
}

//inseriscce n copie dell'elemento t prima dell'elemento puntato da it
template<class T>
void Container<T>::insert(Iterator it, unsigned int n, T t){}

template<class T>
void Container<T>::push_front(const T & t){} //-> c.insert(c.begin(), t)

template<class T>
void Container<T>::push_back(const T & t){} //-> c.insert(c.end(), t)

// distrugge l'elemento puntato da it e ritorna l'iteratore all'elemento successivo
template<class T>
typename Container<T>::Iterator Container<T>::erase(Iterator it){}

//distrugge gli elementi nell'intervallo itb - ite, incluso il primo, escluso l'ultimo e ritorna l'elemento successivo all'ultimo rimosso
template<class T>
typename Container<T>::Iterator Container<T>::erase(Iterator itb, Iterator ite){}

//equivale a erase(c.begin(), c.end())
template<class T>
void Container<T>::clear(){}

template<class T>
void Container<T>::pop_back(){} //-> c.erase(--c.end())

template<class T>
void Container<T>::pop_front(){} //rimuove l'elemento in testa -> c.erase(c.begin())








template<class T>
Container<T>::Container(const Container & c): first(c.first), last(c.last), size(c.size) {} //costruttore di copia

template<class T>
Container<T>& Container<T>::operator=(const Container & c){

}

template<class T>
Container<T>::~Container(){
	delete first; //chiama ~nodo, quindi la cancella tutta
}

template<class T>
T& Container<T>::front()const {
	return *(first->info);
}

template<class T>
T& Container<T>::back()const {
	return *(last->info);
}

template<class T>
typename Container<T>::Iterator Container<T>::begin() const {
	return Iterator(first);
}

template<class T>
typename Container<T>::Iterator Container<T>::end() const {
	return Iterator(nullptr);
}

template<class T>
unsigned int Container<T>::getSize() const {
	return size;
}

template<class T>
bool Container<T>::isEmpty() const { 
	return (size == 0 && first == nullptr);
}


#endif