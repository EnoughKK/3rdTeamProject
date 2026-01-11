#include "pch.h"
#include "Light.h"
#include "LineManager.h"
#include "ScrollManager.h"
#include "Player03.h"

LightObject::LightObject()	{			 }
LightObject::~LightObject() { Release(); }

void LightObject::Initialize() {

	_info.vLook = { 1.f, 0.f, 0.f };

	if (!Player) { Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front(); }
}
int LightObject::Update() {
	return 0;
}
void LightObject::Late_Update()	{

}
void LightObject::Render(HDC DC) {
	MousePoint = dynamic_cast<Player03*>(Player)->GetMousePoint();
	_info.vDir = Player->Get_Info().vDir;
	FLOAT LightAngle = 20.f;

	D3DXVECTOR3	LineDirectionVertex = { 0.f, 0.f, 0.f };
	D3DXVECTOR3 LineVertex = { Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), 0.f };
	MoveToEx(DC, Player->Get_Info().vPos.x + ScrollManager::GetInstance()->Get_ScrollX(), Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
	for (FLOAT i = 0.f; i < LightAngle * 2; i += 0.75f) {
		
		if (Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY() < MousePoint.y) {
			LineDirectionVertex = { cosf(D3DXToRadian(D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle + i)), 
									sinf(D3DXToRadian(D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle + i)), 0.f };
		}
		else if(Player->Get_Info().vPos.y + ScrollManager::GetInstance()->Get_ScrollY() >= MousePoint.y){
			LineDirectionVertex = { cosf(-D3DXToRadian(D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle + i)),
									sinf(-D3DXToRadian(D3DXToDegree(acosf(D3DXVec3Dot(&_info.vLook, &_info.vDir))) - LightAngle + i)), 0.f };
		}
		for (int j = 1; j < 235; j += 1) {
			
			if (LineManager::GetInstance()->Collision_Line(LineVertex.x, LineVertex.y) == COL_LR) { LineDirectionVertex.x = -LineDirectionVertex.x; }
			else if (LineManager::GetInstance()->Collision_Line(LineVertex.x, LineVertex.y) == COL_UD) { LineDirectionVertex.y = -LineDirectionVertex.y; }
			
			HPEN myPen = CreatePen(PS_SOLID, 0, RGB(255 - j , 255 - j, 255 - j));
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