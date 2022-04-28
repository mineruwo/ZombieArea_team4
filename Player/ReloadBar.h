#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/InputMgr.h"
using namespace sf;

class ReloadBar
{
private:
	RectangleShape reloadBar;
	Vector2f position;
	float maxXsize = 50;
	float xSize = 0;
public:
	ReloadBar();

	void Update(float dt, Vector2f playPos, bool& reload, float maxreload, float currreload);

	RectangleShape GetReloadBar();
};

