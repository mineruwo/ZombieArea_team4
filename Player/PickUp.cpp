#include "PickUp.h"
#include <iostream>

PickUp::PickUp(PickupType type)
	:type(type), amount(5)

{
	string textureID;

	switch (this->type)
	{
	case PickupType::AMMO:
		textureID = "graphics/ammo_pickup.png";
		value = AMMO_START_VALUE;
		break;

	case PickupType::HEALTH:
		textureID = "graphics/health_pickup.png";
		value = HEALTH_START_VALUE;
		break;
	}
	sprite.setTexture(TextureHolder::GetTexture(textureID));

	Utils::SetOrigin(sprite, Pivots::CC);

	Spawn(false);
}

void PickUp::Update(float dt)
{
	timer -= dt;
	if (timer < 0.f)
	{
		Spawn(!spawned);
	}
}

void PickUp::Spawn(bool spawn)
{
	spawned = spawn;
	if (spawned)
	{
		timer = START_SECONDS_FOR_LIVE;
		
		int x = Utils::RandomRange(arena.left, arena.left + arena.width );

		int y = Utils::RandomRange(arena.top, arena.top + arena.height);

		Vector2f position;
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
	else
	{
		timer = START_WAIT_TIME;
	}
}
void PickUp::GotIt(Player* player)
{
	switch (type)
	{
	case PickupType::AMMO:
		//std::cout << "AMMO" << std::endl;
		player->GetAmmoItem(amount);
		Spawn(true);
		break;
	case PickupType::HEALTH:	
		//std::cout << "HEALTH" << std::endl;
		player->GetHealthItem(amount);
		Spawn(true);
		break;
	}
	//return value;

	//저 출력문 구간엔 실제로 해야하는 일들 리턴해줘야 해.
}

void PickUp::SetArena(IntRect rect)
{
	arena = rect;
}

bool PickUp::IsSpwawned()
{
	return spawned;
}

Sprite PickUp::GetSprite()
{
	return sprite;
}

FloatRect PickUp::GetGlobalBounds()
{
	return sprite.getGlobalBounds();
}


void PickUp::UpgradePickupAmmo()
{
	totalAmmo += 5;
}

void PickUp::UpgradePickupHealth()
{
	totalHealth += 10;
}

