#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"

//プレイシーン管理するクラス
class Player :
	public GameObject
{
	Text* pText;
	XMFLOAT3 cp;
	float hitRate;
	int hTankBody_;
	XMVECTOR front_;//前ベクトル z+方向　大きさ1
	float speed_;   //0.05 0.05*60 m/s
	int camState_;  //カメラタイプの指定
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);


	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

