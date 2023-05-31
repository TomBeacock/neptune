#include "window.h"

#include <GLFW/glfw3.h>

namespace Neptune
{
	Window::Window(const std::string& title, int width, int height)
	{
		glfwInit();

		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
	}

	bool Window::open()
	{
		return !glfwWindowShouldClose(m_window);
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	void Window::swapBuffer()
	{
		glfwSwapBuffers(m_window);
	}
}
