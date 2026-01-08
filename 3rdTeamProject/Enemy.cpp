#include "pch.h"
#include "Enemy.h"

EnemyObject::EnemyObject()  { }
EnemyObject::~EnemyObject() { Release(); }

void EnemyObject::Initialize() {
	_info.vLook = { 1.f, 0.f, 0.f };
	EnemyHP = 60.f;
	_speed = 5.f;
	if (!Player) {
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();
	}
}
int EnemyObject::Update() {
	_info.vDir = Player->Get_Info().vPos - _info.vPos;
	D3DXVec3Normalize(&_info.vDir, &_info.vDir);

	if (_info.vPos.y < Player->Get_Info().vPos.y) {
		AngleFromPlayer = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}
	else if (_info.vPos.y >= Player->Get_Info().vPos.y) {
		AngleFromPlayer = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}

    return 0;
}
void EnemyObject::Late_Update() {

}
void EnemyObject::Render(HDC DC) {
	D3DXMatrixIdentity(&_info.matWorld);

	D3DXMATRIX ScaleMatrix, RotationMatrix, PositionMatrix;

	_info.vPos = { 0.f, 0.f, 0.f };

	D3DXVECTOR3 TriVertex01 = { _info.vPos.x + 5.f, _info.vPos.y , 1.f };
	D3DXVECTOR3 TriVertex02 = { _info.vPos.x - 4.f, _info.vPos.y + 3.f, 1.f };
	D3DXVECTOR3 TriVertex03 = { _info.vPos.x - 4.f, _info.vPos.y - 3.f, 1.f };

	D3DXMatrixScaling(&ScaleMatrix, 5.f, 5.f, 5.f);
	D3DXMatrixRotationZ(&RotationMatrix, D3DXToRadian(AngleFromPlayer));
	D3DXMatrixTranslation(&PositionMatrix, 700.f, 100.f, 0.f);

	_info.matWorld = ScaleMatrix * RotationMatrix * PositionMatrix;

	D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);
	D3DXVec3TransformCoord(&TriVertex01, &TriVertex01, &_info.matWorld);
	D3DXVec3TransformCoord(&TriVertex02, &TriVertex02, &_info.matWorld);
	D3DXVec3TransformCoord(&TriVertex03, &TriVertex03, &_info.matWorld);

	MoveToEx(DC, _info.vPos.x, _info.vPos.y, nullptr);
	LineTo(DC, _info.vPos.x + 50 * _info.vDir.x, _info.vPos.y + 50 * _info.vDir.y);

	MoveToEx(DC, TriVertex01.x, TriVertex01.y, nullptr);
	LineTo(DC, TriVertex02.x, TriVertex02.y);
	LineTo(DC, TriVertex03.x, TriVertex03.y);
	LineTo(DC, TriVertex01.x, TriVertex01.y);

	Get_HPBar(DC);
}
void EnemyObject::Release() {

}
void EnemyObject::Get_HPBar(HDC DC) {
	Rectangle(DC, _info.vPos.x - 30.f, _info.vPos.y - 40.f, _info.vPos.x + 30.f, _info.vPos.y - 30.f);

	// InLine

	HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	HGDIOBJ oldPen = SelectObject(DC, myPen);

	HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(DC, myBrush);

	Rectangle(DC, _info.vPos.x - 30.f, _info.vPos.y - 40.f, _info.vPos.x - 30.f + EnemyHP, _info.vPos.y - 30.f);

	SelectObject(DC, oldBrush);
	DeleteObject(myBrush);

	SelectObject(DC, oldPen);
	DeleteObject(myPen);
}
