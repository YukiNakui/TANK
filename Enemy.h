#pragma once
#include "Engine/GameObject.h"

class Enemy :
    public GameObject
{
private:
	int hModel_; //Enemy�̃��f����ǂޕϐ�
	//���f�����̂̓O���[�o���̈�ɕۑ�����Ă���
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="parent">parent:�e�̃I�u�W�F�N�g�̃|�C���^</param>
	Enemy(GameObject* parent);

	~Enemy();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ƏՓ˂����ꍇ�ɌĂ΂��
   //�����FpTarget	�Փ˂�������
	//void OnCollision(GameObject* pTarget);
};

