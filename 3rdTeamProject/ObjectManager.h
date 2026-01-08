#pragma once
#include "Object.h"

class ObjectManager
{
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

public:
	void Update(OBJID eObjID);
	void Add(OBJID eObjID, Object* object);
	void Remove(OBJID eObjID, Object* object);
	void Clear(OBJID eObjID);
	void Clear();
	void ChangeSceneClear();


	const std::vector<Object*>* GetObjectList() { return _objectList; }
	const std::vector<Object*>* GetObjectList(OBJID eObjID) { return &_objectList[eObjID]; }

	Object* GetPlayer() { if (_objectList[PLAYER].empty()) return nullptr; return _objectList[PLAYER].front(); }

private:
	std::vector<Object*> _objectList[OBJ_END];
};

