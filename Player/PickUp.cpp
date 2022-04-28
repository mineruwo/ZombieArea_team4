#include "PickUp.h"
#include <iostream>

PickUp::PickUp(PickupType type)
	:type(type)
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
		
		int x = Utils::RandomRange(arena.left, arena.left + arena.width);

		int y = Utils::RandomRange(arena.top, arena.top + arena.height);

		sprite.setPosition(Vector2f(x, y));
	}
	else
	{
		timer = START_WAIT_TIME;
	}
}

//totalAmmo;
int PickUp::GotIt()
{
	switch (type)
	{
	case PickupType::AMMO: // 총알
		//총알을 먹은 갯수 만큼 증가
		//totalAmmo++;



		break;
	case PickupType::HEALTH:
		//구급상자를 먹은 갯수 만큼 증가
		//totalHealth++;
		
		break;
	default:
		break;
	}
	return 0;

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

//void PickUp::AddAmmo()
//{
//	PickupType::AMMO;
//	value += AMMO_START_VALUE;
//}
//
//void PickUp::AddPickup()
//{
//
//
//}

Sprite PickUp::GetSprite()
{
	return sprite;
}

FloatRect PickUp::GetGlobalBounds()
{
	return sprite.getGlobalBounds();
}
