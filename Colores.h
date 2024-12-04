#pragma once
#ifndef COLORES_H
#define COLORES_H
#include <GL/glut.h>

enum ListaColores {
    BLACK, WHITE, RED, GREEN, BLUE, LBLUE, YELLOW, MAGENTA, CYAN, GREY, LGREY, DGREY
};

void asignarColor(ListaColores color);

#endif
