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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	HUD(GameObject* parent);
	int hHUD_;//残り残機数の画像
	int hNumbers_;//数字の画像
	int hKinoko_;
	Transform tHud_;
	std::vector<Transform> tNumbers_;
	//Transform tNumbers[3];
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

