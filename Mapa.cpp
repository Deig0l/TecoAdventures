#include "Mapa.h"
#include <iostream>
#include <GL/glut.h>
#include <ctime>

// Constructor
Mapa::Mapa(GestorRecursos* gestor)
    : gestorRecursos(gestor), indiceActual(0) {}

void Mapa::initMapa() {
    // Si las imágenes ya están cargadas, no las recargues
    if (imagenes.empty()) {
        cargarImagenes(
            "MapaNivel1", "Imagenes/Mapa/TecMapN1.png",
            "MapaNivel2", "Imagenes/Mapa/TecMapN2.png",
            "MapaNivel3", "Imagenes/Mapa/TecMapN3.png");
    }
    imagenes.push_back("MapaNivel1");
    imagenes.push_back("MapaNivel2");
    imagenes.push_back("MapaNivel3");
}

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
void Mapa::renderizarMapa() {
    // Limpia la pantalla con el color de fondo
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fondo negro
    glClear(GL_COLOR_BUFFER_BIT);

    // Establece el color blanco para evitar modificar la textura
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    GLuint texturaActual = gestorRecursos->obtenerTextura(imagenes[indiceActual]);
    if (texturaActual) {
        glBindTexture(GL_TEXTURE_2D, texturaActual);

        // Dibujar un cuadrado con la textura actual
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); // Esquina inferior izquierda
        glTexCoord2f(1.0f, 1.0f); glVertex3f(800.0f, 0.0f, 0.0f);  // Esquina inferior derecha
        glTexCoord2f(1.0f, 0.0f); glVertex3f(800.0f, 640.0f, 0.0f);   // Esquina superior derecha
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 640.0f, 0.0f);  // Esquina superior izquierda

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glColor3f(1.0,0.0,0.0);
        glRasterPos2f(450,100);
        std::string mensaje = "Nivel seleccionado: " + std::to_string(indiceActual);
        writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, mensaje.c_str());
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glEnd();
    }
    else {
        std::cerr << "Error: No se pudo obtener la textura actual para renderizar." << std::endl;
    }
}

void Mapa::cambiarIndice(int nuevoIndice) {
    if (nuevoIndice >= 0 && nuevoIndice < static_cast<int>(imagenes.size())) {
        indiceActual = nuevoIndice;
    }
    else {
        std::cerr << "Error: Indice fuera de rango. Total de imagenes: " << imagenes.size() << std::endl;
    }
}

void Mapa::siguienteIndice() {
    indiceActual = (indiceActual + 1) % imagenes.size();
}

void Mapa::indiceAnterior() {
    indiceActual = (indiceActual - 1 + imagenes.size()) % imagenes.size();
}

void Mapa::writeBitmapString(void* font, const char* string) {
    const char* c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}