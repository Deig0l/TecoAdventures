#pragma once
#ifndef FLECHA_H
#define FLECHA_H
#include <GL/freeglut.h>
#include "Figura.h"
#include "Colores.h"

// Clase base abstracta Flecha
class Flecha
{
public:
    float x_origen;
    float y_origen;
    float mover = false;
    float size = 1;
    ListaColores color = GREY;
public:
    // Constructor para inicializar la posición de la figura
    Flecha(float x, float y);

    // Constructor para inicializar la posición de la figura y color
    Flecha(float x, float y, ListaColores c);

    // Constructor para inicializar la posición y size de la figura
    Flecha(float x, float y, float s);

    // Constructor para inicializar la posición de la figura y color
    Flecha(float x, float y, float s, ListaColores c);

    // Destructor virtual
    virtual ~Flecha() {}
};


//Clase derivada para una Flecha hacia arriba
class FlechaUP : public Flecha {
public:
    // Constructor
    FlechaUP(float x, float y);
    // Constructor con color
    FlechaUP(float x, float y, ListaColores c);
    // Constructor para inicializar la posición y size de la figura
    FlechaUP(float x, float y, float s);
    // Constructor para inicializar la posición de la figura y color
    FlechaUP(float x, float y, float s, ListaColores c);

    // Métodos sobreescritos
    float getY() /*const override*/;
    void setY(float new_y) /*const override*/;

    void incY(float velocidad);

    bool getMover();
    void setMover(bool b);

    void dibujar() /*const override*/;
};

//Clase derivada para una Flecha hacia abajo
class FlechaDOWN : public Flecha {
public:
    // Constructor
    FlechaDOWN(float x, float y);
    // Constructor con color
    FlechaDOWN(float x, float y, ListaColores c);
    // Constructor para inicializar la posición y size de la figura
    FlechaDOWN(float x, float y, float s);
    // Constructor para inicializar la posición de la figura y color
    FlechaDOWN(float x, float y, float s, ListaColores c);

    // Métodos sobreescritos
    float getY() /*const override*/;
    void setY(float new_y) /*const override*/;

    void incY(float velocidad);

    bool getMover();
    void setMover(bool b);

    void dibujar() /*const override*/;
};

//Clase derivada para una Flecha hacia la izquierda
class FlechaLEFT : public Flecha {
public:
    // Constructor
    FlechaLEFT(float x, float y);
    // Constructor con color
    FlechaLEFT(float x, float y, ListaColores c);
    // Constructor para inicializar la posición y size de la figura
    FlechaLEFT(float x, float y, float s);
    // Constructor para inicializar la posición de la figura y color
    FlechaLEFT(float x, float y, float s, ListaColores c);

    // Métodos sobreescritos
    float getY() /*const override*/;
    void setY(float new_y) /*const override*/;

    void incY(float velocidad);

    bool getMover();
    void setMover(bool b);

    void dibujar() /*const override*/;
};

//Clase derivada para una Flecha hacia la derecha
class FlechaRIGHT : public Flecha {
public:
    // Constructor
    FlechaRIGHT(float x, float y);
    // Constructor con color
    FlechaRIGHT(float x, float y, ListaColores c);
    // Constructor para inicializar la posición y size de la figura
    FlechaRIGHT(float x, float y, float s);
    // Constructor para inicializar la posición de la figura y color
    FlechaRIGHT(float x, float y, float s, ListaColores c);

    // Métodos sobreescritos
    float getY() /*const override*/;
    void setY(float new_y) /*const override*/;

    void incY(float velocidad);

    bool getMover();
    void setMover(bool b);

    void dibujar() /*const override*/;
};

#endif

