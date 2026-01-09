#pragma once
class ScrollManager {
	DECLARE_SINGLE(ScrollManager);
public:
	float		Get_ScrollX() { return ScrollX; }
	float		Get_ScrollY() { return ScrollY; }

	void		Set_ScrollX(float fX) { ScrollX += fX; }
	void		Set_ScrollY(float fY) { ScrollY += fY; }

	void		Scroll_Lock();

private:
	float		ScrollX;
	float		ScrollY;
};

