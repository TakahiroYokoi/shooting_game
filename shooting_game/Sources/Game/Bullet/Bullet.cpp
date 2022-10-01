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
    _circle = Circle(*_position, _size);
}

void Bullet::Draw()
{
    _circle.draw();
}

void Bullet::OnDestroy()
{
    if (_destroy != nullptr) {
        _destroy(this);
    }
}

void Bullet::Move(float deltaTime)
{
    _position->x += kSpeed * deltaTime;
    if (_position->x >= Window::GetState().virtualSize.x + _size)
    {
        SceneBase::Destroy(this);
    }
}

void Bullet::SetDestroy(std::function<void(Bullet*)> func) {
    _destroy = func;
}

Circle Bullet::GetCircle()
{
    return _circle;
}

void Bullet::Hit()
{
    SceneBase::Destroy(this);
}
