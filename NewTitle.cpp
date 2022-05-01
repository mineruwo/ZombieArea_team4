#include "NewTitle.h"

void NewTitle::Init()
{
	textureFileName = "graphics/background.png";
	sprite.setTexture(TextureHolder::GetTexture(textureFileName));

	sprite.setPosition(0, 0);

	font.loadFromFile("fonts/zombiecontrol.ttf");

	PressEnter.setFont(Scene::font);
	PressEnter.setFillColor(Color::Red);
	PressEnter.setCharacterSize(100);
	PressEnter.setString("PRESS ENTER TO PLAY ");
	PressEnter.setPosition(300, 800);

	Scene::currScene = SceneID::Title;
}

void NewTitle::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Enter))
	{
		Scene::NextScene(SceneID::GamePlay);
	}
}

void NewTitle::Draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(PressEnter);
}

void NewTitle::Release()
{

}
