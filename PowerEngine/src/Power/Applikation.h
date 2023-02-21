#pragma once

#include "Core.h"

namespace Power {	


	class POWER_API Applikation
	{
	public:
		Applikation();
		virtual ~Applikation();

		void Run();
	};
	
	Applikation* CreateApplikation();

}