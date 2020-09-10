#pragma once

#include "renderable2d.h"
namespace Engine { namespace Graphics {

	class Label : public Renderable2D
	{
	public:
		std::string text;
		Maths::vec3& position;
		Maths::vec4& Color;
		float x, y;
	public:
		Label(std::string text, float x, float y, Maths::vec4 color);
		void submit(Renderer2D* renderer) const override;
	};
}}