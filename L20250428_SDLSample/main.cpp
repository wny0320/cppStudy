#include <iostream>

#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

#define RECT_COUNT	100
#define WIDTH	640
#define HEIGHT	480
#define SPEED	100
int main()
{
	//������ ����� �ʱ�ȭ �Լ�
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	//������ ����� �Լ�, ���ϰ��� ������� ������
	SDL_Window* MyWindow = SDL_CreateWindow("Sample", WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	
	//Renderer�� ������ ȭ�鿡 �׸���
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	bool IsRunning = true;
	SDL_Event MyEvent;

	// �簢�� �迭 �غ�
	//SDL_FRect rects[RECT_COUNT];
	//for (int i = 0; i < RECT_COUNT; ++i) {
	//	rects[i].x = SDL_randf() * (WIDTH - 50);   // 50�� �簢�� �ִ� �ʺ�
	//	rects[i].y = SDL_randf() * (HEIGHT - 50);  // 50�� �簢�� �ִ� ����
	//	rects[i].w = 20 + SDL_randf() * 31;        // 20~50 ������ �ʺ�
	//	rects[i].h = 20 + SDL_randf() * 31;        // 20~50 ������ ����
	//}
	float RectX = WIDTH / 2;
	float RectY = HEIGHT / 2;
	SDL_FRect* Square = new SDL_FRect();
	Square->x = RectX;
	Square->y = RectY;
	Square->w = 30;
	Square->h = 30;
	const bool* KeyState = SDL_GetKeyboardState(NULL);
	Uint64 LastTime = SDL_GetPerformanceCounter();
	//�̺�Ʈ�� �޾Ҵ��� ��� ���
	while (IsRunning)
	{
		SDL_PollEvent(&MyEvent);
		Uint64 CurrentTime = SDL_GetPerformanceCounter();
		float DeltaTime = (float)(CurrentTime - LastTime) / SDL_GetPerformanceFrequency();
		LastTime = CurrentTime;
		float MoveX = 0;
		float MoveY = 0;
		switch (MyEvent.type)
		{
			//�����ư�� ������ �̺�Ʈ Ÿ���̸� �ݺ��� ����
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		case SDL_EVENT_KEY_DOWN:
			if (KeyState[SDL_SCANCODE_UP])
			{
				MoveY -= 1;
			}
			if (KeyState[SDL_SCANCODE_DOWN])
			{
				MoveY += 1;
			}
			if (KeyState[SDL_SCANCODE_LEFT])
			{
				MoveX -= 1;
			}
			if (KeyState[SDL_SCANCODE_RIGHT])
			{
				MoveX += 1;
			}
			if (KeyState[SDL_SCANCODE_ESCAPE])
			{
				IsRunning = false;
			}
			break;
		default:
			break;
		}

		// 5. ���� ��ġ ������Ʈ (��Ÿ Ÿ�� ����)
		 RectX += (MoveX * SPEED * DeltaTime);
		 RectY += (MoveY * SPEED * DeltaTime);
		 Square->x = RectX;
		 Square->y = RectY;
		//�������� �ʱ�ȭ
		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(MyRenderer);

		SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0);
		SDL_RenderFillRects(MyRenderer, Square, RECT_COUNT);
		//�簢�� �׸���
		//SDL_RenderFillRects(MyRenderer, rects, RECT_COUNT);   // ���� �簢�� �� ���� �׸���
		//SDL_SetRenderDrawColor(MyRenderer, 255, 255, 0, 0); // �����

		//�� �׸���
		//SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0); // ������
		//int Radius = 200;
		//int X = WIDTH/2;
		//int Y = HEIGHT/2;
		//int PrevCircleX = Radius * SDL_cos(0) + X;
		//int PrevCircleY = Radius * SDL_sin(0) + Y;
		//for (int Angle = 0; Angle <= 360; Angle+=10)
		//{
		//	int CircleX = Radius * SDL_cos(Angle * SDL_PI_F / 180) + X;
		//	int CircleY = Radius * SDL_sin(Angle * SDL_PI_F / 180) + Y;
		//	SDL_RenderLine(MyRenderer, PrevCircleX, PrevCircleY, CircleX, CircleY);
		//	PrevCircleX = CircleX;
		//	PrevCircleY = CircleY;
		//}
		//ȭ�鿡 ����ϱ�
		SDL_RenderPresent(MyRenderer);
	}

	//SDL_Delay(3000);

	//Renderer �����
	SDL_DestroyRenderer(MyRenderer);

	//Window �����
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}

