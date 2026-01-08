#include "pch.h"
#include "Maze.h"

Maze::Maze() : m_fAngle(0.f)
{
}

Maze::~Maze()
{
	Release();
}

void Maze::Initialize()
{
	_info.vPos = { 400.f, 300.f, 0.f };

	_info.vLook = { 0.f, -1.f, 0.f };

	m_vPoint[0] = { _info.vPos.x - 150.f, _info.vPos.y + 150.f, 0.f };
	m_vPoint[1] = { _info.vPos.x + 150.f, _info.vPos.y + 100.f, 0.f };
	lines.push_back({ m_vPoint[0] ,m_vPoint[1] });
	originalLines.push_back({ m_vPoint[0] ,m_vPoint[1] });
	/*m_vPoint[2] = { _info.vPos.x + 150.f, _info.vPos.y + 150.f, 0.f };
	m_vPoint[3] = { _info.vPos.x - 150.f, _info.vPos.y + 150.f, 0.f };*/


	for (int i = 0; i < 2; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	
}

int Maze::Update()
{
	Key_Input();

	D3DXMATRIX		matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, _info.vPos.x,
		_info.vPos.y,
		_info.vPos.z);
	
	_info.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 2; ++i)
	{
		m_vPoint[i] = m_vOriginPoint[i];

		m_vPoint[i] -= {400.f, 300.f, 0.f};
		
		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &_info.matWorld);
	}
	
	for (size_t i = 0; i < lines.size(); ++i) {
		lines[i].first = originalLines[i].first;
		lines[i].second = originalLines[i].second;

		lines[i].first -= {400.f, 300.f, 0.f};
		lines[i].second -= {400.f, 300.f, 0.f};

		D3DXVec3TransformCoord(&lines[i].first, &lines[i].first, &_info.matWorld);
		D3DXVec3TransformCoord(&lines[i].second, &lines[i].second, &_info.matWorld);

	}
    return 0;
}

void Maze::Late_Update()
{
}

void Maze::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 2; ++i)
	{
		
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);
	}
	LineTo(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y);
}

void Maze::Release()
{
}

void Maze::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_fAngle -= D3DXToRadian(3.f);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_fAngle += D3DXToRadian(3.f);
	}

}
