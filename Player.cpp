#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Ground.h"
#include"Engine/SceneManager.h"
#include"TankHead.h"
#include"Engine/Camera.h"

//�J��������
enum CAM_TYPE
{
	FIXED_TYPE,     //�Œ�
	TPS_NOROT_TYPE, //3�l�̉�]�Ȃ�
	TPS_TYPE,       //3�l��
	FPS_TYPE,       //1�l��
	MAX_TYPE        //�ԕ�����i�`�F�b�N�p�̒l�j
};

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hTankBody_(-1), front_({ 0,0,1,0 }), speed_(0.05),camState_(CAM_TYPE::FIXED_TYPE)
{
}

void Player::Initialize()
{
	hTankBody_ = Model::Load("Model\\TankBody.fbx");
	assert(hTankBody_ >= 0);
	transform_.position_ = { 0,0,0 };
	Instantiate<TankHead>(this);
}

void Player::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();//�s���1 �P�ʍs��
	XMVECTOR move{ 0,0,0,0};
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_W)) 
	{
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S))
	{
		dir = -1.0;
	}
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y -= 1.0f;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y += 1.0f;
	}

	//��]�s������߂�
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//�x�N�g���̉�]���ʂ����߂�
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//XMVECTOR�ɍ��킹��
	pos = pos + dir * move;//pos = pos + speed * front_ ���ۂɈʒu���ړ�������
	XMStoreFloat3(&(transform_.position_), pos);

	//Debug::Log("angle = ");
	//Debug::Log(transform_.rotate_.y,true);
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		//camState_ = (++camState_) % (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 20.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		/*Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;

		XMVECTOR vMove = XMLoadFloat3(&());
		XMStoreFloat3(&camTarget, pos + dir * move);
		Camera::SetTarget(camTarget);*/
		break;
	}
	default:
		break;
	}
}

void Player::Draw()
{
	Model::SetTransform(hTankBody_, transform_);
	Model::Draw(hTankBody_);
}

void Player::Release()
{
}
