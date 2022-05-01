#pragma once
#include "Scene.h"
class NewGameOver : public Scene
{
private:
	Text overText;
public:
	virtual void Init();
	virtual void Update();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
};

