#pragma once

struct Line {
	FLOAT VX1, VY1, VX2, VY2;
	Line(FLOAT _VX1, FLOAT _VY1, FLOAT _VX2, FLOAT _VY2)
		: VX1(_VX1), VY1(_VY1), VX2(_VX2), VY2(_VY2) {}
};
class LineManager {
	DECLARE_SINGLE(LineManager)

public:
	void MakeLine(FLOAT _VX1, FLOAT _VY1, FLOAT _VX2, FLOAT _VY2)
	{
		m_Linelist.push_back(new Line{ _VX1 , _VY1 , _VX2 , _VY2 });
	}
	bool Collision_Line(INT fX, INT fY);
	list<Line*>*	Get_LineList() {return &m_Linelist;}
	void Render(HDC DC);

private:
	list<Line*>		m_Linelist;
};

