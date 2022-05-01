#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Utils/TextureHolder.h"
#include "../Utils/InputMgr.h"
#include "../Utils/Utils.h"
#include "../Player/Player.h"
#include "../Zombie/Zombie.h"
#include "../Wall/Wall.h"
#include "../Bullet/Bullet.h"
#include "../Player/PickUp.h"
#include "../Player/ReloadBar.h"
#include "../UI/UI.h"

using namespace sf;
using namespace std;

class GamePlay
{
private:
	IntRect arena;
	Player player;
	std::vector <Wall*> walls;
	std::vector<Zombie*> zombies;

	Clock clock;
	Time playTime;

	UI ui;
	ReloadBar reloaing;

	std::list<PickUp*> items;
	VertexArray tileMap;

	PickUp pickup = (PickupType)Utils::RandomRange(0, 2);

	int zombiesCount;
	int waves = 0;
	int score = 0;
	int hiScore = 0;

	Texture& texBackground = TextureHolder::GetTexture("graphics/background_sheet.png");

	const int START_ZOMBIES_COUNT;

public:
	GamePlay();

	void initialize(Vector2i resolution);
	void update(RenderWindow& window, View& mainview);
	void draw(RenderWindow& window, View& mainview, View& UiView);


	int CreateBackGround(VertexArray& va, IntRect arena);

	void CreateZombies(std::vector<Zombie*>& zombies, int count, IntRect arena, std::vector <Wall*> walls);

	void CreateWalls(std::vector<Wall*>& walls, IntRect arena);



};