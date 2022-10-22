#include "EnemyD.h"
#include "Game/Enemy/EnemyBullet/EnemyBullet.h"
#include "Common/SceneBase/SceneBase.h"
#include "Game/Scenes/GameScene/GameScene.h"

EnemyD::EnemyD(std::queue<VecTime> route) : EnemyBase(route)
{
    _routeQueue = route;
}

bool EnemyD::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyD::Draw()
{
    Circle(*_position, _size).draw(Palette::Gold);
}

void EnemyD::Shot(float deltaTime, Vec2* playerPosition)
{
    if (_coolTime <= 0)
    {
        _coolTime = kShotCoolTime;
        EnemyBullet* bullet = new EnemyBullet((*playerPosition - *_position).normalized());
        GameScene::Instantiate(bullet, *_position);
        bullet->SetDestroy([&](EnemyBullet* destroyBullet) {
            _bulletList.remove(destroyBullet);
            });
        _bulletList.push_back(bullet);
    }
    else
    {
        _coolTime -= deltaTime;
    }
}
