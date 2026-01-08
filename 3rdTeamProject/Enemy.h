#pragma once
#include "Object.h"
class EnemyObject : public Object {
public:
    EnemyObject();
    virtual ~EnemyObject();

public:
    void Initialize()       override;
    int  Update()           override;
    void Late_Update()      override;
    void Render(HDC DC)    override;
    void Release()          override;

public:
    void    Set_Player(Object* _Player) { Player = _Player; }

    void    Get_HPBar(HDC DC);

private:
    Object* Player;
    FLOAT   EnemyHP;

    FLOAT AngleFromPlayer;
};

