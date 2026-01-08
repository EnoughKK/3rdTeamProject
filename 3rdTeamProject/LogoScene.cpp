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
    button->SetPos(400, 200);
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
