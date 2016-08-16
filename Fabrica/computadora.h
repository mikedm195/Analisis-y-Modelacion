#include "producto.h"
#include "string.h"

using namespace std;

class Desktop:public Computadora{
	public:
		Desktop(){
            printf("Creando Desktop\n");
        };
};

class Laptop :public Computadora{
    public:
    	Laptop(){
            printf("Creando Laptop\n");
        };
};

class Notebook :public Computadora{
    public:
    	Notebook(){
            printf("Creando Notebook\n");
        };

};

class Tablet :public Computadora{
    public:
    	Tablet(){
            printf("Creando Tablet\n");
        };

};
