#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Title
{

private:

	std::string textureFileName;
	Sprite sprite;
	Text PressEnter;
	Font font;

public:

	Title();
	bool IsTitleOn(const Event& event);
	//Sprite GetSprite();
	void Draw(RenderWindow& window);



};