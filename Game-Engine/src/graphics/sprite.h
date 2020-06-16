#pragma once
#include "renderable2d.h"

namespace Engine { namespace Graphics {
	
	class Sprite : public Renderable2D
	{
	public:
		Sprite(float x, float y, float width, float height, const Maths::vec4& color);
	};
}}