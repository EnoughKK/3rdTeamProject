#include "pch.h"
#include "Button.h"

Button::Button()
{
}

Button::Button(const wstring text) : _text(text)
{
}

Button::Button(const wstring text, SceneType sceneType) : _text(text), _sceneType(sceneType)
{
}

Button::~Button()
{
}

void Button::Initialize()
{
	_info.vPos = { 400.f, 300.f, 0.f };
	_size = { 150.f, 50.f, 0.f };
}

int Button::Update()
{
    POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

	float l = _info.vPos.x;
	float r = _info.vPos.x + _size.x;
	float t = _info.vPos.y;
	float d = _info.vPos.y + _size.y;

	if (mousePos.x > l && mousePos.x < r && mousePos.y > t && mousePos.y < d)
	{

		if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse) && _sceneType != SceneType::None)
		{
			GET_SINGLE(SceneManager)->ChangeScene(_sceneType);
			return CHANGE_SCENE;
		}
	}
	else
	{
		_isOnButton = false;
	}

    return OBJ_NOEVENT;
}

void Button::Late_Update()
{
}

void Button::Render(HDC hDC)
{
	//Utils::DrawCircle(hDC, _info.vPos, 50);
    Utils::DrawText(hDC, _info.vPos, _text);
}

void Button::Release()
{
}
