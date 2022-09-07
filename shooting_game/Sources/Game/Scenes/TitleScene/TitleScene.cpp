#include "TitleScene.h"

#include "Game/UI/Button.h"
#include "Game/UI/Text.h"

TitleScene::TitleScene(const InitData& init) :
    SceneBase(init)
{
    const double titleButtonSize = 150.0;
    Size windowSize = Scene::Size();

    _startButton = new Button();
    _quitButton = new Button();

    SceneBase::Instantiate(_startButton, Vec2(windowSize.x * 0.5, windowSize.y * 0.6));
    SceneBase::Instantiate(_quitButton, Vec2(windowSize.x * 0.5, windowSize.y * 0.7));

    _title = new Text();
    _title->Init(U"シューティング", 72);
    SceneBase::Instantiate(_title, Vec2(windowSize.x / 2, windowSize.y / 3));

    _startButton
        ->SetText(U"スタート")
        ->SetWidth(titleButtonSize)
        ->AddListener([this]()
            {
                changeScene("GameScene");
            });

    _quitButton
        ->SetText(U"終了")
        ->SetWidth(titleButtonSize)
        ->AddListener([]()
            {
                System::Exit();
            });
}

TitleScene::~TitleScene()
{
    delete _startButton;
    delete _quitButton;

    _startButton = nullptr;
    _quitButton = nullptr;
}
