#include "simple2drenderer.h"
#include "renderable2d.h"
namespace Engine { namespace Graphics {

	void Simple2DRenderer::submit(const Renderable2D* renderable)
	{
		m_RenderQueue.push_back((StaticSprite*) renderable);
	}
	void Simple2DRenderer::flush()
	{
		while (!m_RenderQueue.empty())
		{
			const StaticSprite* sprite = m_RenderQueue.front();
			/*bind vertex array and index buffer*/
			sprite->getVAO()->bind();
			sprite->getIBO()->bind();
			/*Import the shader*/
			sprite->getShader().setUniformMat4("ml_matrix", Maths::mat4::translation(sprite->getPosition()));
			/*Draw the element*/
			glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
			/*unbind vertex array and index buffer*/
			sprite->getVAO()->unbind();
			sprite->getIBO()->unbind();

			m_RenderQueue.pop_front();
		}
	}
}}


