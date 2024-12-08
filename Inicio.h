#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

class Inicio {
private:
    GestorRecursos* gestorRecursos; // Puntero al gestor de recursos
    std::vector<std::string> imagenes; // Nombres de las imágenes cargadas
    int indiceActual; // Índice de la imagen actual
    unsigned int tiempoAnterior; // Tiempo de la última actualización
    unsigned int intervalo; // Intervalo entre cambios de imagen en milisegundos

public:
    Inicio(GestorRecursos* gestor, unsigned int intervaloMs = 500);
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1,
        const std::string& nombre2, const std::string& ruta2);
    void alternarImagen();
    void renderizar();
};