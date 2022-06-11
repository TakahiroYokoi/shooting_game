#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"
#include "EnemyManager.h"

class EnemyA : public GameObject
{
public:
    EnemyA(std::queue<VecTime> route);
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    std::queue<VecTime> _routeQueue;
    float _time = -1;
    Vec2 _vec;
    const float kSpeed = 500.f;
    float _size = 15.f;
    void Move(float deltaTime);
    void Shot();
};
