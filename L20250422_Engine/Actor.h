#pragma once
#include "Vector2D.h"
class AActor
{
public:
	AActor();
	virtual ~AActor();

	//�̵����ִ� �Լ�
	void AddActorWorldOffset(const FVector2D& offset);
	//���¸� �˾ƾ��ϹǷ� ���漱���� �ȵ�
	FVector2D Location;

	virtual void Tick();
	virtual void Render();
};

