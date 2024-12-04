#pragma once
#ifndef FIGURA_H
#define FIGURA_H
#include <GL/freeglut.h>

// Clase base abstracta Figura
class Figura {
protected:
    float x_origen;
    float y_origen;
public:
    // Constructor para inicializar la posici�n de la figura
    Figura(float x, float y);

    // M�todos virtuales puros para calcular �rea, per�metro y dibujar la figura
    virtual void dibujar() const = 0;

    // Destructor virtual
    virtual ~Figura() {}
};

// Clase derivada para un Rect�ngulo
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    // Constructor
    Rectangulo(double ancho, double alto, float x, float y);

    // M�todos sobreescritos
    void dibujar() const override;
};

// Clase derivada para un Tri�ngulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    // Constructor
    Triangulo(double base, double altura, float x, float y);

    // M�todos sobreescritos
    void dibujar() const override;
};

#endif

