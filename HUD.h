#pragma once
#include "Engine/GameObject.h"
#include <string>
#include<vector>

using std::string;
class PlayScene;

class HUD :
    public GameObject
{
    string ConstructEnemyNumberString();
	PlayScene* playScene_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	HUD(GameObject* parent);
	int hHUD_;//�c��c�@���̉摜
	int hNumbers_;//�����̉摜
	int hKinoko_;
	Transform tHud_;
	std::vector<Transform> tNumbers_;
	//Transform tNumbers[3];
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

