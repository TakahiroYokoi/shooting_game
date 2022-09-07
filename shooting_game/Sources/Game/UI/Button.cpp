#include "Button.h"

using namespace std;

bool Button::Init(Vec2 position)
{
    if (!GameObject::Init(position))
    {
        return false;
    }

    _text = U"Button";

    return true;
}

void Button::Update(float deltaTime)
{
    deltaTime;
}

void Button::Draw()
{
    if (SimpleGUI::ButtonAt(
            _text,
            *_position,
            _width,
            _enabled)
        && !_isPress)
    {
        _isPress = true;
        for_each(_listener.begin(), _listener.end(), [](function<void()> listener) {
            listener();
         });
    }
    else
    {
        _isPress = false;
    }
}

void Button::OnDestroy()
{
    DeleteListener();
}

Button* Button::SetText(const std::u32string& text)
{
    _text = text;

    return this;
}

Button* Button::SetEnabled(bool enabled)
{
    _enabled = enabled;

    return this;
}

Button* Button::SetWidth(const Optional<double>& width)
{
    _width = width;

    return this;
}

Button* Button::AddListener(function<void()> listener)
{
    _listener.push_back(listener);

    return this;
}

Button* Button::DeleteListener()
{
    _listener.clear();

    return this;
}
