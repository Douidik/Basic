#version 460 core

out vec4 f_Result;
in vec2 v_TextureCoords;
uniform sampler2D u_DiffuseTexture;

void main()
{
    f_Result = texture(u_DiffuseTexture, v_TextureCoords);
}