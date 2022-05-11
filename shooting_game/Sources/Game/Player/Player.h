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
    // プレイヤーのサイズ
    float _size = 10.f;
    void Move(float deltaTime);
};
