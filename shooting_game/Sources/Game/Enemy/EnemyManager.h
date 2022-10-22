#pragma once
#include "Common/GameObject/GameObject.h"
#include "Common/Singleton.h"
#include <vector>
#include <queue>

class EnemyBase;
class Player;

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
    void Init(Player* player);
    void Update(float deltaTime);

private:
    std::vector<std::queue<VecTime>*> _routeVector;
    const float kSpawnCoolTime = 2.5;
    const int kNumOfEnemyType = 4;
    std::list<EnemyBase*> _enemyList;
    Vec2 _enemyASpawnPoint;
    Player* _player;

private:
    int _pHitCount = 0;
    int _score = 0;

    void Spawn(float deltaTime);
    void ReadRoute(const JSON& value, std::vector<float>& buf, std::queue<VecTime>*& tmpQueue);
    void Collison();
};

