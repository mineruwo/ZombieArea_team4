#include "NewPause.h"

void NewPause::Init()
{
	pauseText.setFillColor(Color::White);
	pauseText.setCharacterSize(100);
	pauseText.setString("PRESS ENTER TO CONTINUE");
	pauseText.setPosition(300, 800);
}

void NewPause::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		Scene::NextScene(SceneID::GamePlay);
	}
}

void NewPause::Draw(RenderWindow& window)
{
	window.draw(pauseText);
}

void NewPause::Release()
{
}
