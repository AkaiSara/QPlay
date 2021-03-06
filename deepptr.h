#ifndef DEEPPTR_H
#define DEEPPTR_H

#include "exception.h"

template <class T>
class DeepPtr{ //puntatori polimorfi al tipo T
	T* ptr;
public:
    explicit DeepPtr(const T* = nullptr); //costruttore
	DeepPtr(const DeepPtr &); //costruttore di copia
	DeepPtr& operator=(const DeepPtr &);
	~DeepPtr();
	T& operator*() const ;
	T* operator->() const ;
	bool operator==(const DeepPtr&) const;
	bool operator!=(const DeepPtr&) const;
};

//----------------[Implementazione]

template<class T>
DeepPtr<T>::DeepPtr(const T* p) : ptr(p != nullptr ? p->clone() : nullptr) {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T> & dp) : ptr(dp.ptr != nullptr ? (dp.ptr)->clone() : nullptr) {}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T> & dp){ //assegnazione profonda
	if(this != &dp){ //se sono uguali non faccio nulla
		if(ptr != nullptr) delete ptr; //svuoto il puntatore se ha qualcosa
        ptr = dp.ptr;
    }
	return *this;
}

template<class T>
DeepPtr<T>::~DeepPtr(){  //distruzione profonda
    if(ptr != nullptr)
        delete ptr;
}

template<class T>
T& DeepPtr<T>::operator*() const { //dereferenziazione
    //if(ptr == nullptr) throw Exception("Invalid pointer");
	return *ptr;
}

template<class T>
T* DeepPtr<T>::operator->() const { //accesso a membro
    if(ptr == nullptr)
        throw Exception("Invalid pointer");
    return ptr;
}

template<class T>
bool DeepPtr<T>::operator==(const DeepPtr<T>& dp) const { //uguaglianza
    if (ptr == nullptr || dp.ptr == nullptr)
        return false;
    if (ptr == dp.ptr)
        return true;
    return *(ptr) == *(dp.ptr);
}

template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr& dp) const { //disuguaglianza
    return !(dp == *this);
}

#endif
