#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Blood
{
private:
	std:: string bloodFileName;

	Vector2f position;
	Sprite sprite;

	bool isdecision;
public:
	Blood();

	void SetPosition(Vector2f zomposition);
	Sprite GetSprite() const;

	void SetDecision(bool isdecision);

	bool GetDecision();
};

