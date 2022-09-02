#pragma once

#ifdef VE_PLATFORM_WINDOWS

extern VEngine::Application* VEngine::CreateApplication();

void main(int argc, char** argv)
{
	VEngine::Log::Init();
	VE_CORE_WARN("Initialized Log!");
	VE_INFO("Hello!");
	
	auto app = VEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // VE_PLATFORM_WINDOWS
