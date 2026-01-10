#pragma once
class Camera
{
	DECLARE_SINGLE(Camera)

	void Init();
	void Update();

public:
	D3DXVECTOR3		GetCameraPos() { return _cameraPos; }
	void			SetCameraPos(D3DXVECTOR3 cameraPos) { _cameraPos = cameraPos; }

private:
	D3DXVECTOR3 _cameraPos = { 0, 0, 0 };
};

