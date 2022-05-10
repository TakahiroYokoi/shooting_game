#pragma once

#include <Siv3D/SceneManager.hpp>
#include <list>

class GameObject;

struct SharedData
{
};

using TSceneManager = SceneManager<std::string, SharedData>;

class SceneBase : public TSceneManager::Scene
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="init">共有データ</param>
    SceneBase(const InitData& init);

    /// <summary>
    /// オブジェクトを生成
    /// </summary>
    /// <param name="gameObject">生成するオブジェクト</param>
    /// <param name="position">初期座標</param>
    virtual void Instantiate(GameObject* gameObject, Vec2 position) final;
    /// <summary>
    /// 生成されてるオブジェクトを削除
    /// </summary>
    /// <param name="gameObject">削除するオブジェクト</param>
    virtual void Destroy(GameObject* gameObject) final;

protected:

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">前フレームからの経過時間</param>
    virtual void Update(float deltaTime);
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">前フレームからの経過時間</param>
    virtual void LateUpdate(float deltaTime);

private:

    using Base = TSceneManager::Scene;

private:

    std::list<GameObject*>* _objectList;

private:

    virtual void update() override;
    virtual void draw() const override;
};
