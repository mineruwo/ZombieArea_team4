#pragma once
#include <SFML/Graphics.hpp>
#include "../Scene/Title.h"
#include "../Scene/Pause.h"
#include "../Scene/GameOver.h"
#include "../Scene/LevelUp.h"
#include "../Scene/gamePlay.h"
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
	TextureHolder textureHolder;

	Title title;
	GamePlay play;
	LevelUp levelup;
	Pause pause;
	GameOver gameover;


	Sprite spriteCrosshair;


public:

	SceneMgr();
	~SceneMgr();

	void sceneInitialize(RenderWindow& window, Vector2i resolution);
	void SceneUpdate(Player& player, PickUp& pickup); // 키값에 반응하는것 switch case 작성
	void SceneChange(Scene id);
	void SceneDraw(RenderWindow& window);
};