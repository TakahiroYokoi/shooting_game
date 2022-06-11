#include "EnemyManager.h"
#include "EnemyA.h"
#include "Game/Scenes/GameScene/GameScene.h"


EnemyManager::EnemyManager()
{
    const CSV csv{ U"RouteList.csv"};
    if (not csv)
    {
        throw Error
        {
            U"Failed to load 'RouteList.csv'"
        };
    }
    std::queue<VecTime> *tmpQueue = new std::queue<VecTime>;
    for (size_t row = 1; row < csv.rows(); ++row)
    {
        if (csv[row][0] == U"position")
        {
            tmpQueue->push(VecTime(Vec2(Parse<int>(csv[row][1]), Parse<int>(csv[row][2])), 0));
        }
        else if (csv[row][0] == U"VecTime")
        {
            tmpQueue->push(VecTime(Vec2(Parse<int>(csv[row][1]), Parse<int>(csv[row][2])), Parse<float>(csv[row][3])));
        }
        else if (csv[row][0] == U"end")
        {
            tmpQueue->push(VecTime(Vec2(Parse<int>(csv[row][1]), Parse<int>(csv[row][2])), Parse<float>(csv[row][3])));
            _routeVector.push_back(tmpQueue);
            tmpQueue = new std::queue<VecTime>;
        }
        else if (csv[row][0] == U"exit"){}
        else
        {
            throw Error
            {
                U"Invalid status in 'RouteList.csv'"
            };
        }
    }
}

void EnemyManager::AlwaysUpdate(float deltaTime)
{
    Spawn(deltaTime);
}

void EnemyManager::Spawn(float deltaTime)
{
    int route = Random<int>(_routeVector.size() - 1);
    std::queue<VecTime> routeQueue = *_routeVector[route];
    _enemyASpawnPoint = routeQueue.front()._vec;
    routeQueue.pop();
    static float coolTime = 0;
    if (coolTime <= 0)
    {
        EnemyA *enemyA = new EnemyA(routeQueue);
        GameScene::Instantiate(enemyA,_enemyASpawnPoint);
        coolTime = kSpawnCoolTime;
    }
    coolTime -= deltaTime;
}

VecTime::VecTime(Vec2 vecIn, float timeIn)
{
    _vec = vecIn;
    _time = timeIn;
}

