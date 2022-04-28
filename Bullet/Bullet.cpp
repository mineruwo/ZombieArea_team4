#include "Bullet.h"
#include "../Utils/TextureHolder.h"
#include "../Utils/Utils.h"
#include "../Utils/InputMgr.h"

Bullet::Bullet() : speed(DEFAULT_SPEED), isFired(false), demage(1)
{
	shape.setSize(Vector2f(10, 10));
	shape.setFillColor(Color::Yellow);
	Utils::SetOrigin(shape, Pivots::CC);
}

void Bullet::SetFired(bool active)
{
	isFired = active;
}

void Bullet::Shoot(Vector2f pos, Vector2f dir)
{
	SetFired(true);

	distance = 0.f;
	position = pos;
	direction = Utils::Normalize(dir);
	float degree = Utils::GetAngel(position, position + direction);
	shape.setPosition(position);
}

bool Bullet::IsFired()
{
	return isFired;
}

RectangleShape Bullet::GetShape()
{
	return shape;
}

void Bullet::Update(float dt)
{
	position += direction * speed * dt;
	shape.setPosition(position);

	distance += speed * dt;

	if (distance > DEFAULT_DISTANCE)
	{
		Stop();
	}

}

bool Bullet::UpdateCollision(const std::vector<Zombie*>& zombies, float time)
{

	FloatRect bounds = shape.getGlobalBounds();
	for (auto zombie : zombies)
	{
		if (zombie->IsALive())
		{
			if (bounds.intersects(zombie->GetGlobalBound()))
			{
				zombie->OnHitted(time);
				Stop();

				return true;
			}
		}
	}
	return false;
}

void Bullet::Stop()
{
	SetFired(false);
}
