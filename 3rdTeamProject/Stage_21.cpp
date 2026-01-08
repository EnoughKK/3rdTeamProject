#include "pch.h"
#include "Stage_21.h"
#include "Player03.h"
#include "Enemy.h"

Stage_21::Stage_21() : Player(nullptr), Enemy(nullptr){  }
Stage_21::~Stage_21() { Release(); }

void Stage_21::Init() { 
	if (!Player)
	{
		ObjectManager::GetInstance()->Add(OBJID::PLAYER, new Player03);
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();
		Player->Initialize();
	}

	if (!Enemy)
	{
		ObjectManager::GetInstance()->Add(OBJID::MONSTER, new EnemyObject);
		Enemy = ObjectManager::GetInstance()->GetObjectList(OBJID::MONSTER)->front();
		Enemy->Initialize();
	}
	//ObjectManager::GetInstance()->AddObject(OBJECT_TAG::OBJ_ENVIROMENT, AbstractFactory<Enviroment>::Create(100, 100));
	dynamic_cast<EnemyObject*>(Enemy)->Set_Player(Player);
}
void Stage_21::Update() {
	TimeManager::GetInstance()->GetDeltaTime();
    GET_SINGLE(ObjectManager)->Update();
	
}

void Stage_21::Late_Update() {

    GET_SINGLE(ObjectManager)->Late_Update();

}

void Stage_21::Render(HDC DC) {
	HPEN myPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	HGDIOBJ oldPen = SelectObject(DC, myPen);

	HBRUSH myBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(DC, myBrush);

	Rectangle(DC, 0, 0, WINCX, WINCY);

	SelectObject(DC, oldBrush);
	DeleteObject(myBrush);

	SelectObject(DC, oldPen);
	DeleteObject(myPen);
	Rectangle(DC, 0, 0, WINCX, WINCY);
    GET_SINGLE(ObjectManager)->Render(DC);

}

void Stage_21::Release()
{
}
