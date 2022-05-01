#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Player/Player.h"
#include <string>
using namespace sf;
using namespace std;

enum class PickupType
{
	AMMO,
	HEALTH,
};

class PickUp
{
private:
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const float START_WAIT_TIME = 10.f;
	const float START_SECONDS_FOR_LIVE = 5.f;

	PickupType type;

	Sprite sprite;
	IntRect arena;

	int value;

	bool spawned;

	float timer;

	int amount;

	int totalHealth;
	int totalAmmo;

public:
	PickUp(PickupType type);

	void Update(float dt);

	void Spawn(bool spawn);

	std::vector <Wall*> walls;

	void GotIt(Player* player);

	void SetArena(IntRect rect);

	bool IsSpwawned();

	Sprite GetSprite();
	FloatRect GetGlobalBounds();

	void UpgradePickupAmmo();
	void UpgradePickupHealth();
 
};

