#pragma once

#ifdef VE_PLATFORM_WINDOWS

extern VEngine::Application* VEngine::CreateApplication();

void main(int argc, char** argv)
{
	printf("VEngine^_^\n");
	auto app = VEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // VE_PLATFORM_WINDOWS
