#pragma once


enum class myScene
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult,
	mySceneSaveName,
	mySceneKeyboard,
};

void SceneMgr_Update();

void SceneMgr_Draw();

void SceneMgrChange(myScene next);
