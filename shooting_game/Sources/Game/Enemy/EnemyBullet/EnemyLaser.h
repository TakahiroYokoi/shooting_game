#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"

class EnemyLaser : public GameObject
{
public:
    EnemyLaser(Vec2);
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void OnDestroy();
    void SetDestroy(std::function<void(EnemyLaser*)> func);
    Line GetLine();
    void Hit();

protected:
    const float kSpeed = 1000.f;
    float _size = 5.f;
    void Move(float deltaTime);

private:
    Vec2 _move;
    Line _line;
    std::function<void(EnemyLaser*)> _destroy;
};
