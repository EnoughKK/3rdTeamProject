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

	D3DXVECTOR3 Get_PosinPos() { return Posin; }

private:
	D3DXVECTOR3	PlayerScaleValue;
	D3DXVECTOR3	PlayerPositionValue;
	FLOAT		PlayerRotationValue;

	D3DXVECTOR3 Posin;
	POINT		MousePoint;
	FLOAT		PosinRotationValue;
};

