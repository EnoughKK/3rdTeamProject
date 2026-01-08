#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;		// À§Ä¡ º¤ÅÍ
	D3DXVECTOR3		vDir;		// ¹æÇâ º¤ÅÍ

	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vNormal;	// ¹ý¼± º¤ÅÍ

	D3DXMATRIX		matWorld;

}INFO;
