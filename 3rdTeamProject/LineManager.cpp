#include "pch.h"
#include "LineManager.h"

bool LineManager::Collision_Line(INT fX, INT fY) {
	for (auto& Line : m_Linelist) {
		if ((fX >= Line->VX1 && fX <= Line->VX2) || (fX >= Line->VX2 && fX <= Line->VX1)) {
			return true;
		}
	}
	return false;
}
void LineManager::Render(HDC DC) {

	for (auto& pLine : m_Linelist) {
		for (int i = pLine->VX1; i <= pLine->VX2; ++i) {
			SetPixel(DC, i, ((pLine->VY2 - pLine->VY1) / (pLine->VX2 - pLine->VX1)) * (i - pLine->VX1) + pLine->VY1, RGB(255, 0, 0));
		}
	}
	for (auto& pLine : m_Linelist) {
		MoveToEx(DC, pLine->VX1, pLine->VY1, nullptr);
		LineTo(DC, pLine->VX2, pLine->VY2);
	}
}