#pragma once
#include "Common/SceneBase/SceneBase.h"

class Button;
class Text;

class TitleScene : public SceneBase
{
public:

    TitleScene(const InitData& init);
    ~TitleScene();

private:

    Button* _startButton;
    Button* _quitButton;

    Text* _title;
};

