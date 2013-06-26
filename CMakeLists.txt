cmake_minimum_required(VERSION 2.8)

project(TrainingGL)

set(CMAKE_CXX_FLAGS "-g -Wall")

#Auto glob any source and headers for the current project
file(GLOB TRAININGGL_HEADERS "include/*.h")
file(GLOB TRAININGGL_SOURCES "src/*.cpp")

#Add header search paths
include_directories(./include/
                    ./ext/glm/
                    /usr/include/GL/)

#Add library search paths
link_directories(/usr/lib64/)

#Define the executable target
add_executable(TrainingGLApp ${TRAININGGL_SOURCES} ${TRAININGGL_HEADERS})
target_link_libraries(TrainingGLApp GL GLEW glut )

