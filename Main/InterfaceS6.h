#pragma once

enum JInterfaceType
{
	JOriginal = 0,
	JSeason1 = 1,
	JSeason2 = 2,
	JEx700 = 3,
	JLegends = 4,
};
#define sub_5B9260		((void(__cdecl*)(float a1, float a2, float a3, float a4, float a5, char a6, char a7)) 0x005B9260)

#define JCGetAttribute			((void(__thiscall*)( )) 0x0080FA10)
#define JCGetAttributeSD			((void(__thiscall*)( )) 0x00810420)
#define JCGetAttributeAG			((void(__thiscall*)( )) 0x00810150)

#define JCLoadSkill				((void(__thiscall*)(int a1, int a5, float a6, float a7, float a8, float a9)) 0x00813DC0)
#define JCPSkill				((void(__cdecl*)(int a1, int a5, float a6, float a7, float a8, float a9)) 0x00813DC0)
#define JCTimerSkillBar 		((void(__stdcall*)(int a1, float a2, float a3, float a4, float a5)) 0x00814F30)

class JCInterface
{
public:
	void Load( );
};

extern JCInterface JCInterfaceBar;