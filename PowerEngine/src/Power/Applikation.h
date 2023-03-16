#pragma once

#include <memory>
#include "Events/Event.h"
#include "Core.h"
#include "Window.h"

namespace Power {	


	class POWER_API Applikation
	{
	public:
		Applikation();
		virtual ~Applikation();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};
	
	Applikation* CreateApplikation();

}