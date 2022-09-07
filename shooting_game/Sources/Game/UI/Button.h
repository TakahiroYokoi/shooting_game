#pragma once
#include "Common/GameObject/GameObject.h"

class Button : public GameObject
{
public:

    /// <summary>
    /// 初期化処理
    /// </summary>
    /// <param name="position">初期位置</param>
    /// <returns>作成に成功したか</returns>
    virtual bool Init(Vec2 position) override;

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">前フレームからの経過時間</param>
    virtual void Update(float deltaTime) override;

    /// <summary>
    /// 描画
    /// </summary>
    virtual void Draw() override;
    /// <summary>
    /// 削除された時
    /// </summary>
    virtual void OnDestroy() override;

    /// <summary>
    /// テキストを設定
    /// </summary>
    /// <param name="text"></param>
    Button* SetText(const std::u32string& text);

    /// <summary>
    /// ボタンを有効にするかを設定
    /// </summary>
    /// <param name="enabled">true: 有効 false: 無効</param>
    Button* SetEnabled(bool enabled);
    /// <summary>
    /// 幅を設定
    /// </summary>
    /// <param name="width">幅</param>
    Button* SetWidth(const Optional<double>& width = unspecified);

    /// <summary>
    /// ボタンクリックした時の処理を設定
    /// </summary>
    /// <param name="listener">処理</param>
    Button* AddListener(std::function<void()> listener);
    /// <summary>
    /// ボタンクリックした時の処理を削除
    /// </summary>
    Button* DeleteListener();

private:

    Optional<double> _width = unspecified;

    bool _isPress = false;
    bool _enabled = true;

    inline static bool _isQuit = false;

    std::list<std::function<void()>> _listener;

    std::u32string _text;
};
