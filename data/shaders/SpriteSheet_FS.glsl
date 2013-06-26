//SpriteSheet_FS.glsl
//Shader used to render a spritesheet

uniform vec4 spriteTexCoord;
uniform sampler2D imgTexture;
varying vec2 OutTexCoord0;

void main()
{
	//New newLoc = scale*oldLoc + offset
	vec2 newTexCoords;
	newTexCoords.s = spriteTexCoord.z*OutTexCoord0.s + spriteTexCoord.x;
	newTexCoords.t = spriteTexCoord.w*OutTexCoord0.t + spriteTexCoord.y;	
	
	//vec4 color = texture2D(imgTexture,OutTexCoord0);
	vec4 color = texture2D(imgTexture,newTexCoords);
	gl_FragColor = color;
}