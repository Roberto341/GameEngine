#pragma once
#include "renderable2d.h"
namespace Engine { namespace Graphics {

	class StaticSprite : public Renderable2D
	{
	private: 
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;
	public:
		StaticSprite(float x, float y, float width, float height, const Maths::vec4& color,Shader& shader);
		~StaticSprite();

		/*inline consts*/
		inline const VertexArray* getVAO() const { return m_VertexArray; } // vertex array
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; } // index buffer

		inline Shader& getShader() const { return m_Shader; } // shader it self
	};
}}