//01_02 : 2h
//06_02 : 4h
//15_02 : 3h
//18_02 : 6h
//19_02 : 6h
//20_02 : 6h


//lista<T> : iteratore -> nodo => *it ottengo deepPtr, ossia info del nodo
//			nodo.info = deepPtr
//			deepPtr -> oggetti

template <class T>
class DeepPtr{ //puntatori polimorfi al tipo T
	T* ptr;

	DeepPtr(T* p = nullptr): ptr(p != nullptr ? p->clone() : nullptr) {} //costruttore
	DeepPtr(const DeepPtr & dp) : ptr(dp.ptr != nullptr ? (dp.ptr)->clone() : nullptr) {} //costruttore di copia
	DeepPtr& operator=(const DeepPtr & dp){ //assegnazione profonda
		if(this != &dp){ //se sono uguali non faccio nulla
			if(ptr != nullptr) delete ptr; //svuoto il puntatore se ha qualcosa
			ptr = (dp.ptr != nullptr? (dp.ptr)->clone() : nullptr) ;
		}
		return *this;
	}
	~DeepPtr(){ if(ptr != nullptr) delete ptr; } //distruzione profonda
	T& operator*() const {return *ptr;} //dereferenziazione
	T* operator->() const {return ptr;} //accesso a membro
	bool operator==(const DeepPtr& dp)const {return ptr == dp.ptr ? true : false;} //uguaglianza
	bool operator!=(const DeepPtr& dp) const {return !(dp == *this); } //disuguaglianza
	
	/*
	questi metodi devono essere all'interno delle classi della gerarchia, deepPtr andrà ad invocarli a seconda del puntatore
	virtual ~T() { if (ptr != nullptr ) delete ptr; } //distruttore, richiesto
	T* clone() const { return new T(*this); } //clonazione, richiesta
	*/
};


/*
Ogni classe contenitore C ha:
	C::value_type -> T
	C::iterator
	C::const_iterator
	C::size_type -> distanza fra due iteratori
	C(const C &)
	C& operator=(const C &)
	~C()
	size_type size() const -> ritorna la dimensione del contenitore >= 0
	bool empty() const -> contenitore.size == 0
	size_type max_size() const -> massima dimensione del contenitore
	operator== -> se la size dei due contenitori è la stessa e se ogni elemento è uguale all'altro
*/
template<class T>
class Container{ //contenitore, double linked list
private:
	class node{
		public:
		node(const DeepPtr<T> & t, node* p = nullptr, node* n = nullptr) : info(t), prev(p), next(n) {}//costuttore

		DeepPtr<T> info;
		node *prev, *next;

		//~node() {if(next )}
	};
	
public:
	class iterator{ //template annidato associato
	public:
		node* pos; //campo dati
		iterator(node * p = nullptr) : pos(p) {} //costruttore


		//C::const_iterator cend() const;
		//C::const_iterator cbegin() const;

		//C::iterator begin();
		//C::iterator end(); 
		//C::iterator operator*();
		//C::iterator& operator++(){++p; return *this;};prefisso
		//C::iterator operator++(int){Iteratore aux(*this); operator++(); return aux;}; //postfisso
		//C::iterator& operator--(){--p; return *this;}; //prefisso
		//C::iterator operator--(int){Iteratore aux(*this); operator--(); return aux;}; //postfisso
		//bool operator==(const Iteratore & it) const {return p == it.p}
		//bool operator!=(const Iteratore & it) const {p != it.p}
		//T& operator*() {return *p;}
		
		//-----------posizione----------
		iterator begin(){
			return iterator(first);
		}
		iterator end(){
			return iterator(nullptr);
		}

		//------------ ++/-- --------
		iterator& operator++(){ //prefisso
			++pos; //pos = pos-> next
			return *this;
		}
		iterator operator++(int){ //postfisso
			iterator aux(*this); 
			operator++(); 
			return aux;
		}
		iterator& operator--(){//prefisso
			--pos; 
			return *this;
		}
		iterator operator--(int){ //postfisso
			iterator aux(*this); 
			operator--(); 
			return aux;
		}

