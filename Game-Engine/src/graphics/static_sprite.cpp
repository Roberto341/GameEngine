#include "static_sprite.h"

namespace Engine {	namespace Graphics {
    StaticSprite::StaticSprite(float x, float y, float width, float height, const Maths::vec4& color, Shader& shader)
        : Renderable2D(Maths::vec3(x, y, 0), Maths::vec2(width, height), color), m_Shader(shader)
    {
        m_VertexArray = new VertexArray();
        /*Vertices of the shape*/
        GLfloat vertices[] =
        {
            0, 0, 0,
            0, height, 0,
            width, height, 0,
            width, 0, 0
        };
        /*Colors*/
        GLfloat colors[] =
        {
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w
        };

        m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
        m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

        GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
        m_IndexBuffer = new IndexBuffer(indices, 6);
    }
    StaticSprite::~StaticSprite()
    {
        delete m_VertexArray;
        delete m_IndexBuffer;
    }
}}