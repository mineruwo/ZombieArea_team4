#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pause
{
private:

	Text PauseText;
	Font font;

public:

	Pause();
	void Draw(RenderWindow& window);

};

