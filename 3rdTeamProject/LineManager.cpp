#include "pch.h"
#include "LineManager.h"
#include "ScrollManager.h"
#include "Player03.h"
LineManager::~LineManager() { Release(); }

void LineManager::Initialize() {
	MakeWall(400.f, 400.f, 30.f, 30.f);
	MakeWall(400.f, 200.f, 30.f, 30.f);

	MakeWall(410.f, 430.f , 25.f, 435.f);
	MakeWall(410.f, 100.f , 25.f, 100.f);
	MakeWall(400.f, 70.f, 30.f, 30.f);
	MakeWall(410.f, -515.f, 25.f, 585.f);

	MakeWall(420.f, 185.f, 450.f, 25.f);
	MakeWall(780.f, 0.f, 25.f, 185.f);
	MakeWall(780.f, -500.f, 25.f, 350.f);
	MakeWall(795.f, -300.f, 200.f, 25.f);
	MakeWall(1000.f, 185.f, 100.f, 25.f);
	MakeWall(1045.f, 50.f, 25.f, 135.f);
	MakeWall(1045.f, -100.f, 25.f, 35.f);
	MakeWall(1045.f, -115.f, 185.f, 25.f);
	MakeWall(1130.f, -300.f, 350.f, 25.f);
	MakeWall(1230.f, -500.f, 25.f, 50.f);
	MakeWall(1230.f, -350.f, 25.f, 600.f);

	MakeWall(425.f, -515.f, 1800.f, 25.f);
	MakeWall(1925.f, -500.f, 25.f, 550.f);
	MakeWall(1675.f, -500.f, 25.f, 215.f);
	MakeWall(1600.f, -300.f, 75.f, 25.f);
	MakeWall(1200.f, 185.f, 30.f, 25.f);
	MakeWall(1245.f, 185.f, 500.f, 25.f);
	MakeWall(1845.f, 185.f, 80.f, 25.f);

	MakeWall(1925.f, 155.f, 25.f, 460.f);
	MakeWall(1230.f, 450.f, 25.f, 150.f);
	MakeWall(1230.f, 600.f, 200.f, 25.f);
	MakeWall(1575.f, 600.f, 350.f, 25.f);
	MakeWall(1625.f, 200.f, 25.f, 200.f);
	MakeWall(1625.f, 530.f, 25.f, 70.f);

	MakeWall(1245.f, -50.f, 300.f, 25.f);
	MakeWall(1545.f, -50.f, 25.f, 50.f);
	MakeWall(1545.f, 100.f, 25.f, 85.f);
	MakeWall(425.f, 850.f, 1800.f, 25.f);
	MakeWall(425.f, 450.f, 150.f, 25.f);
	MakeWall(675.f, 450.f, 50.f, 25.f);
	MakeWall(725.f, 450.f, 25.f, 400.f);
	MakeWall(2210.f, -500.f, 25.f, 1350.f);

	Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();
}
void LineManager::Update() {
	
}
INT LineManager::Collision_Line(INT fX, INT fY) {
	for (auto& Line : m_Linelist) {
		if (((fX >= Line->VX1 + ScrollManager::GetInstance()->Get_ScrollX() && fX <= Line->VX2 + ScrollManager::GetInstance()->Get_ScrollX()) || 
			(fX >= Line->VX2 + ScrollManager::GetInstance()->Get_ScrollX() && fX <= Line->VX1 + ScrollManager::GetInstance()->Get_ScrollX())) && 
			(Line->VY1 != Line->VY2)
			&& ((fY >= Line->VY1 + ScrollManager::GetInstance()->Get_ScrollY() && fY <= Line->VY2 + ScrollManager::GetInstance()->Get_ScrollY()) || 
				(fY >= Line->VY2 + ScrollManager::GetInstance()->Get_ScrollY() && fY <= Line->VY1 + ScrollManager::GetInstance()->Get_ScrollY()))) {
			return COL_LR;
		}
		else if ((Line->VY1 == Line->VY2) && 
			((fX >= Line->VX1 + ScrollManager::GetInstance()->Get_ScrollX() && fX <= Line->VX2 + ScrollManager::GetInstance()->Get_ScrollX()) || 
				(fX >= Line->VX2 + ScrollManager::GetInstance()->Get_ScrollX() && fX <= Line->VX1 + ScrollManager::GetInstance()->Get_ScrollX()))
			&& ((fY >= Line->VY1 + ScrollManager::GetInstance()->Get_ScrollY() && fY <= Line->VY2 + ScrollManager::GetInstance()->Get_ScrollY()) || 
				(fY >= Line->VY2 + ScrollManager::GetInstance()->Get_ScrollY() && fY <= Line->VY1 + ScrollManager::GetInstance()->Get_ScrollY()))) {
			return COL_UD;
		}
	}
	return COL_END;
}
void LineManager::Render(HDC DC) {
	HBRUSH myBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(DC, myBrush);
	for (auto& pLine : m_WallList) {
		Rectangle(DC, pLine->VX1 + ScrollManager::GetInstance()->Get_ScrollX(), pLine->VY1 + ScrollManager::GetInstance()->Get_ScrollY(), 
			pLine->VX2 + ScrollManager::GetInstance()->Get_ScrollX(), pLine->VY2 + ScrollManager::GetInstance()->Get_ScrollY());
	}
	SelectObject(DC, oldBrush);
	DeleteObject(myBrush);
}

void LineManager::Release() {
	for_each(m_Linelist.begin(), m_Linelist.end(), Safe_Delete<Line*>);
	m_Linelist.clear();
}