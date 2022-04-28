#include "UI.h"

UI::UI()
{
	font.loadFromFile("fonts/zombiecontrol.ttf");
	textcurrMagazine.setFont(font);
	textcurrMagazine.setFillColor(Color::White);
	textcurrMagazine.setCharacterSize(50);
	textcurrMagazine.setPosition(200, 950);

	textMaxMag.setFont(font);
	textMaxMag.setFillColor(Color::White);
	textMaxMag.setCharacterSize(50);
	textMaxMag.setPosition(250, 950);

	textTotalAmmo.setFont(font);
	textTotalAmmo.setFillColor(Color::White);
	textTotalAmmo.setCharacterSize(50);
	textTotalAmmo.setPosition(350, 950);

	magSprite.setTexture(TextureHolder::GetTexture("graphics/ammo_pickup.png"));

	magSprite.setPosition(50, 950);
}

void UI::UpdatecurrMagazine(int curMag)
{
	std::stringstream ss;

	ss << curMag;
	textcurrMagazine.setString(ss.str());

	ss.clear();
}

void UI::UpdateMaxMag(int maxMag)
{
	std::stringstream ss;

	ss << "/" << maxMag;
	textMaxMag.setString(ss.str());

	ss.clear();
}

void UI::UpdateTotalAmmo(int totalAmmo)
{
	std::stringstream ss;

	ss << totalAmmo;
	textTotalAmmo.setString(ss.str());

	ss.clear();
}

void UI::UpdateUi(int curMag, int maxMag, int totalAmmo)
{
	UpdatecurrMagazine(curMag);
	UpdateMaxMag(maxMag);
	UpdateTotalAmmo(totalAmmo);
}

void UI::DrawUi(RenderWindow& window)
{
	window.draw(textcurrMagazine);
	window.draw(textMaxMag);
	window.draw(textTotalAmmo);
	window.draw(magSprite);
}
