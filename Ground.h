#pragma once
#include "Engine/GameObject.h"

class Ground :
    public GameObject
{
    int hGround_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Ground(GameObject* parent);


	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetModelHandle() { return(hGround_); }
};

