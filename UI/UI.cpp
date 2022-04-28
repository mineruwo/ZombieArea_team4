#include "UI.h"

UI::UI()
	:currHealthXsize(MaxhealthXsize)
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

	textWave.setFont(font);
	textWave.setFillColor(Color::White);
	textWave.setCharacterSize(50);
	textWave.setPosition(1300, 950);

	textZombieCount.setFont(font);
	textZombieCount.setFillColor(Color::White);
	textZombieCount.setCharacterSize(50);
	textZombieCount.setPosition(1600, 950);

	textScore.setFont(font);
	textScore.setFillColor(Color::White);
	textScore.setCharacterSize(50);
	textScore.setPosition(100, 50);

	textHiScore.setFont(font);
	textHiScore.setFillColor(Color::White);
	textHiScore.setCharacterSize(50);
	textHiScore.setPosition(1550, 50);

	HealthBar.setPosition(450, 950);
	HealthBar.setFillColor(Color::Red);


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

void UI::UpdateWave(int waves)
{
	std::stringstream ss;

	ss << "WAVE:" << waves;
	textWave.setString(ss.str());

	ss.clear();
}

void UI::UpdateZombieCount(int counts)
{
	std::stringstream ss;

	ss << "ZOMBIES:" << counts;
	textZombieCount.setString(ss.str());

	ss.clear();
}

void UI::UpdateScore(int score)
{
	std::stringstream ss;

	ss << "SCORE:" <<score;
	textScore.setString(ss.str());

	ss.clear();
}

void UI::UpdateHiScore(int hiScore)
{
	std::stringstream ss;

	ss << "HI SCORE:" <<hiScore;
	textHiScore.setString(ss.str());

	ss.clear();
}

void UI::UpdateHealthBar(int maxHealth, int currHealth)
{
	float healthPer = (100.f-((maxHealth - currHealth))) / 100.f;
	
	currHealthXsize = MaxhealthXsize * healthPer;

	if (currHealthXsize < 0)
	{
		currHealthXsize = 0;
	}

	HealthBar.setSize(Vector2f(currHealthXsize, 50.f));

}

void UI::UpdateUi(int curMag, int maxMag, int totalAmmo, int waves, int counts, int score, int hiScore, int playerMaxhealth, int playerCurrhealth)
{
	UpdatecurrMagazine(curMag);
	UpdateMaxMag(maxMag);
	UpdateTotalAmmo(totalAmmo);
	UpdateWave(waves);
	UpdateZombieCount(counts);
	UpdateScore(score);
	UpdateHiScore(hiScore);
	UpdateHealthBar(playerMaxhealth, playerCurrhealth);
}

void UI::DrawUi(RenderWindow& window)
{
	window.draw(textcurrMagazine);
	window.draw(textMaxMag);
	window.draw(textTotalAmmo);
	window.draw(textWave);
	window.draw(textZombieCount);
	window.draw(textScore);
	window.draw(textHiScore);
	window.draw(HealthBar);

	window.draw(magSprite);

}
