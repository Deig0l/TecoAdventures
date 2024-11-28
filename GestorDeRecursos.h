#pragma once
#include <map>
#include <string>
#include <GL/glut.h>

class GestorRecursos {
private:
    std::map<std::string, GLuint> texturas; // Almacena las texturas cargadas

public:
    // Carga una textura si no está ya cargada
    GLuint cargarTextura(const std::string& nombre, const char* archivo);

    // Obtiene una textura cargada por nombre
    GLuint obtenerTextura(const std::string& nombre);

    // Libera todos los recursos cargados
    void liberarRecursos();
};
