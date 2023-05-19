#include "ui.h"
namespace Engine { namespace Graphics { namespace UI {
			Ui::Ui()
			{
			}
			void Ui::Init(GLFWwindow* window_ref)
			{
				IMGUI_CHECKVERSION();
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				ImGui::StyleColorsDark();

				ImGui_ImplGlfw_InitForOpenGL(window_ref, true);
				ImGui_ImplOpenGL3_Init("#version 330 core");
			}

			void Ui::Draw(Sprite* obj, Engine::Maths::vec4 col)
			{
				Shader* s = new Shader("res/shaders/basic.vert", "res/shaders/basic.frag"); //shader's
				Shader& shader = *s;

				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();
				
				ImGui::Begin("Test window");
				
				shader.enable();
				shader.setUniform4f("color", stat_col);
				float my_col[4] = { 0, 1, 0, 1 };
				stat_col = Engine::Maths::vec4(my_col[0], my_col[1], my_col[2], my_col[3]);
				ImGui::ColorEdit4("Color", my_col);
				if (ImGui::Button("My button")) {
					TestBtn(obj, col);
				}
				ImGui::End();

				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			}

			void Ui::ChangeSpriteColor(Sprite* obj, float r, float g, float b, float a) {
				test_col = Engine::Maths::vec4(r, g, b, a);
				obj->col = test_col;
			}

			void Ui::TestBtn(Sprite* obj,Engine::Maths::vec4 col)
			{
				obj->col = col;
				std::cout << "Test button has been pressed" << std::endl;
			}

			void Ui::Destroy()
			{
				ImGui_ImplOpenGL3_Shutdown();
				ImGui_ImplGlfw_Shutdown();
				ImGui::DestroyContext();
			}
}}}

/*
// Default behavior requires click + release inside bounding box
	if ((flags & ImGuiButtonFlags_PressedOnMask_) == 0)
		flags |= ImGuiButtonFlags_PressedOnDefault_;

		ImGuiButtonFlags flags
		ImGuiButtonFlags_None
*/