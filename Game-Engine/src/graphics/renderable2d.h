#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "renderer2d.h"
#include "texture.h"
#include "../math/maths.h"
#include "shader.h"

namespace Engine {	namespace Graphics {

    struct VertexData
    {
        Maths::vec3 vertex;
        Maths::vec2 uv;
        float tid;
        unsigned int color;
    };

    class Renderable2D
    {
     protected:
        Maths::vec3 m_Position; 
        Maths::vec2 m_Size; 
        Maths::vec4 m_Color;
        std::vector<Maths::vec2> m_UV;
        Texture* m_Texture; 
    protected:
        Renderable2D() : m_Texture(nullptr) { setUVDefaults(); }
    public:
        Renderable2D(Maths::vec3 position, Maths::vec2 size, Maths::vec4 color)
            : m_Position(position), m_Size(size), m_Color(color), m_Texture(nullptr)
        { setUVDefaults(); }
        /*Delete the vertex array and index buffer*/
        virtual ~Renderable2D(){ }
       
        virtual void submit(Renderer2D* renderer) const
        {
            renderer->submit(this);
        }

        inline const Maths::vec3& getPosition() const { return m_Position; } // position of the shape
        inline const Maths::vec2& getSize() const { return m_Size; } // size of the shape
        inline const Maths::vec4& getColor() const { return m_Color; } // color of the shape 
        inline const std::vector<Maths::vec2>& getUV() const { return m_UV; } // uv of the shape
        
        inline const GLuint getTID() const { return m_Texture ? m_Texture->getID() : 0; }
    private:
        void setUVDefaults() {
            m_UV.push_back(Maths::vec2(0, 0));
            m_UV.push_back(Maths::vec2(0, 1));
            m_UV.push_back(Maths::vec2(1, 1));
            m_UV.push_back(Maths::vec2(1, 0));
        }
    };
}}
