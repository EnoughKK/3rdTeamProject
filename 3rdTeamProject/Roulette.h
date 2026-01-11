#pragma once
#include "Object.h"
#include "Arrow.h"
class Roulette :
    public Object
{
public:
    Roulette();
    virtual ~Roulette();
public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Set_Arrow(Arrow* arrow) { m_pArrow = arrow; }
    void Set_ResultChecked(bool flag) { resultChecked = flag; }
    bool GameOver() { return gameOver; }
private:
    float objectRadius;
    float rouletteRadius;
    int result[12];
    Arrow* m_pArrow;
    bool RoundStart;
    bool gameOver;
    bool resultChecked;
};

