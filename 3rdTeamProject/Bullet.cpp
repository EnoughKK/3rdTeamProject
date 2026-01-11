#include "pch.h"
#include "Bullet.h"
#include "Player03.h"
#include "ScrollManager.h"

Bullet::Bullet() : Player(nullptr) { }
Bullet::~Bullet() { Release(); }

void Bullet::Initialize() {
	if (!Player) {
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();//Get_ObjectList(OBJECT_TAG::OBJ_PLAYER)->front();
	}
	Broken = false;
	ScaleVector = { 3.f, 3.f, 0.f };
	_size = { 5.f, 5.f, 0.f };
	_info.vLook = { 1.f, 0.f, 0.f };
	_info.vPos = { Player->Get_Info().vPos.x, Player->Get_Info().vPos.y, 0.f };

	MousePoint = dynamic_cast<Player03*>(Player)->GetMousePoint();

	D3DXVECTOR3 PlayerDirectionVector = Player->Get_Info().vDir;

	if (_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() < MousePoint.y) {
		AngleFromPlayer = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &PlayerDirectionVector)));
	}
	else if (_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() >= MousePoint.y) {
		AngleFromPlayer = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &PlayerDirectionVector)));
	}
}
int Bullet::Update() {
	
	if (Broken)	return 0;

	for (auto& Env : *ObjectManager::GetInstance()->GetObjectList(OBJID::ENVIROMENT)) {
		if (CollisionManager::GetInstance()->Collision_RectForPlayer(this, Env)) {
			Set_Used(true);
		}
	}
	FLOAT BulletSpeed = 25.f;

	PositionVector = { _info.vPos.x + BulletSpeed * cosf(D3DXToRadian(AngleFromPlayer)),
					   _info.vPos.y + BulletSpeed * sinf(D3DXToRadian(AngleFromPlayer)), 0.f };

	return 0;
}
void Bullet::Late_Update() { 
	 
}  
void Bullet::Render(HDC DC) {
	if (Broken)	return;

	D3DXMatrixIdentity(&_info.matWorld);

	D3DXMATRIX ScaleMatrix, RotationMatrix, PositionMatrix;

	_info.vPos = { 0.f, 0.f, 0.f };

	vector<D3DXVECTOR3> BulletVertex;

	BulletVertex.push_back({ _info.vPos.x, _info.vPos.y, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x + 1.f, BulletVertex.back().y, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x + 0.5f, BulletVertex.back().y + 0.5f, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x, BulletVertex.back().y + 0.5f, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x - 0.5f, BulletVertex.back().y + 0.5f, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x - 1.f, BulletVertex.back().y, 0.f });
	BulletVertex.push_back({ BulletVertex.back().x, BulletVertex.back().y - 1.5f, 0.f });

	D3DXMatrixScaling(&ScaleMatrix, ScaleVector.x, ScaleVector.y, ScaleVector.z);
	D3DXMatrixRotationZ(&RotationMatrix, D3DXToRadian(AngleFromPlayer));
	D3DXMatrixTranslation(&PositionMatrix, PositionVector.x, PositionVector.y, PositionVector.z);

	_info.matWorld = ScaleMatrix * RotationMatrix * PositionMatrix;

	D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);
	D3DXVec3TransformCoord(&BulletVertex[0], &BulletVertex[0], &_info.matWorld);

	MoveToEx(DC, BulletVertex[0].x + ScrollManager::GetInstance()->Get_ScrollX(), BulletVertex[0].y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
	for (int i = 1; i < BulletVertex.size(); ++i) {
		D3DXVec3TransformCoord(&BulletVertex[i], &BulletVertex[i], &_info.matWorld);
		LineTo(DC, BulletVertex[i].x + ScrollManager::GetInstance()->Get_ScrollX(), BulletVertex[i].y + ScrollManager::GetInstance()->Get_ScrollY());
	}
	//Rectangle(DC, _info.vPos.x + ScrollManager::GetInstance()->Get_ScrollX() - ScaleVector.x ,
	//	_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() - ScaleVector.y,
	//	_info.vPos.x + ScrollManager::GetInstance()->Get_ScrollX() + ScaleVector.x,
	//	_info.vPos.y + ScrollManager::GetInstance()->Get_ScrollY() + ScaleVector.y);
}
void Bullet::Release() {

}