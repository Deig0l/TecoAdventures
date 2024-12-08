#include "Inicio.h"
#include <iostream>
#include <GL/glut.h>
#include <ctime>

// Constructor
Inicio::Inicio(GestorRecursos* gestor, unsigned int intervaloMs)
    : gestorRecursos(gestor), intervalo(intervaloMs), indiceActual(0), tiempoAnterior(0) {}

// M�todo para cargar las dos im�genes
void Inicio::cargarImagenes(const std::string& nombre1, const std::string& ruta1,
    const std::string& nombre2, const std::string& ruta2) {
    gestorRecursos->cargarTextura(nombre1, ruta1.c_str());
    gestorRecursos->cargarTextura(nombre2, ruta2.c_str());
    imagenes.push_back(nombre1);
    imagenes.push_back(nombre2);
}

// M�todo para alternar entre las im�genes
void Inicio::alternarImagen() {
    unsigned int tiempoActual = glutGet(GLUT_ELAPSED_TIME); // Tiempo desde el inicio del programa

    if (tiempoActual - tiempoAnterior >= intervalo) {
        indiceActual = (indiceActual + 1) % imagenes.size(); // Alterna entre 0 y 1
        tiempoAnterior = tiempoActual; // Actualiza el tiempo de la �ltima alternancia
    }
}

// M�todo para renderizar la imagen actual
void Inicio::renderizar() {
    GLuint texturaActual = gestorRecursos->obtenerTextura(imagenes[indiceActual]);
    if (texturaActual) {
        glClear(GL_COLOR_BUFFER_BIT);          // Limpia el buffer de color
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Fondo blanco

        glEnable(GL_TEXTURE_2D);               // Habilita texturas
        glBindTexture(GL_TEXTURE_2D, texturaActual);

        glDisable(GL_BLEND);                   // Aseg�rate de deshabilitar blending
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);     // Color blanco para no alterar la textura

        glBegin(GL_QUADS);                     // Dibuja el cuadrado con la textura
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); // Esquina inferior izquierda
        glTexCoord2f(1.0f, 1.0f); glVertex3f(800.0f, 0.0f, 0.0f);  // Esquina inferior derecha
        glTexCoord2f(1.0f, 0.0f); glVertex3f(800.0f, 640.0f, 0.0f);   // Esquina superior derecha
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 640.0f, 0.0f);  // Esquina superior izquierda
        glEnd();

        glDisable(GL_TEXTURE_2D);              // Deshabilita texturas para limpiar el estado
    }
    else {
        std::cerr << "Error: No se pudo obtener la textura actual para renderizar." << std::endl;
    }
}