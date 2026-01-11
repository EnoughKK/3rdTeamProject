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

	mapInit();
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

void Stage_11::mapInit()
{
	Object* SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(650.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(700.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(750.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(800.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(850.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(1200.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(1250.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

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

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(1700.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(1800.f, 475.f);
	SO->SetSize(150.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(1900.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(1900.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(2200.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2250.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2300.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2350.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);
	SO = new TriAngle_Obstacle;

	SO->Initialize();
	SO->SetPos(2400.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2450.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(2450.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2500.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2550.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2600.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2900.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(2950.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(3000.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3100.f, 475.f);
	SO->SetSize(150.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(3200.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3300.f, 475.f);
	SO->SetSize(150.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(3400.f, 425.f);
	SO->SetSize(50.f, 150.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3450.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3500.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3550.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3900.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(3950.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(4150.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4350.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(4350.f, 375.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);


}
