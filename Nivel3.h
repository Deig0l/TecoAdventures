#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

class Nivel3 {
public:
    Nivel3(GestorRecursos* gestor);
    void initNivel3();  // M�todo de inicializaci�n para cargar im�genes
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1);
    void renderizarNivel3();
private:
    GestorRecursos* gestorRecursos;
    std::vector<std::string> imagenes;
    int indiceActual;
};

