#include "EnemyManager.h"
#include "EnemyA/EnemyA.h"
#include "EnemyB/EnemyB.h"
#include "Game/Scenes/GameScene/GameScene.h"

EnemyManager::EnemyManager()
{
    std::queue<VecTime>* tmpQueue = new std::queue<VecTime>;
    const JSON json = JSON::Load(U"RouteList.json");
    std::vector<double> buf;
    if (not json)
    {
        throw Error
        {
            U"Failed to load 'RouteList.json'"
        };
    }
    ReadRoute(json,buf,tmpQueue,_routeVector);
}


void EnemyManager::ReadRoute(const JSON& value, std::vector<double>& buf, std::queue<VecTime>*& tmpQueue, std::vector<std::queue<VecTime>*>& _routeVector)
{
    switch (value.getType())
    {
        case JSONValueType::Object:
            for (const auto& object : value)
            {
                ReadRoute(object.value, buf, tmpQueue, _routeVector);
                if (object.key != U"Route")
                {
                    _routeVector.push_back(tmpQueue);
                    tmpQueue = new std::queue<VecTime>;
                }
            }
            break;
        case JSONValueType::Array:
            for (const auto& element : value.arrayView())
            {
                ReadRoute(element, buf, tmpQueue, _routeVector);
            }
            if (buf.size() == 0)
            {
                break;
            }
            if(buf.size() == 2)
            {
                tmpQueue->push(VecTime(Vec2(buf[0], buf[1]), 0));
            }
            else
            {
                tmpQueue->push(VecTime(Vec2(buf[0], buf[1]), buf[2]));
            }
            buf.clear();
            break;
        case JSONValueType::Number:
            buf.push_back(value.get<double>());
            break;
    }
}

void EnemyManager::AlwaysUpdate(float deltaTime)
{
    Spawn(deltaTime);
}

void EnemyManager::Spawn(float deltaTime)
{
    int r = Random<int>(_routeVector.size() - 1);
    std::queue<VecTime> routeQueue = *_routeVector[r];
    _enemyASpawnPoint = routeQueue.front()._vec;
    routeQueue.pop();
    static float coolTime = 0;
    if (coolTime <= 0)
    {
        r = Random<int>(1);
        if (r == 0) {
            EnemyA *enemyA = new EnemyA(routeQueue);
            GameScene::Instantiate(enemyA,_enemyASpawnPoint);
        }
        else if (r == 1)
        {
            EnemyB* enemyB = new EnemyB(routeQueue);
            GameScene::Instantiate(enemyB, _enemyASpawnPoint);
        }
        coolTime = kSpawnCoolTime;
    }
    coolTime -= deltaTime;
}

VecTime::VecTime(Vec2 vecIn, float timeIn)
{
    _vec = vecIn;
    _time = timeIn;
}
