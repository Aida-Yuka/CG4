#pragma once
#include "KamataEngine.h"
#include "Model2.h"
#include <2d/Sprite.h>

// ゲームシーン
class GameScene {
public:
	GameScene();
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	KamataEngine::Sprite* sprite_ = nullptr;
	uint32_t textureHandle_ = 0;
};
