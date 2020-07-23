#version 330 core

in vec4 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourFace;
uniform float mixValue;

//uniform vec4 ourColor;

out vec4 FragColor;	

void main(){				
	//FragColor = vertexColor;
	FragColor =  mix(texture(ourTexture, TexCoord), texture(ourFace,TexCoord), mixValue);
}	
