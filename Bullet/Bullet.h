#pragma once
#include <SFML/Graphics.hpp>
#include "../Zombie/Zombie.h"
using namespace sf;

class Bullet
{
private :
	const float DEFAULT_SPEED = 900.f;
	const float DEFAULT_DISTANCE = 500.f;

	bool isFired;

	RectangleShape shape;

	Vector2f position;
	Vector2f direction;

	int demage;
	float speed;
	float distance;


	//발사 속도는 여기서 구현해야겠다. 간격? ㅇㅇ
public :
	Bullet();

	void SetFired(bool fired);
	void Shoot(Vector2f pos, Vector2f dir);
	void Update(float dt);
	bool UpdateCollision(const std::vector<Zombie*>& zombies, Time time);
	void Stop();
	bool IsFired();

	RectangleShape GetShape(); 
	
};

