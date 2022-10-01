#include "EnemyBullet.h"
#include "Common/SceneBase/SceneBase.h"

EnemyBullet::EnemyBullet(Vec2 move)
{
    _move = move;
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
    _circle = Circle(*_position, _size);
}

void EnemyBullet::Draw()
{
    _circle.draw();
}

void EnemyBullet::Move(float deltaTime)
{
    Vec2 virtualSize = Window::GetState().virtualSize;
    *_position += _move * kSpeed * deltaTime;
    if (_position->x >= virtualSize.x + _size ||
        _position->x <= -_size ||
        _position->y >= virtualSize.y + _size ||
        _position->y <= -_size)
    {
        SceneBase::Destroy(this);
    }
}

void EnemyBullet::SetDestroy(std::function<void(EnemyBullet*)> func)
{
    _destroy = func;
}

void EnemyBullet::OnDestroy()
{
    if (_destroy != nullptr) {
        _destroy(this);
    }
}

Circle EnemyBullet::GetCircle()
{
    return _circle;
}

void EnemyBullet::Hit()
{
    SceneBase::Destroy(this);
}
