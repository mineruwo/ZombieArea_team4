#include "GameOver.h"

GameOver::GameOver()
{
	font.loadFromFile("fonts/zombiecontrol.ttf");
	overText.setFont(font);
	overText.setFillColor(Color::White);
	overText.setCharacterSize(200);
	overText.setString("Game Over ");
	overText.setPosition(500,450 );// 1920 1080
}

void GameOver::Draw(RenderWindow& window)
{
	window.draw(overText);
}


