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

		void setTitle(const std::string& title);
		bool isOpen();

		void maximise();
		void minimise();
		void restore();
		void pollEvents();
		void swapBuffers();
		void close();

	private:
		GLFWwindow* m_window;
	};
}