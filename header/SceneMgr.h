#pragma once


enum class myScene
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult,
	mySceneSaveName
};

void SceneMgrUpdate();

void SceneMgrDraw();

void SceneMgrChange(myScene next);
