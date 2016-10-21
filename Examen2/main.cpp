#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Televisoras{
public:
    void mandaNoticiaMVS(string noticia){
        cout << "MVS dice: " << noticia << endl;
    }
    void mandaNoticiaTelevisa(string noticia){
        cout << "Televisa dice: " << noticia << endl;
    }
    void mandaNoticiaTVAzteca(string noticia){
        cout << "TVAzteca dice: " << noticia << endl;
    }
    void mandaNoticiaRadioFormula(string noticia){
        cout << "MVRadioFormulaS dice: " << noticia << endl;
    }
    void mandaNoticiaCNN(string noticia){
        cout << "CNN Noticias dice: " << noticia << endl;
    }
};

class Noticia {
    vector < class Observer * > views;
    string value;
public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(string val) {
        value = val;
        notify();
    }
    string getVal() {
        return value;
    }
    void notify();
};

class Observer {
    Noticia *model;
public:
    Televisoras televisoras;
    Observer(Noticia *mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update() = 0;
protected:
    Noticia *getNoticia() {
        return model;
    }
};

void Noticia::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

class PenaObserver: public Observer {
public:
    PenaObserver(Noticia *mod): Observer(mod){}
    void update() {
        string v = getNoticia()->getVal();
        televisoras.mandaNoticiaMVS(v);
        televisoras.mandaNoticiaTelevisa(v);
        televisoras.mandaNoticiaTVAzteca(v);
        televisoras.mandaNoticiaRadioFormula(v);
    }
};

class HilariaObserver: public Observer {
public:
    HilariaObserver(Noticia *mod): Observer(mod){}
    void update() {
        string v = getNoticia()->getVal();
        televisoras.mandaNoticiaMVS(v);
        televisoras.mandaNoticiaTelevisa(v);
        televisoras.mandaNoticiaTVAzteca(v);
        televisoras.mandaNoticiaRadioFormula(v);
        televisoras.mandaNoticiaCNN(v);
    }
};

class trumpadoresObserver: public Observer {
public:
    trumpadoresObserver(Noticia *mod): Observer(mod){}
    void update() {
        string v = getNoticia()->getVal();
        televisoras.mandaNoticiaMVS(v);
        televisoras.mandaNoticiaTelevisa(v);
        televisoras.mandaNoticiaTVAzteca(v);
        televisoras.mandaNoticiaRadioFormula(v);
        televisoras.mandaNoticiaCNN(v);
    }
};

int main() {
    Noticia nPena;
    Noticia nHilaria;
    Noticia nTrumpadores;
    PenaObserver pena(&nPena);
    HilariaObserver hilaria(&nHilaria);
    trumpadoresObserver trumpadores(&nTrumpadores);
    string menu = "¿Qué desea hacer?\n1)Noticia de Peña\n2)Noticia de Hilaria\n3)Noticia del discurso de los trumpadores\n4)Salir\n\n";
    int opcion = 0;
    string noticia;
    while (opcion != 4){
        std::cout << endl << menu;
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << "\nDame la Noticia: ";
                getline (cin,noticia);
                cout << endl;
                nPena.setVal(noticia);
            break;
            case 2:
                cout << "\nDame la Noticia: ";
                getline (cin,noticia);
                cout << endl;
                nHilaria.setVal(noticia);
            break;
            case 3:
                cout << "\nDame la Noticia: ";
                getline (cin,noticia);
                cout << endl;
                nTrumpadores.setVal(noticia);
            break;
            case 4: cout << "adios\n";
            break;
            default: cout << "no existe eso\n" << endl;
            break;
        }
    }
}
