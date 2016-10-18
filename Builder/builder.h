#include "aviones.h"

class Builder{
protected:
    Avion* avion;
public:
    void* getAvion(){
        return avion;
    }
    void createAvion(){
        avion = new Avion();
    }
    virtual void buildAlas() = 0;
    virtual void buildMotor() = 0;
    virtual void buildPiloto() = 0;
    virtual void buildNoSerie() = 0;
    virtual void buildMarca() = 0;
};

class BoeingBuilder : public Builder{
public:
    virtual void buildAlas(){
        Alas* alas = new Alas();
        alas->setMarca("Boeing");
        avion->setAlas(alas);
    }
    virtual void buildMotor(){
        Motor* motor = new Motor();
        motor->setMarca(500);
        avion->setMotor(motor);
    }
    virtual void buildPiloto(){
        Piloto* piloto = new Piloto();
        piloto->setNombre("Mike");
        avion->setPiloto(piloto);
    }
    virtual void buildNoSerie(){
        NoSerie* noSerie = new NoSerie();
        noSerie->setMarca("Boeing");
        avion->setNoSerie(noSerie);
    }
    virtual void buildMarca(){
        Marca* marca = new Marca();
        marca->setMarca("Boeing");
        avion->setMarca(marca);
    }
};

class AirBusBuilder : public Builder{

};
