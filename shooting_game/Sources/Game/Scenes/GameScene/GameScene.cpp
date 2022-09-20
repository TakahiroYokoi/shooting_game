#include "GameScene.h"

GameScene::GameScene(const InitData& init):
    SceneBase(init)
{
    _player = new Player();
    Instantiate(_player, Vec2(100, 100));
    EnemyManager::Instance().Init(_player->_position);
}

void GameScene::Update(float deltaTime)
{
    EnemyManager::Instance().Update(deltaTime);
}

GameScene::~GameScene()
{
    delete _player;
    delete _enemyManager;
}
