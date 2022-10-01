#include "EnemyBase.h"
#include "Common/SceneBase/SceneBase.h"

EnemyBase::EnemyBase(std::queue<VecTime> route)
{
    _routeQueue = route;
    _destroy = nullptr;
}

bool EnemyBase::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyBase::Update(float DeltaTime)
{
    _circle = Circle(*_position, _size);
}

void EnemyBase::Draw()
{
    _circle.draw(Palette::Red);
}

void EnemyBase::OnDestroy() {
    if (_destroy != nullptr) {
        _destroy(this);
    }
}

void EnemyBase::Move(float deltaTime)
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

void EnemyBase::Shot(float deltaTime, Vec2* playerPosition)
{
}

void EnemyBase::SetDestroy(std::function<void(EnemyBase*)> func)
{
    _destroy = func;
}

Circle EnemyBase::GetCircle()
{
    return _circle;
}

std::list<EnemyBullet*> EnemyBase::GetBulletList()
{
    return _bulletList;
}

void EnemyBase::Hit()
{
    SceneBase::Destroy(this);
}
