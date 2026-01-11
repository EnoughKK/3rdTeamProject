#pragma once
#include "Object.h"
class Player03 : public Object {
public: 
	Player03();
	virtual ~Player03();

public:
	void Initialize()		override;
	int  Update()			override;
	void Late_Update()		override;
	void Render(HDC DC)		override;
	void Release()			override;

	D3DXVECTOR3 Get_PlayerPositionValue() { return PlayerPositionValue; }
	void Set_PlayerPositionValue(D3DXVECTOR3 _pOut) { PlayerPositionValue = _pOut; }

	POINT GetMousePoint() { return MousePoint; }

	void SetKillCount(INT _KC) { EnemyKillCount = _KC; }
	INT GetKillCount() { return EnemyKillCount; }

	D3DXMATRIX GetPosinWorld() { return PosinWorld; }

private:
	D3DXVECTOR3	PlayerScaleValue;
	D3DXVECTOR3	PlayerPositionValue;
	FLOAT		PlayerRotationValue;

	D3DXVECTOR3 Posin;
	POINT		MousePoint;
	FLOAT		PosinRotationValue;
	D3DXMATRIX  PosinWorld;

	INT			EnemyKillCount;
	HFONT		SerifFont;
};

