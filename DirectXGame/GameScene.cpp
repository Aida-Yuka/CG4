#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}
GameScene::~GameScene() { Model2::StaticFinalize(); }

// 初期化
void GameScene::Initialize() {
	Model2::StaticInitialize();
	textureHandle_ = TextureManager::Load("uvChecker.png");
	sprite_ = Sprite::Create(textureHandle_, {400, 100});
}

// 更新
void GameScene::Update() {}

// 描画
void GameScene::Draw() {
	ID3D12GraphicsCommandList* commandList = DirectXCommon::GetInstance()->GetCommandList();
	Sprite::PreDraw(commandList);
	sprite_->Draw();
	Sprite::PostDraw();
}