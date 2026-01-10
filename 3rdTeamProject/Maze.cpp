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
	//네모
	m_vPoint.push_back({ _info.vPos.x - 150.f, _info.vPos.y + 150.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 150.f, _info.vPos.y + 150.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 150.f, _info.vPos.y - 150.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 150.f, _info.vPos.y - 150.f, 0.f });
	// 미로 
	//1
	m_vPoint.push_back({ _info.vPos.x - 150.f, _info.vPos.y - 120.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 110.f, _info.vPos.y - 120.f, 0.f });
	//2
	m_vPoint.push_back({ _info.vPos.x - 110.f, _info.vPos.y - 80.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 110.f, _info.vPos.y - 10.f, 0.f });
	//3
	m_vPoint.push_back({ _info.vPos.x - 110.f, _info.vPos.y - 50.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 45.f, _info.vPos.y - 50.f, 0.f });
	//4
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y - 150.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y - 100.f, 0.f });
	//5
	m_vPoint.push_back({ _info.vPos.x - 45.f, _info.vPos.y - 100.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 45.f, _info.vPos.y - 20.f, 0.f });
	//6
	m_vPoint.push_back({ _info.vPos.x - 45.f, _info.vPos.y - 20.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y - 20.f, 0.f });
	//7
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y + 20.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 150.f, _info.vPos.y + 20.f, 0.f });
	//8
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y - 20.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 80.f, _info.vPos.y + 20.f, 0.f });
	//9
	m_vPoint.push_back({ _info.vPos.x - 10.f, _info.vPos.y - 150.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 10.f, _info.vPos.y - 80.f, 0.f });
	//10
	m_vPoint.push_back({ _info.vPos.x - 10.f, _info.vPos.y - 80.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 80.f, _info.vPos.y - 80.f, 0.f });

	//11
	m_vPoint.push_back({ _info.vPos.x + 30.f, _info.vPos.y - 115.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 110.f, _info.vPos.y - 115.f, 0.f });
	//12
	m_vPoint.push_back({ _info.vPos.x + 110.f, _info.vPos.y - 115.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 110.f, _info.vPos.y, 0.f });
	//13
	m_vPoint.push_back({ _info.vPos.x + 110.f, _info.vPos.y - 45.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x, _info.vPos.y - 45.f, 0.f });
	//14
	m_vPoint.push_back({ _info.vPos.x + 110.f, _info.vPos.y, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 50.f, _info.vPos.y, 0.f });

	//15
	m_vPoint.push_back({ _info.vPos.x , _info.vPos.y - 45.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x , _info.vPos.y + 100.f, 0.f });
	//16
	m_vPoint.push_back({ _info.vPos.x , _info.vPos.y + 100.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 80.f , _info.vPos.y + 100.f, 0.f });

	//17
	m_vPoint.push_back({ _info.vPos.x + 40.f , _info.vPos.y + 40.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 150.f , _info.vPos.y + 40.f, 0.f });

	//18
	m_vPoint.push_back({ _info.vPos.x + 40.f , _info.vPos.y + 40.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 40.f , _info.vPos.y + 70.f, 0.f });

	//19
	m_vPoint.push_back({ _info.vPos.x + 80.f , _info.vPos.y + 100.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 80.f , _info.vPos.y + 70.f, 0.f });
	//20
	m_vPoint.push_back({ _info.vPos.x + 115.f , _info.vPos.y + 40.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 115.f , _info.vPos.y + 100.f, 0.f });
	//21
	m_vPoint.push_back({ _info.vPos.x + 115.f , _info.vPos.y + 125.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 150.f , _info.vPos.y + 125.f, 0.f });

	//22
	m_vPoint.push_back({ _info.vPos.x  , _info.vPos.y + 125.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 80.f , _info.vPos.y + 125.f, 0.f });

	//23
	m_vPoint.push_back({ _info.vPos.x - 150.f  , _info.vPos.y + 120.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 40.f , _info.vPos.y + 120.f, 0.f });

	//24
	m_vPoint.push_back({ _info.vPos.x - 40.f  , _info.vPos.y + 120.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 40.f , _info.vPos.y + 85.f, 0.f });

	//25
	m_vPoint.push_back({ _info.vPos.x - 40.f  , _info.vPos.y + 85.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 110.f , _info.vPos.y + 85.f, 0.f });
	//26
	m_vPoint.push_back({ _info.vPos.x - 110.f  , _info.vPos.y + 85.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 110.f , _info.vPos.y + 55.f, 0.f });
	//27
	m_vPoint.push_back({ _info.vPos.x - 110.f  , _info.vPos.y + 55.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 45.f , _info.vPos.y + 55.f, 0.f });
	//28
	m_vPoint.push_back({ _info.vPos.x - 45.f  , _info.vPos.y + 55.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x - 45.f , _info.vPos.y + 20.f, 0.f });
	//29
	m_vPoint.push_back({ _info.vPos.x - 45.f  , _info.vPos.y + 20.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x  , _info.vPos.y + 20.f, 0.f });
	lines.push_back({ m_vPoint[0] ,m_vPoint[1] });
	lines.push_back({ m_vPoint[1] ,m_vPoint[2] });
	lines.push_back({ m_vPoint[2] ,m_vPoint[3] });
	lines.push_back({ m_vPoint[3] ,m_vPoint[0] });

#ifdef _DEBUG

	cout << m_vPoint.size() << endl;

#endif // _DEBUG
	for (int i = 4; i < m_vPoint.size(); i = i+2) {
		if (i >= m_vPoint.size()) {
			break;
		}
		lines.push_back({ m_vPoint[i] ,m_vPoint[i+1] });
		
	}

	originalLines.push_back({ m_vPoint[0] ,m_vPoint[1] });
	originalLines.push_back({ m_vPoint[1] ,m_vPoint[2] });
	originalLines.push_back({ m_vPoint[2] ,m_vPoint[3] });
	originalLines.push_back({ m_vPoint[3] ,m_vPoint[0] });

	for (int i = 4; i < lines.size(); i++) {
		originalLines.push_back(lines[i]);
	}

	for (int i = 0; i < m_vPoint.size(); ++i)
		m_vOriginPoint.push_back(m_vPoint[i]);

	
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

	for (int i = 0; i < m_vOriginPoint.size(); ++i)
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

	for (int i = 1; i < 4; ++i)
	{
		
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);
	}
	LineTo(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y);
	for (int i = 4; i < lines.size(); i++) {
		MoveToEx(hDC, (int)lines[i].first.x, (int)lines[i].first.y, nullptr);
		LineTo(hDC, (int)lines[i].second.x, (int)lines[i].second.y);
	}

}

void Maze::Release()
{
}

void Maze::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_fAngle += D3DXToRadian(0.5f);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_fAngle -= D3DXToRadian(0.5f);
	}

}
