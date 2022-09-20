﻿#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"

class EnemyBullet : public GameObject
{
public:
    EnemyBullet(Vec2*);
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    const float kSpeed = 1000.f;
    float _size = 5.f;
    void Move(float deltaTime);

private:
    Vec2 _target;
    Vec2 _move;
};
