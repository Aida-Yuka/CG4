#include "Particle.h"

void Particle::Initialize(Model* model)
{
	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Particle::Update()
{
	//行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Particle::Draw(Camera& camera)
{
	//3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}