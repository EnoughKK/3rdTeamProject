#pragma once
#include "Scene.h"
class LogoScene : public Scene
{
public:
	LogoScene();
	virtual ~LogoScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

