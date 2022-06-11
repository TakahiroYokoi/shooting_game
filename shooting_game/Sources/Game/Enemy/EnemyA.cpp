#include "EnemyA.h"
#include "Common/SceneBase/SceneBase.h"
#include "EnemyManager.h"

EnemyA::EnemyA(std::queue<VecTime> route)
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

void EnemyA::Update(float deltaTime)
{
    Move(deltaTime);
}

void EnemyA::Draw()
{
    Circle(*_position, _size).draw();
}

void EnemyA::Move(float deltaTime)
{
    if (_time < 0)
    {
        _time = _routeQueue.front()._time;
        _vec = _routeQueue.front()._vec;
        _routeQueue.pop();
    }
    *_position += _vec.normalized() * kSpeed * deltaTime;
    _time -= deltaTime;
    if (_position->x < -_size)
    {
        SceneBase::Destroy(this);
    }
}
