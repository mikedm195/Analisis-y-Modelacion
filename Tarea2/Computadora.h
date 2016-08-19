class Computadora{
public:
    virtual void crear() = 0;
};

class Desktop : public Computadora{
private:
    Desktop();
public:
    void crear(){
        printf("Desktop\n");
    	printf("selección de componentes\n");
        printf("ensamblado de componentes\n");
        printf("instalación y configuración de Software\n");
    	printf("empaquetado del computador\n\n");
    }

};

class Laptop : public Computadora{
private:
    Laptop();
public:
    void crear(){
        printf("Laptop\n");
    	printf("selección de componentes\n");
        printf("ensamblado de componentes\n");
        printf("instalación y configuración de Software\n");
    	printf("empaquetado del computador\n\n");
    }
};

class Notebook : public Computadora{
private:
    Notebook();
public:
    void crear(){
        printf("Notebook\n");
    	printf("selección de componentes\n");
        printf("ensamblado de componentes\n");
        printf("instalación y configuración de Software\n");
    	printf("empaquetado del computador\n\n");
    }
};

class Tablet : public Computadora{
private:
    Tablet();
public:
    void crear(){
        printf("Tablet\n");
    	printf("selección de componentes\n");
        printf("ensamblado de componentes\n");
        printf("instalación y configuración de Software\n");
    	printf("empaquetado del computador\n\n");
    }
};
