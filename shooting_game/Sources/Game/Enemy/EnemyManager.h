#pragma once
#include "Common/GameObject/GameObject.h"
#include "Common/Singleton.h"
#include <vector>
#include <queue>

class EnemyBase;

class VecTime
{
public:
    Vec2 _vec;
    float _time;
    VecTime(Vec2 vecIn, float timeIn);
};

class EnemyManager : public Singleton<EnemyManager>
{
public:
    void Init(Vec2* playerPosition);
    void Update(float deltaTime);

private:
    std::vector<std::queue<VecTime>*> _routeVector;
    const float kSpawnCoolTime = 2.5;
    const int kNumOfEnemyType = 2;
    std::list<EnemyBase*> _enemyList;
    Vec2 _enemyASpawnPoint;
    Vec2* _playerPosition;

private:
    void Spawn(float deltaTime);
    void ReadRoute(const JSON&, std::vector<double>&, std::queue<VecTime>*&, std::vector<std::queue<VecTime>*>&);
    void OnEnemyDestroy(EnemyBase*);
};

