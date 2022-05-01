#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/InputMgr.h"
#include "../NewTitle.h"
#include "../NewPause.h"
#include "../NewGamePlay.h"
#include "../NewGameOver.h"
#include "../NewLevelUp.h"
#include "../Scene.h"

using namespace sf;

class SceneMgr
{
private:
	Scene* scene;
	SceneID currScene;

public:
	SceneMgr();
	void ChangeScene(SceneID Id);

	void SceneInit(Vector2i resolution);
	void SceneUpdate();
	void SceneDraw(RenderWindow& window);
	void SceneRelease();

};

