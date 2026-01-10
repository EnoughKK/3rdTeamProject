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

	_speed = 5.f;

	_size = { 50.f, 50.f, 0 };

	_info.vPos.x = 400;
	_info.vPos.y = 300;
}

int Player2::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_prevPos = _info.vPos;

	if (_bodyAngle > (2 * D3DX_PI))
		_bodyAngle -= (2 * D3DX_PI);

	if (_bodyAngle < 0.f)
		_bodyAngle += (2 * D3DX_PI);

	_prevAngle = _bodyAngle;

	SortRotation();

	float  g = 15.f;

	Key_Input();

	_jumpSpeed -= g * deltaTime;

	_info.vPos.y -= _jumpSpeed * 3;
	_info.vPos.x += _speed * deltaTime * 70.f;

	if (_jumpSpeed < -1.f)
		_isjump = true;

	JumpRotation();

	CalcWorld();

	SquareCol();

	BottomCol();

	CalcWorld();

    return OBJ_NOEVENT;
}

void Player2::Late_Update()
{
}

void Player2::Render(HDC hDC)
{
	D3DXVECTOR3 cameraPos = GET_SINGLE(Camera)->GetCameraPos();

	MoveToEx(hDC, _LT.x - cameraPos.x, _LT.y, nullptr);
	LineTo(hDC, _RT.x - cameraPos.x, _RT.y);
	LineTo(hDC, _RD.x - cameraPos.x, _RD.y);
	LineTo(hDC, _LD.x - cameraPos.x, _LD.y);
	LineTo(hDC, _LT.x - cameraPos.x, _LT.y);

	MoveToEx(hDC, _LT_LE.x - cameraPos.x, _LT_LE.y, nullptr);
	LineTo(hDC, _RT_LE.x - cameraPos.x, _RT_LE.y);
	LineTo(hDC, _RD_LE.x - cameraPos.x, _RD_LE.y);
	LineTo(hDC, _LD_LE.x - cameraPos.x, _LD_LE.y);
	LineTo(hDC, _LT_LE.x - cameraPos.x, _LT_LE.y);

	MoveToEx(hDC, _LT_RE.x - cameraPos.x, _LT_RE.y, nullptr);
	LineTo(hDC, _RT_RE.x - cameraPos.x, _RT_RE.y);
	LineTo(hDC, _RD_RE.x - cameraPos.x, _RD_RE.y);
	LineTo(hDC, _LD_RE.x - cameraPos.x, _LD_RE.y);
	LineTo(hDC, _LT_RE.x - cameraPos.x, _LT_RE.y);

	MoveToEx(hDC, _LT_MS.x - cameraPos.x, _LT_MS.y, nullptr);
	LineTo(hDC, _RT_MS.x - cameraPos.x, _RT_MS.y);
	LineTo(hDC, _RD_MS.x - cameraPos.x, _RD_MS.y);
	LineTo(hDC, _LD_MS.x - cameraPos.x, _LD_MS.y);
	LineTo(hDC, _LT_MS.x - cameraPos.x, _LT_MS.y);
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

	if (GET_SINGLE(InputManager)->GetButton(KeyType::SpaceBar) && !_isjump)
	{
		_jumpSpeed = 4.5f;

		_isjump = true;
	}
}

void Player2::CalcWorld()
{
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
}

void Player2::BottomCol()
{
	float maxY = 0;

	maxY = max(maxY, _LT.y);
	maxY = max(maxY, _RT.y);
	maxY = max(maxY, _RD.y);
	maxY = max(maxY, _LD.y);

	if (maxY > 500.f)
	{
		_isjump = false;
		
		_jumpSpeed = 0.f;

		_info.vPos.y -= maxY - 500;
	}
}

void Player2::SquareCol()
{
	const vector<Object*>* Obstacle_List = GET_SINGLE(ObjectManager)->GetObjectList(OBSTACLE_S);

	// 사각형 발판
	for (auto obstacle : (*Obstacle_List))
	{
		if (GET_SINGLE(CollisionManager)->CollisionLine(this, obstacle))
		{
			_isjump = false;

			_jumpSpeed = 0.f;
		}

		GET_SINGLE(CollisionManager)->Collision_Left(this, obstacle);

		if(GET_SINGLE(CollisionManager)->Collision_Down(this, obstacle))
			_jumpSpeed = 0.f;
	}

	// 삼각형 장애물
	Obstacle_List = GET_SINGLE(ObjectManager)->GetObjectList(OBSTACLE_T);

	for (auto obstacle : (*Obstacle_List))
	{
		if (GET_SINGLE(CollisionManager)->Collision_Tri(this, obstacle))
		{
			_isjump = false;

			_jumpSpeed = 0.f;

			_info.vPos = { 150.f, 470.f, 0 };

			_bodyAngle = 0.f;
		}
	}

	Obstacle_List = GET_SINGLE(ObjectManager)->GetObjectList(OBSTACLE_J);

	for (auto obstacle : (*Obstacle_List))
	{
		if (GET_SINGLE(CollisionManager)->Collision_Tri(this, obstacle))
		{
			_isjump = true;

			_jumpSpeed = 6.5f;
		}
	}
}

