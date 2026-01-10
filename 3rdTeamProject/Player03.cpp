#include "pch.h"
#include "Player03.h"
#include "Bullet.h"
#include "Rifle.h"
#include "Light.h"
#include "ScrollManager.h"

Player03::Player03() { }
Player03::~Player03() { Release(); }

void Player03::Initialize() {
	PlayerScaleValue = { 0.f, 0.f, 0.f };
	PlayerPositionValue = { 400.f, 300.f, 0.f };
	PlayerRotationValue = 0.f;
	PosinRotationValue = 0.f;

	_info.vLook = { 1.f, 0.f, 0.f };
	_info.vDir = { 1.f, 0.f, 0.f };
	Posin = { 0.f, 0.f, 0.f };

	ObjectManager::GetInstance()->Add(OBJID::PLAYER_RIFLE, new Rifle);
	ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_RIFLE)->back()->Initialize();
	dynamic_cast<Rifle*>(ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_RIFLE)->back())->Set_Player(this);

	//ObjectManager::GetInstance()->Add(OBJID::PLAYER_LIGHT, new LightObject);
	//ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_LIGHT)->back()->Initialize();
	//dynamic_cast<LightObject*>(ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_LIGHT)->back())->Set_Player(this);
}
int Player03::Update() {
	GetCursorPos(&MousePoint);
	ScreenToClient(g_hWnd, &MousePoint);

	D3DXVECTOR3 MousePos = { (FLOAT)MousePoint.x, (FLOAT)MousePoint.y , 0.f };

	_info.vDir.x = MousePos.x - (PlayerPositionValue.x + ScrollManager::GetInstance()->Get_ScrollX());
	_info.vDir.y = MousePos.y - (PlayerPositionValue.y + ScrollManager::GetInstance()->Get_ScrollY());

	float	fLength = sqrtf(_info.vDir.x * _info.vDir.x + _info.vDir.y * _info.vDir.y);

	_info.vDir.x /= fLength;
	_info.vDir.y /= fLength;
	_info.vDir.z = 0.f;

	FLOAT Angle = 0.f;
	if (_info.vPos.y < MousePoint.y) {
		Angle = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}
	else if (_info.vPos.y >= MousePoint.y) {
		Angle = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir)));
	}

	PosinRotationValue = Angle;

	if (InputManager::GetInstance()->GetButton(KeyType::Right)) {
		PlayerPositionValue.x += +10.f;
	}
	if (InputManager::GetInstance()->GetButton(KeyType::Left)) {
		PlayerPositionValue.x += -10.f;
	}
	if (InputManager::GetInstance()->GetButton(KeyType::Up)) {
		PlayerPositionValue.y += -10.f;
	}
	if (InputManager::GetInstance()->GetButton(KeyType::Down)) {
		PlayerPositionValue.y += 10.f;
	}

	if (500 < PlayerPositionValue.x + ScrollManager::GetInstance()->Get_ScrollX()) {
		ScrollManager::GetInstance()->Set_ScrollX(-10);
	}
	if (300 > PlayerPositionValue.x + ScrollManager::GetInstance()->Get_ScrollX()) {
		ScrollManager::GetInstance()->Set_ScrollX(10);
	}
	if (400 < PlayerPositionValue.y + ScrollManager::GetInstance()->Get_ScrollY()) {
		ScrollManager::GetInstance()->Set_ScrollY(-10);
	}
	if (200 > PlayerPositionValue.y + ScrollManager::GetInstance()->Get_ScrollY()) {
		ScrollManager::GetInstance()->Set_ScrollY(10);
	}

	if (InputManager::GetInstance()->GetButtonDown(KeyType::LeftMouse)) {
		ObjectManager::GetInstance()->Add(OBJID::PLAYER_BULLET, new Bullet);
		ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER_BULLET)->back()->Initialize();
	}
    return 0;
}
void Player03::Late_Update() {
}
void Player03::Render(HDC DC) {

	SetPixel(DC, _info.vPos.x, _info.vPos.y, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x - 1, _info.vPos.y, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x + 1, _info.vPos.y, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x, _info.vPos.y + 1, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x - 1, _info.vPos.y + 1, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x + 1, _info.vPos.y + 1, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x, _info.vPos.y - 1, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x - 1, _info.vPos.y - 1, RGB(255, 0, 0));
	SetPixel(DC, _info.vPos.x + 1, _info.vPos.y - 1, RGB(255, 0, 0));

	D3DXMatrixIdentity(&_info.matWorld);

	D3DXMATRIX ScaleMatrix, RotationMatrix, PositionMatrix;

	_info.vPos = { 0.f, 0.f, 0.f };
	PlayerScaleValue = { 5.f, 5.f, 5.f };

	D3DXVECTOR3 DotPosRT = { _info.vPos.x + 5, _info.vPos.y + 5, 0.f };
	D3DXVECTOR3 DotPosRB = { _info.vPos.x + 5, _info.vPos.y - 5, 0.f };
	D3DXVECTOR3 DotPosLT = { _info.vPos.x - 5, _info.vPos.y + 5, 0.f };
	D3DXVECTOR3 DotPosLB = { _info.vPos.x - 5, _info.vPos.y - 5, 0.f };

	D3DXMatrixScaling(&ScaleMatrix, PlayerScaleValue.x, PlayerScaleValue.y, PlayerScaleValue.z);
	D3DXMatrixRotationZ(&RotationMatrix, D3DXToRadian(PlayerRotationValue));
	D3DXMatrixTranslation(&PositionMatrix, PlayerPositionValue.x, PlayerPositionValue.y, PlayerPositionValue.z);

	_info.matWorld = ScaleMatrix * RotationMatrix * PositionMatrix;

	D3DXVec3TransformCoord(&_info.vPos, &_info.vPos, &_info.matWorld);

	D3DXVec3TransformCoord(&DotPosRT, &DotPosRT, &_info.matWorld);
	D3DXVec3TransformCoord(&DotPosRB, &DotPosRB, &_info.matWorld);
	D3DXVec3TransformCoord(&DotPosLT, &DotPosLT, &_info.matWorld);
	D3DXVec3TransformCoord(&DotPosLB, &DotPosLB, &_info.matWorld);

	

	MoveToEx(DC, DotPosRT.x + ScrollManager::GetInstance()->Get_ScrollX(), DotPosRT.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
	LineTo(DC,   DotPosRB.x	+ ScrollManager::GetInstance()->Get_ScrollX(), DotPosRB.y + ScrollManager::GetInstance()->Get_ScrollY());
	LineTo(DC,   DotPosLB.x	+ ScrollManager::GetInstance()->Get_ScrollX(), DotPosLB.y + ScrollManager::GetInstance()->Get_ScrollY());
	LineTo(DC,   DotPosLT.x	+ ScrollManager::GetInstance()->Get_ScrollX(), DotPosLT.y + ScrollManager::GetInstance()->Get_ScrollY());
	LineTo(DC,   DotPosRT.x + ScrollManager::GetInstance()->Get_ScrollX(), DotPosRT.y + ScrollManager::GetInstance()->Get_ScrollY());
}
void Player03::Release() {
}

