#include <stdio.h>

#include <string>

using namespace std;

class Computadora{
	public:
		string tipo;

		Computadora(){};

		void produce();
};

void Computadora::produce(){
    printf("%s\n",tipo);
	printf("selección de componentes\n");
    printf("ensamblado de componentes\n");
    printf("instalación y configuración de Software\n");
	printf("empaquetado del computador\n");
}
