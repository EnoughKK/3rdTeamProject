#pragma once
#include "Scene.h"
class Stage_01 : public Scene
{
public:
	Stage_01();
	virtual ~Stage_01();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

