#include "pwpch.h"
#include "Applikation.h"
#include "Log.h"
#include "GLFW/glfw3.h"

namespace Power {
	
#define BIND_EVENT_FN(x) std::bind(&Applikation::x, this, std::placeholders::_1)


	Applikation::Applikation()
	{
	
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Applikation::OnEvent));
	}

	Applikation::~Applikation()
	{
	}
	void Applikation::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Applikation::OnWindowClose));

		PW_CORE_TRACE("{0}", e);
	}

	void Applikation::Run() 
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		
	}

	bool Applikation::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	
	

}