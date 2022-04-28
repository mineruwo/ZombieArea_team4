#include "SceneMgr.h"

SceneMgr::SceneMgr(RenderWindow& window)
    : window(&window)
{
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::sceneInitialize()
{
        switch (currscene)
        {
        case Scene::TITLE:
            break;
        case Scene::GAME:
        //    scene = new GAME;
            break;
        case Scene::LEVELUP:
            break;
        case Scene::PAUSE:
            break;
        case Scene::GAMEOVER:
            break;
        }
}

void SceneMgr::SceneUpdate()
{
    switch (currscene)
    {
    case Scene::TITLE:
        SceneMgr::SceneDraw();
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GAME);
        }
        break;
    case Scene::GAME:
        SceneMgr::SceneDraw();
        if (InputMgr::GetKeyDown(Keyboard::P))
        {
            SceneChange(Scene::PAUSE);
        }
        break;
    case Scene::LEVELUP:
        SceneMgr::SceneDraw();
        LevelUp::SelectUpgrade();
        SceneChange(Scene::GAME);

        break;
    case Scene::PAUSE:
        SceneMgr::SceneDraw();
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GAME);
        }
        break;
    case Scene::GAMEOVER:
        SceneMgr::SceneDraw();
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GAME);
        }
        break;
    default:
        break;
    }

}


void SceneMgr::SceneChange(Scene id)
{
    currscene = id;
}

void SceneMgr::SceneDraw()
{
    switch (currscene)
    {
    case Scene::TITLE:
    title.Draw(*window);
        break;
    case Scene::GAME:
      //  Game::Draw(*window);
        break;
    case Scene::LEVELUP:
        levelup.Draw(*window);
        break;
    case Scene::PAUSE:
        pause.Draw(*window);
        break;
    case Scene::GAMEOVER:
        gameover.Draw(*window);
        break;
    }

}




