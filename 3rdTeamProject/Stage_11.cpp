#include "pch.h"
#include "Stage_11.h"
#include "Player2.h"
#include "Square_Obstacle.h"
#include "TriAngle_Obstacle.h"
#include "TriAngle_Obstacle2.h"
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

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(4550.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(4750.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(4950.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(5150.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4700.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4700.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4750.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4750.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4800.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4800.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4850.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4850.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4900.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4900.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(4950.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(4950.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(5000.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5000.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(5050.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5050.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(5100.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5100.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(5150.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5150.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle2;
	SO->Initialize();
	SO->SetPos(5200.f, 275.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T2, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5200.f, 225.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(5500.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(5700.f, 375.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(5700.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6000.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6050.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(6100.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6150.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6200.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6250.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6450.f, 375.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(6450.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(6600.f, 490.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6650.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6700.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6750.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(6800.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(6850.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(6900.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(6950.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7000.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7050.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7100.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(7200.f, 475.f);
	SO->SetSize(150.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7300.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7350.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7400.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7450.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7500.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(7500.f, 375.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(7575.f, 475.f);
	SO->SetSize(100.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7650.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7700.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7750.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7800.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(7800.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7850.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7900.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(7950.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(7950.f, 440.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8200.f, 362.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8400.f, 312.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8600.f, 262.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8800.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8850.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(8900.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9000.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9050.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9250.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9450.f, 362.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9550.f, 412.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(8800.f, 487.5f);
	SO->SetSize(1650.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9650.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9700.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9750.f, 462.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9800.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(9800.f, 425.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(9875.f, 487.5f);
	SO->SetSize(100.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(9950.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(10050.f, 487.5f);
	SO->SetSize(150.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(10150.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(10250.f, 487.5f);
	SO->SetSize(150.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(10350.f, 425.f);
	SO->SetSize(50.f, 150.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(10350.f, 340.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(10500.f, 487.5f);
	SO->SetSize(250.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(10650.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(10725.f, 487.5f);
	SO->SetSize(100.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(10800.f, 475.f);
	SO->SetSize(50.f, 50.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(10900.f, 487.5f);
	SO->SetSize(150.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11000.f, 450.f);
	SO->SetSize(50.f, 100.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(11100.f, 487.5f);
	SO->SetSize(150.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11200.f, 425.f);
	SO->SetSize(50.f, 150.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new TriAngle_Obstacle;
	SO->Initialize();
	SO->SetPos(11300.f, 487.5f);
	SO->SetSize(150.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_T, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11400.f, 400.f);
	SO->SetSize(50.f, 200.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(11400.f, 290.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11700.f, 262.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11800.f, 312.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(11900.f, 362.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Jump_Obstacle;
	SO->Initialize();
	SO->SetPos(11900.f, 340.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_J, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(12200.f, 362.5f);
	SO->SetSize(50.f, 25.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);

	SO = new Square_Obstacle;
	SO->Initialize();
	SO->SetPos(12400.f, 400.f);
	SO->SetSize(50.f, 200.f);
	GET_SINGLE(ObjectManager)->Add(OBSTACLE_S, SO);
}
