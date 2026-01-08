#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Late_Update() abstract;
	virtual void Render(HDC hDC) abstract;
	virtual void Release()	abstract;
};

