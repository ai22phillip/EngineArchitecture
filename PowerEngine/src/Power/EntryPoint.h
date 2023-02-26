#pragma once

#ifdef PW_PLATFORM_WINDOWS

extern Power::Applikation* Power::CreateApplikation();

int main(int argc, char** argv)

{
	Power::Log::Init();
	PW_CORE_WARN("Initialized Log!");
	int a = 5;
	PW_INFO("Hello! Var={0}", a);

	auto app = Power::CreateApplikation();
	app->Run();
	delete app;
}

#endif