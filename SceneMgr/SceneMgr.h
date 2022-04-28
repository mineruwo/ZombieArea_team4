#pragma once
#include <SFML/Graphics.hpp>
#include "../Scene/Title.h"
#include "../Scene/Pause.h"
#include "../Scene/GameOver.h"
#include "../Scene/LevelUp.h"
#include "../Utils/InputMgr.h"

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
	Scene currscene;
	RenderWindow* window;

	Title title;
	// Game game;
	LevelUp levelup;
	Pause pause;
	GameOver gameover;


public:


	SceneMgr(RenderWindow& window);
	~SceneMgr();

	void sceneInitialize();
	void SceneUpdate(); // Ű���� �����ϴ°� switch case �ۼ�
	void SceneChange(Scene id);
	void SceneDraw(); //


};

