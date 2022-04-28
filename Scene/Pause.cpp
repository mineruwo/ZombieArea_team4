#include "Pause.h"

Pause::Pause()
{
	font.loadFromFile("fonts/zombiecontrol.ttf");
	PauseText.setFont(font);
	PauseText.setFillColor(Color::White);
	PauseText.setCharacterSize(100);
	PauseText.setString("PRESS ENTER TO CONTINUE");
	PauseText.setPosition(300, 800);// 1920 1080
}

void Pause::Draw(RenderWindow& window)
{
	window.draw(PauseText);
}
