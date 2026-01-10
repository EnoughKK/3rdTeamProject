#include "pch.h"
#include "Camera.h"

void Camera::Init()
{
}

void Camera::Update()
{
	Object* player = nullptr;

	if (!GET_SINGLE(ObjectManager)->GetObjectList(PLAYER)->empty())
	{
		player = GET_SINGLE(ObjectManager)->GetObjectList(PLAYER)->front();
	}

	if (player != nullptr)
	{
		_cameraPos.x = player->GetPos().x - 150.f;
	}
	
}
