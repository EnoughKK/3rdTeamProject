#include "pch.h"
#include "CollisionManager.h"
#include "Player1.h"
#include "Player2.h"

void CollisionManager::Collision_Line_Player(Object* player, vector<pair<D3DXVECTOR3, D3DXVECTOR3>> lines)
{
	for (auto line : lines) {

		if (line.first.x > line.second.x) {
			D3DXVECTOR3 temp = line.first;
			line.first = line.second;
			line.second = temp;
		}
		float playerX = player->GetPos().x;
		float playerY = player->GetPos().y;
		float slope = (float)(line.second.y - line.first.y) / (line.second.x - line.first.x);
		float lineY = slope * (playerX - line.first.x) + line.first.y;
		float radius = dynamic_cast<Player1*>(player)->GetRadius();
		D3DXVECTOR3 midPoint = player->GetPos();
		D3DXVECTOR3 linePoint = { playerX, lineY ,0};
		D3DXVECTOR3 slopeVec = line.second - line.first;
		D3DXVECTOR3 anotherVec = player->GetPos() - linePoint;
		// 라인 법선 벡터
		D3DXVECTOR3 normalVec = D3DXVECTOR3(-slopeVec.y, slopeVec.x, 0);
		D3DXVec3Normalize(&normalVec, &normalVec);
		normalVec = normalVec * radius ;
		float minY = 0;
		float maxY = 0;
	
		if (line.first.y < line.second.y) {
			minY = line.first.y;
			maxY = line.second.y;
		}
		else {
			minY = line.second.y;
			maxY = line.first.y;
		}

		if ((playerX > line.first.x &&
			playerX < line.second.x &&
			fabsf(midPoint.y  - lineY) <= radius)
			) {
			player->SetPos(playerX - normalVec.x, lineY - normalVec.y);

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

void CollisionManager::Collision_Rect(Object* Dst, Object* Src)
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
			}
			// 하 충돌
			else
			{
				//Dst->Set_PosY(fHeight);
				Dst->SetPos(Dst->GetPos().x, (Dst->GetPos().y + fHeight));
			}
		}

		// 좌 우 충돌
		else
		{
			// 좌 충돌
			if (Dst->GetPos().x < Src->GetPos().x)
			{
				Dst->SetPos(Dst->GetPos().x - fWidth, (Dst->GetPos().y));
			}
			// 우 충돌
			else
			{
				//Dst->Set_PosX(fWidth);
				Dst->SetPos(Dst->GetPos().x + fWidth, (Dst->GetPos().y));

			}
		}
	}
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
