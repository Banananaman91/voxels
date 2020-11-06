#version 330 core
out vec4 FragColour;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColour;
uniform vec3 lightColour;
uniform float ambientStrength;
uniform vec3 lightPos;
uniform mat4 lightMat;

void main()
{
    vec3 light = vec3(lightMat * vec4(lightPos, 1.0f));
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColour;
    FragColour = vec4((ambientStrength + diff) * objectColour, 1.0f);
}