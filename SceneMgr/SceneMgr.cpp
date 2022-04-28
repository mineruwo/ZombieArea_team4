#include "SceneMgr.h"



SceneMgr::SceneMgr()
{
	bool titleOn = true;
	bool lvUP = false;
	bool pause = false;
	bool gameover = false;
}

bool SceneMgr::sceneOper(const Event& event)
{
	switch (event.type)
	{
	case Keyboard::Enter:
		titleOn = false;
		break;
	case Keyboard::Num1:
		lvUP = false;
		//연사속도 증가
		break;
	case Keyboard::Num2:
		lvUP = false;
		//탄창수증가
	case Keyboard::Num3:
		lvUP = false;
		//체력증가
	case Keyboard::Num4:
		lvUP = false;
		//이동속도증가
	case Keyboard::Num5:
		lvUP = false;
		//아이템 회복량 증가
	case Keyboard::Num6:
		lvUP = false;
		//아이템 탄증가수 증가
		break;
	}
	return;
}

void SceneMgr::sceneChange()
{

	/*if (titleOn)
	{
		Title::Draw(RenderWindow& window)
	}*/

}

