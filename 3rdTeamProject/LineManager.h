#pragma once
enum COL_TYPE { COL_LR, COL_UD, COL_END };
struct Line {
	FLOAT VX1, VY1, VX2, VY2;
	Line(FLOAT _VX1, FLOAT _VY1, FLOAT _VX2, FLOAT _VY2)
		: VX1(_VX1), VY1(_VY1), VX2(_VX2), VY2(_VY2) {}
};
class LineManager {
	DECLARE_SINGLE(LineManager)

public:
	void Initialize();
	void MakeLine(FLOAT _VX1, FLOAT _VY1, FLOAT _VX2, FLOAT _VY2)
	{
		m_Linelist.push_back(new Line{ _VX1 , _VY1 , _VX2 , _VY2 });
	}
	INT Collision_Line(INT fX, INT fY);
	list<Line*>*	Get_LineList() {return &m_Linelist;}
	void Render(HDC DC);

	void MakeWall(FLOAT _POSX, FLOAT _POSY, FLOAT _WTH, FLOAT _HGT) {
		m_Linelist.push_back(new Line{ _POSX , _POSY , _POSX + _WTH , _POSY });
		m_Linelist.push_back(new Line{ _POSX , _POSY + _HGT , _POSX + _WTH , _POSY + _HGT });
		m_Linelist.push_back(new Line{ _POSX , _POSY , _POSX , _POSY + _HGT });
		m_Linelist.push_back(new Line{ _POSX + _WTH , _POSY , _POSX + _WTH , _POSY + _HGT });
	}

private:
	list<Line*>		m_Linelist;
};

