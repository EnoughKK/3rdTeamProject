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
