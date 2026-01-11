#include "pch.h"
#include "Stage_21.h"
#include "Player03.h"
#include "Enemy.h"
#include "LineManager.h"
#include "ScrollManager.h"
#include "Button.h"

Stage_21::Stage_21() : Player(nullptr), Enemy(nullptr){  }
Stage_21::~Stage_21() { Release(); }

void Stage_21::Init() { 
	if (!Player)
	{
		ObjectManager::GetInstance()->Add(OBJID::PLAYER, new Player03);
		Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front();
		Player->Initialize();
	}

	POINT EnemyStartPositionList[10] = { {700.f, 100.f}, {900.f, -400.f}, { 1700.f, 500.f }, {1500.f, -100.f}, {2000.f, 750.f},
										{1850.f, -400.f}, {1300.f, 150.f}, { 600.f, 800.f }, {1400.f, 250.f}, {1000.f, 600.f} };

	for (int i = 0; i < 10; ++i) {
		ObjectManager::GetInstance()->Add(OBJID::MONSTER, new EnemyObject);
		ObjectManager::GetInstance()->GetObjectList(OBJID::MONSTER)->back()->Initialize();
		dynamic_cast<EnemyObject*>(ObjectManager::GetInstance()->
			GetObjectList(OBJID::MONSTER)->back())->Set_EnemyStartPos(EnemyStartPositionList[i].x, EnemyStartPositionList[i].y);
		dynamic_cast<EnemyObject*>(ObjectManager::GetInstance()->GetObjectList(OBJID::MONSTER)->back())->Set_Player(Player);
	}

	LineManager::GetInstance()->Initialize();
}
void Stage_21::Update() {

	if (dynamic_cast<Player03*>(Player)->GetKillCount() >= 10) {
		return;
	}

	ScrollManager::GetInstance()->Scroll_Lock();
	LineManager::GetInstance()->Update();
	
    GET_SINGLE(ObjectManager)->Update();
	
}

void Stage_21::Late_Update() {
	if (dynamic_cast<Player03*>(Player)->GetKillCount() >= 10) {
		return;
	}
    GET_SINGLE(ObjectManager)->Late_Update();
}

void Stage_21::Render(HDC DC) {
	HBRUSH myBrush = CreateSolidBrush(RGB(20, 20, 20));
	HBRUSH oldBrush = (HBRUSH)SelectObject(DC, myBrush);
	
	Rectangle(DC, 0, 0, WINCX, WINCY);
	
	SelectObject(DC, oldBrush);
	DeleteObject(myBrush);

	INT Timer = 180 - clock() / 1000;
	if (Timer < 0) {
		HFONT currentFont = CreateFont(100, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Dead Stock  Demo"));
		HFONT oldFont = (HFONT)SelectObject(DC, currentFont);

		SetBkMode(DC, TRANSPARENT);
		SetTextColor(DC, RGB(255, 255, 255));

		Utils::DrawText(DC, { WINCX / 2 - 170.f, WINCY / 2 - 50.f, 0.f }, L"DEFEAT");

		SelectObject(DC, oldFont);


		HFONT LobbyFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("³ª´®½ºÄù¾î Bold"));
		(HFONT)SelectObject(DC, LobbyFont);

		float l = 340;
		float r = 350 + 70 + 10;
		float t = 400 - 10;
		float d = 400 + 20 + 10;

		::Rectangle(DC, 340, 390, 430, 430);
		SetTextColor(DC, RGB(0, 0, 0));
		Utils::DrawText(DC, { 350.f, 400.f, 0.f }, L"·Îºñ ÀÌµ¿");

		if (GET_SINGLE(InputManager)->GetMousePos().x > 340 && GET_SINGLE(InputManager)->GetMousePos().x < 430
			&& GET_SINGLE(InputManager)->GetMousePos().y > 390 && GET_SINGLE(InputManager)->GetMousePos().y < 430)
		{
			if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
			{
				dynamic_cast<Player03*>(Player)->SetKillCount(0);
				DeleteObject(currentFont);
				DeleteObject(LobbyFont);

				SelectObject(DC, oldFont);

				GET_SINGLE(SceneManager)->ChangeScene(SceneType::Logo);
				return;
			}
		}
		return;
	}
	if (dynamic_cast<Player03*>(Player)->GetKillCount() >= 10) {
		HFONT currentFont = CreateFont(100, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Dead Stock  Demo"));
		HFONT oldFont = (HFONT)SelectObject(DC, currentFont);

		SetBkMode(DC, TRANSPARENT);
		SetTextColor(DC, RGB(255, 255, 255));

		Utils::DrawText(DC, { WINCX / 2 - 170.f, WINCY / 2 - 50.f, 0.f }, L"VICTORY");

		SelectObject(DC, oldFont);
		

		HFONT LobbyFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("³ª´®½ºÄù¾î Bold"));
		(HFONT)SelectObject(DC, LobbyFont);

		float l = 340;
		float r = 350 + 70 + 10;
		float t = 400 - 10;
		float d = 400 + 20 + 10;

		::Rectangle(DC, 340, 390, 430, 430);
		SetTextColor(DC, RGB(0, 0, 0));
		Utils::DrawText(DC, { 350.f, 400.f, 0.f }, L"·Îºñ ÀÌµ¿");

		if (GET_SINGLE(InputManager)->GetMousePos().x > 340 && GET_SINGLE(InputManager)->GetMousePos().x < 430
			&& GET_SINGLE(InputManager)->GetMousePos().y > 390 && GET_SINGLE(InputManager)->GetMousePos().y < 430)
		{
			if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
			{
				dynamic_cast<Player03*>(Player)->SetKillCount(0);
				DeleteObject(currentFont);
				DeleteObject(LobbyFont);

				SelectObject(DC, oldFont);
				
				GET_SINGLE(SceneManager)->ChangeScene(SceneType::Logo);
				return;
			}
		}
		return;
	}
	
	LineManager::GetInstance()->Render(DC);
    GET_SINGLE(ObjectManager)->Render(DC);
	GameUI(DC);

	return;
}

void Stage_21::Release() {
}

void Stage_21::GameUI(HDC DC) {
	AddFontResource(TEXT("Dead Stock  Demo.ttf"));
	HFONT currentFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("Dead Stock  Demo"));
	HFONT oldFont = (HFONT)SelectObject(DC, currentFont);

	SetBkMode(DC, TRANSPARENT);
	SetTextColor(DC, RGB(255, 255, 255));

	TCHAR str[128] = { 0 };
	wsprintf(str, TEXT("KillCount : %d         time : %d"), dynamic_cast<Player03*>(Player)->GetKillCount(), 180 - clock() / 1000);
	Utils::DrawText(DC, { WINCX / 2 - 200, 40.f, 0.f }, str);
}
