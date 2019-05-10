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
#include "deepptr.h"

template<class T>
class Container{ //contenitore, double linked list
private:
	class Node{
		public:
		DeepPtr<T> info;
		Node *prev, *next;
        Node(const DeepPtr<T> &, Node* = nullptr, Node* = nullptr); //non serve nessun valore di default per il primo parametro perchè chiama la funzione apposira in DeepPtr
		~Node();
        //operator==
        //operator!=
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

	class Const_Iterator{ //template annidato associato
		friend class Container;
	public:
		Node* pos; //campo dati
		Const_Iterator(Node * = nullptr); //costruttore

		Const_Iterator& operator++(); //prefisso
		Const_Iterator operator++(int); //postfisso
		Const_Iterator& operator--();//prefisso
		Const_Iterator operator--(int); //postfisso

		bool operator==(const Const_Iterator & it) const; //uguaglianza
		bool operator!=(const Const_Iterator & it) const; //disuguaglianza

		T& operator*() const; //dereferenziazione
		T* operator->() const; //accesso a membro
	};

private: //------campi dati contenitore-----
	Node * first; //puntatore al primo nodo
	Node * last; //puntatore all'ultimo nodo
	unsigned int size; //contatore nodi

public:
	//---contenitore----
    Container(); //costruttore di default
    Container(Node* = new Node(), Node* = nullptr, unsigned int = 0); //costruttore
    Container(unsigned int=9, const T & = T());
    Container(unsigned int=0);
	Container(const Container &); //costruttore di copia
	Container& operator=(const Container & c); //assegnazione
	~Container(); //distruttore

	unsigned int getSize() const;
	bool isEmpty() const;

	//-----iteratore-----
	T& front() const;
	T& back() const;
	Iterator begin();
	Const_Iterator begin() const;
	Const_Iterator cbegin() const;
	Iterator end();
	Const_Iterator end() const;
	Const_Iterator cend() const;

    Iterator insert(const Iterator &, const T &);
    void insert(Iterator, unsigned int, const T&);
	void push_back(const T &);
	void push_front(const T &);

	Iterator erase(Iterator);
	Iterator erase(Iterator, Iterator);
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
Container<T>::Node::~Node() {
	delete next;
}

//-----------iteratore-------

template<class T>
Container<T>::Iterator::Iterator(Node * p) : pos(p) {} //costruttore

template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(){ //prefisso
	if(pos != nullptr && pos->next != nullptr)
		pos = pos-> next;
	return *this;
}
template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator++(int){ //postfisso
	Iterator aux(*this);
	operator++(); //++(*this);
	return aux;
}
template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--(){//prefisso
	if(pos != nullptr && pos->prev != nullptr)
		pos = pos->prev;
	return *this;
}
template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator--(int){ //postfisso
	Iterator aux(*this);
	operator--(); //--(*this);
	return aux;
}

template<class T>
bool Container<T>::Iterator::operator==(const Iterator & it) const {
    return pos == it.pos;
}

template<class T>
bool Container<T>::Iterator::operator!=(const Iterator & it) const {
    return !(*this == it);
}

template<class T>
T& Container<T>::Iterator::operator*() const { //dereferenziazione
	if(pos != nullptr)
		return pos->info; //se contiene qualcosa
}

template<class T>
T* Container<T>::Iterator::operator->() const {
	if(pos != nullptr)
		return &(pos->info); //se contiene qualcosa
}

//-----------container------


template<class T>
Container<T>::Container(Node* f, Node* l, unsigned int s): first(f), last(l), size(s) {} //costruttore di default
	
//costruisce c con n copie inizializzate a t
template<class T>
Container<T>::Container(unsigned int size, const T & t){
	Container();
	while(size > 0){
		push_back(t);
		size--;
	}
}

//costruisce c con n elementi con valore di default -> T deve avere un costruttore di default
template<class T>
Container<T>::Container(unsigned int size){
	Container(size, nullptr);
}

template<class T>
Container<T>::Container(const Container & c): first(c.first), last(c.last), size(c.size) {
    if(size == 2){
        first->next = last;
        last->prev = first;
    }
    if(size > 2){
        Node* p = first;
        for(auto cit= c.first->next; cit != c.last; ++cit)
            p = insert(p->next, (*cit)->info);
    }
} //costruttore di copia

//inserisce l'elemento t nella sequenza c prima dell'elemento puntato da it e ritorna un iteratore che punta all'elemento appena inserito
template<class T>
typename Container<T>::Iterator Container<T>::insert(const Iterator & it, const T & t){
    if (*it == nullptr){ //se vuota
        it = new Node(t);
        return it;
    }
    //se non vuota
    Node* aux= new Node(t);
    it->prev.next = aux;
    aux->prev = it->prev;
    it-> prev = aux;
    aux->next = *it;
    return it->prev;
}

//inseriscce n copie dell'elemento t prima dell'elemento puntato da it
template<class T>
void Container<T>::insert(Iterator it, unsigned int n, const T& t){
    for(unsigned int i=0; i<n; i++)
        insert(it,t);
}

template<class T>
void Container<T>::push_front(const T & t){
	insert(cbegin(), t);
} //-> c.insert(c.begin(), t)

template<class T>
void Container<T>::push_back(const T & t){
	insert(cend(), t);
} //-> c.insert(c.end(), t)

// distrugge l'elemento puntato da it e ritorna l'iteratore all'elemento successivo
template<class T>
typename Container<T>::Iterator Container<T>::erase(Iterator it){
    if(*it == nullptr){ //se vuota
        //eccezione, non c'è nulla da eliminare
        return nullptr;
    }
    //se non vuota
    it->prev.next = it->next;
    it->next.prev = it->prev;
    Node * p = *it;
    p->next = nullptr;
    p->prev = nullptr;
    delete p; //altrimenti cancella l'intera lista
}

//distrugge gli elementi nell'intervallo itb - ite, incluso il primo, escluso l'ultimo e ritorna l'elemento successivo all'ultimo rimosso
template<class T>
typename Container<T>::Iterator Container<T>::erase(Iterator itb, Iterator ite){
    while(itb != ite){
        erase(itb);
        itb++;
    }
    return ite;
}

//equivale a erase(c.begin(), c.end())
template<class T>
void Container<T>::clear(){
    erase(begin(), end());
}

template<class T>
void Container<T>::pop_back(){
    erase(--cend());
} //-> c.erase(--c.end())

template<class T>
void Container<T>::pop_front(){
    erase(cbegin());
} //rimuove l'elemento in testa -> c.erase(c.begin())

template<class T>
Container<T>& Container<T>::operator=(const Container & c){
	Container aux(c);
    //DA FARE
	return *this;
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
typename Container<T>::Iterator Container<T>::begin() {
	return Iterator(first);
}

template<class T>
typename Container<T>::Iterator Container<T>::end() {
	return Iterator(nullptr); //last->next
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::begin() const {
	return Const_Iterator(first);
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::end() const {
	return Const_Iterator(last->next);
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::cbegin() const {
	return Const_Iterator(first);
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::cend() const {
	return Const_Iterator(last->next);
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
