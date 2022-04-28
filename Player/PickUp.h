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

	int totalAmmo;

	int totalHealth;

public:
	PickUp(PickupType type);

	void Update(float dt);

	void Spawn(bool spawn);
	int GotIt();

	void SetArena(IntRect rect);

	bool IsSpwawned();

	void PlayerUpdate();

	Sprite GetSprite();
	FloatRect GetGlobalBounds();

};

