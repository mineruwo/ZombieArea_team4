#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "../Utils/TextureHolder.h"

using namespace sf;

class UI
{
private:
	Font font;
	Text textcurrMagazine;
	Text textMaxMag;
	Text textTotalAmmo;
	Text textWave;
	Text textZombieCount;
	Text textScore;
	Text textHiScore;

	RectangleShape HealthBar;
	float MaxhealthXsize = 800.f;
	float currHealthXsize;

	Sprite magSprite;

public:
	UI();
	void UpdatecurrMagazine(int curMag);
	void UpdateMaxMag(int maxMag);
	void UpdateTotalAmmo(int totalAmmo);
	void UpdateWave(int waves);
	void UpdateZombieCount(int counts);
	void UpdateScore(int score);
	void UpdateHiScore(int hiScore);

	void UpdateHealthBar(int maxHealth, int currHealth);
 
	void UpdateUi(int curMag, int maxMag, int totalAmmo, int waves, int counts, int score, int hiScore, int playerMaxhealth, int playerCurrhealth);

	void DrawUi(RenderWindow& window);
};

