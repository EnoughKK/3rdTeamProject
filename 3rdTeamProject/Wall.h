#pragma once
#include "Object.h"
class Wall : public Object {
public:
	Wall();
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

