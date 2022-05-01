#pragma once
#include "Scene.h"
#include "Utils/InputMgr.h"
#include "Utils/TextureHolder.h"

using namespace sf;

class NewTitle : public Scene
{
private:
	std::string textureFileName;
	Sprite sprite;
	Text PressEnter;

public:
	virtual void Init();
	virtual void Update();
	virtual void Draw(RenderWindow& window);
	virtual void Release();
};

