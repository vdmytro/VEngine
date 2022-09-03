#include "Application.h"

#include "VEngine/Events/ApplicationEvent.h"
#include "VEngine/Log.h"

namespace VEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		VE_TRACE(e);

		while (true);
	}

}