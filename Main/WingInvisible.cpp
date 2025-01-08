#include "stdafx.h"
#include "WingInvisible.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Import.h"
#include "Defines.h"

DWORD ObjItemExc	=	0;
DWORD ObjItemWing	=	0;
DWORD dwItem;
DWORD effect_buff;
DWORD effect_pointer;
__declspec(naked) void HieuUngSuongWing3DK ()
{
	_asm
	{
		mov effect_buff, eax
		// ----
		mov eax, dword ptr ss:[ebp+0x10]
		mov effect_pointer, eax
		// ----
		mov eax, effect_buff
	}
	//--
	if( effect_pointer == ITEM2(12, 36) )
	{
		_asm
		{
			mov effect_buff, 0x005FAA45
			jmp effect_buff
		}
	}
	else if( effect_pointer == ITEM2(12, 175) )
	{
		_asm
		{
			mov effect_buff, 0x005FAA45
			jmp effect_buff
		}
	}
	else
	{
		_asm
		{
			mov effect_buff, 0x005FABC2
			jmp effect_buff
		}
	}
}
void __declspec(naked) DebugEffectExcillent()
{
//	static DWORD Address1 = 0x005FB2BE;
	static DWORD Address2 = 0x0060F325;
	static DWORD Address3 = 0x0060EEA5;
	
	_asm
	{
		Mov Ecx, Dword ptr ss : [ebp + 0x1C]
		Mov Dword ptr ss : [ebp + 0x1C],Ecx
		Mov ObjItemExc, Ecx
	}

	if(ObjItemExc == 0)
	{
		_asm
		{
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1C93
			JL next01
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1C99
			JLE BACK02
next01:
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1EB1
			JE BACK02
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1CB7
			JL next02
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1CBE
			JLE BACK02
next02:
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1D15
			JL next03
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1D19
			JLE BACK02
next03:
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1CC4
			JL next04
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1CC5
			JLE BACK02
next04:
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1D1A
			JE BACK02
			//Vùng để set SWing
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,150)
			JL next05
			///////////////////////////////////////từ 174 đổ về trước sẽ ko có exc
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,174)
			JLE BACK02
			///////////////////////////////////////// Từ 174 -189 sẽ có efffect exc
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,189)
			JL next05
			///=> từ 12,190 đến 15,200 sẽ ko có effect exc

			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(15,200)
			JLE BACK02
next05:
			//Them dãy ID Wing vào đây nếu muốn có effect Exc
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,175)
			JL BACK02
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,176)
			JLE BACK01
						MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,177)
			JLE BACK01
						MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,178)
			JLE BACK01
						MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,179)
			JLE BACK01
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,184)
				JLE BACK01
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,185)
				JLE BACK01
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,186)
				JLE BACK01
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,187)
				JLE BACK01
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,188)
				JLE BACK01
BACK02:
			jmp Address2
BACK01:
			jmp Address3
		}

	}
	else
	{
		__asm
		{
			//check recove unlock item <= ITEM2(11,255) return effect Exc
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1B92
			JLE BACK011
next012:
			//Original Webzen Block Wing not effect Exc
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1C93
			JL next011
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1C99
			JLE BACK022
next011:
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1EB1
			JE BACK022
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1CB7
			JL next02
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1CBE
			JLE BACK022
next022:
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1D15
			JL next033
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1D19
			JLE BACK022
next033:
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],0x1CC4
			JL next044
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],0x1CC5
			JLE BACK022
next044:
			MOV EDX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EDX+0x30],0x1D1A
			JE BACK022
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,150)
			JL next055
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,174)
			JLE BACK022
						MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,189)
			JL next055
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(15,200)
			JLE BACK022

next055:
			//custom effect exc wing
			MOV EAX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[EAX+0x30],ITEM2(12,175)
			JL BACK011
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,176)
			JLE BACK011
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,177)
			JLE BACK011
							MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,178)
			JLE BACK011
							MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,179)
			JLE BACK011
			MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,184)
				JLE BACK011
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,185)
				JLE BACK011
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,186)
				JLE BACK011
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,187)
				JLE BACK011
				MOV ECX,DWORD PTR SS:[EBP+8]
			CMP DWORD PTR DS:[ECX+0x30],ITEM2(12,188)
				JLE BACK011
			jmp Address3
BACK022:
			jmp Address2
