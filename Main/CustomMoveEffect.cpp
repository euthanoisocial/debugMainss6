#include "StdAfx.h"
#include "CustomMoveEffect.h"
#include "User.h"
#include "Util.h"
//fixx add debug
#include "Import.h"

CustomMoveEffect gMoveEffect;
CustomMoveEffect::CustomMoveEffect(void)
{
}


CustomMoveEffect::~CustomMoveEffect(void)
{
}


void __cdecl RenderCharacter2(ObjectPreview* a4, ObjectModel* a5, int Select)
{
	pDrawMessage("CustomMoveEffect::Init() called", 1); // Thông báo debug
	MsgBox("CustomMoveEffect::RenderCharacter() called"); // Thông báo debug
	vec3_t vLight;
	Vector(1.0f, 1.0f, 1.f, vLight);
	float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	Vector(fLumi * vLight[0], fLumi * vLight[1], fLumi * vLight[2], vLight);
	EnableAlphaBlend();
	RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 5.8f, 5.8f, vLight, WorldTime * 0.11f, 1.0, 5, 1);
	RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 3.8f, 3.8f, vLight, -WorldTime * 0.01f, 1.0, 5, 1);
	DisableAlphaBlend();
}

void CustomMoveEffect::Init()
{
	//MsgBox("CustomMoveEffect::Init() called"); // Thông báo debug
	SetCompleteHook(0xE8, 0x404570 + 0x30D, &RenderCharacter2);
	SetCompleteHook(0xE8, 0x48E120 + 0x44C, &RenderCharacter2);
	SetCompleteHook(0xE8, 0x57D260 + 0x29F, &RenderCharacter2);
	SetCompleteHook(0xE8, 0x57D260 + 0x2B3, &RenderCharacter2);
}

