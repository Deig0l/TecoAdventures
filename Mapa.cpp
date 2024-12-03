#include "Mapa.h"
#include <iostream>
#include <GL/glut.h>
#include <ctime>

// Constructor
Mapa::Mapa(GestorRecursos* gestor)
    : gestorRecursos(gestor), indiceActual(2) {}

// Método para cargar las dos imágenes
void Mapa::cargarImagenes(const std::string& nombre1, const std::string& ruta1,
    const std::string& nombre2, const std::string& ruta2,
    const std::string& nombre3, const std::string& ruta3){
    gestorRecursos->cargarTextura(nombre1, ruta1.c_str());
    gestorRecursos->cargarTextura(nombre2, ruta2.c_str());
    gestorRecursos->cargarTextura(nombre3, ruta3.c_str());
    imagenes.push_back(nombre1);
    imagenes.push_back(nombre2);
    imagenes.push_back(nombre3);
}

// Método para renderizar la imagen actual
void Mapa::renderizar() {
    GLuint texturaActual = gestorRecursos->obtenerTextura(imagenes[indiceActual]);
    if (texturaActual) {
        glBindTexture(GL_TEXTURE_2D, texturaActual);

        glColor3f(0.0f, 1.0f, 0.0f); // Rojo
        // Dibujar un cuadrado con la textura actual
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-400.0f, -300.0f, 0.0f); // Esquina inferior izquierda
        glTexCoord2f(1.0f, 1.0f); glVertex3f(400.0f, -300.0f, 0.0f);  // Esquina inferior derecha
        glTexCoord2f(1.0f, 0.0f); glVertex3f(400.0f, 300.0f, 0.0f);   // Esquina superior derecha
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-400.0f, 300.0f, 0.0f);  // Esquina superior izquierda
        glEnd();
    }
    else {
        std::cerr << "Error: No se pudo obtener la textura actual para renderizar." << std::endl;
    }
}
