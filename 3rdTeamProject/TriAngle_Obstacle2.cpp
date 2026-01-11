#include "pch.h"
#include "TriAngle_Obstacle2.h"

TriAngle_Obstacle2::TriAngle_Obstacle2()
{
}

TriAngle_Obstacle2::~TriAngle_Obstacle2()
{
}

void TriAngle_Obstacle2::Initialize()
{
	_size = { 50.f, 50.f, 0.f };
}

int TriAngle_Obstacle2::Update()
{
	return OBJ_NOEVENT;
}

void TriAngle_Obstacle2::Late_Update()
{
}

void TriAngle_Obstacle2::Render(HDC hDC)
{
	HPEN myPen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
	HGDIOBJ oldPen = SelectObject(hDC, myPen);

	D3DXVECTOR3 cameraPos = GET_SINGLE(Camera)->GetCameraPos();

	MoveToEx(hDC, _info.vPos.x - (_size.x / 2) - cameraPos.x, _info.vPos.y - (_size.y / 2), nullptr);
	LineTo(hDC, _info.vPos.x + (_size.x / 2) - cameraPos.x, _info.vPos.y - (_size.y / 2));
	LineTo(hDC, _info.vPos.x - cameraPos.x, _info.vPos.y + (_size.y / 2));
	LineTo(hDC, _info.vPos.x - (_size.x / 2) - cameraPos.x, _info.vPos.y - (_size.y / 2));

	SelectObject(hDC, oldPen);
	DeleteObject(myPen);
}

void TriAngle_Obstacle2::Release()
{
}
