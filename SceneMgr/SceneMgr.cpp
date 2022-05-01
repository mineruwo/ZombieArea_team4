#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
}

SceneMgr::~SceneMgr()
{

}

void SceneMgr::sceneInitialize(RenderWindow& window, Vector2i resolution)
{

    window.setMouseCursorVisible(false);

    switch (currscene)
    {
    case Scene::TITLE:
        break;
    case Scene::GamePlay:
        play.initialize(resolution);
        break;
    case Scene::LEVELUP:
        break;
    case Scene::PAUSE:
        break;
    case Scene::GAMEOVER:
        break;
    }
}

void SceneMgr::SceneUpdate(Player& player, PickUp& pickup)
{
    switch (currscene)
    {
    case Scene::TITLE:
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GamePlay);
        }
        break;
    case Scene::GamePlay:
        if (InputMgr::GetKeyDown(Keyboard::P))
        {
            SceneChange(Scene::PAUSE);
        }
        break;
    case Scene::LEVELUP:
        levelup.SelectUpgrade(player, pickup);
        SceneChange(Scene::GamePlay);
        break;
    case Scene::PAUSE:
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GamePlay);
        }
        break;
    case Scene::GAMEOVER:
        if (InputMgr::GetKeyDown(Keyboard::Enter))
        {
            SceneChange(Scene::GamePlay);
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

void SceneMgr::SceneDraw(RenderWindow& window, View& mainview, View& UiView)
{
    window.clear();

    switch (currscene)
    {
    case Scene::TITLE:
        title.Draw(window);
        break;
    case Scene::GamePlay:
        play.draw(window, mainview, UiView);
        break;
    case Scene::LEVELUP:
        levelup.Draw(window);
        break;
    case Scene::PAUSE:
        pause.Draw(window);
        break;
    case Scene::GAMEOVER:
        gameover.Draw(window);
        break;
    }

    window.display();
}