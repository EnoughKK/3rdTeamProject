#include "pch.h"
#include "Rifle.h"
#include "Player03.h"
#include "ScrollManager.h"

Rifle::Rifle()	{			 }
Rifle::~Rifle() { Release(); }

void Rifle::Initialize() {
	_info.vPos = { 0.f, 0.f, 0.f };
	_info.vLook = { 1.f, 0.f, 0.f };
	if (!Player) { Player = ObjectManager::GetInstance()->GetObjectList(OBJID::PLAYER)->front(); }
}
int Rifle::Update() {
	

	return 0;
}
void Rifle::Late_Update(){

}
void Rifle::Render(HDC DC) {
	MousePoint = dynamic_cast<Player03*>(Player)->GetMousePoint();
	//_info.vDir = Player->Get_Info().vDir;

	vector<D3DXVECTOR3> RifleVertex;

	RifleVertex.push_back({ _info.vPos.x, _info.vPos.y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 5.f, RifleVertex.back().y, 0.f});
	RifleVertex.push_back({ RifleVertex.back().x + 5.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 5.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 1.f, RifleVertex.back().y - 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 3.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 1.f, RifleVertex.back().y + 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 8.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 3.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 2.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 2.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 2.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 4.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 4.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x + 0.5f, RifleVertex.back().y + 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 0.5f, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 2.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y + 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x + 1.f, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 0.5f, RifleVertex.back().y - 0.5f, 0.f });


	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 2.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x + 5.5f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 5.5f, RifleVertex.back().y, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y + 1.f, 0.f });

	RifleVertex.push_back({ RifleVertex.back().x - 3.f, RifleVertex.back().y + 0.5f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y + 1.f, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x - 1.f, RifleVertex.back().y, 0.f });
	RifleVertex.push_back({ RifleVertex.back().x, RifleVertex.back().y - 3.f, 0.f });

	D3DXMATRIX PosinWorld = dynamic_cast<Player03*>(Player)->GetPosinWorld();

	D3DXVec3TransformCoord(&RifleVertex[0], &RifleVertex[0], &PosinWorld);

	HPEN myPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(DC, myPen);

	MoveToEx(DC, RifleVertex[0].x + ScrollManager::GetInstance()->Get_ScrollX(), RifleVertex[0].y + ScrollManager::GetInstance()->Get_ScrollY(), nullptr);
	for (int i = 1; i < RifleVertex.size(); ++i) {
		D3DXVec3TransformCoord(&RifleVertex[i], &RifleVertex[i], &PosinWorld);
		LineTo(DC, RifleVertex[i].x + ScrollManager::GetInstance()->Get_ScrollX(), RifleVertex[i].y + ScrollManager::GetInstance()->Get_ScrollY());
	}
	SelectObject(DC, oldPen);
	DeleteObject(myPen);

}
void Rifle::Release() {

}