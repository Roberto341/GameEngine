#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine { namespace Graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
	class Window 
	{
	private:
		const char *m_Title;
		int m_width, m_height;
		GLFWwindow *m_window;
		bool m_Closed;

	    bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		bool m_KeyState[MAX_KEYS];
		double mx, my;
	//public:
		//int m_width, m_height;
	public:
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }

		 bool isKeyPressed(unsigned int keycode);
		 bool isMouseButtonPressed(unsigned int button);
		 void getMousePosition(double& x, double& y);
	private:
		bool init();
		friend static void window_resize(GLFWwindow* window, int width, int height);
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};
} }

