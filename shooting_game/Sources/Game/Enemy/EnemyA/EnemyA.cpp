#include "EnemyA.h"
#include "Common/SceneBase/SceneBase.h"

EnemyA::EnemyA(std::queue<VecTime> route) : EnemyBase(route)
{
    _routeQueue = route;
}

bool EnemyA::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyA::Draw()
{
    Circle(*_position, _size).draw(Palette::Red);
}
