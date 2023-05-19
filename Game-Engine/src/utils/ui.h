#pragma once
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../graphics/static_sprite.h"
#include "../graphics/sprite.h"
#include <iostream>
namespace Engine { namespace Graphics{ namespace UI {
class Ui {
public:
	Ui();
	void Init(GLFWwindow* window_ref);
	void Draw(Sprite* obj, Engine::Maths::vec4 col);
	void Destroy();
private:
	void TestBtn(Sprite* obj, Engine::Maths::vec4 col);
	void ChangeSpriteColor(Sprite* obj, float r, float g, float b, float a);
	Engine::Maths::vec4 test_col;
	Engine::Maths::vec4 stat_col;
};
} }}