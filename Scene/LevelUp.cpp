#include "LevelUp.h"
#include "../Utils/TextureHolder.h"


LevelUp::LevelUp() :textureFileName("graphics/background.png")
{
	sprite.setTexture(TextureHolder::GetTexture(textureFileName));
	sprite.setPosition(0, 0);

	font.loadFromFile("fonts/zombiecontrol.ttf");
	Upgrade.setFont(font);
	Upgrade.setFillColor(Color::White);
	Upgrade.setCharacterSize(80);
	Upgrade.setString(
		" 1.INCREASED RATE OF FIRE \n 2.INCREASED CLIP SIZE (NEXT RELOAD) \n 3.INCREASED MAX HEALTH \n"
		" 4.INCREASED RUN SPEED \n 5.MORE AND BETTER HEALTH PICKUPS \n 6.MORE AND BETTER AMMO PICKUPS \n");
	Upgrade.setPosition(200, 300);// 1920 1080
}

void LevelUp::SelectUpgrade(const Event& event, Player& player)
{
	switch (event.type)
	{
	case Keyboard::Num1:
		//연사속도 증가
		break;
	case Keyboard::Num2:
		//탄창수증가
	case Keyboard::Num3:
		player.UpgradeMaxHealth();
		//체력증가
	case Keyboard::Num4:
		player.UpgradeSpeed();
		//이동속도증가
	case Keyboard::Num5:
		//아이템 회복량 증가
	case Keyboard::Num6:
		//아이템 탄증가수 증가
		break;
	}
}

void LevelUp::Draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(Upgrade);
}
