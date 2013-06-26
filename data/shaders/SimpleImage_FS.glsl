//SimpleImage_FS.glsl
//Simple shader used to draw an image plane

varying vec2 OutTexCoord0;
uniform sampler2D imgTexture;

void main()
{
	vec4 color = texture2D(imgTexture,OutTexCoord0.st);
	gl_FragColor = color;
}