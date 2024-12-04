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
    void initNivel1();  // M�todo de inicializaci�n para cargar im�genes
    void cargarImagenes(const std::string& nombre1, const std::string& ruta1);
    void renderizarNivel1();
private:
    GestorRecursos* gestorRecursos;
    std::vector<std::string> imagenes;
    int indiceActual;
};