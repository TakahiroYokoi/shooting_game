#include "GameScene.h"
#include "Game/Player/Player.h"

GameScene::GameScene(const InitData& init):
    SceneBase(init)
{
    Player* player = new Player();
    Instantiate(player, Vec2(100, 100));
}
