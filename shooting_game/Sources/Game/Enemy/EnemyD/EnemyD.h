#pragma once
#include <Siv3D.hpp>
#include "Game/Enemy/EnemyBase.h"
#include "Game/Enemy/EnemyManager.h"

class EnemyD : public EnemyBase
{
public:
    EnemyD(std::queue<VecTime> route);
    virtual bool Init(Vec2 position) override;
    virtual void Draw() override;
    virtual void Shot(float deltaTime, Vec2* playerPosition) override;

protected:

private:
    const float kShotCoolTime = 1.0f;
    double _coolTime = 0;
};