void Player2::JumpRotation()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	float angle = D3DX_PI / 180.0f;

	if (_isjump)
	{
		_bodyAngle += angle * _RSpeed * 150 * deltaTime;
	}
}

void Player2::SortRotation()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	float angle = D3DX_PI / 180.0f;

	if (!_isjump)
	{
		if (_bodyAngle > (D3DX_PI * 7.f / 4.f) && _bodyAngle < 2 * D3DX_PI)
		{
			_bodyAngle += angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI/ 4.f) && _bodyAngle > 0.f)
		{
			_bodyAngle -= angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI / 2.f) && _bodyAngle > (D3DX_PI / 4.f))
		{
			_bodyAngle += angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI * 3.f / 4.f) && _bodyAngle > (D3DX_PI / 2.f))
		{
			_bodyAngle -= angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI) && _bodyAngle > (D3DX_PI * 3.f / 4.f))
		{
			_bodyAngle += angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI * 5.f / 4.f) && _bodyAngle > (D3DX_PI))
		{
			_bodyAngle -= angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI * 3.f / 2.f) && _bodyAngle > (D3DX_PI * 5.f / 4.f))
		{
			_bodyAngle += angle * _SRSpeed * 150 * deltaTime;
		}

		else if (_bodyAngle < (D3DX_PI * 7.f / 4.f) && _bodyAngle > (D3DX_PI * 3.f / 2.f))
		{
			_bodyAngle -= angle * _SRSpeed * 150 * deltaTime;
		}

		// 360도 넘으면 다시 0도로
		if (_bodyAngle > (2 * D3DX_PI))
			_bodyAngle -= (2 * D3DX_PI);

		if(_bodyAngle < 0.f)
			_bodyAngle += (2 * D3DX_PI);

		if (_prevAngle > (D3DX_PI * 7.f / 4.f) && _prevAngle < 0.f)
		{
			if (_bodyAngle < (D3DX_PI / 4.f))
				_bodyAngle = 0.f;
		}

		if (_prevAngle > 0.f && _prevAngle < (D3DX_PI / 4.f))
		{
			if (_bodyAngle > (D3DX_PI * 7.f / 4.f))
				_bodyAngle = 0.f;
		}

		if (_prevAngle < (D3DX_PI / 2.f) && _prevAngle >(D3DX_PI / 4.f))
		{
			if (_bodyAngle > (D3DX_PI / 2.f))
				_bodyAngle = (D3DX_PI / 2.f);
		}

		if (_prevAngle < (D3DX_PI * 3.f / 4.f) && _prevAngle > (D3DX_PI / 2.f))
		{
			if (_bodyAngle < (D3DX_PI / 2.f))
				_bodyAngle = (D3DX_PI / 2.f);
		}

		if (_prevAngle < (D3DX_PI) && _prevAngle >(D3DX_PI * 3.f / 4.f))
		{
			if (_bodyAngle > (D3DX_PI))
				_bodyAngle = (D3DX_PI);
		}

		if (_prevAngle < (D3DX_PI * 5.f / 4.f) && _prevAngle > (D3DX_PI))
		{
			if (_bodyAngle < (D3DX_PI))
				_bodyAngle = (D3DX_PI);
		}

		if (_prevAngle < (D3DX_PI * 3.f / 2.f) && _prevAngle >(D3DX_PI * 5.f / 4.f))
		{
			if (_bodyAngle > (D3DX_PI * 3.f / 2.f))
				_bodyAngle = (D3DX_PI * 3.f / 2.f);
		}

		if (_prevAngle < (D3DX_PI * 7.f / 4.f) && _prevAngle > (D3DX_PI * 3.f / 2.f))
		{
			if (_bodyAngle < (D3DX_PI * 3.f / 2.f))
				_bodyAngle = (D3DX_PI * 3.f / 2.f);
		}
	}
}
