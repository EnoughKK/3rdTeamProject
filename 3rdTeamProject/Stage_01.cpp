#include "pch.h"
#include "Stage_01.h"
#include "Button.h"

Stage_01::Stage_01()
{
}

Stage_01::~Stage_01()
{
        
}

void Stage_01::Init()
{
    Object* button = new Button(L"Stage_01");
    button->Initialize();
    button->SetPos(400, 300);
    GET_SINGLE(ObjectManager)->Add(BUTTON, button);
}

void Stage_01::Update()
{
    GET_SINGLE(ObjectManager)->Update();

}

void Stage_01::Late_Update()
{
    GET_SINGLE(ObjectManager)->Late_Update();

}

void Stage_01::Render(HDC hdc)
{
    GET_SINGLE(ObjectManager)->Render(hdc);

}

void Stage_01::Release()
{
}
