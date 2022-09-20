#pragma once
#include <Siv3D.hpp>
#include "Common/GameObject/GameObject.h"
#include "Game/Enemy/EnemyManager.h"

class EnemyBase : public GameObject
{
public:
    EnemyBase(std::queue<VecTime> route);
    virtual bool Init(Vec2 position) override;
    virtual void Draw() override;
    virtual void Shot(float deltaTime, Vec2* playerPosiotion);
	virtual void OnDestroy();
    void Move(float deltaTime);
    void SetDestroy(std::function<void(EnemyBase*)>);

protected:
    std::queue<VecTime> _routeQueue;
    float _size = 15.f;

private:
    std::function<void(EnemyBase*)> _destroy;
    float _time = -1;
    Vec2 _vec;
    const float kSpeed = 500.f;
};

#include "Game/Enemy/EnemyA/EnemyA.h"
#include "Game/Enemy/EnemyB/EnemyB.h"
