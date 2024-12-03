#include "GestorDeRecursos.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // Implementación de stb_image solo aquí

//Sirve para cargar imagenes

// Implementación de cargarTextura
GLuint GestorRecursos::cargarTextura(const std::string& nombre, const char* archivo) {
    if (texturas.find(nombre) != texturas.end()) {
        return texturas[nombre]; // Devuelve la textura si ya está cargada
    }

    // Carga la textura
    int width, height, nrChannels;
    unsigned char* data = stbi_load(archivo, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Error al cargar la textura: " << archivo << std::endl;
        return 0;
    }
    else {
        std::cout << "Textura cargada exitosamente: " << archivo << std::endl;
    }

    GLuint texturaID;
    glGenTextures(1, &texturaID);
    glBindTexture(GL_TEXTURE_2D, texturaID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLenum formato = (nrChannels == 4) ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, formato, width, height, 0, formato, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);

    texturas[nombre] = texturaID; // Almacena la textura en el mapa
    return texturaID;
}

// Implementación de obtenerTextura
GLuint GestorRecursos::obtenerTextura(const std::string& nombre) {
    if (texturas.find(nombre) != texturas.end()) {
        return texturas[nombre];
    }
    std::cerr << "Error: La textura " << nombre << " no está cargada." << std::endl;
    return 0;
}

// Implementación de liberarRecursos
void GestorRecursos::liberarRecursos() {
    for (const auto& par : texturas) {
        glDeleteTextures(1, &par.second);
    }
    texturas.clear();
}
