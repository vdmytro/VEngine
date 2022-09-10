#include <VEngine.h>

class ExampleLayer : public VEngine::Layer
{
public:
	ExampleLayer()
		: Layer("example")
	{}
	void OnUpdate() override
	{
		//VE_INFO("ExampleLayer::Update");
	}
	void OnEvent(VEngine::Event& event) override
	{
		//VE_TRACE("{0}",event); // heap errors
		VE_TRACE("ExampleLayer::Event");
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