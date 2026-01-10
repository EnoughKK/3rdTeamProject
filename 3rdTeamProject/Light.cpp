#include "pch.h"
#include "Light.h"
#include "LineManager.h"
#include "ScrollManager.h"

LightObject::LightObject()	{			 }
LightObject::~LightObject() { Release(); }

void LightObject::Initialize() {
	_info.vLook = { 1.f, 0.f, 0.f };
	if (!Player) { Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front(); }

	
}
int LightObject::Update() {
	GetCursorPos(&MousePoint);
	ScreenToClient(g_hWnd, &MousePoint);

	MousePoint.x += ScrollManager::GetInstance()->Get_ScrollX();
	MousePoint.y += ScrollManager::GetInstance()->Get_ScrollY();

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

	FLOAT DrawTransition = 0.f;

	D3DXVECTOR3	LineDirectionVertex = { 0.f, 0.f, 0.f };
	D3DXVECTOR3 LineVertex = { Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), 0.f };
	MoveToEx(DC, Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
	for (FLOAT i = 0.f; i < abs(RightAngle - LeftAngle); i += 1.f) {
		
		if(((RightAngle - i) <= -30.f && (RightAngle - i) >= -90.f) ||
			((RightAngle - i) <= -120.f && (RightAngle - i) >= -180.f) ||
			((RightAngle - i) <= 60.f && (RightAngle - i) >= 0.f) ||
			((RightAngle - i) <= 150.f && (RightAngle - i) >= 90.f)) {
			LineDirectionVertex = { cosf(D3DXToRadian(LeftAngle + i - DrawTransition)),
				sinf(D3DXToRadian(LeftAngle + i - DrawTransition)), 0.f };
		}
		else {
			LineDirectionVertex = { cosf(D3DXToRadian(RightAngle - i)), sinf(D3DXToRadian(RightAngle - i)), 0.f };

			DrawTransition = i;
		}
		for (int j = 1; j < 255; ++j) {
			
			if (LineManager::GetInstance()->Collision_Line(LineVertex.x, LineVertex.y) == COL_LR) {
				LineDirectionVertex.x = -LineDirectionVertex.x;
			}

			else if (LineManager::GetInstance()->Collision_Line(LineVertex.x, LineVertex.y) == COL_UD) {
				LineDirectionVertex.y = -LineDirectionVertex.y;
			}
			
			HPEN myPen = CreatePen(PS_SOLID, 0, RGB(255 - j, 255 - j, 255 - j));
			HGDIOBJ oldPen = SelectObject(DC, myPen);

			LineTo(DC, LineVertex.x + LineDirectionVertex.x, LineVertex.y + LineDirectionVertex.y);

			SelectObject(DC, oldPen);
			DeleteObject(myPen);

			MoveToEx(DC, LineVertex.x + LineDirectionVertex.x, LineVertex.y + LineDirectionVertex.y, nullptr);

			LineVertex = { LineVertex.x + LineDirectionVertex.x, LineVertex.y + LineDirectionVertex.y, 0.f };
		}
		MoveToEx(DC, Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
		LineVertex = { Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), 0.f };
	}
}
void LightObject::Release() {

}