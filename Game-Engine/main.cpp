#include "src/graphics/window.h"
#include "src/math/maths.h"
#include  "src/utils/timer.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/graphics/BatchRenderer2D.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"
#include <time.h>
#include <FreeImage.h>
#include "src/graphics/texture.h"
#include "src/graphics/label.h"
#include "src/graphics/font/font_manager.h"
#include "src/sound/audio.h"
#define BATCH_RENDERER 0
int main()
{
	/*Namespaces*/
	using namespace Engine;
	using namespace Graphics;
	using namespace Maths;

	/*Create window*/
	Window window("RobCo Game Engine, Copyright (C) RobCo 2020. All rights reserved.", 960, 540);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("res/shaders/basic.vert", "res/shaders/basic.frag"); //shader's
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // lighting

	TileLayer layer(&shader);
#if BATCH_RENDERER
	Texture* textures[] = {
	new Texture("res/tc.png"),
	new Texture("res/b.png"),
	};
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++) //0.1
		{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 2]));
		}
	}
#else
	Texture* p1 = new Texture("res/tc.png");
	Sprite* player1 = new Sprite(0, 0, 3, 3, p1);
	layer.add(player1);
#endif

	FontManager::add(new Font("Arial", "res/fonts/arial.ttf", 32));
	Group* g = new Group(Maths::mat4::translation(Maths::vec3(-15.8f, 7.0f, 0.0f)));
	Label* fps = new Label("", 0.4f, 0.4f, FontManager::get("Arial"), Maths::vec4(1, 1, 1, 1));
	g->add(new Sprite(0, 0, 5, 1.5f, Maths::vec4(0.3f, 0.3f, 0.3f, 0.9f)));
	g->add(fps);

	layer.add(g);
	GLint texIDs[] =
	{
		0,1,2,3,4,5,6,7,8,9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", Maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	Timer time;
	float timer = 0;

	unsigned int frames = 0;
	Audio* ad = new Audio("res/Audio/Rocket.wav");

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		layer.render();

		if (window.isKeyPressed(GLFW_KEY_P)) {
			ad->play();
		}
		if (window.isKeyPressed(GLFW_KEY_S)) {
			ad->pause();
		}
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			fps->text = std::to_string(frames) + " fps";
			frames = 0;
		}
	}
	FontManager::clean();
	ad->stop();
#if BATCH_RENDERER
	for (int i = 0; i < 2; i++) {
		delete textures[i];
	}
#else
	delete p1;
#endif
	return 0;
}
