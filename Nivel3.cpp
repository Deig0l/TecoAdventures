#include "Nivel3.h"
#include <iostream>
#include <GL/glut.h>
#include <ctime>

//Constructor
Nivel3::Nivel3(GestorRecursos* gestor)
    : gestorRecursos(gestor), indiceActual(0) {}

void Nivel3::initNivel3() {
    //// Inicializa elementos específicos del nivel 1
    //glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fondo azul

    if (imagenes.empty()) {//cargar la imagen y ponerla en el arreglo.
        cargarImagenes("FondoNivel3", "Imagenes/Niveles/BGN3.png");
    }
    imagenes.push_back("FondoNivel3");
}

void Nivel3::renderizarNivel3() {
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
        glEnd();
    }
    else {
        std::cerr << "Error: No se pudo obtener la textura actual para renderizar." << std::endl;
    }
}

void Nivel3::cargarImagenes(const std::string& nombre1, const std::string& ruta1) {
    gestorRecursos->cargarTextura(nombre1, ruta1.c_str());
    imagenes.push_back(nombre1);
}

//void updateNivel1() {
//    // Actualiza el estado del nivel si es necesario
//}
