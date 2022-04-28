#pragma once
#include <SFML/Graphics.hpp>
#include "../Scene/Title.h"

using namespace sf;

enum class Scene
{
	TITLE,
	GAME,
	LEVELUP,
	PAUSE,
	GAMEOVER,

};

class SceneMgr
{
private:

	Scene scene;
	bool titleOn;
	bool lvUP;
	bool pause;
	bool gameover;


public:
	SceneMgr();
	bool sceneOper(const Event& event);
	void sceneChange();

};

