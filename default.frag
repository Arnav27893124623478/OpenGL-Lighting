#version 330 core

out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;
in vec2 Texture;

uniform vec3 object_Color;
uniform vec3 light_Color;
uniform vec3 light_Position;
uniform vec3 view_Position;


struct Material{

	sampler2D diffuse;
	sampler2D  specular;
	float shininess;
};
struct Light{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

};

uniform Material material;
uniform Light light;

void main()
{
    // Ambient Lighting 
	vec3 ambient = vec3(texture(material.diffuse, Texture)) * light.ambient;


	// Diffuse Lighting
	vec3 norm = normalize(Normal);
	vec3 light_Dir = normalize(light_Position - FragPos);
	float diff = max(dot(norm, light_Dir), 0.0);
	vec3 diffuse = diff * vec3(texture(material.diffuse, Texture)) * light.diffuse;
	
	// Specular Lighting 
	vec3 view_Dir = normalize(view_Position - FragPos);
	vec3 refelctDir = reflect(-light_Dir, norm);
	float spec = pow(max(dot(view_Dir, refelctDir), 0.0), material.shininess);
	vec3 specular = light.specular * vec3(texture(material.specular, Texture))* spec;

	// result
	vec3 result = (ambient + diffuse + specular);
	FragColor = vec4(result, 1.0);
}