#include "pch.h"
#include "Light.h"
#include "LineManager.h"

LightObject::LightObject()	{			 }
LightObject::~LightObject() { Release(); }

void LightObject::Initialize() {
	_info.vLook = { 1.f, 0.f, 0.f };
	if (!Player) {
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();//Get_ObjectList(OBJECT_TAG::OBJ_PLAYER)->front();
	}

	Distortion = false;
	LineManager::GetInstance()->MakeLine(100.f, 100.f, 100.f, 500.f);
}
int LightObject::Update() {
	GetCursorPos(&MousePoint);
	ScreenToClient(g_hWnd, &MousePoint);
	return 0;
}
void LightObject::Late_Update()	{

}
void LightObject::Render(HDC DC) {
	_info.vDir = Player->Get_Info().vDir;
	FLOAT RightAngle = 0.f, LeftAngle = 0.f, LightDistance = 0.f, LightMaxDistance = 300.f, LightAngle = 15.f;

	if (Player->Get_Info().vPos.y < MousePoint.y) {
		RightAngle = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) + LightAngle;
		LeftAngle = D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle;
	}
	else if (Player->Get_Info().vPos.y >= MousePoint.y) {
		RightAngle = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) + LightAngle;
		LeftAngle = -D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle;
	}

	//for (FLOAT i = 0.f; i < abs(RightAngle - LeftAngle); i += 0.25f) {
	//	MoveToEx(DC, Player->Get_Info().vPos.x, Player->Get_Info().vPos.y, nullptr);
	//	LineTo(DC, Player->Get_Info().vPos.x + 200 * cosf(D3DXToRadian(RightAngle - i)), Player->Get_Info().vPos.y + 200 * sinf(D3DXToRadian(RightAngle - i)));
	//}
	//
	//MoveToEx(DC, Player->Get_Info().vPos.x, Player->Get_Info().vPos.y, nullptr);
	//LineTo(DC, Player->Get_Info().vPos.x + 200 * cosf(D3DXToRadian(RightAngle)), Player->Get_Info().vPos.y + 200 * sinf(D3DXToRadian(RightAngle)));
	//
	//MoveToEx(DC, Player->Get_Info().vPos.x, Player->Get_Info().vPos.y, nullptr);
	//LineTo(DC, Player->Get_Info().vPos.x + 200 * cosf(D3DXToRadian(LeftAngle)), Player->Get_Info().vPos.y + 200 * sinf(D3DXToRadian(LeftAngle)));
	//
	//TCHAR FPS[100] = { 0 };
	//swprintf_s(FPS, L"FPS : %f , %f", LeftAngle, RightAngle);
	//SetWindowText(g_hWnd, FPS);

	D3DXVECTOR3 Vertex01 = { Player->Get_Info().vPos.x, Player->Get_Info().vPos.y, 0.f };
	Distortion = true;

	MoveToEx(DC, Vertex01.x, Vertex01.y, nullptr);
	for (int i = 1; i < 200; ++i) {
		D3DXVECTOR3 Vertex02 = { Player->Get_Info().vPos.x + i * _info.vDir.x, Player->Get_Info().vPos.y + i * _info.vDir.y, 0.f };
		if (LineManager::GetInstance()->Collision_Line(Vertex02.x, Vertex02.y)) {
			_info.vDir.x = -_info.vDir.x;

			LineTo(DC, Vertex02.x + (200 - i) * _info.vDir.x, Vertex02.y + (200 - i) * _info.vDir.y );
			Distortion = false;
		}
		else if(Distortion){
			//(_info.vDir.x / _info.vDir.y) * (X - Vertex01.x) + Vertex01.y
			LineTo(DC, Player->Get_Info().vPos.x + i * _info.vDir.x, Player->Get_Info().vPos.y + i * _info.vDir.y);
		}
		
	}
	LineManager::GetInstance()->Render(DC);

}
void LightObject::Release() {
}
//if (LineManager::GetInstance()->Collision_Line(Player->Get_Info().vPos.x + Distance * cosf(D3DXToRadian(RightAngle - Angle)),
//	Player->Get_Info().vPos.y + Distance * sinf(D3DXToRadian(RightAngle - Angle)))) {
//	SetPixel(DC, Player->Get_Info().vPos.x + Distance * cosf(D3DXToRadian(RightAngle - Angle)),
//		Player->Get_Info().vPos.y + Distance * sinf(D3DXToRadian(RightAngle - Angle)), RGB(255, 0, 0));
//}
//else {
//	SetPixel(DC, Player->Get_Info().vPos.x + Distance * cosf(D3DXToRadian(RightAngle - Angle)),
//		Player->Get_Info().vPos.y + Distance * sinf(D3DXToRadian(RightAngle - Angle)), RGB(255 - Distance, 255 - Distance, 255 - Distance));
//}