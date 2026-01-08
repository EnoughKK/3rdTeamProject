#include "pch.h"
#include "Player1.h"

Player1::Player1()
{
}

Player1::~Player1()
{
}

void Player1::Initialize()
{
	_info.vPos = { 400.f, 300.f, 0.f };
	radius = 20.f;

}

int Player1::Update()
{
	_info.vPos.y += 1.f;
	LT = { LONG(_info.vPos.x - radius), LONG(_info.vPos.y - radius)};
	RT = { LONG(_info.vPos.x + radius), LONG(_info.vPos.y - radius) };
	LB = { LONG(_info.vPos.x - radius), LONG(_info.vPos.y + radius) };
	RB = { LONG(_info.vPos.x + radius), LONG(_info.vPos.y + radius) };
	return 0;
}

void Player1::Late_Update()
{
}

void Player1::Render(HDC hDC)
{
	Ellipse(hDC, _info.vPos.x - radius, _info.vPos.y - radius, _info.vPos.x + radius, _info.vPos.y + radius);
}

void Player1::Release()
{
}
