#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"

class Bullet : public GameObject
{
public:
    virtual bool Init(Vec2 position) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void OnDestroy();
    void SetDestroy(std::function<void(Bullet*)>);
    Circle GetCircle();
    void Hit();

protected:
    // 弾の移動スピード
    const float kSpeed = 1000.f;
    // 弾のサイズ
    float _size = 5.f;
    Circle _circle;
    virtual void Move(float deltaTime);

private:
    std::function<void(Bullet*)> _destroy;
};
