#pragma once
class Object
{
public:
	Object();
	virtual ~Object();

public:
	virtual void	Initialize()	PURE;
	virtual int 	Update()		PURE;
	virtual void 	Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

public:
	INFO			Get_Info() { return _info; }

	D3DXVECTOR3		GetPos() { return _info.vPos; }
	void			SetPos(float x, float y) { _info.vPos.x = x; _info.vPos.y = y; }

	D3DXVECTOR3		GetSize() { return _size; }
	void			SetSize(float x, float y) { _size.x = x; _size.y = y; }

protected:
	INFO		_info;
	D3DXVECTOR3 _size;

	float		_speed;
};

