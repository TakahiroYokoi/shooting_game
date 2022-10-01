#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"
#include "Game/Bullet/Bullet.h"

class Player : public GameObject
{
public:
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    std::list<Bullet*> GetBulletList();
    Circle GetCircle();

private:
    // プレイヤーの移動スピード
    const float kSpeed = 500.f;
    const float kShotCoolTime = 0.5f;
    // プレイヤーのサイズ
    float _size = 16.f;
    std::list<Bullet*> _bulletList;
    Circle _circle;

    void Move(float deltaTime);
};
