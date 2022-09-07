#include "Text.h"

bool Text::Init(Vec2 position)
{
    if (!GameObject::Init(position))
    {
        return false;
    }

    _font = Font(_size);

    return true;
}

bool Text::Init(std::u32string text, int size)
{
    _text = text;
    _size = size;

    _font = Font(_size);

    return true;
}

void Text::Draw()
{
    _font(_text).drawAt(*_position);
}