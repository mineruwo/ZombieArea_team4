#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/Player.h"
#include "../Player/PickUp.h"

using namespace sf;




class LevelUp
{

private:

	std::string textureFileName;
	Sprite sprite;
	Text Upgrade;
	Font font;

public:

	LevelUp();
	void SelectUpgrade(Player& player, PickUp& pickup);
	void Draw(RenderWindow& window);




};

