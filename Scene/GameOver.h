#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameOver
{
private:

	Text overText;
	Font font;

public:

	GameOver();
	void Draw(RenderWindow& window);
};

