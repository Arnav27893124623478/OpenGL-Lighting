#version 330 core

out vec4 FragColor;
in vec3 FragPos;
in vec3 Normal;


uniform vec3 object_Color;
uniform vec3 light_Color;
uniform vec3 light_Position;
uniform vec3 view_Position;


void main()
{
    // Ambient Lighting 
    float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * light_Color;


	// Diffuse Lighting
	vec3 norm = normalize(Normal);
	vec3 light_Dir = normalize(light_Position - FragPos);
	float diff = max(dot(norm, light_Dir), 0.0);
	vec3 diffuse = diff * light_Color;
	
	// Specular Lighting 
	float specularStrength = 0.5f;
	vec3 view_Dir = normalize(view_Position - FragPos);
	vec3 refelctDir = reflect(-light_Dir, norm);
	float spec = pow(max(dot(view_Dir, refelctDir), 0.0), 32);
	vec3 specular = light_Color * specularStrength * spec;

	// result
	vec3 result = (ambient + diffuse + specular) * object_Color;
	FragColor = vec4(result, 1.0);
}