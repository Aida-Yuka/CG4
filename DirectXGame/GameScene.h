#pragma once

//#include "Effect.h"
#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

// ゲームシーン
class GameScene {
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:

	// 3Dモデル パーティクル
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	/// <summary>
	/// パーティクル発生
	/// </sumary>
	/// <param name = "position">位置</param>
	void ParticleBorn(Vector3 position);
};