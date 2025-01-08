#pragma once
#define WorldTime            *(float*)0x005EF5A1C
#define EnableAlphaBlend               ((void(__cdecl*)()) 0x636070)
#define DisableAlphaBlend            ((void(__cdecl*)()) 0x00635F50)
#define RenderTerrainAlphaBitmap                      ((void(__cdecl*)(int Texture,float xf,float yf,float SizeX,float SizeY,vec3_t Light,float Rotation,float Alpha,float Height, char a10)) 0x005DAD80)

class CustomMoveEffect
{
public:
	CustomMoveEffect(void);
	~CustomMoveEffect(void);
	void Init();
};

extern CustomMoveEffect gMoveEffect;