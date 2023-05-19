#pragma once

#include "renderable2d.h"
#include "font/font_manager.h"
namespace Engine { namespace Graphics {
	class Label : public Renderable2D
	{
	public:
		Font* m_Font;
		std::string text;
		Maths::vec3& position;
		float x, y;
		unsigned int m_Color;
	public:
		Label(std::string text, float x, float y, Font* font, unsigned int color);
		Label(std::string text, float x, float y, const std::string& font, unsigned int color);
		Label(std::string text, float x, float y, const std::string& font, unsigned int size, unsigned int color);
		void submit(Renderer2D* renderer) const override;
		void validateFont(const std::string& name, int size = -1);
	};
}}