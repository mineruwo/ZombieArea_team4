#include "Blood.h"
#include "../Utils/Utils.h"
#include "../Utils/TextureHolder.h"


Blood::Blood()
	:bloodFileName("graphics/blood.png"), isdecision(false)
{
	sprite.setTexture(TextureHolder::GetTexture(bloodFileName));
	Utils::SetOrigin(sprite, Pivots::CC);
}

void Blood::SetPosition(Vector2f zomposition)
{
	sprite.setPosition(zomposition);
}

Sprite Blood::GetSprite() const
{
	return sprite;
}

void Blood::SetDecision(bool decision)
{
	isdecision = decision;
}

bool Blood::GetDecision()
{
	return isdecision;
}
