#include "Figura.h"

//Constructor de figura
Figura::Figura(float x, float y) : x_origen(x), y_origen(y) {}

// Constructor del Rectángulo
Rectangulo::Rectangulo(double ancho, double alto, float x, float y)
    : Figura(x, y), ancho(ancho), alto(alto) {}

void Rectangulo::dibujar() const {
    glBegin(GL_POLYGON);
    glVertex2f(x_origen, y_origen);
    glVertex2f(x_origen + ancho, y_origen);
    glVertex2f(x_origen + ancho, y_origen + alto);
    glVertex2f(x_origen, y_origen + alto);
    glEnd();
}

//Constructor del Triangulo
Triangulo::Triangulo(double base, double altura, float x, float y)
    : Figura(x, y), base(base), altura(altura) {}

void Triangulo::dibujar() const {
    glBegin(GL_TRIANGLES);
    glVertex2f(x_origen, y_origen); // Vértice inferior izquierdo
    glVertex2f(x_origen + base, y_origen); // Vértice inferior derecho
    glVertex2f(x_origen + (base / 2), y_origen + altura); // Vértice superior
    glEnd();
}