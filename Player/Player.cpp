#include "Player.h"
#include "../Utils/Utils.h"
#include "../Utils/InputMgr.h"
#include "../Bullet/Bullet.h"
#include "../Zombie/Zombie.h"
#include "../Player/PickUp.h"
#include <cmath>
#include <iostream>
#include "../Utils/TextureHolder.h"
#include <algorithm>

Player::Player()
	: speed(START_SPEED), health(START_HEALTH), maxHealth(START_HEALTH),
	arena(), resolution(), tileSize(0.f), immuneMs(START_IMMUNE_MS), distanceToMuzzle(25.f), shootRate(START_SHOTRATE), timer(0.f), 
	texFileName("graphics/player.png"), MaxMagazine(START_MAX_MAGAZINE), currMagazine(MaxMagazine), totalAmmo(START_TOTAL_AMMO), isReload(false), 
	reloadtimer(0.f),reloadingTime(START_RELOADING_TIME),player(player)
{
	sprite.setTexture(TextureHolder::GetTexture(texFileName));
	Utils::SetOrigin(sprite, Pivots::CC);

	for (int i = 0; i < BULLET_CACHE_SIZE; ++i)
	{
		unuseBullets.push_back(new Bullet());
	}
}

Player::~Player()
{
	for (auto bullet : unuseBullets)
	{
		delete bullet;
	}
	unuseBullets.clear();

	for (auto bullet : useBullets)
	{
		delete bullet;
	}
	useBullets.clear();
}

void Player::Shoot(Vector2f dir)
{
	Vector2f spawnPos = position + dir * distanceToMuzzle;

	if (unuseBullets.empty())
	{
		for (int i = 0; i < BULLET_CACHE_SIZE; ++i)
		{
			unuseBullets.push_back(new Bullet());
		}
	}

	Bullet* bullet = unuseBullets.front();
	unuseBullets.pop_front();

	useBullets.push_back(bullet);
	bullet->Shoot(spawnPos, dir);	
}

void Player::Spawn(IntRect arena, Vector2i res, int tileSize)
{
	this->arena = arena;
	resolution = res;
	this->tileSize = tileSize;

	position.x = arena.width * 0.5f;
	position.y = arena.height * 0.5f;
	sprite.setPosition(position.x, position.y);
}

bool Player::OnHitted(Time timeHit)
{
	if (timeHit.asMilliseconds() - lastHit.asMilliseconds() > immuneMs)
	{
		lastHit = timeHit;
		health -= 10;
		return true;
	}
	return false;
}

Time Player::GetLastTime() const
{
	return lastHit;
}

FloatRect Player::GetGobalBound() const
{
	return sprite.getGlobalBounds();
}

Vector2f Player::GetPosition() const
{
	return position;
}

float Player::GetRotation() const
{
	return sprite.getRotation();
}

Sprite Player::GetSprite() const
{
	return sprite;
}

int Player::GetHealth() const
{
	return health;
}

