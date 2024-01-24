#pragma once
#include "Engine/GameObject.h"

class Enemy :
    public GameObject
{
private:
	int hModel_; //Enemyのモデルを読む変数
	//モデル自体はグローバル領域に保存されている
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="parent">parent:親のオブジェクトのポインタ</param>
	Enemy(GameObject* parent);

	~Enemy();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//何かと衝突した場合に呼ばれる
   //引数：pTarget	衝突した相手
	//void OnCollision(GameObject* pTarget);
};

