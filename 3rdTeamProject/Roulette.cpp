#include "pch.h"
#include "Roulette.h"

Roulette::Roulette() : m_pArrow(nullptr), RoundStart(false), gameOver(false), resultChecked(false)
{
}

Roulette::~Roulette()
{
    Release();
}

void Roulette::Initialize()
{
    rouletteRadius = 200.f;
    objectRadius = 180.f;
    _info.vPos = { 400.f, 300.f, 0.f };
    srand((unsigned int)time(0));
    int random = rand() % 12;
    for (int i = 0; i < 12; i++) {
        result[i] = 1;

        if (i == random) {
            result[i] = 0;
        }
    }
}

int Roulette::Update()
{
    
    if (!m_pArrow->Spinning()&& m_pArrow->RoundEnd() && !resultChecked) {
        int angle = D3DXToDegree(m_pArrow->GetAngle());
        for (int i = 0; i < 12; i++) {
            if (i == 11) {
                if (result[i] == 0) 
                    gameOver = true;
                else 
                    result[i] = 0;

                resultChecked = true;
                break;
            }
            if (angle >= i * 30 && angle <= (i + 1) * 30) {
                if (result[i] == 0) 
                    gameOver = true;
                else 
                    result[i] = 0;

                resultChecked = true;
                break;
            }
        }
        m_pArrow->SetSpinning(false);
    }
    return 0;
}

void Roulette::Late_Update()
{
}

void Roulette::Render(HDC hDC)
{
  
    Ellipse(hDC, _info.vPos.x - rouletteRadius, _info.vPos.y - rouletteRadius, _info.vPos.x + rouletteRadius, _info.vPos.y + rouletteRadius);
    for (int i = 0; i < 12; i++) {
        D3DXVECTOR3 objPos = { objectRadius * cosf(D3DXToRadian(15.f + 30.f* i)), objectRadius * sinf(D3DXToRadian(15.f + 30.f * i)), 0 };
        D3DXVECTOR3 newPos = objPos + _info.vPos;
        if (result[i] == 0) {
            Rectangle(hDC, newPos.x - 10.f, newPos.y -10.f, newPos.x+ 10.f, newPos.y + 10.f);
        }
        else {
            Ellipse(hDC, newPos.x - 10.f, newPos.y - 10.f, newPos.x + 10.f, newPos.y + 10.f);
        }
    }
    for (int i = 0; i < 12; i++) {
        D3DXVECTOR3 linePos = { rouletteRadius * cosf(D3DXToRadian(30.f * i)), rouletteRadius * sinf(D3DXToRadian(30.f * i)), 0 };
        MoveToEx(hDC, _info.vPos.x, _info.vPos.y, nullptr);
        LineTo(hDC, _info.vPos.x + linePos.x, _info.vPos.y + linePos.y);

    }

}

void Roulette::Release()
{
}
