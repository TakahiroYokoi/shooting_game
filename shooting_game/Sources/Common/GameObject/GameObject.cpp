#include "GameObject.h"

GameObject::GameObject():
    _position(new Vec2(0.0f, 0.0f)),
    _isActive(true)
{
}

GameObject::~GameObject()
{
    delete _position;
}

bool GameObject::Init(Vec2 position)
{
    _position = new Vec2(position);

    return true;
}

void GameObject::Update(float deltaTime)
{
    deltaTime;
}

void GameObject::AlwaysUpdate(float deltaTime)
{
    deltaTime;
}

void GameObject::Draw()
{
}

void GameObject::SetActive(bool isActive)
{
    if (!_isActive && isActive)
    {
        OnActive();
    }
    else if (_isActive && !isActive)
    {
        OnDeactive();
    }

    _isActive = isActive;
}

bool GameObject::GetActive()
{
    return _isActive;
}

void GameObject::OnActive()
{
}

void GameObject::OnDeactive()
{
}

void GameObject::OnDestroy()
{
}
