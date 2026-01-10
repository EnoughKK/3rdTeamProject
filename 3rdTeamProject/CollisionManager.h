#pragma once

class CollisionManager
{
	DECLARE_SINGLE(CollisionManager);

	void Collision_Line_Player(Object* player, vector<pair<D3DXVECTOR3, D3DXVECTOR3>> lines);

	bool CheckRect(Object* _Dst, Object* _Src, float* pX, float* pY);

	void Collision_Rect(Object* Dst, Object* Src);

	bool CollisionLine(Object* Dst, Object* Src);

	bool Collision_Left(Object* Dst, Object* Src);

	bool Collision_Down(Object* Dst, Object* Src);

	bool Collision_Tri(Object* Dst, Object* Src);

	bool OnlyCheck(Object* _Dst, Object* _Src);

};

