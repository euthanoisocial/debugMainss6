#include "stdafx.h"
#include "Resolution.h"
#include "Offset.h"
#include "Util.h"

double Resolution_ClipX1 = 2000.0f;
double Resolution_ClipX2 = 2000.0f;

void InitResolution() // OK
{
	SetCompleteHook(0xE9,0x004D13C2,&ResolutionSwitch);

	SetCompleteHook(0xE9,0x004D2782,&ResolutionSwitchFont);

	SetCompleteHook(0xE9,0x00830C3A,&ResolutionMoveList);
}

__declspec(naked) void ResolutionSwitch() // OK
{
	static DWORD ResolutionSwitchAddress1 = 0x004D1450;

	_asm
	{
		Mov Edx,Dword Ptr Ds:[MAIN_RESOLUTION]
		Mov Dword Ptr Ss:[Ebp-0x340],Edx
		Cmp Dword Ptr Ss:[Ebp-0x340],0x00
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],640
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],400
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x01
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],800
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],500
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x02
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1024
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],640
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x03
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],800
		Jmp EXIT
		NEXT4:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x04
		Jnz NEXT5
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1366
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],852
		Jmp EXIT
		NEXT5:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x05
		Jnz NEXT6
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1440
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT6:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x06
		Jnz NEXT7
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1536
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],960
		Jmp EXIT
		NEXT7:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x07
		Jnz NEXT8
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1680
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1050
		Jmp EXIT
		NEXT8:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x08
		Jnz NEXT9
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1920
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1200
		Jmp EXIT
		NEXT9:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x09
		Jnz EXIT
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],3440
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1440
		EXIT:
		Jmp [ResolutionSwitchAddress1]
	}
}



__declspec(naked) void ResolutionSwitchFont() // OK
{
	static DWORD ResolutionSwitchFontAddress1 = 0x004D27FB;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0xF20],Eax
		Cmp Dword Ptr Ss:[Ebp-0xF20],640
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0C
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0xF20],800
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0D
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1024
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1280
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Jmp EXIT
		NEXT4:
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Lea Ecx,Resolution_ClipX1
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C848
		Call [SetDouble]
		Add Esp,0x0C
		Lea Ecx,Resolution_ClipX2
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C898
		Call [SetDouble]
		Add Esp,0x0C
		EXIT:
		Jmp [ResolutionSwitchFontAddress1]
	}
}

//__declspec(naked) void ResolutionMoveList() // OK
//{
//	static DWORD ResolutionMoveListAddress1 = 0x00830CE2;
//	static DWORD ResolutionMoveListAddress2 = 0x00830C43;
//
//	_asm
//	{
//		Mov Ecx,Dword Ptr Ds:[MAIN_RESOLUTION_X]
//		Mov Dword Ptr Ss:[Ebp-0x08],Ecx
//		Cmp Dword Ptr Ss:[Ebp-0x08],0x500
//		Jbe EXIT
//		Jmp [ResolutionMoveListAddress1]
//		EXIT:
//		Jmp [ResolutionMoveListAddress2]
//	}
//}


__declspec(naked) void ResolutionMoveList()
{
	static DWORD ResolutionMoveListAddress1 = 0x00830CE2;
	static DWORD ResolutionMoveListAddress2 = 0x00830D1B;
	static DWORD ResolutionMoveListAddress3 = 0x00830C43;

	_asm
	{
		Mov Ecx, Dword Ptr Ds : [MAIN_RESOLUTION_X] ;
		Mov Dword Ptr Ss : [Ebp - 0x08] , Ecx;
		Cmp Dword Ptr Ss : [Ebp - 0x08] , 0x500;
		Jbe CHECK640;
		Jmp[ResolutionMoveListAddress1];
	CHECK640:
		Cmp Dword Ptr Ss : [Ebp - 0x08] , 0x280; //640
		Jnz EXIT;
		Mov Edx, [Ebp - 0x04];
		Mov Dword Ptr Ss : [Edx + 0x48] , 0xFF;		//Background X Size
		Mov Dword Ptr Ss : [Edx + 0x50] , 0x22;		//Battle Zone
		Mov Dword Ptr Ss : [Edx + 0x58] , 0x62;		//Map Name
		Mov Dword Ptr Ss : [Edx + 0x60] , 0xB0;		//Required Level
		Mov Dword Ptr Ss : [Edx + 0x68] , 0xE0;		//Money Cost
		Push 0x1A;	//Background Y Size
		Push 0x00830D66;
		Call[SetByte];
		Push 0x1A;	//Size Maps 1
		Push 0x0083245D;
		Call[SetByte];
		Push 0x1A;	//Size Maps 2
		Push 0x00830ED5;
		Call[SetByte];
		Push 0x1A;	//Size Maps 3
		Push 0X00830FD8;
		Call[SetByte];
		Push 0x1A;	//Scroll Maps Size
		Push 0x00830E57;
		Call[SetByte];
		Jmp[ResolutionMoveListAddress2];
	EXIT :
		Jmp[ResolutionMoveListAddress3];
	}
}