#include "Core/Core.h"
#include "Application.h"
using namespace Basic;

struct AppArguments
{
	std::string name = "undefined";
	int width = 1280, height = 720;
};

AppArguments ParseArguments(int argc, char** argv)
{
	AppArguments args;

	if(argc >= 1)
		args.name = argv[1];
	if(argc >= 3)
	{
		args.width = std::atoi(argv[2]);
		args.height = std::atoi(argv[3]);
	}

	return args;
}

int main(int argc, char**argv)
{
	Core::Initialize();

	{
		AppArguments args = ParseArguments(argc, argv);
		Application application(args.name, args.width, args.height);
		application.Run();
	}

	Core::Release();
}