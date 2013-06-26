//Solid_VS.glsl
//Shader drawing vertices in single colour

uniform mat4 ProjectionModelViewMatrix;
attribute vec4 InVertex;	//w will be set to 1.0 automatically
uniform vec4 Color;		//Color specified for all vertices

void main()
{
	gl_Position = ProjectionModelViewMatrix * InVertex;
}