#pragma once

#include <vector>

// Math library
#include <glm/glm.hpp>

namespace TrainingGL
{
    class Mesh
    {
    public:
        /// \brief  Constructor
        Mesh();

        /// \brief  Destructor
        ~Mesh();

        /// \brief  Loads mesh data
        void load();

        /// \brief  Prepares the mesh
        /// \detail This sets up/prepares the vertex buffers
        void prepare();

    protected:
        std::vector<glm::vec3> _vertices;
        std::vector<GLuint> _faceIndices;
        std::vector<glm::vec2> _texCoords;

        GLuint _vertexBufferId;
        GLuint _elementBufferId;
    };
}
