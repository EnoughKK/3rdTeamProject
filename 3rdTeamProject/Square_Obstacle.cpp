#include "pch.h"
#include "Square_Obstacle.h"

Square_Obstacle::Square_Obstacle()
{
}

Square_Obstacle::~Square_Obstacle()
{
}

void Square_Obstacle::Initialize()
{
	_size = { 50.f, 50.f, 0.f };
	_info.vPos = { 200.f, 450.f, 0.f };
}

int Square_Obstacle::Update()
{
	return OBJ_NOEVENT;
}

void Square_Obstacle::Late_Update()
{
}

void Square_Obstacle::Render(HDC hDC)
{
	D3DXVECTOR3 cameraPos = GET_SINGLE(Camera)->GetCameraPos();

	D3DXVECTOR3 drawPos = { _info.vPos.x - cameraPos.x, _info.vPos.y, _info.vPos.z};

	Utils::DrawRect(hDC, drawPos, _size.x, _size.y);
}

void Square_Obstacle::Release()
{
}
