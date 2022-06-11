#include "Player.h"
#include "Game/Bullet/Bullet.h"
#include "Game/Scenes/GameScene/GameScene.h"

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
    Vec2 virtualSize = Window::GetState().virtualSize;
    bool isMove = false;
    static double coolTime;
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
    if (KeyZ.pressed() && coolTime <= 0)
    {
        coolTime = kShotCoolTime;
        Bullet* bullet = new Bullet();
        GameScene::Instantiate(bullet,*_position);
    }
    if (coolTime > 0)
    {
        coolTime -= deltaTime;
    }
    // プレイヤーが動いてるとき
    if (isMove)
    {
        // プレイヤー移動
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
        if (_position->y >= virtualSize.y - _size)
        {
            _position->y = virtualSize.y - _size;
        }
        if (_position->x >= virtualSize.x - _size)
        {
            _position->x = virtualSize.x - _size;
        }
    }
}

