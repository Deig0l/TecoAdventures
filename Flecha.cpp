#include "Flecha.h"

//Constructor de figura
Flecha::Flecha(float x, float y) : x_origen(x), y_origen(y) {}
//Constructor de figura con color
Flecha::Flecha(float x, float y, ListaColores c) : x_origen(x), y_origen(y), color(c) {}
//Constructor de figura
Flecha::Flecha(float x, float y, float s) : x_origen(x), y_origen(y), size(s) {}
//Constructor de figura con color
Flecha::Flecha(float x, float y, float s, ListaColores c) : x_origen(x), y_origen(y), size(s), color(c) {}

// Constructor de FlechaUP
FlechaUP::FlechaUP(float x, float y) : Flecha(x, y) {}
// Constructor de FlechaUP con color
FlechaUP::FlechaUP(float x, float y, ListaColores c) : Flecha(x, y, c) {}
// Constructor de FlechaDOWN
FlechaUP::FlechaUP(float x, float y, float s) : Flecha(x, y, s) {}
// Constructor de FlechaDOWN con color
FlechaUP::FlechaUP(float x, float y, float s, ListaColores c) : Flecha(x, y, s, c) {}

float FlechaUP::getY() /*const*/ {
	return y_origen;
}

void FlechaUP::setY(float new_y) /*const*/ {
	this->y_origen = new_y;
}

void FlechaUP::incY(float velocidad) /*const*/ {
	this->y_origen += velocidad;
}

bool FlechaUP::getMover() {
	return mover;
}

void FlechaUP::setMover(bool b) {
	this->mover = b;
}

void FlechaUP::dibujar() /*const*/ {
	asignarColor(color);
	/*Rectangulo rect(60, 50, 25 + x_origen, y_origen);
	rect.dibujar();
	Triangulo tri(110, 60, x_origen, 50 + y_origen);
	tri.dibujar();*/
	Rectangulo rect(6 * size, 5 * size, (2.5 * size) + x_origen, y_origen);
	rect.dibujar();
	Triangulo tri(11 * size, 6 * size, x_origen, (5 * size) + y_origen);
	tri.dibujar();
}

// Constructor de FlechaDOWN
FlechaDOWN::FlechaDOWN(float x, float y) : Flecha(x, y) {}
// Constructor de FlechaDOWN con color
FlechaDOWN::FlechaDOWN(float x, float y, ListaColores c) : Flecha(x, y, c) {}
// Constructor de FlechaDOWN
FlechaDOWN::FlechaDOWN(float x, float y, float s) : Flecha(x, y, s) {}
// Constructor de FlechaDOWN con color
FlechaDOWN::FlechaDOWN(float x, float y, float s, ListaColores c) : Flecha(x, y, s, c) {}

//void FlechaDOWN::incY() /*const*/ {
//	this->y_origen = y_origen++;
//}

float FlechaDOWN::getY() {
	return y_origen;
}

void FlechaDOWN::setY(float new_y) {
	this->y_origen = new_y;
}

void FlechaDOWN::incY(float velocidad) {
	this->y_origen += velocidad;
}

bool FlechaDOWN::getMover() {
	return mover;
}

void FlechaDOWN::setMover(bool b) {
	this->mover = b;
}

void FlechaDOWN::dibujar() {
	asignarColor(color);
	Rectangulo rect(6 * size, 5 * size, (2.5 * size) + x_origen, (6 * size) + y_origen);
	rect.dibujar();
	glBegin(GL_TRIANGLES);
	glVertex2f(0 + x_origen, (6 * size) + y_origen); // Vértice superior izquierdo
	glVertex2f((11 * size) + x_origen, (6 * size) + y_origen); // Vértice superior derecho
	glVertex2f((5.5 * size) + x_origen, 0 + y_origen); // Vértice inferior
	glEnd();
}

// Constructor de FlechaLEFT
FlechaLEFT::FlechaLEFT(float x, float y) : Flecha(x, y) {}
// Constructor de FlechaDOWN con color
FlechaLEFT::FlechaLEFT(float x, float y, ListaColores c) : Flecha(x, y, c) {}
// Constructor de FlechaDOWN
FlechaLEFT::FlechaLEFT(float x, float y, float s) : Flecha(x, y, s) {}
// Constructor de FlechaDOWN con color
FlechaLEFT::FlechaLEFT(float x, float y, float s, ListaColores c) : Flecha(x, y, s, c) {}

float FlechaLEFT::getY() /*const*/ {
	return y_origen;
}

void FlechaLEFT::setY(float new_y) /*const*/ {
	this->y_origen = new_y;
}

void FlechaLEFT::incY(float velocidad) /*const*/ {
	this->y_origen += velocidad;
}

bool FlechaLEFT::getMover() {
	return mover;
}

void FlechaLEFT::setMover(bool b) {
	this->mover = b;
}

void FlechaLEFT::dibujar() /*const*/ {
	asignarColor(color);
	Rectangulo rect(5 * size, 6 * size, (6 * size) + x_origen, (2.5 * size) + y_origen);
	rect.dibujar();
	glBegin(GL_TRIANGLES);
	glVertex2f((6 * size) + x_origen, (11 * size) + y_origen); // Vértice superior
	glVertex2f(0 + x_origen, (5.5 * size) + y_origen); // Vértice medio
	glVertex2f((6 * size) + x_origen, y_origen); // Vértice inferior
	glEnd();
}

// Constructor de FlechaRIGHT
FlechaRIGHT::FlechaRIGHT(float x, float y) : Flecha(x, y) {}
// Constructor de FlechaDOWN con color
FlechaRIGHT::FlechaRIGHT(float x, float y, ListaColores c) : Flecha(x, y, c) {}
// Constructor de FlechaDOWN
FlechaRIGHT::FlechaRIGHT(float x, float y, float s) : Flecha(x, y, s) {}
// Constructor de FlechaDOWN con color
FlechaRIGHT::FlechaRIGHT(float x, float y, float s, ListaColores c) : Flecha(x, y, s, c) {}

float FlechaRIGHT::getY() /*const*/ {
	return y_origen;
}

void FlechaRIGHT::setY(float new_y) /*const*/ {
	this->y_origen = new_y;
}

void FlechaRIGHT::incY(float velocidad) /*const*/ {
	this->y_origen += velocidad;
}

bool FlechaRIGHT::getMover() {
	return mover;
}

void FlechaRIGHT::setMover(bool b) {
	this->mover = b;
}

void FlechaRIGHT::dibujar() /*const*/ {
	asignarColor(color);
	Rectangulo rect((5 * size), (6 * size), x_origen, (2.5 * size) + y_origen);
	rect.dibujar();
	glBegin(GL_TRIANGLES);
	glVertex2f((5 * size) + x_origen, (11 * size) + y_origen); // Vértice superior
	glVertex2f((11 * size) + x_origen, (5.5 * size) + y_origen); // Vértice medio
	glVertex2f((5 * size) + x_origen, y_origen); // Vértice inferior
	glEnd();
}