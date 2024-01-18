#include "Ground.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"),hGround_(-1)
{
}

void Ground::Initialize()
{
	hGround_ = Model::Load("Model\\Ground.fbx");
	assert(hGround_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hGround_, transform_);
	Model::Draw(hGround_);
}

void Ground::Release()
{
}
