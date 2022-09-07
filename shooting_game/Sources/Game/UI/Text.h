#pragma once
#include "Common/GameObject/GameObject.h"

class Text : public GameObject
{
public:

    virtual bool Init(Vec2 position) override;
    bool Init(std::u32string text, int size = 16);

    virtual void Draw() override;

private:

    Font _font;

    std::u32string _text = U"";
    int _size = 16;
};
