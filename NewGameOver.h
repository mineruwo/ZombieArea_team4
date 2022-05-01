#pragma once
#include "Scene.h"
class NewGameOver : public Scene
{

public:
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
};

