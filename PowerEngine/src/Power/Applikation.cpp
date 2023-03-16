#include "pwpch.h"
#include "Applikation.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/Event.h"

namespace Power {
	

	Applikation::Applikation()
	{
	
	}

	Applikation::~Applikation()
	{
	}

	void Applikation::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			PW_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			PW_CORE_TRACE(e);
		}
		while (true);
	}

	
	

}