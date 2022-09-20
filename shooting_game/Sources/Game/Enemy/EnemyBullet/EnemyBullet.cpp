#include "EnemyBullet.h"
#include "Common/SceneBase/SceneBase.h"

EnemyBullet::EnemyBullet(Vec2* target) {
    _target = *target;
}

bool EnemyBullet::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyBullet::Update(float deltaTime)
{
    Move(deltaTime);
}

void EnemyBullet::Draw()
{
    Circle(*_position, _size).draw();
}

void EnemyBullet::Move(float deltaTime)
{
    Vec2 virtualSize = Window::GetState().virtualSize;
    if (_move == Vec2::Zero()) {
        _move = _target - *_position;
    }
    *_position += _move.normalized() * kSpeed * deltaTime;
    if (_position->x >= virtualSize.x + _size ||
        _position->x <= _size ||
        _position->y >= virtualSize.y + _size ||
        _position->y <= _size)
    {
        SceneBase::Destroy(this);
    }
}
