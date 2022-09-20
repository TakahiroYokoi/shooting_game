#include "EnemyManager.h"
#include "EnemyBase.h"
#include "Game/Scenes/GameScene/GameScene.h"
#include <functional>
#include "Game/Enemy/EnemyA/EnemyA.h"
#include "Game/Enemy/EnemyB/EnemyB.h"

EnemyManager::EnemyManager(Vec2* playerPosition)
{
    _playerPosition = playerPosition;
    std::queue<VecTime>* tmpQueue = new std::queue<VecTime>();
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
    _enemyList = std::list<EnemyBase*>();
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
                    tmpQueue = new std::queue<VecTime>();
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

void EnemyManager::Update(float deltaTime)
{
    Spawn(deltaTime);

    for (auto enemy : _enemyList)
    {
        enemy->Move(deltaTime);
        enemy->Shot(deltaTime,_playerPosition);
    }
}

void EnemyManager::Spawn(float deltaTime)
{
    int r = Random<int>(_routeVector.size() - 1);
    std::queue<VecTime> routeQueue = *_routeVector[r];
    _enemyASpawnPoint = routeQueue.front()._vec;
    routeQueue.pop();
    static float coolTime = 0;
    EnemyBase* enemy;
    if (coolTime <= 0)
    {
        r = Random<int>(kNumOfEnemyType-1);
        if (r == 0)
        {
            enemy = new EnemyA(routeQueue);
        }
        else
        {
            enemy = new EnemyB(routeQueue);
        }
        enemy->SetDestroy([&](EnemyBase* destroyEnemy) {
            _enemyList.remove(destroyEnemy);
            });
        _enemyList.push_back(enemy);
        GameScene::Instantiate(enemy, _enemyASpawnPoint);
        coolTime = kSpawnCoolTime;
    }
    coolTime -= deltaTime;
}

VecTime::VecTime(Vec2 vecIn, float timeIn)
{
    _vec = vecIn;
    _time = timeIn;
}
