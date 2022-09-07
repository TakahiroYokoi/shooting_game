#include "SceneBase.h"

#include <Siv3D/Scene.hpp>
#include <Siv3D/Vector2D.hpp>
#include "Common/GameObject/GameObject.h"

using namespace std;

SceneBase::SceneBase(const InitData& init) :
    Base(init)
{
    if (_objectList == nullptr)
    {
        _objectList = new list<GameObject*>();
    }
    if (_destroyList == nullptr)
    {
        _destroyList = new list<GameObject*>();
    }
}

SceneBase::~SceneBase()
{
    _objectList->clear();
    _destroyList->clear();
}

void SceneBase::Instantiate(GameObject* gameObject, Vec2 position)
{
    gameObject->Init(position);
    _objectList->push_back(gameObject);
}

void SceneBase::Destroy(GameObject* gameObject)
{
    _destroyList->push_back(gameObject);
}

void SceneBase::Update(float deltaTime)
{
    deltaTime;
}

void SceneBase::LateUpdate(float deltaTime)
{
    deltaTime;
}

void SceneBase::update()
{
    float deltaTime = (float)s3d::Scene::DeltaTime();
    Update(deltaTime);

    for_each(_objectList->begin(), _objectList->end(), [deltaTime](GameObject* object) {
            object->AlwaysUpdate(deltaTime);
            if (object->GetActive())
            {
                object->Update(deltaTime);
                object->Draw();
            }
        });

    LateUpdate(deltaTime);
    DestroyObjects();
}

void SceneBase::draw() const
{
    for_each(_objectList->begin(), _objectList->end(), [](GameObject* object) {
            if (object->GetActive())
            {
                object->Draw();
            }
        });
}

void SceneBase::DestroyObjects()
{
    for_each(_destroyList->begin(), _destroyList->end(), [](GameObject* object) {
            _objectList->remove(object);
            object->OnDestroy();
        });

    _destroyList->clear();
}
