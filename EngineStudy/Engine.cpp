#include "Engine.h"
#include "World.h"
#include "Input.h"


UEngine* UEngine::Instance = nullptr;


UEngine::UEngine() //: World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initiailze(std::string filename)
{
	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filename);

}

void UEngine::Run()
{
	while (true)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}

	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}
}

void UEngine::Input()
{
	InputDevice->Tick();
	//Engine has a Input
	//키보드, 마우스, 조이스틱, 터치, 자이로 센스
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
