#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <glew.h>

#ifndef UTILFUNC
#define UTILFUNC

#ifdef NDEBUG
#define ASSERT(condition,printstatement)  if(!condition){ printf(printstatement); exit(1); }
#else
#define ASSERT(condition,printstatement)  if(!condition){ printf(printstatement); assert(condition); }
#endif

namespace TrainingGL
{
    class Util
    {
    public:
        static void GLErrorAssert()
        {
            GLint err = glGetError();
            if (err == GL_NO_ERROR)
                return;

            printf("DW_ERROR: OpenGL error encountered! Details follow...\n");
            switch(err)
            {
                case GL_INVALID_ENUM:
                    printf("INVALID ENUM Error: "
                           "An unacceptable value is specified for an enumerated argument."
                           "The offending command is ignored and has no other side effect "
                           "than to set the error flag.\n");
                    break;

                case GL_INVALID_VALUE:
                    printf("INVALID VALUE Error: "
                           "A numeric argument is out of range."
                           "The offending command is ignored and has no other side effect "
                           "than to set the error flag.\n");
                    break;

                case GL_INVALID_OPERATION:
                    printf("INVALID OPERATION Error "
                           "The specified operation is not allowed in the current state. "
                           "The offending command is ignored and has no other side effect "
                           "than to set the error flag.\n");
                    break;

                case GL_STACK_OVERFLOW:
                    printf("STACK OVERFLOW Error: "
                           "This command would cause a stack overflow. "
                           "The offending command is ignored and has no other side effect "
                           "than to set the error flag.\n");
                    break;

                case GL_STACK_UNDERFLOW:
                    printf("STACK UNDERFLOW Error: "
                           "This command would cause a stack underflow. "
                           "The offending command is ignored and has no other side effect "
                           "than to set the error flag.\n");
                    break;

                case GL_OUT_OF_MEMORY:
                    printf("OUT OF MEMORY Error: "
                           "There is not enough memory left to execute the command."
                           "The state of the GL is undefined, except for the state of the error flags,"
                           "after this error is recorded.\n");
                    break;

                case GL_TABLE_TOO_LARGE:
                    printf("TABLE TOO LARGE Error: "
                           "The specified table exceeds the implementation's maximum supported table size."
                           "The offending command is ignored and has no other side effect than to set"
                           "the error flag.\n");
                    break;

                default:
                    printf("Undocumented OpenGL error!\n");
                    break;
            }

            assert(false);
        }
    };
}
#endif  //UTILFUNC
