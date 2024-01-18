#include "TankHead.h"
#include"Engine/Model.h"
#include"Engine//Input.h"
#include"Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\TankHead_anime.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 1.0;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 1.0;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//モデルの関節の位置を持ってくる
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);//XMFLOATのままだと計算できない
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);//よってXMVECTORに直している
		XMVECTOR moveDir = vtop - vroot;//砲台の根本から先端への方向ベクトル
		moveDir = XMVector3Normalize(moveDir);//ベクトルの正規化(単位ベクトル)
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.2);
	}
}

void TankHead::Draw()
{
	//transform_は自分(TankHead)のメンバ変数
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
