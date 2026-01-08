#pragma once
using namespace std;

class Utils
{
public:
	static void DrawText(HDC hdc, D3DXVECTOR3 pos, const wstring& str);

	static void DrawRect(HDC hdc, D3DXVECTOR3 pos, int32 w, int32 h);

	static void DrawCircle(HDC hdc, D3DXVECTOR3 pos, int32 radius);

	static void DrawLine(HDC hdc, D3DXVECTOR3 from, D3DXVECTOR3 to);

};
