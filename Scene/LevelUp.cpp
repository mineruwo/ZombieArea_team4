#include "LevelUp.h"
#include "../Utils/TextureHolder.h"


LevelUp::LevelUp() :textureFileName("graphics/background.png")
{
    sprite.setTexture(TextureHolder::GetTexture(textureFileName));
    sprite.setPosition(0, 0);

    font.loadFromFile("fonts/zombiecontrol.ttf");
    Upgrade.setFont(font);
    Upgrade.setFillColor(Color::White);
    Upgrade.setCharacterSize(80);
    Upgrade.setString(
        " 1.INCREASED RATE OF FIRE \n 2.INCREASED CLIP SIZE (NEXT RELOAD) \n 3.INCREASED MAX HEALTH \n"
        " 4.INCREASED RUN SPEED \n 5.MORE AND BETTER HEALTH PICKUPS \n 6.MORE AND BETTER AMMO PICKUPS \n");
    Upgrade.setPosition(200, 300);// 1920 1080
}

void LevelUp::SelectUpgrade(Player& player, PickUp& pickup)
{
    if (InputMgr::GetKeyDown(Keyboard::Num1))
    {
        player.UpgradeShootRate();
        //����ӵ� ����
    }
    if (InputMgr::GetKeyDown(Keyboard::Num2))
    {
        player.UpgrageMag();
        //źâ������
    }
    if (InputMgr::GetKeyDown(Keyboard::Num3))
    {
        player.UpgradeMaxHealth();
        //ü������
    }
    if (InputMgr::GetKeyDown(Keyboard::Num4))
    {
        player.UpgradeSpeed();
        //�̵��ӵ�����
    }
    if (InputMgr::GetKeyDown(Keyboard::Num5))
    {
        pickup.UpgradePickupHealth();
        //������ ȸ���� ����
    }
    if (InputMgr::GetKeyDown(Keyboard::Num6))
    {
        pickup.UpgradePickupAmmo();
        //������ ź������ ����
    }
}

void LevelUp::Draw(RenderWindow& window)
{
    window.draw(sprite);
    window.draw(Upgrade);
}