#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager)
	~SceneManager();

public:
	void Init();
	void Update();
	void Late_Update();
	void Render(HDC hdc);
	void Release();

public:
	void ChangeScene(SceneType);
	Scene* GetScene() { return _scene; }

private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;
};

