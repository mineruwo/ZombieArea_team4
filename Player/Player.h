#pragma once
#include <SFML/Graphics.hpp>
#include "../Wall/Wall.h"
#include <vector>
#include <list>

using namespace sf;

class PickUp;
class Bullet;
class Zombie;


class Player
{
private:
	const float START_SPEED = 200;
	const float START_SHOTRATE = 0.5f;
	//second 단위에오
	const float START_HEALTH = 100000;
	const float START_IMMUNE_MS = 3000;
	//밀리세컨드라 1000이 1초인점 감안해야해요.

	const int START_TOTAL_AMMO = 300;
	const int START_MAX_MAGAZINE = 30;
	const int START_RELOADING_TIME = 3;

	Vector2f position;

	std::string texFileName;
	Sprite sprite;

	Vector2i resolution;
	IntRect arena;

	int tileSize;

	Vector2f direction;
	float speed;
	float shootRate;
	float timer;

	int MaxMagazine;
	int currMagazine;
	int totalAmmo;
	float reloadingTime;
	float reloadtimer;
	bool isReload;

	int health;
	int maxHealth;
	float immuneMs;
	float immuneTimer = 0.f;
	bool isImuune = false;



	Time lastHit;

	const int BULLET_CACHE_SIZE = 1000;
	std::list<Bullet*> unuseBullets;
	std::list<Bullet*> useBullets;

	float distanceToMuzzle;

public:
	Player();
	~Player();

	void Shoot(Vector2f dir);

	void Spawn(IntRect arena, Vector2i res, int tileSize);

	bool OnHitted(Time timeHit);

	Time GetLastTime() const;
	FloatRect GetGobalBound() const;
	Vector2f GetPosition() const;
	float GetRotation() const;
	Sprite GetSprite() const;
	int GetHealth() const;

	void Update(float dt, std::vector<Wall*> walls);
	void Draw(RenderWindow& window);
	void GetHealthItem(int amount);

	bool UpdateCollision(const std::vector<Zombie*>& zombies, float time);
	bool UpdateCollisionPickup(const std::list<PickUp*>& items);

	void UpgradeSpeed();
	void UpgradeMaxHealth();

	int GetCurrMag();
	int GetMaxMag();
	int GetTotalAmmo();

	int GetHealth();
	int GetMaxHealth();

	void Reload();
	bool IsReload();

};

