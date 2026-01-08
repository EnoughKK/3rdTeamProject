#include "pch.h"
#include "ObjectManager.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = _objectList[i].begin();
			iter != _objectList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (iResult == CHANGE_SCENE)
				return;

			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<Object*>(*iter);
				iter = _objectList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}

void ObjectManager::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : _objectList[i])
		{
			pObj->Late_Update();
		}
	}
}

void ObjectManager::Render(HDC hDC)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : _objectList[i])
		{
			pObj->Render(hDC);
		}
	}
}

void ObjectManager::Release()
{
}

void ObjectManager::Update(OBJID eObjID)
{
	for (auto iter = _objectList[eObjID].begin();
		iter != _objectList[eObjID].end(); )
	{
		int iResult = (*iter)->Update();

		if (iResult == CHANGE_SCENE)
			return;

		if (iResult == OBJ_DEAD)
		{
			Safe_Delete<Object*>(*iter);
			iter = _objectList[eObjID].erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void ObjectManager::Add(OBJID eObjID, Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = find(_objectList[eObjID].begin(), _objectList[eObjID].end(), object);
	if (findIt != _objectList[eObjID].end())
		return;

	_objectList[eObjID].push_back(object);

	return;
}

void ObjectManager::Remove(OBJID eObjID, Object* object)
{
	if (object == nullptr)
		return;

	auto It = remove(_objectList[eObjID].begin(), _objectList[eObjID].end(), object);
	_objectList[eObjID].erase(It, _objectList[eObjID].end());

	delete object;
}

void ObjectManager::Clear(OBJID eObjID)
{
	std::for_each(_objectList[eObjID].begin(), _objectList[eObjID].end(), Safe_Delete<Object*>);
	_objectList[eObjID].clear();
}

void ObjectManager::Clear()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		std::for_each(_objectList[i].begin(), _objectList[i].end(), Safe_Delete<Object*>);
		_objectList[i].clear();
	}
}

void ObjectManager::ChangeSceneClear()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		if (i == PLAYER)
			continue;

		std::for_each(_objectList[i].begin(), _objectList[i].end(), Safe_Delete<Object*>);
		_objectList[i].clear();
		//dfdfdfd



	}
}
