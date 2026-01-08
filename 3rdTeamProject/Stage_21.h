#pragma once
#include "Scene.h"
class Stage_21 : public Scene
{
public:
	Stage_21();
	virtual ~Stage_21();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

