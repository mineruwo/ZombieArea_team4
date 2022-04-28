#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/Player.h"

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
	void SelectUpgrade(const Event& event ,Player& player);
	void Draw(RenderWindow& window);




};

