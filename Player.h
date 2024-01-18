#pragma once
#include "Engine/GameObject.h"

//�v���C�V�[���Ǘ�����N���X
class Player :
	public GameObject
{
	int hTankBody_;
	XMVECTOR front_;//�O�x�N�g�� z+�����@�傫��1
	float speed_;   //0.05 0.05*60 m/s
	int camState_;  //�J�����^�C�v�̎w��
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);


	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

