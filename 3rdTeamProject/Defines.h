#pragma once

#define		WINCX 800
#define		WINCY 600

#define		PURE = 0

#define		OBJ_NOEVENT  0
#define		OBJ_DEAD     1
#define     CHANGE_SCENE 2

#define PI (float)3.141592

#define DECLARE_SINGLE(classname)				\
private:										\
	classname() { }								\
public:											\
	static classname* GetInstance()				\
	{											\
		static classname s_instance;			\
												\
		return &s_instance;						\
	}

#define GET_SINGLE(classname) classname::GetInstance()

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}




extern HWND g_hWnd;