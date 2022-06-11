#include "GameScene.h"
#include "Game/Player/Player.h"
#include "Game/Enemy/EnemyManager.h"

GameScene::GameScene(const InitData& init):
    SceneBase(init)
{
    Player* player = new Player();
	EnemyManager* enemyManager = new EnemyManager();
    Instantiate(player, Vec2(100, 100));
	Instantiate(enemyManager, Vec2(0, 0));
	
}
