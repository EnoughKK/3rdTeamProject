#pragma once
class CollisionManager
{
	DECLARE_SINGLE(CollisionManager);

	void Collision_Line_Player(Object* player, vector<pair<D3DXVECTOR3, D3DXVECTOR3>> lines);
};

