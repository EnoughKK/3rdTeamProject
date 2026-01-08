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
    Object* button = new Button(L"Stage_01", SceneType::Stage_01);
    button->Initialize();
    button->SetPos(350, 200);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);

    button = new Button(L"Stage_11", SceneType::Stage_11);
    button->Initialize();
    button->SetPos(350, 300);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);

    button = new Button(L"Stage_21", SceneType::Stage_21);
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
}

void LogoScene::Release()
{
}
