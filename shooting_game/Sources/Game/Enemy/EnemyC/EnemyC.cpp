#include <math.h>

#include "EnemyC.h"
#include "Game/Enemy/EnemyBullet/EnemyBullet.h"
#include "Common/SceneBase/SceneBase.h"
#include "Game/Scenes/GameScene/GameScene.h"

constexpr auto PI = 3.141592;

EnemyC::EnemyC(std::queue<VecTime> route) : EnemyBase(route)
{
    _routeQueue = route;
}

bool EnemyC::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyC::Draw()
{
    Circle(*_position, _size).draw(Palette::Cyan);
}

void EnemyC::Shot(float deltaTime, Vec2* playerPosition)
{
    if (_coolTime <= 0)
    {
        _coolTime = kShotCoolTime;
        std::vector<Vec2> moveList;
        moveList.push_back((*playerPosition - *_position).normalized());
        double targetRad;
        if (moveList[0].y >= 0)
        {
            targetRad = asin(moveList[0].x);
        }
        else
        {
            targetRad = asin(- moveList[0].x) + PI;
        }
        moveList.push_back(Vec2(sin(targetRad + (20 * PI / 180.0)), cos(targetRad + (20 * PI / 180.0))));
        moveList.push_back(Vec2(sin(targetRad + (-20 * PI / 180.0)), cos(targetRad + (-20 * PI / 180.0))));
        moveList.push_back(Vec2(sin(targetRad + (40 * PI / 180.0)), cos(targetRad + (40 * PI / 180.0))));
        moveList.push_back(Vec2(sin(targetRad + (-40 * PI / 180.0)), cos(targetRad + (-40 * PI / 180.0))));
        for (auto move : moveList)
        {
            MakeBullet(move);
        }
    }
    else
    {
        _coolTime -= deltaTime;
    }
}

void EnemyC::MakeBullet(Vec2 move)
{
    EnemyBullet* bullet = new EnemyBullet(move);
    GameScene::Instantiate(bullet, *_position);
    bullet->SetDestroy([&](EnemyBullet* destroyBullet)
    {
    _bulletList.remove(destroyBullet);
    });
    _bulletList.push_back(bullet);
}
