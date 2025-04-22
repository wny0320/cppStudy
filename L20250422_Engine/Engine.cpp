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
		Input(); //�Է�
		Tick(); //�Ͻ�Ű��
		Render(); //���������� �׸��׸���
	}
}

void UEngine::Terminate()
{
	//null�� �ƴ� ���
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
	//Ű����, ���콺, ���̽�ƽ, ��ġ �� ���� �Է���ġ�� ����.
	//���ο� �Է���ġ�� ���涧���� �ڵ带 �����ϰ� �Ǿ� �Է���ġ�� �߻�ȭ�ؾ���
	//���⼭�� ����ȭ�ϱ� ���� �Է����� �߻�ȭ ��
}

void UEngine::Render()
{
	World->Tick();
}

void UEngine::Tick()
{
	World->Render();
}
