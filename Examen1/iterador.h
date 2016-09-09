#ifndef singleton_iterador_h
#define singleton_iterador_h

#include<iostream>

template<class T>
class Iterator;

template<class T>
class Aggregate
{

    T* lista;
    int size;
    int pos;

public:

    friend class Iterator<T>;

    Aggregate(){
        pos = 0;

        size = 10; //Se hace el tamaño estático, se puede establecer una lista
        lista = new T[size];
    }

    void add(T element){
        if(pos < size)
            lista[pos++] = element;
        else
            std::cout << "No hay espacio en el arreglo";
    }

    Iterator<T>* getIterator(){
        return new Iterator<T>(this);
    }

    ~Aggregate(){
        delete [] lista;
    }

    T getElementAt(int pos){
        return lista[pos];
    }

    int getPos(){
        return pos;
    }
};


template<class T>
class Iterator
{

public:

    Iterator(Aggregate<T>* aggregate) : idx(0), aggregate(aggregate){}

    T actual(){
        return aggregate->lista[idx];
    }

    T next(){
        if(hasNext())
            return aggregate->lista[idx++];
        else
            return 0;
    }

    bool hasNext()
    {
        return (idx < aggregate->getPos());
    }
    ~Iterator(){}

private:
    Iterator(){}
    Aggregate<T>* aggregate;
    int idx;
};

#endif
