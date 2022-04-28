#include "Zombie.h"
#include "../Utils/TextureHolder.h"
#include "../Utils/Utils.h"
#include <iostream>

std::vector<ZombieInfo> Zombie::zombieInfo;
bool Zombie::isInitInfo = false;

Zombie::Zombie()
	:alive(true), bloodSpawned(true)
{
	if (!isInitInfo)
	{
		zombieInfo.resize((int)ZombieTypes::COUNT);
		{
			auto& info = zombieInfo[(int)ZombieTypes::BLOATER];
			info.type = ZombieTypes::BLOATER;
			info.textureFileName = "graphics/bloater.png";
			info.speed = 40.f;
			info.health = 5;
		}
		{
			auto& info = zombieInfo[(int)ZombieTypes::CHASER];
			info.type = ZombieTypes::CHASER;
			info.textureFileName = "graphics/chaser.png";
			info.speed = 70.f;
			info.health = 1;
		}
		{
			auto& info = zombieInfo[(int)ZombieTypes::CRAWLER];
			info.type = ZombieTypes::CRAWLER;
			info.textureFileName = "graphics/crawler.png";
			info.speed = 20.f;
			info.health = 3;
			isInitInfo = true;
		}	
	}
}

bool Zombie::OnHitted(float timeZomHit)
{
	//std::cout << "hit" << std::endl;
	//여기서 죽었을때도 처리 해야함 예를 들면 그 자리에 핏자국 만드는거
	//일정시간 지난 후 사라지기		
	health--;	
	if (health < 0)
	{		
		alive = false; //회전
		speed = 0; //움직임		
		
		timer -= timeZomHit;
		if (timer < 0.f)
		{
			Dead(!bloodSpawned);
		}
		return true;							
	}
	return false;
}

bool Zombie::IsALive()
{
	return alive;
}

void Zombie::Dead(bool spawn)
{
	if (bloodSpawned)
	{
		timer = START_BLOOD;
		sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
		isInitInfo = false;
	}
	else
	{
		timer = START_WAIT_BLOOD;
	}
}

void Zombie::Spawn(ZombieTypes type, IntRect arena, int x, int y, std::vector<Wall*> walls)
{

	auto& info = zombieInfo[(int)type];
	sprite.setTexture(TextureHolder::GetTexture(info.textureFileName));
	speed = info.speed;
	health = info.health;

	Utils::SetOrigin(sprite, Pivots::CC);
	FloatRect zombieBounds = sprite.getGlobalBounds();

	position.x = x;
	position.y = y;
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
				break;

			case Pivots::RC:
				position.x -= (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) - (v->GetWallRect().left);
				break;

			case Pivots::CT:
				position.y += (v->GetWallRect().top + v->GetWallRect().height) - (sprite.getGlobalBounds().top);
				break;

			case Pivots::CB:
				position.y -= (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) - (v->GetWallRect().top);
				break;

			defalut:
				break;
			}
			sprite.setPosition(position);
		}
	}
}

void Zombie::Update(float dt, Vector2f playerPosition)
{
	// 이동	
	Vector2f dir;

	dir = playerPosition - position;

	position += Utils::Normalize(dir) * speed * dt;
	sprite.setPosition(position);

	if (alive == true)
	{
		// 회전
		float radian = atan2(dir.y, dir.x);
		float dgree = radian * 180.f / 3.141592;
		sprite.setRotation(dgree);
	}	
}

bool Zombie::UpdateCollision(Player& player, Time time)
{
	if (sprite.getGlobalBounds().intersects(player.GetGobalBound()))
	{
		player.OnHitted(time);
		return true;
	}
	return false;
}

FloatRect Zombie::GetGlobalBound()
{
	return sprite.getGlobalBounds();
}

Sprite Zombie::GetSprite()
{
	return sprite;
}
