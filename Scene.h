#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
enum class SceneID
{
	Title,
	GamePlay,
	Pause,
	LevelUp,
	GameOver,
};

class Scene
{
protected:
	sf::Font font;
	SceneID currScene;
private:
public:
	Scene();

	virtual void Init(Vector2i resolution);
	virtual void Update(Time dt, RenderWindow& window);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Release();

	SceneID NextScene(SceneID Id);
	SceneID GetCurrScene();
};

