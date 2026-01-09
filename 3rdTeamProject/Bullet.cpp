#include "pch.h"
#include "Bullet.h"
#include "Player03.h"

Bullet::Bullet() : Player(nullptr) { }
Bullet::~Bullet() { Release(); }

void Bullet::Initialize() {
	if (!Player) {
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();//Get_ObjectList(OBJECT_TAG::OBJ_PLAYER)->front();
	}
	ScaleVector = { 3.f, 3.f, 0.f };
	_info.vPos = Player->Get_Info().vPos;
	_info.vLook = { 1.f, 0.f, 0.f };
	PositionVector = { dynamic_cast<Player03*>(Player)->Get_PosinPos() };

	GetCursorPos(&MousePoint);
	ScreenToClient(g_hWnd, &MousePoint);

	D3DXVECTOR3 PlayerDirectionVector = Player->Get_Info().vDir;

	if (_info.vPos.y < MousePoint.y) {
		AngleFromPlayer = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &PlayerDirectionVector)));
	}
	else if (_info.vPos.y >= MousePoint.y) {
		AngleFromPlayer = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &PlayerDirectionVector)));
	}
}
int Bullet::Update() {
	FLOAT BulletSpeed = 50.f;
	PositionVector = { _info.vPos.x + BulletSpeed * cosf(D3DXToRadian(AngleFromPlayer)), _info.vPos.y + BulletSpeed * sinf(D3DXToRadian(AngleFromPlayer)) , 0.f };
    
	return 0;
}
void Bullet::Late_Update() {

} 
void Bullet::Render(HDC DC) {
	D3DXMatrixIdentity(&_info.matWorld);

	D3DXMATRIX ScaleMatrix, RotationMatrix, PositionMatrix;

	_info.vPos = { 0.f, 0.f, 0.f };

	D3DXMatrixScaling(&ScaleMatrix, ScaleVector.x, ScaleVector.y, ScaleVector.z);
	D3DXMatrixTranslation(&PositionMatrix, PositionVector.x, PositionVector.y, PositionVector.z);

	_info.matWorld = ScaleMatrix * PositionMatrix;

	D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);

	Rectangle(DC, _info.vPos.x - ScaleVector.x,
		_info.vPos.y - ScaleVector.y,
		_info.vPos.x + ScaleVector.x,
		_info.vPos.y + ScaleVector.y);
}
void Bullet::Release() {

}
