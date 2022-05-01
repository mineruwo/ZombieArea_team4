#pragma once
#include "Scene.h"
#include "Utils/InputMgr.h"

using namespace sf;
class NewPause : public Scene
{
private:
	Text pauseText;
public:
	virtual void Init();
	virtual void Update();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
};

