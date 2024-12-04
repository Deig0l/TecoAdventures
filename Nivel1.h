#pragma once
#include "GestorDeRecursos.h"
#include <GL/glut.h>
#include <string>
#include <vector>

//void initNivel1();       // Inicializa los recursos para el nivel 1
//void renderizarNivel1();     // Renderiza el nivel 1
//void updateNivel1();

class Nivel1 {
public:
    Nivel1(GestorRecursos* gestor);
    void initNivel1();  // Método de inicialización para cargar imágenes
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1);
    void renderizarNivel1();
private:
    GestorRecursos* gestorRecursos;
    std::vector<std::string> imagenes;
    int indiceActual;
};