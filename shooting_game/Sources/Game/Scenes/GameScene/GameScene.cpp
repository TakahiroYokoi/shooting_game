#include "GameScene.h"

struct InitData;

GameScene::GameScene(const InitData& init):
    SceneBase(init)
{
    _player = new Player();
    Instantiate(_player, Vec2(100, 540));
    EnemyManager::Instance().Init(_player);
}

void GameScene::Update(float deltaTime)
{
    EnemyManager::Instance().Update(deltaTime);
}

GameScene::~GameScene()
{
    delete _player;
}
