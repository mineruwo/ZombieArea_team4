#include "Zombie.h"
#include "../Utils/TextureHolder.h"
#include "../Utils/Utils.h"
#include <iostream>

std::vector<ZombieInfo> Zombie::zombieInfo;
bool Zombie::isInitInfo = false;

Zombie::Zombie()
	:alive(true), bloodSpawned(true), timer(4.f), isTime(true)
{
		zombieInfo.resize((int)ZombieTypes::COUNT);
		{
			auto& info = zombieInfo[(int)ZombieTypes::BLOATER];
			info.type = ZombieTypes::BLOATER;
	if (!isInitInfo)
		{
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

bool Zombie::OnHitted(float timeZomHit, int demage)
{		
	isdemage = demage;
	health--;

	if (health <= 0)
	{		
		alive = false; 
		speed = 0; 		
		isdemage = 0;
		return true;
		//Dead(bloodSpawned);								
	}
	return false;
}


bool Zombie::IsALive()
{
	return alive;
}

//void Zombie::Dead()
//{
//	if (bloodSpawned)
//	{
//		//alive = false;
//		sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
//		//isInitInfo = false;
//	}
//	else
//	{
//		alive = true;
//	}	
//}

void Zombie::Spawn(ZombieTypes type, IntRect arena, int x, int y, std::vector<Wall*> walls)
{	
	auto& info = zombieInfo[(int)type];
	sprite.setTexture(TextureHolder::GetTexture(info.textureFileName));
	speed = info.speed * 0.1f* Utils::RandomRange(2,13);
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
	Vector2f dir;

	dir = playerPosition - position;

	position += Utils::Normalize(dir) * speed * dt;
	sprite.setPosition(position);

	if (alive)
	{
		float radian = atan2(dir.y, dir.x);
		float dgree = radian * 180.f / 3.141592;
		sprite.setRotation(dgree);
	}

	if (!alive)
	{		
		sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
		timer -= dt;
		if (timer < 0.f)
		{
			//sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
			//Dead();
			//isTime = false;			
		}
		//피가 생성  중
	}
	/*if (!alive)
	{
		sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
	}*/

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

bool Zombie::IsTime()
{
	return isTime;
}
