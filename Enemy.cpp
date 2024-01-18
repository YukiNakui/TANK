#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\MyEnemy_anime.fbx");
	assert(hModel_ >= 0);
	//transform_.position_ = { 5,0,15 };
	transform_.rotate_ = { 0,180,0 };
	transform_.scale_ = { 2,2,2 };
	SphereCollider* collision = new SphereCollider({ 0, 0.5, 0 }, 1.0f);
	AddCollider(collision);
	//アニメーションのセット
	Model::SetAnimFrame(hModel_, 1, 60, 1);

	//敵のポジションをランダムにセット
	float x = (float)rand() / RAND_MAX;//0-1の乱数
	x = 2.0 * x;
	transform_.position_.x = 25.0 * (x - 1.0);
	float z = (float)rand() / RAND_MAX;//0-1の乱数
	z = 2.0 * z;
	transform_.position_.z = 25.0 * (z - 1.0);
	transform_.position_.y = 0;
	
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 1.0;
	}
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
