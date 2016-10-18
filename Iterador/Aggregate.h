#pragma once

#include "Iterator.h"

template<class T>
class Aggregate{
public:
    friend class Iterator<T>;

    Aggregate() : pos(0), lista(new T[size]){}
    void add(T element){
        //validar que hay espacio
        if(size < 10)
            lista[pos++] = element;
    }
    Iterator<T> getIterator(){
        return new Iterator<T>(*this);
    }
    ~Aggregate(){
        delete [] lista;
    }
    T getElementAt(int pos){
        return lista[pos];
    }
    int getSize(){
        return size;
    }
private:
    T* lista;
    int size = 10;
    int pos;
};


//Valgrind
