#pragma once
#include "Object.h"
class TriAngle_Obstacle : public Object
{
public:
	TriAngle_Obstacle();
	virtual ~TriAngle_Obstacle();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};