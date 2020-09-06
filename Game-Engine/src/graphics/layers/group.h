#pragma once

#include "../renderable2d.h"

namespace Engine { namespace Graphics {

	class Group : public Renderable2D
	{
	private:
		std::vector<Renderable2D*> m_Renderables;
		Maths::mat4 m_TransformationMatrix;
	public:
		Group(const Maths::mat4& transform);
		void add(Renderable2D* renderable);
		void submit(Renderer2D* renderer) const override;
	};

} }