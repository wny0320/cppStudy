#include "Engine.h"
#include "World.h"
#include "Input.h"
UEngine::UEngine()// : World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initialize()
{
	InputDevice = new UInput();
	World = new UWorld();
}

void UEngine::Run()
{
	while (true)
	{
		Input(); //입력
		Tick(); //일시키고
		Render(); //수학적으로 그림그리기
	}
}

void UEngine::Terminate()
{
	//null이 아닐 경우
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
	//Engine has a InputDevice
	//키보드, 마우스, 조이스틱, 터치 등 여러 입력장치가 있음.
	//새로운 입력장치가 생길때마다 코드를 수정하게 되어 입력장치로 추상화해야함
	//여기서는 간소화하기 위해 입력으로 추상화 함
}

void UEngine::Render()
{
	World->Tick();
}

void UEngine::Tick()
{
	World->Render();
}
