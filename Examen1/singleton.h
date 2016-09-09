/*
FACTORY builder
clone
singleton
iterator
*/

#ifndef singleton_singleton_h
#define singleton_singleton_h

#include <iostream>
#include <string>

using namespace std;

class Product
{

public:
    string tipo;
    string sucursal;
    string getDatos(){
        return tipo + "\t" + sucursal + "\n";
    }
    virtual void batido() = 0;
    virtual void amasado() = 0;
    virtual void horneado() = 0;
    virtual void decorado() = 0;
    virtual void empacado() = 0;
    //virtual Personaje* clonar() = 0;

};

template <class SubClase>
class ClonPastel : public Product
{
public:
    virtual Product* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};


class tresLeches : public Product
{

    friend class ConcreteCreator;

    void batido() { cout << " Batiendo pastel de tres leches\n"; }
    void amasado() { cout << " Amasando pastel de tres leches\n"; }
    void horneado() { cout << " Horneando pastel de tres leches\n"; }
    void decorado() { cout << " Decorando pastel de tres leches\n"; }
    void empacado() { cout << " Empacado pastel de tres leches\n"; }

private:
    tresLeches(){}
};

class sacher : public Product
{
    friend class ConcreteCreator;

    void batido() { cout << " Batiendo pastel sacher\n"; }
    void amasado() { cout << " Amasando pastel sacher\n"; }
    void horneado() { cout << " Horneando pastel sacher\n"; }
    void decorado() { cout << " Decorando pastel sacher\n"; }
    void empacado() { cout << " Empacado pastel sacher\n"; }

private:

    sacher(){};

};

class imposible : public Product
{
    friend class ConcreteCreator;

    void batido() { cout << " Batiendo pastel imposible\n"; }
    void amasado() { cout << " Amasando pastel imposible\n"; }
    void horneado() { cout << " Horneando pastel imposible\n"; }
    void decorado() { cout << " Decorando pastel imposible\n"; }
    void empacado() { cout << " Empacado pastel imposible\n"; }

private:
    imposible(){};
};

class Creator
{

public:

    virtual Product* factoryMethod(int) = 0;

    Product* createProduct(int tipo, int sucursal)
    {
        Product* myProduct = factoryMethod(tipo);
        if (tipo == 1)
            myProduct->tipo = "Tres leches";
        else if (tipo == 2)
            myProduct->tipo = "Sacher";
        else if (tipo == 3)
            myProduct->tipo = "imposible";
        if (sucursal == 1)
            myProduct->sucursal = "Aguascalientes";
        else if (sucursal == 2)
            myProduct->sucursal = "D.F.";
        else
            myProduct->sucursal = "Undefined";

        myProduct->batido();
        myProduct->amasado();
        myProduct->horneado();
        myProduct->decorado();
        myProduct->empacado();
        // Regresar el producto
        return myProduct;
    }
};

class ConcreteCreator : public Creator
{

public:

    Product* factoryMethod(int tipo){
        if (tipo == 1)
            return new tresLeches;
        else if (tipo == 2)
            return new sacher;
        else if (tipo == 3)
            return new imposible;
        else
            std::cout << "Lo sentimos, opción no disponible.\n";

        return nullptr;

    }

    static ConcreteCreator* GetInstance(){
        static ConcreteCreator* instance = new ConcreteCreator;
        return instance;

    }

private:

    ConcreteCreator(){};
};

#endif
