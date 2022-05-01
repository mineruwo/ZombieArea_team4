#include "NewGameOver.h"

void NewGameOver::Init()
{
	overText.setFont(Scene::font);
	overText.setFillColor(Color::White);
	overText.setCharacterSize(200);
	overText.setString("Game Over");
	overText.setPosition(500, 450);// 1920 1080

	currScene = SceneID::GameOver;
}

void NewGameOver::Update()
{
	// Ű �Է����� �� ��ȯ�ϰ� �ϱ�

}

void NewGameOver::Draw(RenderWindow& window)
{
	window.draw(overText);
}

void NewGameOver::Release()
{
}
