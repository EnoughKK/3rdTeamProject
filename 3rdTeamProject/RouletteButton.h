#pragma once
#include "Object.h"
#include "Arrow.h"
#include "Roulette.h"
class RouletteButton :
    public Object
{
public:
    RouletteButton();
    RouletteButton(const wstring text);
    virtual ~RouletteButton();
public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void SetArrow(Object* arrow) { m_pArrow = arrow; }
    void SetRoulette(Object* roulette) { m_pRoulette = roulette; }
private:
    wstring _text = L"";
    Object* m_pArrow;
    Object* m_pRoulette;
    bool _isOnButton = false;
};

