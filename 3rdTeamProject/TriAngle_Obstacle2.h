#pragma once
#include "Object.h"
class TriAngle_Obstacle2 : public Object
{
public:
	TriAngle_Obstacle2();
	virtual ~TriAngle_Obstacle2();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

