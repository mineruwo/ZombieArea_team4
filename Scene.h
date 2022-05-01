#pragma once
#include <SFML/Graphics.hpp>

enum class SceneID
{
	Title,
	GamePlay,
	Pause,
	LevelUp,
	GameOver,
	Scene,
};

class Scene
{
protected:
	sf::Font font;
	SceneID currScene;
private:
public:
	Scene();

	virtual void Init();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
	virtual void Release();

	SceneID NextScene(SceneID Id);
	SceneID GetCurrScene();
};

