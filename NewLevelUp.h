#pragma once
#include "Scene.h"

using namespace sf;

class NewLevelUp : public Scene
{
public:
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
};