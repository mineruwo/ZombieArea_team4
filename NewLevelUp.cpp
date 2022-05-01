#include "NewLevelUp.h"


void NewLevelUp::Init()
{
	sprite.setTexture(TextureHolder::GetTexture(textureFileName));
	sprite.setPosition(0, 0);
    Upgrade.setFont(Scene::font);
    Upgrade.setFillColor(Color::White);
    Upgrade.setCharacterSize(80);
    Upgrade.setString(
        " 1.INCREASED RATE OF FIRE \n 2.INCREASED CLIP SIZE (NEXT RELOAD) \n 3.INCREASED MAX HEALTH \n"
        " 4.INCREASED RUN SPEED \n 5.MORE AND BETTER HEALTH PICKUPS \n 6.MORE AND BETTER AMMO PICKUPS \n");
    Upgrade.setPosition(200, 300);// 1920 1080

    currScene = SceneID::LevelUp;
}

void NewLevelUp::Update(Player& player, PickUp& pickup)
{
    if (InputMgr::GetKeyDown(Keyboard::Num1))
    {
        player.UpgradeShootRate();
        //연사속도 증가
    }
    if (InputMgr::GetKeyDown(Keyboard::Num2))
    {
        player.UpgrageMag();
        //탄창수증가
    }
    if (InputMgr::GetKeyDown(Keyboard::Num3))
    {
        player.UpgradeMaxHealth();
        //체력증가
    }
    if (InputMgr::GetKeyDown(Keyboard::Num4))
    {
        player.UpgradeSpeed();
        //이동속도증가
    }
    if (InputMgr::GetKeyDown(Keyboard::Num5))
    {
        pickup.UpgradePickupHealth();
        //아이템 회복량 증가
    }
    if (InputMgr::GetKeyDown(Keyboard::Num6))
    {
        pickup.UpgradePickupAmmo();
        //아이템 탄증가수 증가
    }
}

void NewLevelUp::Draw(RenderWindow& window)
{
    window.draw(sprite);
    window.draw(Upgrade);
}

void NewLevelUp::Release()
{
}
