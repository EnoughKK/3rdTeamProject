#include "pch.h"
#include "Stage_21.h"

Stage_21::Stage_21()  { }
Stage_21::~Stage_21() { Release(); }

void Stage_21::Init() { 

}
void Stage_21::Update() {
    GET_SINGLE(ObjectManager)->Update();

}

void Stage_21::Late_Update() {
    GET_SINGLE(ObjectManager)->Late_Update();

}

void Stage_21::Render(HDC DC) {
    GET_SINGLE(ObjectManager)->Render(DC);

}

void Stage_21::Release()
{
}
