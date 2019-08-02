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
#include "exception.h"

template<class T>
class Container{ //contenitore, double linked list
private:
	class Node{
		public:
		T info;
		Node *prev, *next;
        Node(const T & = T(), Node* = nullptr, Node* = nullptr);
		~Node();
        bool operator==(const Node &) const;
        bool operator!=(const Node &) const;
	};
    static Node* copy(Node*, Node*&);
	
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

		bool operator==(const Iterator &) const; //uguaglianza
		bool operator!=(const Iterator &) const; //disuguaglianza

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

		bool operator==(const Const_Iterator &) const; //uguaglianza
		bool operator!=(const Const_Iterator &) const; //disuguaglianza

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
    Container(const Container &); //costruttore di copia
	Container& operator=(const Container &); //assegnazione
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

	void push_back(const T &);
	void push_front(const T &);

	void clear();
    void pop_back();
    void pop_front();

    Iterator search(const T&);
    Const_Iterator search(const T&) const;
};

//--------implementazione-------


//------------node---------

template<class T>
Container<T>::Node::Node(const T & t, Node* p, Node* n) : info(t), prev(p), next(n) {}//costuttore

template<class T>
Container<T>::Node::~Node() {
	if(next != nullptr) 
        delete next;
}

template<class T>
bool Container<T>::Node::operator==(const Node & n) const{
    return (info == n.info);

}

template<class T>
bool Container<T>::Node::operator!=(const Node & n) const{
    return !(n == *this);
}





//-----------iteratore-------






template<class T>
Container<T>::Iterator::Iterator(Node * p) : pos(p) {} //costruttore

template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++(){ //prefisso
    if(pos == nullptr) 
        throw Exception("invalid iterator");
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
    if(pos == nullptr ) 
        throw Exception("invalid iterator");
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
    if(pos == nullptr)
        throw Exception("invalid iterator");
    return pos->info;
}

template<class T>
T* Container<T>::Iterator::operator->() const {
    if(pos == nullptr)
        throw Exception("invalid iterator");
    return  *(pos->info);
}

template<class T>
Container<T>::Const_Iterator::Const_Iterator(Node * p) : pos(p) {} //costruttore

template<class T>
typename Container<T>::Const_Iterator& Container<T>::Const_Iterator::operator++(){ //prefisso
    if(pos == nullptr ) 
        throw Exception("invalid iterator");
    pos = pos-> next;
    return *this;
}
template<class T>
typename Container<T>::Const_Iterator Container<T>::Const_Iterator::operator++(int){ //postfisso
    Iterator aux(*this);
    operator++(); //++(*this);
    return aux;
}
template<class T>
typename Container<T>::Const_Iterator& Container<T>::Const_Iterator::operator--(){//prefisso
    if(pos == nullptr ) 
        throw Exception("invalid iterator");
    pos = pos->prev;
    return *this;
}
template<class T>
typename Container<T>::Const_Iterator Container<T>::Const_Iterator::operator--(int){ //postfisso
    Iterator aux(*this);
    operator--(); //--(*this);
    return aux;
}

template<class T>
bool Container<T>::Const_Iterator::operator==(const Const_Iterator & it) const {
    return pos == it.pos;
}

template<class T>
bool Container<T>::Const_Iterator::operator!=(const Const_Iterator & it) const {
    return !(*this == it);
}

template<class T>
T& Container<T>::Const_Iterator::operator*() const { //dereferenziazione
    if(pos == nullptr)
        throw Exception("invalid iterator");
    return pos->info; 
}

template<class T>
T* Container<T>::Const_Iterator::operator->() const {
    if(pos == nullptr)
        throw Exception("invalid iterator");
    return *(pos->info);
}




//-----------container------

template<class T>
typename Container<T>::Node* Container<T>::copy(Node* f, Node*& l){
    if(!f)
        return l = nullptr;
    Node * tmp = new Node(f->info), * p = tmp;
    while(f->next){
        p->next = new Node(f->next->info, p);
        f = f->next;
        p = p->next;
    }
    l = p;
    return  tmp;
}


template<class T>
Container<T>::Container() : first(nullptr), last(first), size(0) {}

template<class T>
Container<T>::Container(const Container & c): first(nullptr), last(nullptr), size(c.size) {
    first = copy(c.first, last);
} //costruttore di copia

template<class T>
Container<T>& Container<T>::operator=(const Container & c){
    if(this != &c){
        if (first != nullptr) 
            delete first;
        size = c.size;
        first = copy(c.first, last);
    }
    return *this;
}

template<class T>
Container<T>::~Container(){
    delete first; //chiama ~nodo, quindi la cancella tutta
}


template<class T>
void Container<T>::push_front(const T & t){
    if (first == nullptr){
        first = last = new Node(t);
        size = 1;
    }
    else {
        first->prev = new Node(t, nullptr, first);
        first = first->prev;
        size++;
    }
} 

template<class T>
void Container<T>::push_back(const T & t){
    if (first == nullptr) {
        first = last = new Node(t);
        size = 1;
        }
    else {
        last->next = new Node(t, last);
        last = last->next;
        size++;
    }    
} 

template<class T>
void Container<T>::clear(){
    delete first;
    first = last = nullptr;
} 

template<class T>
void Container<T>::pop_back(){
    if(first == nullptr)
        throw Exception("aouifncodsn");
    /* Node * p = last;
    T i = p->info;
    if(first != last){
        last = last->prev;
        p->prev = nullptr;
    }
    first->prev = last->next = nullptr;
    delete p;
    size--;
    return i; */
    Node * p = last;
    last = last->prev;
    if(last) 
        last->next = nullptr;
    else 
        first = nullptr;
    delete p;
} 

template<class T>
void Container<T>::pop_front(){
    if(first == nullptr)
        throw Exception("zxdb");
    Node * p = first;
    first = first->next;
    if(first) 
        first->prev = nullptr;
    else 
        last = nullptr;
    p->next = nullptr;
    delete p;
}
template<class T>
T& Container<T>::front() const {
	return *(first->info);
}

template<class T>
T& Container<T>::back() const {
	return *(last->info);
}

template<class T>
typename Container<T>::Iterator Container<T>::begin() {
	return Iterator(first);
}

template<class T>
typename Container<T>::Iterator Container<T>::end() {
	return Iterator();
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::begin() const {
	return Const_Iterator(first);
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::end() const {
	return Const_Iterator();
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::cbegin() const {
	return Const_Iterator(first);
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::cend() const {
	return Const_Iterator();
}

template<class T>
unsigned int Container<T>::getSize() const {
	return size;
}

template<class T>
bool Container<T>::isEmpty() const { 
	return (size == 0 && first == nullptr);
}

/*--------- ricerca -------*/
template<class T>
typename Container<T>::Iterator Container<T>::search(const T& t){
    Iterator it = begin();
    for(; it != end() && *it != t; it++);
    return it;
}

template<class T>
typename Container<T>::Const_Iterator Container<T>::search(const T& t) const{
    Const_Iterator cit = cbegin();
    for(; cit != cend() && *cit != t; cit++);
    return cit;
}


#endif
