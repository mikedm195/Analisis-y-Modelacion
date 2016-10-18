#pragma once

#include "Aggregate.h"

template<class T>
class Iterator{
public:
    Iterator(const Aggregate<T>& lista){
        this->lista = lista;
        idx = 0;
    }

    T next(){
        if(hasNext())
            return lista->getElementAt(idx++);
        else
            return NULL;
    }

    bool hasNext(){
        return idx < lista->getSize();
    }

    ~Iterator(){
        delete [] lista;
    }
private:
    Iterator(){

    }
    int idx;
    Aggregate<T>* lista
};
