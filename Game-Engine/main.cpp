#include "src/graphics/window.h"
#include "src/maths/maths.h"
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

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag"); //shader files 
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f)); // lighting

	TileLayer layer(&shader);
	Texture* textures[] =
	{
		new Texture("test.png"),
		new Texture("b.png"),
		new Texture("tc.png")
	};
#if 0
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++) //0.1
		{
		//	layer.add(new Sprite(x, y, 0.9f, 0.9f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1))); // 0.9
			layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 3]));
		}
	}
#endif
	Sprite* testSprite = new Sprite(5.0f, 5.0f, 3.0f, 3.0f, new Texture("tc.png"));
	layer.add(testSprite);

	Label* kar = new Label("Test", -13.0f, 3.0f, Maths::vec4(0, 0.3, 1, 1));
	layer.add(kar);
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
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		layer.render();

		window.update();
		frames++;
		if(time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}

		if (window.isKeyPressed(GLFW_KEY_C)) {
			kar->Color = Maths::vec4(0, 1, 0, 1);
		}
		if (window.isKeyPressed(GLFW_KEY_A)) {
			testSprite->pos.x -= 0.1;
		}
		if (window.isKeyPressed(GLFW_KEY_D)) {
			testSprite->pos.x += 0.1f;
		}
		if (window.isKeyPressed(GLFW_KEY_W)) {
			testSprite->pos.y += 0.1f;
		}
		if (window.isKeyPressed(GLFW_KEY_S)) {
			testSprite->pos.y -= 0.1f;
		}
	}
	for (int i = 0; i < 3; i++)
		delete textures[i];
	return 0;
}
