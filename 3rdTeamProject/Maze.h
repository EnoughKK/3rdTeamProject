#pragma once
#include "Object.h"
class Maze :
    public Object
{
    // Object을(를) 통해 상속됨
public:
    Maze();
    ~Maze();
public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    vector<pair<D3DXVECTOR3, D3DXVECTOR3>> GetLines() { return lines; }
    
private:
    void	Key_Input();

private:
    D3DXVECTOR3		m_vPoint[2];
    D3DXVECTOR3		m_vOriginPoint[2];
    float			m_fAngle;

    vector<pair<D3DXVECTOR3, D3DXVECTOR3>>lines;
    vector<pair<D3DXVECTOR3, D3DXVECTOR3>>originalLines;
};

