#pragma once
#include "Scene.h"
#include "Utils/TextureHolder.h"
#include "Utils/InputMgr.h"
#include "Player/Player.h"
#include "Player/PickUp.h"

using namespace sf;

class NewLevelUp : public Scene
{
private:
	std::string textureFileName;
	Sprite sprite;
	Text Upgrade;
public:
	virtual void Init();
	virtual void Update(Player& player, PickUp& pickup);
	virtual void Draw(RenderWindow& window);
	virtual void Release();
};