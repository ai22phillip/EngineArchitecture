#include "pwpch.h"
#include "Applikation.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/Event.h"
#include "GLFW/glfw3.h"

namespace Power {
	

	Applikation::Applikation()
	{
	
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Applikation::~Applikation()
	{
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

	
	

}