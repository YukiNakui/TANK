#include "HUD.h"
#include"Engine/Image.h"
#include"PlayScene.h"

string HUD::ConstructEnemyNumberString()
{
	string enemyNum = std::to_string(playScene_->GetEnemyNum());
	return enemyNum;
}

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumbers_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("HUDENEMY.png");
	assert(hHUD_ > 0);
	hNumbers_ = Image::Load("numbers.png");
	assert(hHUD_ > 0);

	for (int i = 0; i < 3; i++)
	{
		Transform t;
		t.position_ = { -0.61f + 0.08f * (float)i,0.85f,0 };
		tNumbers_.push_back(t);
	}
	playScene_ = (PlayScene*)GetParent();
}

void HUD::Update()
{
	tHud_.scale_ = { 0.8,0.8,1.0 };
	tHud_.position_ = { -0.6,0.85,0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	/*Transform trans;
	trans.scale_ = { 0.85,0.85,1.0 };

	trans.position_ = { -0.61,0.85,0 };
	Image::SetRect(hNumbers_, 51.2 * 0, 0, 51.2, 88);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

	trans.position_ = { -0.53,0.85,0 };
	Image::SetRect(hNumbers_, 51.2 * 0, 0, 51.2, 88);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

	trans.position_ = { -0.45,0.85,0 };
	Image::SetRect(hNumbers_, 51.2 * 8, 0, 51.2, 88);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);*/

	string estr = ConstructEnemyNumberString();
	if (estr.size() < 3)
		estr = std::string(3 - estr.size(), '0') + estr;

	for (int i = 0; i < 3; i++)
	{
		int n = estr[i] - '0';
		Image::SetRect(hNumbers_, 51.2 * (float)n, 0, 51.2, 88);
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::Draw(hNumbers_);
	}
}

void HUD::Release()
{
}
