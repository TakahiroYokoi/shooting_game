#include "Player.h"

bool Player::Init(Vec2 position)
{
    if (!__super::Init(position))
    {
        return false;
    }
    return true;
}

void Player::Update(float deltaTime)
{
    Move(deltaTime);
}

void Player::Draw()
{
    Circle(*_position, _size).draw();
}

void Player::Move(float deltaTime)
{
    Vec2 move = Vec2::Zero();
    bool isMove = false;
    // キーが押されたとき
    if (KeyUp.pressed())
    {
        move.y = -1;
        isMove = true;
    }
    if (KeyLeft.pressed())
    {
        move.x = -1;
        isMove = true;
    }
    if (KeyDown.pressed())
    {
        move.y = 1;
        isMove = true;
    }
    if (KeyRight.pressed())
    {
        move.x = 1;
        isMove = true;
    }
    // プレイヤーが動いてるとき
    if (isMove)
    {
        // 移動量を均一に
        *_position += move.normalized() * kSpeed * deltaTime;
        // 画面外に出ないように
        if (_position->y <= _size)
        {
            _position->y = _size;
        }
        if (_position->x <= _size)
        {
            _position->x = _size;
        }
        if (_position->y >= Window::GetState().virtualSize.y - _size)
        {
            _position->y = Window::GetState().virtualSize.y - _size;
        }
        if (_position->x >= Window::GetState().virtualSize.x - _size)
        {
            _position->x = Window::GetState().virtualSize.x - _size;
        }
    }
    // x,yベクトルそれぞれの移動量とプレイヤーの座標表示
    // デバッグ用
    /*
    ClearPrint();
    Print << move.normalized();
    Print << _position;
    */
}

