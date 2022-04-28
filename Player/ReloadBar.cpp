#include "ReloadBar.h"

ReloadBar::ReloadBar()
{
	reloadBar.setFillColor(Color::Yellow);
}

void ReloadBar::Update(float dt, Vector2f playPos, bool& reload, float maxreload, float currreload)
{
	float reloadPer= 1 + ((maxreload - currreload) / 100.f);
	
	float addSize= maxXsize / currreload;

	if (reload)
	{
		reloadBar.setPosition(playPos.x - 25, playPos.y - 25);
		
		xSize += addSize * reloadPer * dt;
		if (maxXsize * 0.7 < xSize)
		{
			reloadBar.setFillColor(Color::Green);
			if (InputMgr::GetKeyDown(Keyboard::R))
			{
				reload = false;
			}
		}
		reloadBar.setSize(Vector2f(xSize, 5.f));
	}
	else
	{
		reloadBar.setFillColor(Color::Yellow);
		xSize = 0;
	}

}

RectangleShape ReloadBar::GetReloadBar()
{
	return reloadBar;
}
