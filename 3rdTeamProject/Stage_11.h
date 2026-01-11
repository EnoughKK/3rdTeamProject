#pragma once
#include "Scene.h"
class Stage_11 : public Scene
{
public:
	Stage_11();
	virtual ~Stage_11();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetStop() { _isStop = true; }

private:
	void mapInit();

	bool _isStop = false;
};

