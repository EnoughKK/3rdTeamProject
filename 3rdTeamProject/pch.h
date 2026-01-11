#pragma once

#include "Resource.h"
#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include <io.h>
#include <iostream>
#include "Types.h"
#include "Defines.h"
#include "Enums.h"
#include "Utils.h"

#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "Camera.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif