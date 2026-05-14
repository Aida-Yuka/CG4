#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() { }
GameScene::~GameScene() { Model2::StaticFinalize(); }

//初期化
void GameScene::Initialize()
{
	Model2::StaticInitialize();
}

//更新
void GameScene::Update()
{

}

//描画
void GameScene::Draw()
{

}