BACK011:
			jmp Address3
		}
	}
}
void __declspec(naked) WingsOfStormEffect()
{
    _asm
    {
        MOV EAX, DWORD PTR SS:[EBP+0x0c]
        MOV dwItem, EAX
	}

	if (dwItem == ObjectId(12,36) || dwItem == ObjectId(12,175)) // => Copy Effect Wing 3 DK
	{
		_asm
		{
			MOV ECX,0x0060C159
			JMP ECX
		}
	}
	if (dwItem == ObjectId(12,36) || dwItem == ObjectId(12,184)) // => Copy Effect Wing 3 DW
	{
		_asm
		{
			MOV ECX,0x0060C159
				JMP ECX
		}
	}


	if (dwItem == ObjectId(12,37) || dwItem == ObjectId(12,176)) // => Copy Effect Wing 3 ELF
	{
		_asm
		{
			MOV ECX,0x0060C76A
			JMP ECX
		}
	}
	if (dwItem == ObjectId(12,37) || dwItem == ObjectId(12,185))
	{
		_asm
		{
			MOV ECX,0x0060C76A
				JMP ECX
		}
	}
	if (dwItem == ObjectId(12,37) || dwItem == ObjectId(12,186))
	{
		_asm
		{
			MOV ECX,0x0060C76A
				JMP ECX
		}
	}
	if (dwItem == ObjectId(12,38) || dwItem == ObjectId(12,177))
	{
		_asm
		{
			MOV ECX,0x0060CB46
			JMP ECX
		}
	}
	
	if (dwItem == ObjectId(12,39) || dwItem == ObjectId(12,178))
	{
		_asm
		{
			MOV ECX,0x0060CF9B
			JMP ECX
		}
	}

		if (dwItem == ObjectId(12,43) || dwItem == ObjectId(12,187))
		{
			_asm
			{
				MOV ECX,0x0060D5D1
					JMP ECX
			}
		}
    _asm
    {
        MOV ECX,0x0060C75D
        JMP ECX
    }

    /*_asm
    {
        CMP dwItem,ObjectId(12,36)
        JE Return
        CMP dwItem, ObjectId(12, 308)
        JE Return
        Return:
        MOV ECX,0x0060C153
        JMP ECX
    }*/
}

void __declspec(naked) WingsOfVortexEffect()
{
   
	DWORD dwItem;
    _asm
    {
        MOV EAX, DWORD PTR SS:[EBP+0x0C]
        MOV dwItem, EAX
	}

	if (dwItem == ObjectId(12,37) || dwItem == ObjectId(12,309))
	{
		_asm
		{
			MOV ECX,0x0060C76A
			JMP ECX
		}
	}

    _asm
    {
        MOV ECX,0x0060CB39
        JMP ECX
    }
}


void __declspec(naked) WingsOfElf()
{
    DWORD dwItem;
    _asm
    {
        MOV EAX, DWORD PTR SS:[EBP+0x0C]
        MOV dwItem, EAX

        // ----
        CMP dwItem,ObjectId(12,310)
        JE Return
        // ----
        Return:
        MOV EAX,0x0060CB40
        JMP EAX
    }
}
void __declspec(naked) WingsOfMg()
{
    DWORD dwItem;
    _asm
    {
        MOV EAX, DWORD PTR SS:[EBP+0x0C]
        MOV dwItem, EAX

        // ----
        CMP dwItem,ObjectId(12,311)
        JE Return
        // ----
        Return:
        MOV EAX,0x0060CF95
        JMP EAX
    }
}

void WingInvisible()
{
	SetRange((LPVOID)0x0060EE09, 12, ASM::NOP);
	SetJmp((LPVOID)0x0060EE09, DebugEffectExcillent);
//	SetCompleteHook(0xE9,0x0060EE4D,&WingCheckModelIndex3);
	SetRange((LPVOID)0x0060C14C, 5,ASM::NOP);
	SetJmp((LPVOID)0x0060C14C, WingsOfStormEffect);
		
	//gTMemory.SetRange((LPVOID)0x0060C75D, 5, ASM::NOP);
	//gTMemory.SetJmp((LPVOID)0x0060C75D, WingsOfVortexEffect);

				
	//	gTMemory.SetRange((LPVOID)0x0060CB39, 5, ASM::NOP);
	//	gTMemory.SetJmp((LPVOID)0x0060CB39, WingsOfElf);
						
	//	gTMemory.SetRange((LPVOID)0x0060CF8E, 5, ASM::NOP);
//	gTMemory.SetJmp((LPVOID)0x0060CF8E, WingsOfMg);

	//	gTMemory.SetRange((LPVOID)0x005FAA38, 13,ASM::NOP);
//	gTMemory.SetJmp((LPVOID)0x005FAA38, HieuUngSuongWing3DK);
}