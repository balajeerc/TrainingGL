//Solid_FS.glsl
//Shader drawing vertices in single colour

uniform vec4 Color;		//Color specified for all vertices

void main()
{
	gl_FragColor = Color;
}