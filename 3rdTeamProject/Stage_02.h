#pragma once
#include "Scene.h"
#include "Roulette.h"
#include "Arrow.h"
class Stage_02 :
    public Scene
{

public:
    Stage_02();
    virtual ~Stage_02();
public:

    // Scene을(를) 통해 상속됨
    void Init() override;
    void Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
    void Key_Input();
private:
    Roulette* roulette;
    Arrow* arrow;
    Object* button;

};