		//------------confronto--------
		bool operator==(const iterator & it) const {
			return pos == it.pos;
		}
		bool operator!=(const iterator & it) const {
			return pos != it.pos;
		}

		//---------
		T& operator*() const { //dereferenziazione
			return pos->info;
		}
		T* operator->() const {
			return &(pos->info);
		}
	};
	
private:
//-------------campi Dati Contenitore----
	node * first; //puntatore al primo nodo
	node * last; //puntatore all'ultimo nodo
	unsigned int size; //contatore nodi
//---------------------------

public:
//-------------costruttori---------------
	Container(node* f = nullptr, node* l = nullptr, unsigned int s = 0): first(f), last(l), size(0) {}
	Container(const Container & c): first(c.first), last(c.last), size(c.size) {}
//---------------------------

//-------------distruttore---------------
	~Container(){
		node* head(first);
		while(head){
			node* tmp(head->next);
			delete head;
			head = tmp;
		}
	}
	/*
	~(){
		node * tmp;
		while(first){
			tmp = first;
			first = first->next;
			delete tmp;
		}
		first = last = nullptr;
	}
	*/
//-------------------------------

//------------assegnazione-------
	Container& operator=(const Container & c){
		
	}
//---------------------------

	unsigned int getSize() const {
		return size;
	}
	bool isEmpty() const {
		return (size == 0 && first == nullptr);
	}

	//C(C::siize_type n, C::value_type t) : c(n,t) //costruisce c con n copie inizializzate a t
	//C(C::size_type n) : c(n) //costruisce c con n elementi con valore di default -> T deve avere un costruttore di default

	//inserimento

	//C::iterator insert(C::iterator it, C::value_type t) //inserisce l'elemento t nella sequenza c prima dell'elemento puntato da it e ritorna un iteratore che punta all'elemento appena inserito
	//void insert(C::iterator it, C::size_type n C::value_type t) //inseriscce n copie dell'elemento t prima dell'elemento puntato da it
	
	//void push_back(C::value__type t) -> c.insert(c.end(), t)
	//void push_front(C::value__type t) -> c.insert(c.begin(), t)

	//rimozione

	//C::iterator erase(C::iterator it) // distrugge l'elemento puntato da it e ritorna l'iteratore all'elemento successivo
	//C::iterator erase(C::iterator itb, C::iterator ite) //distrugge gli elementi nell'intervallo itb - ite, incluso il primo, escluso l'ultimo e ritorna l'elemento successivo all'ultimo rimosso
	//void clear() //equivale a erase(c.begin(), c.end())
	
	//void pop_back() -> c.erase(--c.end()) 
	//void pop_front() //rimuove l'elemento in testa -> c.erase(c.begin())

	//void merge(list<T>& x) //se le liste sono ordinate unisce le due liste
	//void reverse() // rovescia l'ordine di memorizzazione degli elementi last = first, first = last
	//void sort() // ordina la lista secondo l'ordinamento < (in modo crescente)

	//operator == != < <= > >=
	//ricerca
	// metodo find()
};

/*https://codefreakr.com/how-is-c-stl-list-implemented-internally/

https://codereview.stackexchange.com/questions/60994/stl-list-implementation

https://codereview.stackexchange.com/questions/158129/doubly-linked-stdlist-simple-implementation



*/




//gerarchia dei tipi
/*
class B{ //classe base, astratta o instanziabile
public:
	B(){} //deve avere il costruttore di default
	B(campo_dati = 0) {}
};

//almeno tre classi derivate
class D: public B{
	D(){} //deve avere il costruttore di default
};
class E: public B{
	E(){} //deve avere il costruttore di default
};
class F: public B{
	F(){} //deve avere il costruttore di default
};

enum Genere{Action, Comedy, Horror, Animation, ...}
enum Rating{T, VM14, VM18, ...}*/
