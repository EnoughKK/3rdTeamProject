#include "pch.h"
#include "Player1.h"

Player1::Player1()
{
}

Player1::~Player1()
{
	Release();
}

void Player1::Initialize()
{
	_info.vPos = { 260.f, 200.f, 0.f };
	radius = 10.f;
	isSliding = false;
}

int Player1::Update()
{
	prevPos = _info.vPos;
	_info.vPos.y += 2.f;
	LT = { LONG(_info.vPos.x - radius), LONG(_info.vPos.y - radius)};
	RT = { LONG(_info.vPos.x + radius), LONG(_info.vPos.y - radius) };
	LB = { LONG(_info.vPos.x - radius), LONG(_info.vPos.y + radius) };
	RB = { LONG(_info.vPos.x + radius), LONG(_info.vPos.y + radius) };
	Key_Input();
	return 0;
}

void Player1::Late_Update()
{
}

void Player1::Render(HDC hDC)
{
	Ellipse(hDC, _info.vPos.x - radius, _info.vPos.y - radius, _info.vPos.x + radius, _info.vPos.y + radius);
	MoveToEx(hDC, (int)_info.vPos.x, _info.vPos.y, nullptr);
	LineTo(hDC, (int)_info.vPos.x, _info.vPos.y + radius);
}
void Player1::Key_Input()
{
	if (GetAsyncKeyState('A')) {
		_info.vPos = _info.vPos = { 450.f, 200.f, 0.f };
	}
}

void Player1::Release()
{
}
