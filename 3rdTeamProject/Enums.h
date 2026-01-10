#pragma once

enum class SceneType
{
	None,
	Logo,
	Stage_01, // º∫πŒ
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
	MONSTER,
	BUTTON,
	MAZE,
	OBSTACLE_S,
	OBSTACLE_T,

	OBJ_END
};

enum DIRECTION {
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_END
};