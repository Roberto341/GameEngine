#include "window.h"

namespace Engine {	namespace Graphics {
	void window_resize(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	/*Window takes in a name, width, and a height*/
	Window::Window(const char* title, int width, int height) {
		m_Title = title;
		m_width = width;
		m_height = height;
		m_window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
			m_KeyState[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}
	Window::~Window() 
	{
		glfwTerminate();
	}

	/*Initialize*/
	bool Window::init() 
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}
		m_window = glfwCreateWindow(m_width, m_height, m_Title, NULL, NULL);
		if (!m_window)
		{
			std::cout << "Failed to create GLFW window!" << std::endl; 
			return false;
		}
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetFramebufferSizeCallback(m_window, window_resize);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSwapInterval(0); // 0 is disabled 1 is enabled
		if (glewInit() != GLEW_OK) {
			std::cout <<  "Could not initialize glew" << std::endl;
			return false;
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		return true;
	}
	/*keyPress*/
	bool Window::isKeyPressed(unsigned int keycode)
	{
		// TODO: Log this
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}
	bool Window::isMouseButtonPressed(unsigned int button)
	{
		// TODO: Log this
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}
	/*Get our mouse position*/
	void Window::getMousePosition(double& x, double& y)
	{
		x = mx;
		y = my;
	}
	/*Clear method*/
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	/* Clear color method*/
	void Window::clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) const
	{
		glClearColor(red, green, blue, alpha);
	}
	/*Update method*/
	void Window::update()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_KeyState[i] = m_Keys[i];
		}

		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
			std::cout << "OpenGL Error: " << error << std::endl;
		//glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	/*Window closed*/
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window) == 1;
	}
	
	void window_resize(GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_width = width;
		win->m_height = height;
	}
	/*Key callback*/
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
		
	}
	/*Mouse button callback*/
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}
	/*Cursor position*/
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}
} }
