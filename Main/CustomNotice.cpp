#include "stdafx.h"
#include "CustomNotice.h"
#include "Tmemory.h"
#include "Defines.h"
#include "CustomFont.h"
#include "CustomMessage.h"
#include "Interface.h"
#include "SItemOption.h"

DWORD		Test_Buff1;
char		Test_LevelBuff1[40];
Naked(Notices)
{
	
	int PosX;
	 PosX = 470;

	 
	//RenderBitmap(500003,(float)455, (float)70 - 47, 200, 420, 0, 0, 1, 1, 1, 1, 0.0);

	//gInterface.DrawButton(eCONFIRM_BTN_OK, PosX, 230, 0, 0);

	//if( gInterface.IsWorkZone(eCONFIRM_BTN_OK) )
	//{
	//	int ScaleY = 30;
	//	// ----
	//	if( gInterface.Data[eCONFIRM_BTN_OK].OnClick )
	//	{
	//		ScaleY = 60;
	//	}
	//	// ----
	//	gInterface.DrawButton(eCONFIRM_BTN_OK,PosX, 230, 0, ScaleY);
	//}

	//gInterface.DrawButton(eCONFIRM_BTN_CANCEL, PosX + 90, 230, 0, 0);

	//if( gInterface.IsWorkZone(eCONFIRM_BTN_CANCEL) )
	//{
	//	int ScaleY = 30;
	//	// ----
	//	if( gInterface.Data[eCONFIRM_BTN_CANCEL].OnClick )
	//	{
	//		ScaleY = 60;
	//	}
	//	// ----
	//	gInterface.DrawButton(eCONFIRM_BTN_CANCEL, PosX + 90, 230, 0, ScaleY);
	//}
	_asm
	{
		lea eax, Test_LevelBuff1
		push eax
	//	// ----
	}
	_asm
	{
		mov Test_Buff1, 0x004D7D1D
		jmp Test_Buff1
	}
}




void InitNotices()
{
   SetRange((PVOID)0x004D7DAD, 0x0f, ASM::NOP);
   
   SetOp((LPVOID)0x004D7D13, (LPVOID)Notices, ASM::JMP);
}