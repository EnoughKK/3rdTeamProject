#include "pch.h"
#include "LineManager.h"
#include "ScrollManager.h"

void LineManager::Initialize() {
	MakeWall(400.f, 400.f, 30.f, 30.f);
	MakeWall(400.f, 200.f, 30.f, 30.f);

	MakeWall(410.f, 400.f + 30.f, 15.f, 1000.f);
	MakeWall(410.f, 100.f , 10.f, 100.f);
	MakeWall(400.f, 70.f, 30.f, 30.f);
	MakeWall(410.f, -930.f, 15.f, 1000.f);

	MakeWall(420.f, 185.f, 450.f, 15.f);
	MakeWall(780.f, 0.f, 15.f, 185.f);
	MakeWall(780.f, -500.f, 15.f, 350.f);
	MakeWall(795.f, -300.f, 200.f, 15.f);
	MakeWall(1000.f, 185.f, 100.f, 15.f);
	MakeWall(1045.f, 50.f, 15.f, 135.f);
	MakeWall(1045.f, -100.f, 15.f, 35.f);
	MakeWall(1045.f, -115.f, 185.f, 15.f);
	MakeWall(1130.f, -300.f, 350.f, 15.f);
	MakeWall(1230.f, -500.f, 15.f, 50.f);
	MakeWall(1230.f, -350.f, 15.f, 600.f);

	MakeWall(425.f, -515.f, 1500.f, 15.f);
	MakeWall(1925.f, -515.f, 15.f, 550.f);
	MakeWall(1200.f, 185.f, 30.f, 15.f);
	MakeWall(1245.f, 185.f, 500.f, 15.f);
	MakeWall(1845.f, 185.f, 80.f, 15.f);
	MakeWall(1925.f, 185.f, 15.f, 430.f);
	MakeWall(1230.f, 450.f, 15.f, 150.f);
	MakeWall(1230.f, 600.f, 300.f, 15.f);
	MakeWall(1625.f, 600.f, 300.f, 15.f);

	MakeWall(1245.f, -50.f, 300.f, 15.f);
	MakeWall(1545.f, -50.f, 15.f, 50.f);
	MakeWall(1545.f, 135.f, 15.f, 50.f);
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
	for (auto& pLine : m_Linelist) {
		MoveToEx(DC, pLine->VX1 + ScrollManager::GetInstance()->Get_ScrollX(), pLine->VY1 + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
		LineTo(DC, pLine->VX2 + ScrollManager::GetInstance()->Get_ScrollX(), pLine->VY2 + ScrollManager::GetInstance()->Get_ScrollY());
	}
}