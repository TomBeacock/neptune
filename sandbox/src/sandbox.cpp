#include "sandbox.h"

using namespace Neptune;

int main(int argc, char** argv)
{
	Sandbox::Sandbox app;
	return app.execute(argc, argv);
}

namespace Sandbox
{
	Sandbox::Sandbox()
	{
		getWindow().setTitle("Sandbox");
	}
}
