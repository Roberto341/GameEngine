#pragma once

#include <deque>
#include "renderer2d.h"
#include "static_sprite.h"
namespace Engine { namespace Graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque < const StaticSprite*> m_RenderQueue;
	public:
		void submit(const Renderable2D* renderable) override; // submit 
		void flush() override; // flush and clean
	};

}}