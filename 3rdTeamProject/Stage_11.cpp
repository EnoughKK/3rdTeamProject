#include "pch.h"
#include "Stage_11.h"
#include "Player2.h"
#include "Square_Obstacle.h"

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
		player->SetPos(150.f, 470.f);
		GET_SINGLE(ObjectManager)->Add(PLAYER, player);
	}

	{
		Object* SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(500.f, 400.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(700.f, 300.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(900.f, 200.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(450.f, 450.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);
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
