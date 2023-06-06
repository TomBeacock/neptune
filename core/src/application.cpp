#include "application.h"

#include "window.h"
#include "assert.h"

namespace Neptune
{
	Application* Application::m_instance = nullptr;

	Application::Application() :
		m_window(std::make_unique<Window>("Neptune"))
	{
		ASSERT(m_instance != nullptr, "Trying to create a second application, only a single application should be created.");
		m_instance = this;
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
