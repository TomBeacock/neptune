#pragma once

#include <memory>

namespace Neptune
{
	class Window;

	class Application
	{
	public:
		Application();
		~Application();

		Window& getWindow() { return *m_window; }

		int execute(int argc, char** argv);

	private:
		static Application* m_instance;

	private:
		std::unique_ptr<Window> m_window;
	};
}