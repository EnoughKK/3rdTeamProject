#include "pch.h"
#include "Stage_01.h"
#include "Button.h"
#include "Maze.h"
#include "Player1.h"
#include "CollisionManager.h"
Stage_01::Stage_01()
{
}

Stage_01::~Stage_01()
{
        
}

void Stage_01::Init()
{
    maze = new Maze();
    maze->Initialize();
    GET_SINGLE(ObjectManager)->Add(MAZE, maze);
    player = new Player1();
    player->Initialize();
    GET_SINGLE(ObjectManager)->Add(PLAYER, player);

    
}

void Stage_01::Update()
{
    GET_SINGLE(ObjectManager)->Update();
    GET_SINGLE(CollisionManager)->Collision_Line_Player(player, dynamic_cast<Maze*>(maze)->GetLines());

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
