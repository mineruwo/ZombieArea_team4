#include "Scene.h"

Scene::Scene() : currScene(SceneID::Scene)
{
	font.loadFromFile("fonts/zombiecontrol.ttf");
}

void Scene::Init()
{
}

void Scene::Update()
{
}

void Scene::Draw(sf::RenderWindow& window)
{
}

void Scene::Release()
{
}

SceneID Scene::NextScene(SceneID Id)
{
	currScene = Id;
	return currScene;
}

SceneID Scene::GetCurrScene()
{
	return Scene::currScene;
}
