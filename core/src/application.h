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

		int execute(int argc, char** argv);

	private:
		std::unique_ptr<Window> m_window;
	};
}