#include "application.h"

#include "window.h"

namespace Neptune
{
	Application::Application() :
		m_window(std::make_unique<Window>("Neptune"))
	{
	}

	Application::~Application()
	{
	}

	int Application::execute(int argc, char** argv)
	{
		while(m_window->open()) {
			m_window->pollEvents();
			m_window->swapBuffer();
		}
		return 0;
	}
}
