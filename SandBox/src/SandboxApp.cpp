#include <VEngine.h>

class ExampleLayer : public VEngine::Layer
{
public:
	ExampleLayer()
		: Layer("example")
	{}
	void OnUpdate() override
	{

		if (VEngine::Input::IsKeyPressed(VE_KEY_TAB))
			VE_TRACE("Tab is pressed!");

	}
	void OnEvent(VEngine::Event& event) override
	{
		//VE_TRACE("{0}",event); // heap errors
		if (event.GetEventType() == VEngine::EventType::KeyPressed)
		{
			VEngine::KeyPressedEvent& e = (VEngine::KeyPressedEvent&)event;
			VE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
	
};

class Sandbox : public VEngine::Application
{

public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new VEngine::ImGuiLayer());
	}
	~Sandbox() {

	}
};

VEngine::Application* VEngine::CreateApplication()
{
	return new Sandbox();
}