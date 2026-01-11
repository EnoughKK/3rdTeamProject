#include "pch.h"
#include "End_Potal.h"

End_Potal::End_Potal()
{
}

End_Potal::~End_Potal()
{
}

void End_Potal::Initialize()
{
    _size = { 40.f, 40.f, 0.f };
}

int End_Potal::Update()
{
    return OBJ_NOEVENT;
}

void End_Potal::Late_Update()
{
}

void End_Potal::Render(HDC hDC)
{
    D3DXVECTOR3 cameraPos = GET_SINGLE(Camera)->GetCameraPos();

    D3DXVECTOR3 drawPos = { _info.vPos.x - cameraPos.x, _info.vPos.y, _info.vPos.z };

    HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
    HGDIOBJ oldPen = SelectObject(hDC, myPen);

    Utils::DrawCircle(hDC, drawPos, 22.5f);

    SelectObject(hDC, oldPen);
    DeleteObject(myPen);
}

void End_Potal::Release()
{
}
