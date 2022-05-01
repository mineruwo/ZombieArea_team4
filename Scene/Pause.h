#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pause
{
private:

	Text pauseText;
	Font font;

public:

	Pause();
	void Draw(RenderWindow& window);

};

