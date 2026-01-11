#pragma once

enum class SceneType
{
	None,
	Logo,
	Stage_01, 
	Stage_02,// º∫πŒ
	Stage_11, // º∫¿±
	Stage_21, // º·¿±

	End
};

enum OBJID
{
	PLAYER,
	PLAYER_LIGHT,
	PLAYER_RIFLE,
	PLAYER_BULLET,
	ENVIROMENT,
	MONSTER,
	BUTTON,
	MAZE,
	ROULETTE,
	ARROW,
	OBSTACLE_S,
	OBSTACLE_T,
	OBSTACLE_T2,
	OBSTACLE_J,
	POTAL,

	OBJ_END
};

enum DIRECTION {
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_END
};