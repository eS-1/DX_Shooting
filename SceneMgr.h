#pragma once


typedef enum
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult
} myScene;

// �V�[���Ǘ��̍X�V
void SceneMgrUpdate();
// �V�[���Ǘ��̕`��
void SceneMgrDraw();
// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next);