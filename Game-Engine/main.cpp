#include "src/math/maths.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/graphics/BatchRenderer2D.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"
#include "src/graphics/texture.h"
#include "src/graphics/label.h"
#include "src/graphics/font/font_manager.h"
#include "src/sound/audio.h"
#include <time.h>
#include <FreeImage.h>
#include "src/graphics/window.h"
#include "src/utils/ui.h"


bool checkCollision(Engine::Graphics::Sprite* sprite1, Engine::Graphics::Sprite* sprite2)
{
	float sp1x = sprite1->getPosition().x;
	float sp1y = sprite1->getPosition().y;

	float sp2x = sprite2->getPosition().x;
	float sp2y = sprite2->getPosition().y;

	bool collX = sp1x + sprite1->size.x >= sp2x &&
		sp2x + sprite2->size.x >= sp1x;

	bool collY = sp1y + sprite1->size.y >= sp2y &&
		sp2y + sprite2->size.y >= sp1y;

	return collX && collY;
}

int main()
{
	using namespace Engine;
	using namespace Graphics;
	using namespace Maths;
	using namespace UI;
	Window window("RobCo Game Engine, Copyright (C) RobCo 2019-2022. All rights reserved.", 960, 540);
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("res/shaders/basic.vert", "res/shaders/basic.frag"); //shader's
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // lighting

	TileLayer layer(&shader);

	Sprite* cube2 = new Sprite(-18.0f, -9.0f, 100, 1, vec4(0.0f, 0.4f, 0.2f, 1));
	Sprite* cube = new Sprite(-5.0f, -8.0f, 1, 1, vec4(0.2f, 0.2f, 0.5f, 1));
	

	FontManager::add(new Font("Arial", "res/fonts/arial.ttf", 32));
	Group* g = new Group(Maths::mat4::translation(Maths::vec3(-15.8f, 7.0f, 0.0f)));
	Label* fps = new Label("Hyper", 0.4f, 0.4f, "Arial", 32, 0xffffffff);
	g->add(new Sprite(0, 0, 5, 1.5f, Maths::vec4(0.3f, 0.3f, 0.3f, 0.9f)));
	g->add(fps);

	layer.add(g);
	layer.add(cube);
	layer.add(cube2);
	GLint texIDs[] =
	{
		0,1,2,3,4,5,6,7,8,9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", Maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	float speed = 0.1f;

	Audio* audio_player = new Audio("res/Audio/rocket.wav");

	Ui* Gui = new Ui();

	Gui->Init(window.m_window);

	vec4 new_col = { 0, 0, 0.5f, 1 };
	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		

		layer.render();
		Gui->Draw(cube, new_col);
			
		if (!checkCollision(cube, cube2)) {
			cube->pos.y -= 0.2f;
			cube->col = vec4(0, 1, 0, 1);
		}else {
			cube->pos.y -= 0;
		}

		if (window.isKeyPressed(GLFW_KEY_SPACE)) {
			cube->pos.y += 0.3f;
		}

		window.update();
	}

	Gui->Destroy();

	FontManager::clean();
	return 0;
}
