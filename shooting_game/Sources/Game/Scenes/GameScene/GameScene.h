#pragma once
#include "Common/SceneBase/SceneBase.h"
#include "Game/Player/Player.h"
#include "Game/Enemy/EnemyManager.h"

class GameScene : public SceneBase
{
public:
    GameScene(const InitData& init);
    ~GameScene();
private:
    Player* _player;
    EnemyManager* _enemyManager;
};

