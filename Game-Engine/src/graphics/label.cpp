#include "label.h"

namespace Engine { namespace Graphics {
	Label::Label(std::string text, float x, float y, Font* font, Maths::vec4 color)
		: Renderable2D(), text(text), position(m_Position), Color(m_Color), m_Font(font)
	{
		m_Position = Maths::vec3(x, y, 0.0f);
		m_Color = color;
	}
	void Label::submit(Renderer2D* renderer) const
	{
		renderer->drawString(text, position, *m_Font, m_Color);
	}
} }