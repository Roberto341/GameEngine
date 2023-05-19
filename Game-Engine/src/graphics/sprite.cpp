#include "sprite.h"

namespace Engine{ namespace Graphics {
	//Color for sprite
	Sprite::Sprite(float x, float y, float width, float height, const Maths::vec4& color)
		: Renderable2D(Maths::vec3(x, y, 0), Maths::vec2(width, height), color), col(m_Color), pos(m_Position), size(m_Size)
	{
		m_Position = Maths::vec3(x, y, 0.0f);
		m_Color = col;
	}
	//Texture for sprite
	Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
		: Renderable2D(Maths::vec3(x, y, 0), Maths::vec2(width, height), Maths::vec4(1, 1, 1, 1)), pos(m_Position), size(m_Size), col(m_Color)
	{
		m_Position = Maths::vec3(x, y, 0.0f);
		m_Texture = texture;
	}
}}
