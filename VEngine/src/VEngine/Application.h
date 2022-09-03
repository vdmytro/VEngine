#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace VEngine {

	class VE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//must be realize in client
	Application* CreateApplication();

}