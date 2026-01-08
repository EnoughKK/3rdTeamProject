#include "pch.h"
#include "Stage_21.h"

Stage_21::Stage_21()
{
}

Stage_21::~Stage_21()
{
}

void Stage_21::Init()
{
}

void Stage_21::Update()
{
    GET_SINGLE(ObjectManager)->Update();

}

void Stage_21::Late_Update()
{
    GET_SINGLE(ObjectManager)->Late_Update();

}

void Stage_21::Render(HDC hdc)
{
    GET_SINGLE(ObjectManager)->Render(hdc);

}

void Stage_21::Release()
{
}
