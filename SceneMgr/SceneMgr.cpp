#include "SceneMgr.h"

SceneMgr::SceneMgr()
{

}


//bool SceneMgr::sceneOper(const Event& event)
//{
//	switch (event.type)
//	{
//	case Keyboard::Enter:
//		titleOn = false;
//		break;
//	case Keyboard::Num1:
//		lvUP = false;
//		//����ӵ� ��
//		break;
//	case Keyboard::Num2:
//		lvUP = false;
//		//źâ����
//	case Keyboard::Num3:
//		lvUP = false;
//		//ü����
//	case Keyboard::Num4:
//		lvUP = false;
//		//�̵��ӵ���
//	case Keyboard::Num5:
//		lvUP = false;
//		//������ ȸ���� ��
//	case Keyboard::Num6:
//		lvUP = false;
//		//������ ź��� ��
//		break;
//	}
//	return;
//}

bool SceneMgr::sceneOper(const Event& event)
{

	return true;
}




void SceneMgr::sceneChange(Scene id)
{
	currscene = id;
}

