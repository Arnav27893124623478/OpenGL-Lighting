#version 330 core

out vec4 FragPostion;

uniform vec3 light_Color;

void main(){
   
   FragPostion = vec4(light_Color, 1.0);
}