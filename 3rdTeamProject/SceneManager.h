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

public:
	D3DXVECTOR3		GetCameraPos() { return _cameraPos; }
	void			SetCameraPos(D3DXVECTOR3 cameraPos) { _cameraPos = cameraPos; }

private:
	D3DXVECTOR3 _cameraPos = { 0, 0, 0 };
};

