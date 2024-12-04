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
    // Constructor para inicializar la posición de la figura
    Figura(float x, float y);

    // Métodos virtuales puros para calcular área, perímetro y dibujar la figura
    virtual void dibujar() const = 0;

    // Destructor virtual
    virtual ~Figura() {}
};

// Clase derivada para un Rectángulo
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    // Constructor
    Rectangulo(double ancho, double alto, float x, float y);

    // Métodos sobreescritos
    void dibujar() const override;
};

// Clase derivada para un Triángulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    // Constructor
    Triangulo(double base, double altura, float x, float y);

    // Métodos sobreescritos
    void dibujar() const override;
};

#endif

