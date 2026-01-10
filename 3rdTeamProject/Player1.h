#pragma once
#include "Object.h"
class Player1 :
    public Object
{
public:
    Player1();
    ~Player1();
public:

    // Object을(를) 통해 상속됨
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Key_Input();
    void Release() override;

    POINT getPoint(int n) {
     switch (n) {
     case 1: 
        return LT; 
     case 2: 
         return RT; 
     case 3: 
        return LB; 
     case 4: 
        return RB; 
     } 
    }

    bool GetSliding() { return isSliding; }
    void SetSliding(bool flag) { isSliding = flag; }
    DIRECTION GetDir() { return curDir; }
    DIRECTION GetPrevDir() { return prevDir; }
    void SetPrevDir(DIRECTION dir) { prevDir = dir; }
    void SetCurDir(DIRECTION dir) { curDir = dir; }

    float GetRadius() { return radius; }
    
private:
    float radius;
    POINT LT;
    POINT RT;
    POINT LB;
    POINT RB;
    bool isSliding;
    DIRECTION curDir;
    DIRECTION prevDir;
};

