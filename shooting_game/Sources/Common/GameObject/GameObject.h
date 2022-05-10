#pragma once

#include <Siv3D.hpp>

class GameObject
{
public:

    Vec2* _position;

public:

    GameObject();
    ~GameObject();

    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name="position">初期座標</param>
    /// <returns>成功したらtrue</returns>
    virtual bool Init(Vec2 position);

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">前フレームからの経過時間</param>
    virtual void Update(float deltaTime);
    /// <summary>
    /// 更新処理(非アクティブでも実行する
    /// </summary>
    /// <param name="deltaTime">前フレームからの経過時間</param>
    virtual void AlwaysUpdate(float deltaTime);
    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw();

    /// <summary>
    /// アクティブ状態を設定
    /// </summary>
    /// <param name="isActive">アクティブか</param>
    virtual void SetActive(bool isActive) final;
    /// <summary>
    /// アクティブ状態を取得
    /// </summary>
    /// <returns>アクティブか</returns>
    virtual bool GetActive() final;

    /// <summary>
    /// アクティブになった時に呼ばれる
    /// </summary>
    virtual void OnActive();
    /// <summary>
    /// 非アクティブになった時に呼ばれる
    /// </summary>
    virtual void OnDeactive();
    /// <summary>
    /// 破壊された時に呼ばれる
    /// </summary>
    virtual void OnDestroy();

private:

    bool _isActive;
};

