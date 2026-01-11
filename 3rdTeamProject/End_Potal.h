#pragma once
#include "Object.h"
class End_Potal : public Object
{
public:
	End_Potal();
	virtual ~End_Potal();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

