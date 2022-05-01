#pragma once
#include "Scene.h"
#include "Utils/InputMgr.h"
#include "Utils/Utils.h"
#include "Player/Player.h"
#include "Zombie/Zombie.h"
#include "Wall/Wall.h"
#include "Bullet/Bullet.h"
#include "Player/PickUp.h"
#include "Scene/Title.h"
#include "Scene/LevelUp.h"
#include "Player/ReloadBar.h"
#include "UI/UI.h"
#include "Scene/Pause.h"
#include "Scene/GameOver.h"

using namespace sf;
using namespace std;

class NewGamePlay :
    public Scene
{
private:
	View mainView;
	View UiView;
public:
	virtual void Init();
	virtual void Update();
	virtual void Draw(RenderWindow& window);
	virtual void Release();

	int CreateBackGround(VertexArray& va, IntRect arena);

	void CreateZombies(std::vector<Zombie*>& zombies, int count, IntRect arena, std::vector <Wall*> walls);

	void CreateWalls(std::vector<Wall*>& walls, IntRect arena);
};

