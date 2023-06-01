#include "window.h"

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Neptune
{
	Window::Window(const std::string& title, int width, int height)
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);

		uint32_t extensionCount;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::cout << extensionCount << " extensions supported" << std::endl;
	}

	void Window::setTitle(const std::string& title)
	{
		glfwSetWindowTitle(m_window, title.c_str());
	}

	bool Window::isOpen()
	{
		return !glfwWindowShouldClose(m_window);
	}

	void Window::maximise()
	{
		glfwMaximizeWindow(m_window);
	}

	void Window::minimise()
	{
		glfwIconifyWindow(m_window);
	}

	void Window::restore()
	{
		glfwRestoreWindow(m_window);
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(m_window, true);
	}
}
