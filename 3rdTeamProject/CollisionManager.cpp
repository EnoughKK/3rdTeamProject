#include "pch.h"
#include "CollisionManager.h"
#include "Player1.h"
#include "Player2.h"
#include "Player03.h"

void CollisionManager::Collision_Line_Player(Object* player, vector<pair<D3DXVECTOR3, D3DXVECTOR3>> lines)
{
	for (auto line : lines) {
		
		if (line.first.x > line.second.x) {
			D3DXVECTOR3 temp = line.first;
			line.first = line.second;
			line.second = temp;
		}
		D3DXVECTOR3 midPoint = player->GetPos();
		float slope = (float)(line.second.y - line.first.y) / (line.second.x - line.first.x);
		float playerX = player->GetPos().x;
		float radius = dynamic_cast<Player1*>(player)->GetRadius();
		float rightX = playerX + dynamic_cast<Player1*>(player)->GetRadius();
		float leftX = playerX - dynamic_cast<Player1*>(player)->GetRadius();
		float lineY = slope * (playerX - line.first.x) + line.first.y;

		/*float rightX = dynamic_cast<Player1*>(player)->getPoint(3).x +
			fabsf(dynamic_cast<Player1*>(player)->getPoint(3).x
				- dynamic_cast<Player1*>(player)->getPoint(4).x) / 2;*/
		if ((playerX > line.first.x &&
			playerX < line.second.x &&
			fabsf(midPoint.y - lineY) < radius)) {
			//기울기 양수
			if (midPoint.y < lineY) {

			}
			if (slope > 0) {
				if (slope > 0.3) {
					player->SetPos(playerX + 1.3f, lineY - radius);
				}
				else if (slope > 0.2) {
					player->SetPos(playerX + 0.9f, lineY - radius);
				}
				else if (slope > 0.1) {
					player->SetPos(playerX + 0.6f, lineY - radius);
				}
				else {
					player->SetPos(playerX + 0.4f, lineY - radius);
//#ifdef _DEBUG
//
//					cout << dynamic_cast<Player1*>(player)->GetDir() << "\t" << endl;
//
//#endif // _DEBUG
				}
			
				dynamic_cast<Player1*>(player)->SetDir(DIR_RIGHT);

			
		
			}
			//기울기 음수 
			else if (slope < 0) {
				dynamic_cast<Player1*>(player)->SetDir(DIR_LEFT);

			
				if (slope < -0.3) {
					player->SetPos(playerX - 1.2f, lineY - radius);
				}
				else if (slope < -0.2) {
					player->SetPos(playerX - 0.9f, lineY - radius);
				}
				else if (slope < -0.1) {
					player->SetPos(playerX - 0.6f, lineY - radius);
				}
				else {
					player->SetPos(playerX - 0.4f, lineY- radius);
//#ifdef _DEBUG
//
//					cout << dynamic_cast<Player1*>(player)->GetDir() << "\t" << endl;
//
//#endif // _DEBUG
				}
			}
			else if(slope == 0){
				player->SetPos(playerX, lineY- radius);

			}
			else {
				if (dynamic_cast<Player1*>(player)->GetDir() == DIR_RIGHT) {
					player->SetPos(playerX - 3, lineY);
				}
				else if (dynamic_cast<Player1*>(player)->GetDir() == DIR_LEFT) {
					player->SetPos(playerX + 3, lineY);
				}
			}
		}
		
	/*	if (fabsf(playerX - line.first.x) < 1.f &&
			fabsf(playerX - line.second.x) < 1.f)*/
		if (fabsf(playerX - line.first.x) < 4.f &&
			fabsf(playerX - line.second.x) < 4.f && line.first.x == line.second.x) {
			//#ifdef _DEBUG

			//cout << dynamic_cast<Player1*>(player)->GetDir() << "\t"  << endl;

			//#endif // _DEBUG
			if (dynamic_cast<Player1*>(player)->GetDir() == DIR_RIGHT) {
				player->SetPos(playerX -3, midPoint.y);
			}else if (dynamic_cast<Player1*>(player)->GetDir() == DIR_LEFT) {
				player->SetPos(playerX + 3, midPoint.y);
			}
		}
		
	}
	
}

bool CollisionManager::CheckRect(Object* _Dst, Object* _Src, float* pX, float* pY)
{
	float		fWidth = fabsf(_Dst->GetPos().x - _Src->GetPos().x);
	float		fHeight = fabsf(_Dst->GetPos().y - _Src->GetPos().y);

	float		fRadiusX = (_Dst->GetSize().x + _Src->GetSize().x) * 0.5f;
	float		fRadiusY = (_Dst->GetSize().y + _Src->GetSize().y) * 0.5f;

	if (fRadiusX >= fWidth && fRadiusY >= fHeight)
	{
		*pX = fRadiusX - fWidth;
		*pY = fRadiusY - fHeight;

		return true;
	}

	return false;
}

bool CollisionManager::Collision_Rect(Object* Dst, Object* Src)
{
	float	fWidth(0.f), fHeight(0.f);

	if (CheckRect(Dst, Src, &fWidth, &fHeight))
	{
		// 상 하 충돌
		if (fWidth > fHeight)
		{
			// 상 충돌
			if (Dst->GetPos().y < Src->GetPos().y)
			{
				//Dst->Set_PosY(-fHeight);
				Dst->SetPos(Dst->GetPos().x, (Dst->GetPos().y - fHeight));
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x, (Dst->GetPos().y - fHeight), 0.f });
				}
				return true;
			}
			// 하 충돌
			else
			{
				//Dst->Set_PosY(fHeight);
				Dst->SetPos(Dst->GetPos().x, (Dst->GetPos().y + fHeight));
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x, (Dst->GetPos().y + fHeight), 0.f });
				}
				return true;
			}
		}

		// 좌 우 충돌
		else
		{
			// 좌 충돌
			if (Dst->GetPos().x < Src->GetPos().x)
			{
				Dst->SetPos(Dst->GetPos().x - fWidth, (Dst->GetPos().y));
				return true;
			}
			// 우 충돌
			else
			{
				//Dst->Set_PosX(fWidth);
				Dst->SetPos(Dst->GetPos().x + fWidth, (Dst->GetPos().y));
				return true;

			}
		}
	}
	return false;
}

