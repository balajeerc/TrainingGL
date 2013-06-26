//SpriteSheet_VS.glsl
//Shader used to render a spritesheet

uniform mat4 ProjectionModelViewMatrix;
attribute vec4 InVertex;	
attribute vec2 InTexCoord0;
varying vec2 OutTexCoord0;
uniform vec4 spriteTexCoord;

void main()
{
	gl_Position = ProjectionModelViewMatrix * InVertex;
	OutTexCoord0 = InTexCoord0;
}