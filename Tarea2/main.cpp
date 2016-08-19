#include <stdio.h>
#include "Computadora.h"
#include "Fabrica.h"

using namespace std;

int main(){
    
    Fabrica* fabrica = new ConcreteFabrica();
    Computadora* miProducto = fabrica->createProduct(1);

    return 0;
}
