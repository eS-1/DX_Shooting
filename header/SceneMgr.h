#pragma once


enum class myScene
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult
};

// シーン管理の更新
void SceneMgrUpdate();
// シーン管理の描画
void SceneMgrDraw();
// シーン遷移用の関数
void SceneMgrChange(myScene next);