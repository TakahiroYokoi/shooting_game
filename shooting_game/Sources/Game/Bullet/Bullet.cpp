#include "Bullet.h"
#include "Common/SceneBase/SceneBase.h"

bool Bullet::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void Bullet::Update(float deltaTime)
{
    Move(deltaTime);
}

void Bullet::Draw()
{
    Circle(*_position, _size).draw();
}

void Bullet::Move(float deltaTime)
{
    _position->x += kSpeed * deltaTime;
    if (_position->x >= Window::GetState().virtualSize.x + _size)
    {
        SceneBase::Destroy(this);
    }
}

