#pragma once
#ifndef NIVEL_H
#define NIVEL_H

#include <vector>
#include <string>

#include <GL/glut.h>
#include <windows.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "Flecha.h"
#include "Colores.h"
#include <iostream>
#include <string> // for string and to_string()
#include "GestorDeRecursos.h"
#include "Secuencia.h"
using namespace std;

void inicializarFlechas();
void crearNivel(int n);
void inicializacionNivel(void);
void writeBitmapString(void* font, const char* string);
void mostrarNivel(void);
void escribirPuntuacion();
void dibujarFlechas();
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
void finishLevel(int);
void idle();
void controlesJuego(unsigned char key, int x, int y);
void controlesEspecial(int key, int x, int y);

void cargarImagenes(const std::string& nombre1, const std::string& ruta1,
    const std::string& nombre2, const std::string& ruta2,
    const std::string& nombre3, const std::string& ruta3);
void mostrarFondo(int niveles);

#endif