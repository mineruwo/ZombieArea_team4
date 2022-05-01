#include "Framework.h"

Framework::Framework()
{
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y), "Zombie Arena!", Style::Fullscreen);
}

void Framework::Initialize()
{
	sceneMgr.SceneInit(resolution);
}

void Framework::Update()
{
	InputMgr::ClearInput();
	Event event;
	Time dt = clock.restart();
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}

		InputMgr::ProcessInput(event);
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();

			//���� �Ͻ������� ������ ����
		}
	}
	sceneMgr.SceneUpdate(dt,window);
}

void Framework::Draw()
{
	window.clear();
	sceneMgr.SceneDraw(window);
	window.display();
}