#include "pch.h"
#include "Jump_Obstacle.h"

Jump_Obstacle::Jump_Obstacle()
{
}

Jump_Obstacle::~Jump_Obstacle()
{
}

void Jump_Obstacle::Initialize()
{
    _size = { 30.f, 20.f, 0.f };
}

int Jump_Obstacle::Update()
{
    return OBJ_NOEVENT;
}

void Jump_Obstacle::Late_Update()
{
}

void Jump_Obstacle::Render(HDC hDC)
{
    HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 255));
    HGDIOBJ oldPen = SelectObject(hDC, myPen);

    D3DXVECTOR3 cameraPos = GET_SINGLE(Camera)->GetCameraPos();

    D3DXVECTOR3 drawPos = { _info.vPos.x - cameraPos.x, _info.vPos.y, _info.vPos.z };

    Utils::DrawRect(hDC, drawPos, _size.x, _size.y);

    SelectObject(hDC, oldPen);
    DeleteObject(myPen);
}

void Jump_Obstacle::Release()
{
}
