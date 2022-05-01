#include "Pause.h"

Pause::Pause()
{
	font.loadFromFile("fonts/zombiecontrol.ttf");
	pauseText.setFont(font);
	pauseText.setFillColor(Color::White);
	pauseText.setCharacterSize(100);
	pauseText.setString("PRESS ENTER TO CONTINUE");
	pauseText.setPosition(300, 800);// 1920 1080
}

void Pause::Draw(RenderWindow& window)
{
	window.draw(pauseText);
}
