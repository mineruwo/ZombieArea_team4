#include "SceneMgr.h"

SceneMgr::SceneMgr()
{

}

bool SceneMgr::sceneOper(const Event& event)
{

	return true;
}



void SceneMgr::sceneChange(Scene id)
{
	currscene = id;
}

