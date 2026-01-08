#pragma once
#include "Object.h"
class Bullet : public Object {
public:
	Bullet();
	virtual ~Bullet();

public:
	void Initialize()		override;
	int  Update()			override;
	void Late_Update()		override;
	void Render(HDC DC)		override;
	void Release()			override;

public:
	void Set_Player(Object* _Player) { Player = _Player; }

private:
	Object* Player;
	POINT	MousePoint;

	FLOAT	AngleFromPlayer;

	D3DXVECTOR3  PositionVector;
	D3DXVECTOR3	 ScaleVector;
};