void Player::Update(float dt, std::vector <Wall*> walls)
{

	float h = InputMgr::GetAxis(Axis::Horizontal);
	float v= InputMgr::GetAxis(Axis::Vertical);
	Vector2f dir(h, v);

	float length = sqrt(dir.x * dir.x + dir.y * dir.y);
	if (length > 1)
	{
		dir /= length;
	}

	position += dir * speed * dt;
	sprite.setPosition(position);

	for (auto v : walls)
	{
		if (sprite.getGlobalBounds().intersects(v->GetWallRect()))
		{

			Pivots pivot = Utils::CollisionDir(v->GetWallRect(), sprite.getGlobalBounds());

			switch (pivot)
			{
			case Pivots::LC:
				position.x += (v->GetWallRect().left + v->GetWallRect().width) - (sprite.getGlobalBounds().left);
				InputMgr::HorInit();
				break;

			case Pivots::RC:
				position.x -= (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) - (v->GetWallRect().left);
				InputMgr::HorInit();
				break;

			case Pivots::CT:
				position.y += (v->GetWallRect().top + v->GetWallRect().height) - (sprite.getGlobalBounds().top);
				InputMgr::VerInit();
				break;

			case Pivots::CB:
				position.y -= (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) - (v->GetWallRect().top);
				InputMgr::VerInit();
				break;

			defalut:
				break;
			}
			
			sprite.setPosition(position);
		}
	}
	Vector2i mousePos = InputMgr::GetMousePosition();
	Vector2i mouseDir;
	mouseDir.x = mousePos.x - resolution.x * 0.5f;
	mouseDir.y = mousePos.y - resolution.y * 0.5f;
	float radian = atan2(mouseDir.y, mouseDir.x);
	float dgree = radian * 180.f / 3.141592;
	sprite.setRotation(dgree);


	timer += dt;
	if (isReload)
	{
		reloadtimer += dt;
	}

	if (reloadingTime < reloadtimer)
	{
		isReload = false;
	}

	if (InputMgr::GetMouseButton(Mouse::Button::Left))
	{
		if (timer > shootRate && currMagazine != 0 && !isReload)
		{
			Shoot(Utils::Normalize(Vector2f(mouseDir.x, mouseDir.y)));
			timer = 0.f;
			currMagazine--;
		}
	}

	if (InputMgr::GetKeyDown(Keyboard::R))
	{
		if (!isReload)
		{
			Reload();
			isReload = true;
			reloadtimer = 0.f;
		}
	
	}

	auto it = useBullets.begin();
	while (it != useBullets.end())
	{
		Bullet* bullet = *it;
		bullet->Update(dt);

		if (!bullet->IsFired())
		{
			it = useBullets.erase(it);
			unuseBullets.push_back(bullet);
		}
		else
		{
			++it;
		}
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
	for (auto bullet : useBullets)
	{
		window.draw(bullet->GetShape());
	}
}

void Player::GetHealthItem(int amount)
{
	health += amount;
	if (health > maxHealth)
	{
		health = maxHealth;
	}
	if (health < 0)
	{
		health = 0;
	}
}

bool Player::UpdateCollision(const std::vector<Zombie*>& zombies, float time)
{
	bool isCollided = false;
	for (auto bullet : useBullets)
	{
		if (bullet->UpdateCollision(zombies, time))
		{
			isCollided = true;
		}
	}
	return isCollided;
}

bool Player::UpdateCollisionPickup(const std::list<PickUp*>& items)
{
	FloatRect bounds = sprite.getGlobalBounds();

	bool isCollided = false;
	for (auto item : items)
	{
		if (bounds.intersects(item->GetGlobalBounds()))
		{
			item->GotIt(this);
			isCollided = true;
		}		
	}
	return isCollided;
}

void Player::UpgradeSpeed()
{
	speed += START_SPEED * 0.2f;
}

void Player::UpgradeMaxHealth()
{
	maxHealth += START_HEALTH * 0.2f;
}

int Player::GetCurrMag()
{
	return currMagazine;
}

int Player::GetMaxMag()
{
	return MaxMagazine;
}

int Player::GetTotalAmmo()
{
	return totalAmmo;
}
void Player::GetAmmoItem(int addAmount)
{
	totalAmmo += addAmount;
}

void Player::Reload()
{
	if (currMagazine < MaxMagazine && totalAmmo >= MaxMagazine)
	{
		totalAmmo -= MaxMagazine - currMagazine;

		currMagazine = MaxMagazine;
	}
	else if (currMagazine < MaxMagazine && totalAmmo < MaxMagazine - currMagazine)
	{
		if (totalAmmo == 0)
		{
			//총알이 없는 것을 표현
		}
		else
		{
			currMagazine += totalAmmo;
			totalAmmo = 0;
		}
	}
}

bool Player::IsReload()
{
	return isReload;
}



