#pragma once
#include "Object.h"
class Arrow :
    public Object
{
public:
    Arrow();
    virtual ~Arrow();
public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    vector<pair<D3DXVECTOR3, D3DXVECTOR3>> GetLines() { return lines; }
    void Spin();
    void Reset();
    float GetAngle() { return m_fAngle; }
    bool Spinning() { return isSpinning; }
    void SetSpinning(bool flag) { isSpinning = flag; }
    bool RoundEnd() { return roundEnd; }
    void SetRoundEnd(bool flag) { roundEnd = flag; }

    bool SpinPressed() { return spinPressed; }
    void SetSpinPressed(bool flag) { spinPressed = flag; }
private:
    float			m_fAngle;
    float           spinAngle;
    vector<D3DXVECTOR3> m_vPoint;
    vector<D3DXVECTOR3> m_vOriginPoint;
    vector<pair<D3DXVECTOR3, D3DXVECTOR3>>lines;
    vector<pair<D3DXVECTOR3, D3DXVECTOR3>>originalLines;
    DWORD           m_dwTime;
    bool            isSpinning;
    bool            spinPressed;
    bool            roundEnd;
};

