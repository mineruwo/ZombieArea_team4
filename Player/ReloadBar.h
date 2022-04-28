#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ReloadBar
{
private:
	RectangleShape reloadBar;
	Vector2f position;
	float xSize = 0;
public:
	ReloadBar();

	void Update(float dt, Vector2f playPos, bool reload);

	RectangleShape GetReloadBar();
};

