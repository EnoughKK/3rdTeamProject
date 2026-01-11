#pragma once
#include "Object.h"
class Square_Obstacle : public Object
{
public:
	Square_Obstacle();
	virtual ~Square_Obstacle();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

