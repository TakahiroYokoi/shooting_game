#pragma once

#include <Siv3D/SceneManager.hpp>
#include <list>

class GameObject;

struct SharedData
{
};

using TSceneManager = SceneManager<std::string, SharedData>;

class SceneBase : public TSceneManager::Scene
{
public:

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="init">���L�f�[�^</param>
    SceneBase(const InitData& init);

    /// <summary>
    /// �I�u�W�F�N�g�𐶐�
    /// </summary>
    /// <param name="gameObject">��������I�u�W�F�N�g</param>
    /// <param name="position">�������W</param>
    virtual void Instantiate(GameObject* gameObject, Vec2 position) final;
    /// <summary>
    /// ��������Ă�I�u�W�F�N�g���폜
    /// </summary>
    /// <param name="gameObject">�폜����I�u�W�F�N�g</param>
    virtual void Destroy(GameObject* gameObject) final;

protected:

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�O�t���[������̌o�ߎ���</param>
    virtual void Update(float deltaTime);
    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">�O�t���[������̌o�ߎ���</param>
    virtual void LateUpdate(float deltaTime);

private:

    using Base = TSceneManager::Scene;

private:

    std::list<GameObject*>* _objectList;

private:

    virtual void update() override;
    virtual void draw() const override;
};
