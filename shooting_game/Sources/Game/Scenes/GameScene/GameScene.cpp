#include "GameScene.h"

GameScene::GameScene(const InitData& init):
    SceneBase(init)
{
    _player = new Player();
    Instantiate(_player, Vec2(100, 100));
    _enemyManager = new EnemyManager(_player->_position);
    Instantiate(_enemyManager, Vec2(0, 0));
}

GameScene::~GameScene()
{
    delete _player;
    delete _enemyManager;
}
