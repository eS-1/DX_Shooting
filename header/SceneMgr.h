#pragma once


enum class myScene
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult,
	mySceneSaveName
};

// �V�[���Ǘ��̍X�V
void SceneMgrUpdate();
// �V�[���Ǘ��̕`��
void SceneMgrDraw();
// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next);