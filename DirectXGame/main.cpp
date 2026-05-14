#include <Windows.h>
#include"KamataEngine.h"
#include"GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	//エンジンの初期化
	KamataEngine::Initialize(L"LE3D_01_アイダ_ユウカ_CG4");

	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	//ゲームシーンの初期化
	gameScene->Initialize();

	//メインループ
	while (true)
	{
		//エンジンの初期化
		if (KamataEngine::Update())
		{
			break;
		}

		//ゲームシーンの更新
		gameScene->Update();

		//描画開始
		dxCommon->PreDraw();
		
		//ゲームシーンの描画
		gameScene->Draw();

		//描画終了
		dxCommon->PostDraw();

	}
	
	//ゲームシーンの解放
	delete gameScene;

	//nullptrの代入
	gameScene = nullptr;

	//エンジンの終了処理
	KamataEngine::Finalize();
	
	return 0;
}