bool CollisionManager::Collision_RectForPlayer(Object* Dst, Object* Src)
{
	float	fWidth(0.f), fHeight(0.f);

	if (CheckRect(Dst, Src, &fWidth, &fHeight))
	{
		// 상 하 충돌
		if (fWidth > fHeight)
		{
			// 상 충돌
			if (Dst->GetPos().y < Src->GetPos().y)
			{
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x, (Dst->GetPos().y - fHeight), 0.f });
				}
				return true;
			}
			// 하 충돌
			else
			{
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x, (Dst->GetPos().y + fHeight), 0.f });
				}
				return true;
			}
		}

		// 좌 우 충돌
		else
		{
			// 좌 충돌
			if (Dst->GetPos().x < Src->GetPos().x)
			{
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x - fWidth, Dst->GetPos().y, 0.f });
				}
				return true;
			}
			// 우 충돌
			else
			{
				if (Dst == ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front()) {
					dynamic_cast<Player03*>(Dst)->Set_PlayerPositionValue({ Dst->GetPos().x + fWidth, Dst->GetPos().y, 0.f });
				}
				return true;

			}
		}
	}
	return false;
}

bool CollisionManager::CollisionLine(Object* Dst, Object* Src)
{
	float tileTop = Src->GetPos().y - Src->GetSize().y * 0.5f;

	float objBottom = Dst->GetPos().y + Dst->GetSize().y * 0.5f;

	float tileLeft = Src->GetPos().x - Src->GetSize().x * 0.5f;
	float tileRight = Src->GetPos().x + Src->GetSize().x * 0.5f;

	float objLeft = Dst->GetPos().x - Dst->GetSize().x * 0.5f;
	float objRight = Dst->GetPos().x + Dst->GetSize().x * 0.5f;

	if (objRight < tileLeft || objLeft > tileRight)
		return false;

	float prevBottom = static_cast<Player2*>(Dst)->GetPrevPos().y + Dst->GetSize().y * 0.5f;
	float currBottom = Dst->GetPos().y + Dst->GetSize().y * 0.5f;

	if (prevBottom <= tileTop && currBottom >= tileTop)
	{
		float newY = tileTop - Dst->GetSize().y * 0.5f;
		Dst->SetPos(Dst->GetPos().x, newY);

		return true;
	}

	return false;
}

bool CollisionManager::Collision_Left(Object* Dst, Object* Src)
{
	float	fWidth(0.f), fHeight(0.f);

	if (CheckRect(Dst, Src, &fWidth, &fHeight))
	{
		if (fWidth <= fHeight)
		{
			// 좌 충돌
			if (Dst->GetPos().x < Src->GetPos().x)
			{
				Dst->SetPos(Dst->GetPos().x - fWidth, (Dst->GetPos().y));

				return true;
			}
		}
	}
	return false;
}

bool CollisionManager::Collision_Down(Object* Dst, Object* Src)
{
	float	fWidth(0.f), fHeight(0.f);

	if (CheckRect(Dst, Src, &fWidth, &fHeight))
	{
		// 하 충돌
		if (fWidth > fHeight)
		{
			if (Dst->GetPos().y > Src->GetPos().y)
			{
				Dst->SetPos(Dst->GetPos().x, (Dst->GetPos().y + fHeight));

				return true;
			}
		}
	}

	return false;
}

bool CollisionManager::Collision_Tri(Object* Dst, Object* Src)
{
	float tileTop = Src->GetPos().y;

	float objBottom = Dst->GetPos().y + Dst->GetSize().y * 0.5f;

	float tileLeft = Src->GetPos().x - Src->GetSize().x * 0.5f;
	float tileRight = Src->GetPos().x + Src->GetSize().x * 0.5f;

	float objLeft = Dst->GetPos().x - Dst->GetSize().x * 0.5f;
	float objRight = Dst->GetPos().x + Dst->GetSize().x * 0.5f;

	if (objRight < tileLeft || objLeft > tileRight)
		return false;

	float prevBottom = static_cast<Player2*>(Dst)->GetPrevPos().y + Dst->GetSize().y * 0.5f;
	float currBottom = Dst->GetPos().y + Dst->GetSize().y * 0.5f;

	if (prevBottom <= tileTop && currBottom >= tileTop)
	{
		float newY = tileTop - Dst->GetSize().y * 0.5f;
		Dst->SetPos(Dst->GetPos().x, newY);

		return true;
	}

	return false;
}

bool CollisionManager::OnlyCheck(Object* _Dst, Object* _Src)
{
	float		fWidth = fabsf(_Dst->GetPos().x - _Src->GetPos().x);
	float		fHeight = fabsf(_Dst->GetPos().y - _Src->GetPos().y);

	float		fRadiusX = (_Dst->GetSize().x + _Src->GetSize().x) * 0.5f;
	float		fRadiusY = (_Dst->GetSize().y + _Src->GetSize().y) * 0.5f;

	if (fRadiusX >= fWidth && fRadiusY >= fHeight)
		return true;

	return false;
}

