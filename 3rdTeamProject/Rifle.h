#pragma once
#include "Object.h"
class Rifle : public Object {
public:
	Rifle();
	virtual ~Rifle();

public:
	void Initialize()		override;
	int  Update()			override;
	void Late_Update()		override;
	void Render(HDC DC)		override;
	void Release()			override;

public:
	void Set_Player(Object* _Player) { Player = _Player; }

private:
	Object* Player;
};

