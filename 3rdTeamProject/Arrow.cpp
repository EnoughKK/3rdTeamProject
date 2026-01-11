#include "pch.h"
#include "Arrow.h"

Arrow::Arrow() : m_fAngle(0), spinAngle(10.f), isSpinning(false), roundEnd(false), spinPressed(false)
{
}

Arrow::~Arrow()
{
}

void Arrow::Initialize()
{
	m_dwTime = GetTickCount();
	_info.vPos = { 400.f, 300.f, 0.f };
	m_vPoint.push_back({ _info.vPos.x , _info.vPos.y - 10.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 100.f, _info.vPos.y - 10.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 100.f, _info.vPos.y - 30.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 140.f, _info.vPos.y, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 100.f, _info.vPos.y + 30.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x + 100.f , _info.vPos.y + 10.f, 0.f });
	m_vPoint.push_back({ _info.vPos.x, _info.vPos.y + 10.f, 0.f });
	

	for (int i = 0; i < m_vPoint.size()-1;  i++) {
		if (i >= m_vPoint.size()) {
			break;
		}
		lines.push_back({ m_vPoint[i] ,m_vPoint[i + 1] });
	}
	lines.push_back({ m_vPoint[6] ,m_vPoint[0] });


	for (int i = 0; i < lines.size(); i++) {
		originalLines.push_back(lines[i]);
	}

	for (int i = 0; i < m_vPoint.size(); ++i)
		m_vOriginPoint.push_back(m_vPoint[i]);
	srand((unsigned int)time(0));
}

int Arrow::Update()
{
	if (spinAngle >= 0) {
		isSpinning = true;
		roundEnd = false;
	}
	else {
		isSpinning = false;
		roundEnd = true;
		spinPressed = false;
	}
	if (spinPressed) {
		Spin();
	}
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
            
	if (m_fAngle >= D3DX_PI * 2.f) {
		m_fAngle -= D3DX_PI * 2.f;
	}

    return 0;
}

void Arrow::Late_Update()
{
}

void Arrow::Render(HDC hDC)
{
	//MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < lines.size(); i++) {
		MoveToEx(hDC, (int)lines[i].first.x, (int)lines[i].first.y, nullptr);
		LineTo(hDC, (int)lines[i].second.x, (int)lines[i].second.y);
	}
}

void Arrow::Release()
{
}

void Arrow::Spin()
{
	isSpinning = true;
	roundEnd = false;
	if (GetTickCount() - m_dwTime >= 100) {
		int random = rand() % 10;
		float deduction = float(1 / (10 - random));
		spinAngle -= deduction;
		m_dwTime = GetTickCount();
	}
	m_fAngle += D3DXToRadian(spinAngle);
}
void Arrow::Reset() {
	roundEnd = false;
	spinAngle = 10.f;
}

