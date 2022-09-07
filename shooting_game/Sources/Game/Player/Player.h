#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"

class Player : public GameObject
{
public:
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    // プレイヤーの移動スピード
    const float kSpeed = 500.f;
    const float kShotCoolTime = 0.5f;
    // プレイヤーのサイズ
    float _size = 16.f;
    void Move(float deltaTime);
};
