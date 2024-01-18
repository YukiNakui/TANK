#pragma once
#include "Engine/GameObject.h"

//タイトルシーンを管理するクラス
class TitleScene :
    public GameObject
{

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);
	int hPict_;

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

