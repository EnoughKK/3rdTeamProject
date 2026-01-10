#include "pch.h"
#include "Enemy.h"
#include "ScrollManager.h"
#include "Bullet.h"

EnemyObject::EnemyObject()  { }
EnemyObject::~EnemyObject() { Release(); }

void EnemyObject::Initialize() {
	_info.vLook = { 1.f, 0.f, 0.f };
	_size = { 5.f, 5.f, 0.f };
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
		AngleFromPlayer =  D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}
	else if (_info.vPos.y >= Player->Get_Info().vPos.y) {
		AngleFromPlayer = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}

	for (auto BulletObject : *ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_BULLET)) {
		if (CollisionManager::GetInstance()->Collision_Rect(this, BulletObject)) {
			EnemyHP -= 10;
			dynamic_cast<Bullet*>(BulletObject)->Set_Used(true);
			if (EnemyHP <= 0.f) { _info.vPos = { -9999999,-9999999,-9999999 }; }
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

		D3DXMatrixScaling(&ScaleMatrix, 5.f, 5.f, 0.f);
		D3DXMatrixRotationZ(&RotationMatrix, D3DXToRadian(AngleFromPlayer));
		D3DXMatrixTranslation(&PositionMatrix, 700.f, 100.f, 0.f);

		_info.matWorld = ScaleMatrix * RotationMatrix * PositionMatrix;

		D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);

		Rectangle(DC, _info.vPos.x + ScrollManager::GetInstance()->Get_ScrollX() - 5.f,
			_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() - 5.f,
			_info.vPos.x + ScrollManager::GetInstance()->Get_ScrollX() + 5.f,
			_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() + 5.f);


		Get_HPBar(DC);
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
