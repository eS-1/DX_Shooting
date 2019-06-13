#pragma once


typedef enum
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult
} myScene;

// シーン管理の更新
void SceneMgrUpdate();
// シーン管理の描画
void SceneMgrDraw();
// シーン遷移用の関数
void SceneMgrChange(myScene next);