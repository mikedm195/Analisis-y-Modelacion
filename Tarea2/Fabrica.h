#include <string>

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
        switch (tipo) {
            case 1:
                return new Desktop();
            break;
            case 2:
                return new Laptop();
            break;
            case 3:
                return new Notebook();
            break;
            case 4:
                return new Tablet();
            break;
            defautl:
                printf("No se encontro el tipo\n");
            break;
        }
    }
};
