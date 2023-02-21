#pragma once

#ifdef PW_PLATFORM_WINDOWS

extern Power::Applikation* Power::CreateApplikation();

int main(int argc, char** argv)

{
	auto app = Power::CreateApplikation();
	app->Run();
	delete app;
}

#endif