#include <string>

using namespace std;

class Avion{
private:
    int noSerie;
    string marca;
    string modelo;
    Motor* motor;
    Alas* alas;
public:
    int getNoSerie(){
        return noSerie;
    }
    string getMarca(){
        return marca;
    }·ñĺo0ikpĺ.{ñ-}{}
};

class Motor{
private:
    int noSerie;
    string marca;
    int potencia;
public:
    int getNoSerie(){
        return noSerie;
    }
    string getMarca(){
        return marca;
    }
    int getPotencia(){
        return potencia;
    }
};

class Alas{
private:
    int noSerie;
    string marca;
    int hiperSustentador;
public:
    int getNoSerie(){
        return noSerie;
    }
    string getMarca(){
        return marca;
    }
    int getHiperSustentador(){
        return hiperSustentador;
    }
};

class Piloto{
private:
    string nombre;
public:
    string getNombre(){
        return nombre;
    }
};
