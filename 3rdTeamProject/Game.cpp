#include "pch.h"
#include "Game.h"

Game::Game()
{
	if(GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{

	}
}

Game::~Game()
{
	Release();
	_CrtDumpMemoryLeaks(); // 메모리 누수 체크 디버그창에 나옴
	// Tesgin
}

void Game::Initialize()
{
	_hDC = ::GetDC(g_hWnd);

	// 더블 버퍼링
	::GetClientRect(g_hWnd, &_rect);
	_hdcBack = ::CreateCompatibleDC(_hDC);
	_bmpBack = ::CreateCompatibleBitmap(_hDC, _rect.right, _rect.bottom);
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(g_hWnd);

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Logo);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Late_Update()
{
}

void Game::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);

	// 더블 버퍼링
	::BitBlt(_hDC, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}

void Game::Release()
{
	ReleaseDC(g_hWnd, _hDC);
	ReleaseDC(g_hWnd, _hdcBack);
}
