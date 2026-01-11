#include "pch.h"
#include "Stage_02.h"
#include "RouletteButton.h"
#include "Object.h"
Stage_02::Stage_02() : roulette(nullptr)
{
}

Stage_02::~Stage_02()
{
    Release();
}

void Stage_02::Init()
{
    roulette = new Roulette();
    roulette->Initialize();
    GET_SINGLE(ObjectManager)->Add(ROULETTE, roulette);
    arrow = new Arrow();
    arrow->Initialize();
    GET_SINGLE(ObjectManager)->Add(ARROW, arrow);

    roulette->Set_Arrow(arrow);

    button = new RouletteButton(L"Press");
    button->Initialize();
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);
    dynamic_cast<RouletteButton*>(button)->SetArrow(arrow);
    dynamic_cast<RouletteButton*>(button)->SetRoulette(roulette);
   
}

void Stage_02::Update()
{
    Key_Input();
    GET_SINGLE(ObjectManager)->Update();
   
}

void Stage_02::Late_Update()
{
    GET_SINGLE(ObjectManager)->Late_Update();
}

void Stage_02::Render(HDC hDC)
{
    GET_SINGLE(ObjectManager)->Render(hDC);
    if (roulette->GameOver()) {
        // 원하는 폰트 크기 지정 (예: 48픽셀)
        HFONT hFont = CreateFont(
            64,                // 높이 (텍스트 크기)
            0,                 // 너비 (0이면 자동)
            0, 0,              // 기울기, 회전
            FW_BOLD,           // 굵기
            FALSE, FALSE, FALSE, // Italic, Underline, StrikeOut
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            L"Arial"           // 폰트 이름
        );
        HFONT hOldFont = (HFONT)SelectObject(hDC, hFont);
        D3DXVECTOR3 newPos = { arrow->GetPos().x - 200.f, arrow->GetPos().y - 50.f, arrow->GetPos().z };
        Utils::DrawText(hDC, newPos, L"GAMEOVER!!!!!!!!");
        SelectObject(hDC, hOldFont);
        DeleteObject(hFont);

    }


}

void Stage_02::Release()
{
    GET_SINGLE(ObjectManager)->Release();
}

void Stage_02::Key_Input()
{
    if (GetAsyncKeyState('K')) {
        GET_SINGLE(SceneManager)->ChangeScene(SceneType::Logo);
    }
}
