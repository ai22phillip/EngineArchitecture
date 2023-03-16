#pragma once

#include <memory>
#include "Events/Event.h"
#include "Core.h"
#include "Window.h"
#include "Power/Events/ApplicationEvent.h"

namespace Power {	


	class POWER_API Applikation
	{
	public:
		Applikation();
		virtual ~Applikation();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};
	
	Applikation* CreateApplikation();

}