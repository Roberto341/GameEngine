#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "shader.h"
#include "../maths/maths.h"

namespace Engine {	namespace Graphics {

    struct VertexData
    {
        Maths::vec3 vertex;
        //Maths::vec4 color;
        unsigned int color;
    };

    class Renderable2D
    {
    protected:
        Maths::vec3 m_Position; // Position of the shape
        Maths::vec2 m_Size; //Size of the shape
        Maths::vec4 m_Color; //Color of the shape

    public:
        Renderable2D(Maths::vec3 position, Maths::vec2 size, Maths::vec4 color)
            : m_Position(position), m_Size(size), m_Color(color)
        {  }
        /*Delete the vertex array and index buffer*/
        virtual ~Renderable2D(){ }
       

        inline const Maths::vec3& getPosition() const { return m_Position; } // position of the shape
        inline const Maths::vec2& getSize() const { return m_Size; } // size of the shape
        inline const Maths::vec4& getColor() const { return m_Color; } // color of the shape 
    };
}}
