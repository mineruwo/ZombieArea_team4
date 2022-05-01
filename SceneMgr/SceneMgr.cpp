#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	scene = new NewTitle;
	currScene = SceneID::Title;
}

void SceneMgr::ChangeScene(SceneID Id)
{
	delete scene;

	switch (Id)
	{
	case SceneID::Title:
		scene = new NewTitle;
		currScene = SceneID::Title;
		break;
	case SceneID::GamePlay:
		scene = new NewGamePlay;
		currScene = SceneID::GamePlay;
		break;
	case SceneID::Pause:
		scene = new NewPause;
		currScene = SceneID::Pause;
		break;
	case SceneID::LevelUp:
		scene = new NewLevelUp;
		currScene = SceneID::LevelUp;
		break;
	case SceneID::GameOver:
		scene = new NewGameOver;
		currScene = SceneID::GameOver;
		break;
	}
}

void SceneMgr::SceneInit(Vector2i resolution)
{
	scene->Init();
}

void SceneMgr::SceneUpdate()
{
	scene->Update();

	if (currScene != scene->GetCurrScene())
	{
		SceneRelease();
		ChangeScene(scene->GetCurrScene());
	}

}

void SceneMgr::SceneDraw(RenderWindow& window)
{
	scene->Draw(window);
}

void SceneMgr::SceneRelease()
{
	scene->Release();
}
