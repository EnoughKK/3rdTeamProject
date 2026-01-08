#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

private:
	HDC			_hDC;

	RECT _rect = {};
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};

