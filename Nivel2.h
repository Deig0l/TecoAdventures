#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

class Nivel2 {
public:
    Nivel2(GestorRecursos* gestor);
    void initNivel2();  // Método de inicialización para cargar imágenes
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1);
    void renderizarNivel2();
private:
    GestorRecursos* gestorRecursos;
    std::vector<std::string> imagenes;
    int indiceActual;
};

