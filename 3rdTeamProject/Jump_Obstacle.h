#pragma once
#include "Object.h"
class Jump_Obstacle : public Object
{
public:
	Jump_Obstacle();
	virtual ~Jump_Obstacle();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

