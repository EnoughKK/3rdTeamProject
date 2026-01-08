#include "pch.h"
#include "Stage_11.h"
#include "Player2.h"

Stage_11::Stage_11()
{
}

Stage_11::~Stage_11()
{
}

void Stage_11::Init()
{
	if (GET_SINGLE(ObjectManager)->GetObjectList(PLAYER)->empty())
	{
		Object* player = new Player2;
		player->Initialize();
		player->SetPos(WINCX/2, WINCY/2);
		GET_SINGLE(ObjectManager)->Add(PLAYER, player);
	}
}

void Stage_11::Update()
{
    GET_SINGLE(ObjectManager)->Update();

}

void Stage_11::Late_Update()
{
    GET_SINGLE(ObjectManager)->Late_Update();

}

void Stage_11::Render(HDC hdc)
{
    GET_SINGLE(ObjectManager)->Render(hdc);

	MoveToEx(hdc, 0.f, 500.f, nullptr);
	LineTo(hdc, 800.f, 500.f);
}

void Stage_11::Release()
{
}
