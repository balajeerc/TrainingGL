//SimpleImage_VS.glsl
//Simple shader used to draw an image plane

uniform mat4 ProjectionModelViewMatrix;
attribute vec4 InVertex;		//w will be set to 1.0 automatically
attribute vec2 InTexCoord0;
varying vec2 OutTexCoord0;

void main()
{
	gl_Position = ProjectionModelViewMatrix * InVertex;
	OutTexCoord0 = InTexCoord0;
}