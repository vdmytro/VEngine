#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace VEngine {

	class VE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//must be realize in client
	Application* CreateApplication();

}