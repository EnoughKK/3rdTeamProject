#include "pch.h"
#include "Stage_11.h"
#include "Player2.h"
#include "Square_Obstacle.h"
#include "TriAngle_Obstacle.h"
#include "Jump_Obstacle.h"

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
		Object*SO = new TriAngle_Obstacle;
		SO->Initialize();
		SO->SetPos(650.f, 475.f);
		SO->SetSize(50.f, 50.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(700.f, 475.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Jump_Obstacle;
		SO->Initialize();
		SO->SetPos(700.f, 440.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(950.f, 275.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Square_Obstacle;
		SO->Initialize();
		SO->SetPos(1200.f, 275.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

		SO = new Jump_Obstacle;
		SO->Initialize();
		SO->SetPos(1550.f, 490.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

		SO = new TriAngle_Obstacle;
		SO->Initialize();
		SO->SetPos(1600.f, 475.f);
		SO->SetSize(50.f, 50.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

		SO = new TriAngle_Obstacle;
		SO->Initialize();
		SO->SetPos(1650.f, 475.f);
		SO->SetSize(50.f, 50.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

		SO = new TriAngle_Obstacle;
		SO->Initialize();
		SO->SetPos(1700.f, 475.f);
		SO->SetSize(50.f, 50.f);
		GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);
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
