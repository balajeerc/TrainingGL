#include <glew.h>

#include "Util.h"
#include "Mesh.h"

namespace TrainingGL
{
    Mesh::Mesh()
    {

    }

    Mesh::~Mesh()
    {

    }

    void Mesh::load()
    {
        float planeWidth = 10;
        float planeHeight = 10;
        _vertices.push_back(glm::vec3(-planeWidth/2,-planeHeight/2, 0.f));
        _vertices.push_back(glm::vec3(planeWidth/2, -planeHeight/2, 0.f));
        _vertices.push_back(glm::vec3(planeWidth/2,  planeHeight/2, 0.f));
        _vertices.push_back(glm::vec3(-planeWidth/2,  planeHeight/2, 0.f));

        GLuint planeIndices[] =
        {
            0, 3, 1,
            3, 2, 1
        };
        _faceIndices.assign(planeIndices, planeIndices+6);


    }

    void Mesh::prepare()
    {
        //First bind the vertex coordinates
        glGenBuffers(1, &_vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size()*sizeof(float), &_vertices[0], GL_STATIC_DRAW);
        Util::GLErrorAssert();

        //Now bind the indices
        glGenBuffers(1,&_elementBufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _faceIndices.size()*sizeof(GLuint), &_faceIndices[0], GL_STATIC_DRAW);
        Util::GLErrorAssert();

        // bind with 0 so that no buffers are left active/selected until necessary
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}
