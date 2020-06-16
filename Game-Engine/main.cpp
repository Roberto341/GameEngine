#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/graphics/BatchRenderer2D.h"
#include  "src/utils/timer.h"
#include "src/graphics/layers/tilelayer.h"
#include <time.h>

#define BATCH_RENDERER 1
int main()
{
	/*Namespaces*/
	using namespace Engine;
	using namespace Graphics;
	using namespace Maths;

	/*Create window*/
	Window window("RobCo Game Engine, Copyright (C) RobCo 2020. All rights reserved.", 960, 540);
	//glClearColor(0.0f, 0.0f, 0.3f, 1.0f); //Color of the window

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	/*Shader load and enable*/
	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s3 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	Shader& shader3 = *s3;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // lighting
	shader2.enable();
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // lighting
	TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, Maths::vec4(0.8f, 0.2f, 0.8f, 1.0f)));
	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader2.setUniform2f("light_pos", vec2(-8, -3));
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		layer.render(); // layer 1
		layer2.render(); // layer2
		window.update();

		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
		}
	}
	return 0;
}