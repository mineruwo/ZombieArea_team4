#pragma once
#include <SFML/Graphics.hpp>
#include "Utils/InputMgr.h"
#include "Utils/Utils.h"
#include "SceneMgr/SceneMgr.h"

using namespace sf;

class Framework
{
private:
	
	Vector2i resolution;
	SceneMgr sceneMgr;
	RenderWindow window; 
	Clock clock;

public:
	Framework();
	void Initialize();
	void Update();
	void Draw();

};

