#pragma once
#include "Object.h"

class Button : public Object
{
public:
	Button();
	Button(const wstring text);
	Button(const wstring text, SceneType sceneType);
	virtual ~Button();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;

private:

	wstring _text = L"";
	SceneType _sceneType = SceneType::None;

	bool _isOnButton = false;
};

