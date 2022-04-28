#include "ReloadBar.h"

ReloadBar::ReloadBar()
{
	reloadBar.setFillColor(Color::Yellow);
}

void ReloadBar::Update(float dt, Vector2f playPos, bool reload)
{
	if (reload)
	{
		reloadBar.setPosition(playPos.x - 25, playPos.y - 25);
		xSize += 15 * dt;
		reloadBar.setSize(Vector2f(xSize, 3.f));
	}
	else
	{
		xSize = 0;
	}

}

RectangleShape ReloadBar::GetReloadBar()
{
	return reloadBar;
}
