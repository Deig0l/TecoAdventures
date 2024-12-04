#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

class Mapa {
public:
    Mapa(GestorRecursos* gestor);
    void init();  // M�todo de inicializaci�n para cargar im�genes
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1,
        const std::string& nombre2, const std::string& ruta2,
        const std::string& nombre3, const std::string& ruta3);
    void renderizar();
private:
    GestorRecursos* gestorRecursos;
    std::vector<std::string> imagenes;
    int indiceActual;
};
