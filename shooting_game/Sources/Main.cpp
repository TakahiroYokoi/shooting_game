#include <Siv3D.hpp>

#include "Common/SceneBase/SceneBase.h"
#include "Game/Scenes/GameScene/GameScene.h"

void Main()
{
    // モニタ情報
    auto monitorData = System::EnumerateMonitors();

    Size monitorSize = { 800, 600 };
    for (auto data : monitorData)
    {
        // メインモニタか
        if (!data.isPrimary)
        {
            continue;
        }

        // フルスクリーンサイズを取得
        monitorSize = data.fullscreenResolution;

        break;
    }

    // フレームレスウィンドウでモニタサイズに合わせる
    Window::SetStyle(WindowStyle::Frameless);
    Window::Resize(monitorSize);

    TSceneManager sceneManager;
	sceneManager
		.add<GameScene>("GameScene")
        .setFadeColor(ColorF{ 1. });

    while (System::Update())
    {
        if (!sceneManager.update())
        {
            break;
        }
    }
}
