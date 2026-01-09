#include "pch.h"
#include "Player2.h"

Player2::Player2()
{
}

Player2::~Player2()
{
}

void Player2::Initialize()
{
	_info.vPos = { 0.f, 0.f, 0.f };

	_info.vDir = { 1.f, 0.f, 0.f };

	_info.vLook = { 1.f, 0.f, 0.f };

	_speed = 2.0f;

	_info.vPos.x = 400;
	_info.vPos.y = 300;
}

int Player2::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (_isjump)
	{
		_info.vPos.y += deltaTime * _speed * 100.f;
	}

	Key_Input();

	D3DXMATRIX matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, _bodyAngle);
	D3DXMatrixTranslation(&matTrans, _info.vPos.x, _info.vPos.y, 0.f);

	D3DXMATRIX bodyWorld = matScale * matRotZ * matTrans;

	_LT = { -25.f, -25.f, 0 };
	_RT = { 25.f, -25.f, 0 };
	_LD = { -25.f, 25.f, 0 };
	_RD = { 25.f, 25.f, 0 };

	D3DXVec3TransformCoord(&_LT, &_LT, &bodyWorld);
	D3DXVec3TransformCoord(&_RT, &_RT, &bodyWorld);
	D3DXVec3TransformCoord(&_LD, &_LD, &bodyWorld);
	D3DXVec3TransformCoord(&_RD, &_RD, &bodyWorld);

	_LT_LE = { -15.f, -15.f, 0 };
	_RT_LE = { -5.f, -15.f, 0 };
	_LD_LE = { -15.f, -5.f, 0 };
	_RD_LE = { -5.f, -5.f, 0 };

	D3DXVec3TransformCoord(&_LT_LE, &_LT_LE, &bodyWorld);
	D3DXVec3TransformCoord(&_RT_LE, &_RT_LE, &bodyWorld);
	D3DXVec3TransformCoord(&_LD_LE, &_LD_LE, &bodyWorld);
	D3DXVec3TransformCoord(&_RD_LE, &_RD_LE, &bodyWorld);

	_LT_RE = { 15.f, -15.f, 0 };
	_RT_RE = { 5.f, -15.f, 0 };
	_LD_RE = { 15.f, -5.f, 0 };
	_RD_RE = { 5.f, -5.f, 0 };

	D3DXVec3TransformCoord(&_LT_RE, &_LT_RE, &bodyWorld);
	D3DXVec3TransformCoord(&_RT_RE, &_RT_RE, &bodyWorld);
	D3DXVec3TransformCoord(&_LD_RE, &_LD_RE, &bodyWorld);
	D3DXVec3TransformCoord(&_RD_RE, &_RD_RE, &bodyWorld);

	_LT_MS = { -15.f, 5.f, 0 };
	_RT_MS = { 15.f, 5.f, 0 };
	_LD_MS = { -15.f, 10.f, 0 };
	_RD_MS = { 15.f, 10.f, 0 };

	D3DXVec3TransformCoord(&_LT_MS, &_LT_MS, &bodyWorld);
	D3DXVec3TransformCoord(&_RT_MS, &_RT_MS, &bodyWorld);
	D3DXVec3TransformCoord(&_LD_MS, &_LD_MS, &bodyWorld);
	D3DXVec3TransformCoord(&_RD_MS, &_RD_MS, &bodyWorld);

	BottomCol();

    return OBJ_NOEVENT;
}

void Player2::Late_Update()
{
}

void Player2::Render(HDC hDC)
{
	MoveToEx(hDC, _LT.x, _LT.y, nullptr);
	LineTo(hDC, _RT.x, _RT.y);
	LineTo(hDC, _RD.x, _RD.y);
	LineTo(hDC, _LD.x, _LD.y);
	LineTo(hDC, _LT.x, _LT.y);

	MoveToEx(hDC, _LT_LE.x, _LT_LE.y, nullptr);
	LineTo(hDC, _RT_LE.x, _RT_LE.y);
	LineTo(hDC, _RD_LE.x, _RD_LE.y);
	LineTo(hDC, _LD_LE.x, _LD_LE.y);
	LineTo(hDC, _LT_LE.x, _LT_LE.y);

	MoveToEx(hDC, _LT_RE.x, _LT_RE.y, nullptr);
	LineTo(hDC, _RT_RE.x, _RT_RE.y);
	LineTo(hDC, _RD_RE.x, _RD_RE.y);
	LineTo(hDC, _LD_RE.x, _LD_RE.y);
	LineTo(hDC, _LT_RE.x, _LT_RE.y);

	MoveToEx(hDC, _LT_MS.x, _LT_MS.y, nullptr);
	LineTo(hDC, _RT_MS.x, _RT_MS.y);
	LineTo(hDC, _RD_MS.x, _RD_MS.y);
	LineTo(hDC, _LD_MS.x, _LD_MS.y);
	LineTo(hDC, _LT_MS.x, _LT_MS.y);
}

void Player2::Release()
{
}

void Player2::Key_Input()
{
	float angle = D3DX_PI / 180.0f;

	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_bodyAngle -= angle * _speed;

	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_bodyAngle += angle * _speed;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_info.vPos.x += cosf(_bodyAngle) * _speed;
		_info.vPos.y += sinf(_bodyAngle) * _speed;
	}
	else if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_info.vPos.x -= cosf(_bodyAngle) * _speed;
		_info.vPos.y -= sinf(_bodyAngle) * _speed;
	}
}

void Player2::BottomCol()
{
	if (_LT.y > 500.f)
	{
		_isjump = false;

		_info.vPos.y -= _LT.y - 500.f;
	}

	else if (_RT.y > 500.f)
	{
		_isjump = false;

		_info.vPos.y -= _RT.y - 500.f;
	}

	else if (_RD.y > 500.f)
	{
		_isjump = false;

		_info.vPos.y -= _RD.y - 500.f;
	}

	else if (_LD.y > 500.f)
	{
		_isjump = false;

		_info.vPos.y -= _LD.y - 500.f;
	}
}
