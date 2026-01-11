#include "pch.h"
#include "RouletteButton.h"

RouletteButton::RouletteButton()
{
}

RouletteButton::RouletteButton(const wstring text) : _text(text)
{
}

RouletteButton::~RouletteButton()
{
    Release();
}

void RouletteButton::Initialize()
{
    _info.vPos = { 650.f, 475.f, 0.f };
}

int RouletteButton::Update()
{
	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

	float l = _info.vPos.x - 50;
	float r = _info.vPos.x + 50;
	float t = _info.vPos.y - 25;
	float d = _info.vPos.y + 25;

	if (mousePos.x > l && mousePos.x < r && mousePos.y > t && mousePos.y < d)
	{

		if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
		{
			dynamic_cast<Roulette*>(m_pRoulette)->Set_ResultChecked(false);
			dynamic_cast<Arrow*>(m_pArrow)->Reset();
			dynamic_cast<Arrow*>(m_pArrow)->SetSpinPressed(true);
		}
	}
	else
	{
		_isOnButton = false;
	}

	return OBJ_NOEVENT;
    return 0;
}

void RouletteButton::Late_Update()
{
}

void RouletteButton::Render(HDC hDC)
{
    Rectangle(hDC, _info.vPos.x - 50.f, 450, _info.vPos.x + 50.f, 500);
	Utils::DrawText(hDC, _info.vPos, _text);
}

void RouletteButton::Release()
{
}
