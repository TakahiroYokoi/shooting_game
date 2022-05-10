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
    /// ������
    /// </summary>
    /// <param name="position">�������W</param>
    /// <returns>����������true</returns>
    virtual bool Init(Vec2 position);

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�O�t���[������̌o�ߎ���</param>
    virtual void Update(float deltaTime);
    /// <summary>
    /// �X�V����(��A�N�e�B�u�ł����s����
    /// </summary>
    /// <param name="deltaTime">�O�t���[������̌o�ߎ���</param>
    virtual void AlwaysUpdate(float deltaTime);
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();

    /// <summary>
    /// �A�N�e�B�u��Ԃ�ݒ�
    /// </summary>
    /// <param name="isActive">�A�N�e�B�u��</param>
    virtual void SetActive(bool isActive) final;
    /// <summary>
    /// �A�N�e�B�u��Ԃ��擾
    /// </summary>
    /// <returns>�A�N�e�B�u��</returns>
    virtual bool GetActive() final;

    /// <summary>
    /// �A�N�e�B�u�ɂȂ������ɌĂ΂��
    /// </summary>
    virtual void OnActive();
    /// <summary>
    /// ��A�N�e�B�u�ɂȂ������ɌĂ΂��
    /// </summary>
    virtual void OnDeactive();
    /// <summary>
    /// �j�󂳂ꂽ���ɌĂ΂��
    /// </summary>
    virtual void OnDestroy();

private:

    bool _isActive;
};

