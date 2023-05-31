#pragma once

#include <string>

struct GLFWwindow;

namespace Neptune
{
	class Window
	{
	public:
		Window(const std::string& title, int width = 1280, int height = 720);
		~Window() = default;

		bool open();

		void pollEvents();
		void swapBuffer();

	private:
		GLFWwindow* m_window;
	};
}