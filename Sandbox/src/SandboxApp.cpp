
#include <Power.h>

class Sandbox : public Power::Applikation
{
	public:
		Sandbox() {
			
		}
		
		~Sandbox() {
			
		}
};



Power::Applikation* Power::CreateApplikation() {
	
	return new Sandbox();
}