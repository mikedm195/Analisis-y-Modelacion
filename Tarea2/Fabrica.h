class Fabrica{
public:
    virtual Computadora* factoryMethod(int)=0;

    Computadora* createProduct(int tipo){
        Computadora* myProduct = factoryMethod(tipo);
        myProduct->crear();
        return myProduct;
    }
};

class ConcreteFabrica : public Fabrica{
    Computadora* factoryMethod(int tipo){
        if(tipo==1)
        return new Desktop;
        else
        return new Laptop;
    }
};
