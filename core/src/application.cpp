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
		while(m_window->isOpen()) {
			m_window->pollEvents();
			m_window->swapBuffers();
		}
		return 0;
	}
}
