#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

class Mapa {
private:
    GestorRecursos* gestorRecursos; // Puntero al gestor de recursos
    std::vector<std::string> imagenes; // Nombres de las imágenes cargadas
    int indiceActual; // Índice de la imagen actual

public:
    Mapa(GestorRecursos* gestor);
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1,
        const std::string& nombre2, const std::string& ruta2,
        const std::string& nombre3, const std::string& ruta3);
    void renderizar();
};
