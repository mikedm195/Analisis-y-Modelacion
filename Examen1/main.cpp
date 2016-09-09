#include <iostream>
#include "singleton.h"
#include "iterador.h"

using namespace std;

int main(int argc, const char * argv[]) {

    Creator* creador = ConcreteCreator::GetInstance();
    Product* tresLeches = creador->createProduct(1,1);
    Product* sacher = creador->createProduct(2,2);
    Product* imposible = creador->createProduct(3,2);

    Aggregate<Product*> p;
    p.add(tresLeches);
    p.add(sacher);
    p.add(imposible);
    Iterator<Product*>* i;

    //Muestra todos los productos
    for(i = p.getIterator(); i->hasNext(); )
    {
        cout << (i->next())->getDatos() << endl;
    }

    //busca un pastel en particular
    for(i = p.getIterator(); i->hasNext(); )
    {
        if((i->actual())->tipo == "Tres leches" && (i->actual())->sucursal == "Aguascalientes")
            cout << (i->next())->getDatos() << endl;
        else
            i->next();
    }

    delete i;

    return 1;
}
