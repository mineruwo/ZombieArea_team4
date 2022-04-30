#pragma once
#include <SFML/Graphics.hpp>
#include "../Player/Player.h"	
#include "../Wall/Wall.h"

using namespace sf;

enum class ZombieTypes
{
	BLOATER,
	CHASER,
	CRAWLER,
	COUNT,
};

struct ZombieInfo
{
	ZombieTypes type;
	std::string textureFileName;
	float speed;
	int health;
};

class Zombie
{
private:
	const float BLOATER_SPEED = 40;
	const float START_BLOOD = 5.f;
	const float START_WAIT_BLOOD = 10.f;

	Vector2f position;
	Sprite sprite;

	float speed;
	int health;

	float timer;
	bool bloodSpawned;
	int isdemage;

	static std::vector<ZombieInfo> zombieInfo;
	static bool isInitInfo;
	bool alive;
	bool isTime;

public:
	Zombie();

	bool OnHitted(float timeZomHit, int demage);
	bool IsALive();
	//void Dead();

	void Spawn(ZombieTypes type, IntRect arena, int x, int y, std::vector<Wall*> walls);
	void Update(float dt, Vector2f playerPosition);
	bool UpdateCollision(Player& player, Time time);

	FloatRect GetGlobalBound();
	Sprite GetSprite();

	bool IsTime();

};

