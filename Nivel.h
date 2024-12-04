#pragma once
#ifndef NIVEL_H
#define NIVEL_H

#include <GL/freeglut.h>
#include <windows.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "Flecha.h"
#include "Colores.h"
#include <iostream>
#include <string> // for string and to_string()
using namespace std;

#include "Secuencia.h"

void crearNivel(int n);
void inicializacion(void);
void writeBitmapString(void* font, const char* string);
void mostrar(void);
void escribirPuntuacion();
void dibujarFlechas();
//void dibujarFlechas(Flecha fArray[10], int top);
void obtenerPuntos(float y);
void calificarFlechaLF();
void calificarFlechaUP();
void calificarFlechaDW();
void calificarFlechaRT();
void incTopDW();
void agregarFlechaLF(int n);
void agregarFlechaUP(int n);
void agregarFlechaDW(int n);
void agregarFlechaRT(int n);
void finishGame(int);
void idle();
void controlesJuego(unsigned char key, int x, int y);
void controlesEspecial(int key, int x, int y);

#endif

