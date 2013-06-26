#include <stdio.h>

#include <glew.h>
#include <freeglut.h>

#include "Shader.h"
#include "AppManager.h"

namespace TrainingGL
{
    AppManager* AppManager::_mainInstance = NULL;

    AppManager::AppManager()
    {
        if(_mainInstance)
        {
            fprintf(stderr, "Error: %s\n", "An app manager instance already exists! Cannot reinstantiate!");
            exit(1);
        }

       _mainInstance = this;
    }

    AppManager::~AppManager()
    {

    }

    void AppManager::initApplication(int argc, char* argv[])
    {
        glutInit(&argc, argv);

        glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(640, 480);

        glutCreateWindow("TrainingGL: Solar System");

        //Print some OpenGL information
        printf("Found OpenGL Version: %s\n", glGetString(GL_VERSION));

        //Initialise extension wrangler
        GLenum glew_status = glewInit();
        if (glew_status != GLEW_OK)
        {
          fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
          exit(1);
        }

        glutDisplayFunc(AppManager::OnDisplay);


        Shader ftShader;
        ftShader.setSources("../data/shaders/Default_VS.glsl",
                            "../data/shaders/Default_FS.glsl");
        ftShader.prepare();

        glutMainLoop();
    }

    void AppManager::update()
    {
        //Clear the buffer with black
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glFrontFace(GL_CW);
        glDisable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glColor3f(1.f, 1.f, 1.f);

        //Swap buffers
        glutSwapBuffers();
    }

    void AppManager::OnDisplay()
    {
        _mainInstance->update();
    }
}
