#include <stdio.h>
#include "Aggregate.h"
#include "Iterator.h"

using namespace std;

class Persona{
public:
    Persona(int edad) : edad(edad){}
    int getEdad(){return edad}
    Persona(){}
    ~Persona();
private:
    int edad;
}


int main(){
    Persona p1(20);
    Persona p2(30);
    Aggregate<Persona> lista;
    lista.add(p1);
    lista.add(p2);

    for(Iterator<Persona> i = lista.getIterator();i.hasNext;)
        printf("%d\n", i.next().getEdad());
    
    return 0;
}
