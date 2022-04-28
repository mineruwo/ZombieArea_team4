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

	Sprite magSprite;

public:
	UI();
	void UpdatecurrMagazine(int curMag);
	void UpdateMaxMag(int maxMag);
	void UpdateTotalAmmo(int totalAmmo);
 
	void UpdateUi(int curMag, int maxMag, int totalAmmo);

	void DrawUi(RenderWindow& window);
};

