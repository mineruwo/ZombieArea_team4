#include "Framework.h"

Framework::Framework()
{
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	window.create(VideoMode(resolution.x, resolution.y), "Zombie Arena!", Style::Fullscreen);
}

void Framework::Initialize(Vector2i resolution)
{
	sceneMgr.SceneInit(resolution);
}

void Framework::Update()
{
	InputMgr::ClearInput();
	Event event;
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

			//이후 일시정지로 변경할 예정
		}
	}
	sceneMgr.SceneUpdate();
}

void Framework::Draw()
{
	window.clear();
	sceneMgr.SceneDraw(window);
	window.display();
}
