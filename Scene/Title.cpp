#include "Title.h"
#include "../Utils/TextureHolder.h"

Title::Title():textureFileName("graphics/background.png")
{
	sprite.setTexture(TextureHolder::GetTexture(textureFileName));
	sprite.setPosition(0, 0);

	font.loadFromFile("fonts/zombiecontrol.ttf");
	PressEnter.setFont(font);
	PressEnter.setFillColor(Color::White);
	PressEnter.setCharacterSize(100);
	PressEnter.setString("PRESS ENTER TO PLAY ");
	PressEnter.setPosition(300,800);// 1920 1080
}
//
//bool Title::IsTitleOn(const Event& event)
//{
//	switch (event.type)
//	{
//	case Keyboard::Enter:
//		TitleOn = false;
//		return TitleOn;
//		break;
//	}
//}

//Sprite Title::GetSprite()
//{
//	return sprite;
//}

void Title::Draw(RenderWindow& window)
{
	//if (TitleOn)
	{
		window.draw(sprite);
		window.draw(PressEnter);

	}

}
