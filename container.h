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
        bool operator==(const Node &) const;
        bool operator!=(const Node &) const;
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
    Container(unsigned int, const T & = T());
    Container(unsigned int);
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

    Iterator search(const T&);
    Const_Iterator search(const T&) const;
};
//void merge(list<T>& x) //se le liste sono ordinate unisce le due liste
//void reverse() // rovescia l'ordine di memorizzazione degli elementi last = first, first = last
//void sort() // ordina la lista secondo l'ordinamento < (in modo crescente) -> posso usare la libreria algorithm


//--------implementazione-------



//------------node---------

template<class T>
Container<T>::Node::Node(const DeepPtr<T> & t, Node* p, Node* n) : info(t), prev(p), next(n) {}//costuttore

template<class T>
Container<T>::Node::~Node() {
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
        return *(pos->info); //se contiene qualcosa
}

template<class T>
T* Container<T>::Iterator::operator->() const {
	if(pos != nullptr)
        return pos->info; //se contiene qualcosa
}

template<class T>
Container<T>::Const_Iterator::Const_Iterator(Node * p) : pos(p) {} //costruttore

template<class T>
typename Container<T>::Const_Iterator& Container<T>::Const_Iterator::operator++(){ //prefisso
    if(pos != nullptr && pos->next != nullptr)
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
    if(pos != nullptr && pos->prev != nullptr)
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
    if(pos != nullptr)
        return *(pos->info); //se contiene qualcosa
}

template<class T>
T* Container<T>::Const_Iterator::operator->() const {
    if(pos != nullptr)
        return &(pos->info); //se contiene qualcosa
}





//-----------container------




template<class T>
Container<T>::Container() : first(nullptr), last(first), size(0) {}
	
//costruisce c con n copie inizializzate a t
template<class T>
Container<T>::Container(unsigned int n, const T & t){
	Container();
    while(n > 0){
		push_back(t);
        n--;
	}
}

//costruisce c con n elementi con valore di default -> T deve avere un costruttore di default
template<class T>
Container<T>::Container(unsigned int n){
    Container(n, T());
}

template<class T>
Container<T>::Container(const Container & c): first(new Node(c.first->info)), last(nullptr), size(c.size) {
    if(c.last == c.first) last = first;
    else{
        Node *aux = c.first->next, *tmp = first;
        while(aux != nullptr){
            tmp->next = new Node(aux->info, tmp);
            aux = aux->next;
            tmp = tmp->next;
        }
        last = tmp;
    }
} //costruttore di copia

//inserisce l'elemento t nella sequenza c prima dell'elemento puntato da it e ritorna un iteratore che punta all'elemento appena inserito
template<class T>
typename Container<T>::Iterator Container<T>::insert(const Iterator & it, const T & t){
    if (first == nullptr){ //se vuota
        last = first = new Node(DeepPtr<T>(&t));
        size = 1;
        return Iterator(first);
    }
    //se non vuota
    Node* aux= new Node(DeepPtr<T>(&t));
    it.pos->prev->next = aux;
    aux->prev = it.pos->prev;
    it.pos-> prev = aux;
    aux->next = it.pos;
    size++;
    return it.pos->prev;
}

//inseriscce n copie dell'elemento t prima dell'elemento puntato da it
template<class T>
void Container<T>::insert(Iterator it, unsigned int n, const T& t){
    for(unsigned int i=0; i<n; i++)
        insert(it,t);
}

template<class T>
void Container<T>::push_front(const T & t){
    insert(begin(), t);
} //-> c.insert(c.begin(), t)

template<class T>
void Container<T>::push_back(const T & t){
    insert(end(), t);
} //-> c.insert(c.end(), t)

// distrugge l'elemento puntato da it e ritorna l'iteratore all'elemento successivo
template<class T>
typename Container<T>::Iterator Container<T>::erase(Iterator it){
    if(first == nullptr){ //se vuota
        //eccezione, non c'è nulla da eliminare
        return nullptr;
    }
    //se non vuota
    it.pos->prev.next = it.pos->next;
    it.pos->next.prev = it.pos->prev;
    Node * p = *it;
    p->next = nullptr;
    p->prev = nullptr;
    delete p; //altrimenti cancella l'intera lista
    size--;
    return it;
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
    erase(--end());
} //-> c.erase(--c.end())

template<class T>
void Container<T>::pop_front(){
    erase(begin());
} //rimuove l'elemento in testa -> c.erase(c.begin())

template<class T>
Container<T>& Container<T>::operator=(const Container & c){
    if(this != &c){
        delete first;
        size = c.size;
        first = new Node(c.first->info);
        Node *aux = c.first->next, *tmp = first;
        while(aux != nullptr){
            tmp->next = new Node(aux->info, tmp);
            aux = aux->next;
            tmp = tmp->next;
        }
        last = tmp;
    }
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
