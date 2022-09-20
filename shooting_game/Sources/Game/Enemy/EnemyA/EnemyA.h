#pragma once
#include <Siv3D.hpp>
#include "Game/Enemy/EnemyBase.h"
#include "Game/Enemy/EnemyManager.h"

class EnemyA : public EnemyBase
{
public:
    EnemyA(std::queue<VecTime> route);
    virtual bool Init(Vec2 position) override;
    virtual void Draw() override;
};
#pragma once
