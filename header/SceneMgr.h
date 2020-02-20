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

void SceneMgrUpdate();

void SceneMgrDraw();

void SceneMgrChange(myScene next);
