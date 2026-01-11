#pragma once
#include "Object.h"
class Wall : public Object {
public:
	Wall();
	Wall(FLOAT _VX1, FLOAT _VY1, FLOAT _VX2, FLOAT _VY2)
	{
		_info.vPos = { (_VX1 + _VX2) / 2, (_VY1 + _VY2) / 2, 0.f };
		_size = { fabsf(_VX1 - _VX2), fabsf(_VY1 - _VY2), 0.f };
	}
	virtual ~Wall();

public:
	void Initialize()		override;
	int  Update()			override;
	void Late_Update()		override;
	void Render(HDC DC)		override;
	void Release()			override;
	
private:
	D3DXVECTOR3 Vertex[4];
	
};

