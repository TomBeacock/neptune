#include "window.h"

#include "log.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

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
		LOG_INFO(extensionCount << " extensions supported");
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
