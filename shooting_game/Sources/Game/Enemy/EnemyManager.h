#pragma once
#include "Common/GameObject/GameObject.h"
#include <vector>
#include <queue>

class VecTime
{
public:
    Vec2 _vec;
    float _time;
    VecTime(Vec2 vecIn, float timeIn);
};

class EnemyManager : public GameObject
{
public:
    EnemyManager();
    virtual void AlwaysUpdate(float deltaTime) override;
private:
    std::vector<std::queue<VecTime>*> _routeVector;
    const float kSpawnCoolTime = 2.5;
    Vec2 _enemyASpawnPoint;
    void Spawn(float deltaTime);
};

