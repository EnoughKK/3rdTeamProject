#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "LogoScene.h"
#include "Stage_01.h"
#include "Stage_11.h"
#include "Stage_21.h"

SceneManager::~SceneManager()
{
	Safe_Delete(_scene);
}

void SceneManager::Init()
{
	if (_scene)
		_scene->Init();
}

void SceneManager::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneManager::Late_Update()
{
	if (_scene)
		_scene->Late_Update();
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (sceneType == _sceneType)
		return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::Logo:
		newScene = new LogoScene();
		break;

	case SceneType::Stage_01:
		newScene = new Stage_01();
		break;

	case SceneType::Stage_11:
		newScene = new Stage_11();
		break;

	case SceneType::Stage_21:
		newScene = new Stage_21();
		break;

	case SceneType::End:
		DestroyWindow(g_hWnd);
		return;
	default:
		break;
	}

	if (sceneType == SceneType::Logo)
	{
		GET_SINGLE(ObjectManager)->Clear();
	}
	else
		GET_SINGLE(ObjectManager)->ChangeSceneClear();

	newScene->Init();

	Safe_Delete(_scene);

	_scene = newScene;
	_sceneType = sceneType;
}
