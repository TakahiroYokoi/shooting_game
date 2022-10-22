#include "EnemyLaser.h"
#include "Common/SceneBase/SceneBase.h"

EnemyLaser::EnemyLaser(Vec2 move)
{
    _move = move;
}

bool EnemyLaser::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void EnemyLaser::Update(float deltaTime)
{
    Move(deltaTime);
    Vec2 end = *_position;
    end.x = end.x + 100;
    _line = Line(*_position, end);
}

void EnemyLaser::Draw()
{
    _line.draw();
}

void EnemyLaser::Move(float deltaTime)
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

void EnemyLaser::SetDestroy(std::function<void(EnemyLaser*)> func)
{
    _destroy = func;
}

void EnemyLaser::OnDestroy()
{
    if (_destroy != nullptr) {
        _destroy(this);
    }
}
Line EnemyLaser::GetLine()
{
    return _line;
}

void EnemyLaser::Hit()
{
    SceneBase::Destroy(this);
}
