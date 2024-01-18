#include "Bullet.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 0.3f);
	AddCollider(collision);
}

void Bullet::Update()
{
	//transform_.positionをmoveDir_とbulletSpeedで更新
	//transform_.position_.z += 0.05;
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	moveDir_ = { moveDir_.x,moveDir_.y - 0.02f,moveDir_.z };//y座標を落とす
	if (transform_.position_.y < -10)//十分落ちたら消す
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
