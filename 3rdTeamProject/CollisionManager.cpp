#include "pch.h"
#include "CollisionManager.h"
#include "Player1.h"
void CollisionManager::Collision_Line_Player(Object* player, vector<pair<D3DXVECTOR3, D3DXVECTOR3>> lines)
{
	for (auto line : lines) {
		
		if (line.first.x > line.second.x) {
			D3DXVECTOR3 temp = line.first;
			line.first = line.second;
			line.second = temp;
		}
		float slope = (float)(line.second.y - line.first.y) / (line.second.x - line.first.x);
		float playerX = player->GetPos().x;
		float lineY = slope * (playerX - line.first.x) + line.first.y;

		if (dynamic_cast<Player1*>(player)->getPoint(3).x > line.first.x &&
			dynamic_cast<Player1*>(player)->getPoint(3).x < line.second.x &&
			fabsf(dynamic_cast<Player1*>(player)->getPoint(3).y - lineY) < 1.5f) {
			player->SetPos(playerX, lineY - 26.f);
		}
	}
}
