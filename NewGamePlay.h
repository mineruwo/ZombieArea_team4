#pragma once
#include "Scene.h"
#include "Utils/InputMgr.h"
#include "Utils/Utils.h"
#include "Player/Player.h"
#include "Zombie/Zombie.h"
#include "Wall/Wall.h"
#include "Bullet/Bullet.h"
#include "Player/PickUp.h"
#include "Scene/Title.h"
#include "Scene/LevelUp.h"
#include "Player/ReloadBar.h"
#include "UI/UI.h"
#include "Scene/Pause.h"
#include "Scene/GameOver.h"

using namespace sf;
using namespace std;

class NewGamePlay :
    public Scene
{
private:
	View mainView;
	View UiView;

	std::vector <Wall*> walls;
	std::vector<Zombie*> zombies;
	std::list<PickUp*> items;

	Player player;
	PickUp pickup;

	Time playTime;

	Texture& texBackground = TextureHolder::GetTexture("graphics/background_sheet.png");

	VertexArray tileMap;
	Sprite spriteCrosshair;
	Texture textureCrosshair = TextureHolder::GetTexture("graphics/crosshair.png");

	UI ui;
	ReloadBar reloaing;

	const int START_ZOMBIE_COUNT = 20;
	int zombieCount;

	int waves = 0;
	int score = 0;
	int hiScore = 0;

public:

	NewGamePlay();

	virtual void Init(Vector2i resolution);
	virtual void Update(Time dt, RenderWindow& window);
	virtual void Draw(RenderWindow& window);
	virtual void Release();

	int CreateBackGround(VertexArray& va, IntRect arena);

	void CreateZombies(std::vector<Zombie*>& zombies, int count, IntRect arena, std::vector <Wall*> walls);

	void CreateWalls(std::vector<Wall*>& walls, IntRect arena);
};

