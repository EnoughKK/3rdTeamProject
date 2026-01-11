#include "pch.h"
#include "Enemy.h"
#include "ScrollManager.h"
#include "Bullet.h"
#include "Player03.h"

EnemyObject::EnemyObject()  { }
EnemyObject::~EnemyObject() { Release(); }

void EnemyObject::Initialize() {
	_info.vLook = { 1.f, 0.f, 0.f };
	_size = { 25.f, 25.f, 0.f };
	EnemyHP = 60.f;
	_speed = 5.f;
	if (!Player) {
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();
	}
}
int EnemyObject::Update() {

	if (isnan(AngleFromPlayer) == true) {
		_info.vPos = { 0, 0, 0 };
	}
	_info.vDir = Player->Get_Info().vPos - _info.vPos;

	D3DXVec3Normalize(&_info.vDir, &_info.vDir);

	if (_info.vPos.y < Player->Get_Info().vPos.y) {
		AngleFromPlayer =  D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}
	else if (_info.vPos.y >= Player->Get_Info().vPos.y) {
		AngleFromPlayer = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}

	for (auto BulletObject : *ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_BULLET)) {
		if (CollisionManager::GetInstance()->Collision_Rect(this, BulletObject)) {
			EnemyHP -= 10;
			dynamic_cast<Bullet*>(BulletObject)->Set_Used(true);
			if (EnemyHP <= 0.f) { _info.vPos = { -9999999,-9999999,-9999999 };
				dynamic_cast<Player03*>(Player)->SetKillCount(dynamic_cast<Player03*>(Player)->GetKillCount() + 1);
			}
		}
	}
    return 0;
}
void EnemyObject::Late_Update() {

}
void EnemyObject::Render(HDC DC) {
	if (EnemyHP > 0.f) {
		D3DXMatrixIdentity(&_info.matWorld);

		D3DXMATRIX ScaleMatrix, RotationMatrix, PositionMatrix;

		_info.vPos = { 0.f, 0.f, 0.f };

		D3DXVECTOR3 Vertex01 = { sqrtf(3) / 3 * 10, 0.f, 0.f };
		D3DXVECTOR3 Vertex02 = { -sqrtf(3) / 3 * cosf(D3DXToRadian(60)) * 10, -sqrtf(3) / 3 * sinf(D3DXToRadian(60)) * 10, 0.f };
		D3DXVECTOR3 Vertex03 = { -sqrtf(3) / 3 * cosf(D3DXToRadian(60)) * 10, sqrtf(3) / 3 * sinf(D3DXToRadian(60)) * 10, 0.f };

		D3DXVECTOR3 Posin01 = { Vertex01.x + 5.f, 0.f, 0.f };

		D3DXVECTOR3 Posin02S = { Vertex01.x - 2.f, -1.f, 0.f };
		D3DXVECTOR3 Posin02 = { Vertex01.x + 4.f, -1.f, 0.f }
		;
		D3DXVECTOR3 Posin03S = { Vertex01.x - 2.f, 1.f, 0.f };
		D3DXVECTOR3 Posin03 = { Vertex01.x + 4.f, 1.f, 0.f };

		D3DXMatrixScaling(&ScaleMatrix, 5.f, 5.f, 0.f);
		D3DXMatrixRotationZ(&RotationMatrix, D3DXToRadian(AngleFromPlayer));
		D3DXMatrixTranslation(&PositionMatrix, StartPos.x, StartPos.y, 0.f);

		_info.matWorld = ScaleMatrix * RotationMatrix * PositionMatrix;

		D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);
		D3DXVec3TransformCoord(&Vertex01, &Vertex01, &_info.matWorld);
		D3DXVec3TransformCoord(&Vertex02, &Vertex02, &_info.matWorld);
		D3DXVec3TransformCoord(&Vertex03, &Vertex03, &_info.matWorld);

		D3DXVec3TransformCoord(&Posin01, &Posin01, &_info.matWorld);
		D3DXVec3TransformCoord(&Posin02, &Posin02, &_info.matWorld);
		D3DXVec3TransformCoord(&Posin03, &Posin03, &_info.matWorld);
		D3DXVec3TransformCoord(&Posin02S, &Posin02S, &_info.matWorld);
		D3DXVec3TransformCoord(&Posin03S, &Posin03S, &_info.matWorld);

		HPEN myPen = CreatePen(PS_SOLID, 5, RGB(20, 20, 20));
		HPEN oldPen = (HPEN)SelectObject(DC, myPen);

		MoveToEx(DC, Vertex01.x + ScrollManager::GetInstance()->Get_ScrollX(), Vertex01.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
		LineTo(DC, Posin01.x + ScrollManager::GetInstance()->Get_ScrollX(), Posin01.y + ScrollManager::GetInstance()->Get_ScrollY());
		MoveToEx(DC, Posin02S.x + ScrollManager::GetInstance()->Get_ScrollX(), Posin02S.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
		LineTo(DC, Posin02.x + ScrollManager::GetInstance()->Get_ScrollX(), Posin02.y + ScrollManager::GetInstance()->Get_ScrollY());
		MoveToEx(DC, Posin03S.x + ScrollManager::GetInstance()->Get_ScrollX(), Posin03S.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
		LineTo(DC, Posin03.x + ScrollManager::GetInstance()->Get_ScrollX(), Posin03.y + ScrollManager::GetInstance()->Get_ScrollY());
		MoveToEx(DC, Vertex01.x + ScrollManager::GetInstance()->Get_ScrollX(), Vertex01.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);

		LineTo(DC, Vertex02.x + ScrollManager::GetInstance()->Get_ScrollX(), Vertex02.y + ScrollManager::GetInstance()->Get_ScrollY());
		LineTo(DC, Vertex03.x + ScrollManager::GetInstance()->Get_ScrollX(), Vertex03.y + ScrollManager::GetInstance()->Get_ScrollY());
		LineTo(DC, Vertex01.x + ScrollManager::GetInstance()->Get_ScrollX(), Vertex01.y + ScrollManager::GetInstance()->Get_ScrollY());

		SelectObject(DC, oldPen);
		DeleteObject(myPen);
		//Get_HPBar(DC);
	}
}
void EnemyObject::Release() {

}
void EnemyObject::Get_HPBar(HDC DC) {
	Rectangle(DC, _info.vPos.x - 30.f + ScrollManager::GetInstance()->Get_ScrollX(), _info.vPos.y - 40.f + ScrollManager::GetInstance()->Get_ScrollY(),
				  _info.vPos.x + 30.f + ScrollManager::GetInstance()->Get_ScrollX(), _info.vPos.y - 30.f + ScrollManager::GetInstance()->Get_ScrollY());

	HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	HGDIOBJ oldPen = SelectObject(DC, myPen);

	HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(DC, myBrush);

	Rectangle(DC, _info.vPos.x - 30.f + ScrollManager::GetInstance()->Get_ScrollX(), _info.vPos.y - 40.f + ScrollManager::GetInstance()->Get_ScrollY(),
		_info.vPos.x - 30.f + EnemyHP + ScrollManager::GetInstance()->Get_ScrollX(), _info.vPos.y - 30.f + ScrollManager::GetInstance()->Get_ScrollY());

	SelectObject(DC, oldBrush);
	DeleteObject(myBrush);

	SelectObject(DC, oldPen);
	DeleteObject(myPen);
}
