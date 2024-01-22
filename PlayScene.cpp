#include "PlayScene.h"
#include"Player.h"
//#include"TankHead.h"
#include"Enemy.h"
#include"Ground.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
#include"Engine/Camera.h"
#include"Engine/Text.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),pText(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	
	enemyNum = ENEMY_NUM;
	for (int i = 0; i < enemyNum; i++)
		Enemy* p = Instantiate<Enemy>(this);
	//Instantiate<TankHead>(this);

	player = Instantiate<Player>(this);

	pText = new Text;
	pText -> Initialize();
}

void PlayScene::Update()
{
	//ƒ^ƒ“ƒN‚Æˆê‚ÉƒJƒƒ‰‚ð“®‚©‚·
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
}

void PlayScene::Draw()
{
	//pText->Draw(30, 30, "SCORE : ");
}

void PlayScene::Release()
{
}
