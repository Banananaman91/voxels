#version 330 core
out vec4 FragColour;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColour;
uniform vec3 lightColour;
uniform float ambientStrength;
uniform vec3 lightPos;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;
    FragColour = vec4((ambientStrength + diffuse) * objectColour, 1.0f);
}