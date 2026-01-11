#include "pch.h"
#include "LogoScene.h"
#include "Button.h"

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
}

void LogoScene::Init()
{
    Object* button = new Button(L"Roulette", SceneType::Stage_01);
    button->Initialize();
    button->SetPos(350, 100);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);

    button = new Button(L"Stage_02", SceneType::Stage_02);
    button->Initialize();
    button->SetPos(350, 200);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);

    button = new Button(L"Geometry", SceneType::Stage_11);
    button->Initialize();
    button->SetPos(350, 300);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);

    button = new Button(L"CQB", SceneType::Stage_21);
    button->Initialize();
    button->SetPos(350, 400);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);
}

void LogoScene::Update()
{
    GET_SINGLE(ObjectManager)->Update();
}

void LogoScene::Late_Update()
{
    GET_SINGLE(ObjectManager)->Late_Update();

}

void LogoScene::Render(HDC hdc)
{
    GET_SINGLE(ObjectManager)->Render(hdc);

    wstring str = L"미니게임 천국";

    // 글자 크기 (픽셀 단위, 음수 권장)
    HFONT hFont = CreateFont(
        -48,                // 글자 높이 (음수 = 문자 높이 기준)
        0,                  // 폭 (0 = 자동)
        0, 0,               // 기울기, 방향
        FW_BOLD,            // 두께 (FW_NORMAL / FW_BOLD)
        FALSE,              // 이탤릭
        FALSE,              // 밑줄
        FALSE,              // 취소선
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        L"맑은 고딕"        // 폰트 이름
    );

    // 기존 폰트 저장
    HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

    // 텍스트 출력
    TextOut(
        hdc,
        (int)(WINCX/2 - 160.f),
        70,
        str.c_str(),
        (int)str.length()
    );

    // 폰트 복구
    SelectObject(hdc, oldFont);
    DeleteObject(hFont);
}

void LogoScene::Release()
{
}
