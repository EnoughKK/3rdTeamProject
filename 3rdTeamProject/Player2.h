#pragma once
#include "Object.h"
class Player2 : public Object
{
public:
	Player2();
	virtual ~Player2();

public:
	virtual void	Initialize()	override;
	virtual int 	Update()		override;
	virtual void 	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;

private:
	void	Key_Input();
	void	CalcWorld();
	void	BottomCol();
	void	JumpRotation();
	void	SortRotation();

private:
	bool _isjump = true;
	float _jumpSpeed = 0.f;
	float _RSpeed = 2.f;

private:
	D3DXVECTOR3 _LT;
	D3DXVECTOR3 _RT;
	D3DXVECTOR3 _LD;
	D3DXVECTOR3 _RD;

	D3DXVECTOR3 _LT_LE;
	D3DXVECTOR3 _RT_LE;
	D3DXVECTOR3 _LD_LE;
	D3DXVECTOR3 _RD_LE;

	D3DXVECTOR3 _LT_RE;
	D3DXVECTOR3 _RT_RE;
	D3DXVECTOR3 _LD_RE;
	D3DXVECTOR3 _RD_RE;

	D3DXVECTOR3 _LT_MS;
	D3DXVECTOR3 _RT_MS;
	D3DXVECTOR3 _LD_MS;
	D3DXVECTOR3 _RD_MS;

	float _bodyAngle = 0.f;
};

