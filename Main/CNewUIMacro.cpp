#include "stdafx.h"
#include "CNewUIMacro.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "CustomFont.h"
#include "Protocol.h"
#include "ConnectServer.h"
#include "SwitchServer.h"
#include "Protect.h"
#include "Common.h"
#include "MuHelper.h"
//tue add button ATM boxx
#include "Config.h"
#include "SPK_ToolKit.h"
#define SizeBtnClickW 15
#define SizeBtnClickH 18
//#include "CMacroUIEx.cpp"
//---

CNewUIMacro gCMacroUIEx;

bool CNewUIMacro::isLockCursor(){
	return gCMacroUIEx.macroSwitchServer->data->state && gCMacroUIEx.macroSwitchServerHoving;
}

void CNewUIMacro::LoadImages(){
	pLoadImage("Interface\\GFx\\Upgrade\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Interface\\GFx\\Upgrade\\shandianCos_red.tga", 0xF2001, 0x2601, 0x2900, 1, 0);
}

void CNewUIMacro::RenderFrame(int *This){
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);

	if (gInterface.CheckWindow(ChaosBox))
	{
		return;	
		
	}
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	float MainWidth			= 130.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
                RenderBitmap(531008,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
switch (gObjUser.m_CAPNHAT7)	   
{
	    case 0:
				RenderBitmap(531010,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			break ;
		case 1:
				RenderBitmap(531010,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			break ;
		case 2: 
				RenderBitmap(531010,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			break ;
        case 16:
				RenderBitmap(531009,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 17:
				RenderBitmap(531009,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 18:
				RenderBitmap(531009,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
	    case 32:
				RenderBitmap(531011,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 33:
				RenderBitmap(531011,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 34:
				RenderBitmap(531011,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
	    case 48:
                RenderBitmap(531012,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 50:
				RenderBitmap(531012,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 64:
			    RenderBitmap(531013,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
           break;
		case 66:
			    RenderBitmap(531013,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
           break;
        case 80:
				RenderBitmap(531014,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
           break;
		case 81:
				RenderBitmap(531014,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
           break;
		case 82:
				RenderBitmap(531014,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
             break;
		case 96:
				RenderBitmap(531015,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;
		case 98:
				RenderBitmap(531015,(float) StartX + (MainWidth / 2) - (200 / 2) -224,(float)StartBody -120, 380, 215,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
            break;

}
				gInterface.DrawFormat(eExcellent,(float)StartX + (MainWidth / 2) - (200 / 2)- 86,(float)StartBody - 40.3, 210, 1, "%d",gObjUser.m_CAPNHAT1); // vip 
				gInterface.DrawFormat(eBlowPink,(float)StartX + (MainWidth / 2) - (200 / 2)- 120, (float)StartBody -27.5, 210, 1, "%d",gObjUser.m_CAPNHAT2); // reset
				gInterface.DrawFormat(eBlowPink,(float)StartX + (MainWidth / 2) - (200 / 2) - 81,(float)StartBody - 27.5, 210, 1, "%d",gObjUser.m_CAPNHAT4); //master
				gInterface.DrawFormat(eShinyGreen,(float)StartX + (MainWidth / 2) - (200 / 2) -105, (float)StartBody- 16, 210, 1, "%d,",gObjUser.m_CAPNHAT5);
				gInterface.DrawFormat(eShinyGreen,(float)StartX + (MainWidth / 2) - (200 / 2) -95,(float)StartBody- 16, 210, 1, "%d",gObjUser.m_CAPNHAT6);
				///-------
				///-------
				gInterface.DrawFormat(eBlowPink,(float)StartX + (MainWidth / 2) - (200 / 2)- 153,(float)StartBody - 27.5, 210, 1, "%d",gObjUser.m_CAPNHAT8); // level

				gInterface.DrawFormat(eExcellent,(float)StartX + (MainWidth / 2) - (200 / 2)- 198,(float)StartBody + 3, 210, 1, "%s",gObjUser.lpPlayer->Name);
///////////////////////////////////////////////////
//tue add atm boxx
				//gToolKit.DrawButtonIcon(SPK_MAIN_ATM, 151558, X + 53.0f - 4, Y + 1, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[34]);
				gToolKit.DrawButtonIcon(SPK_MAIN_ATM, 151558, 53.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[34]);
//tue add more button
				gToolKit.DrawButtonIcon(SPK_MAIN_ZMCAM, 151556, X + 5.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[31]);
				gToolKit.DrawButtonIcon(SPK_MAIN_RSCAM, 151557, X + 21.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[32]);
				//gToolKit.DrawButtonIcon(SPK_MAIN_ARESET, 151554, X + 37.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[33]);
				gToolKit.DrawButtonIcon(SPK_MAIN_ARESET, 151554, X + 21.0f - 4, 125, SizeBtnClickW, SizeBtnClickH, "Vòng quay May Mắn");
				gToolKit.DrawButtonIcon(SPK_MAIN_ARESET, 151554, X + 37.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, "Nhận thưởng Mốc Nạp");
				gToolKit.DrawButtonIcon(SPK_MAIN_BOXSK, 151559, X + 69.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, gConfig.TSPK_TEXT_ENGINE[35]);
				gToolKit.DrawButtonIcon(SPK_ITEM_BLOCK, 151560, X + 133.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, "Khóa Giao Dịch");
				//gToolKit.DrawButtonIcon(SPK_PK_LOCK, 0x1792E, X + 149.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, "Auto PK");
				gToolKit.DrawButtonIcon(SPK_AUTO_HP, 151561, X + 165.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, "Auto HP");
				gToolKit.DrawButtonIcon(SPK_AUTO_BF, 151562, X + 181.0f - 4, 100, SizeBtnClickW, SizeBtnClickH, "Buff");
//----
				pGLSwitch();
				EnableAlphaTest(0);
///////////////////////////////////////////////////
// end add ---------------				
	if (nInterface.Drawbutton(gCMacroUIEx.macroLog, ""))
	{
		//OPEN
		gInterface.SwitchMenuWindowState();
	}
	nInterface.Drawbutton(gCMacroUIEx.macroConfig, "");
	nInterface.Drawbutton(gCMacroUIEx.macroAuto, "");
	gCMacroUIEx.macroAuto->data->state = pMUHelperStat;
	


	ConnectServer.currently_subcode = *(DWORD*)0x0986C128;
	if (nInterface.Drawbutton(gCMacroUIEx.macroSwitchServer, " "))
	{
		if (gCMacroUIEx.macroSwitchServer->data->state == 1)
		{
			ConnectServer.ReqServerList(true);
		}
	}
	if (ConnectServer.currently_subcode)
	{
		if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 0)
			pSetTextColor(pTextThis(), 240, 50, 50, 255);
		else if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 1)
			pSetTextColor(pTextThis(), 50, 240, 50, 255);
		else
			pSetTextColor(pTextThis(), 160, 160, 160, 255);
		//wsprintf(Cord, "SV: %d", ConnectServer.currently_subcode);
		//pDrawText(pTextThis(), X + 22, Y + 55, Cord, 30, 0, (LPINT)0, 0);
	}
	
	if (gCMacroUIEx.macroSwitchServer->data->state == 1)
	{
		ConnectServer.ReqServerList(false);
		nInterface.DrawFrame(0xF3001, X + 7.5 , Y + 21.5, 198, 226, 1, 3, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
		if (nInterface.IsWorkZone(X + 7.5, Y + 21.5, 198 / 1.5, 226 / 1.5)){
			gCMacroUIEx.macroSwitchServerHoving = true;
		}else {
			gCMacroUIEx.macroSwitchServerHoving = false;
		}
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 160, 160, 160, 255);
		bool showToolTip = false;
		for (char i = 0; i < ConnectServer.server_list_count; i++){
			if (ConnectServer.currently_subcode - 1 != i){
				if (nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerHover, X + 11, Y + 21.5 + 14.65 * i, "")){
					if (!gCMacroUIEx.isSwitchServer && gCMacroUIEx.lastSwitch + DelaySwitchServer < GetTickCount()){
						SwitchServer.switchServer(ConnectServer.SrvStat[i].ServerCode);
						*(DWORD*)0x0986C128 = ConnectServer.SrvStat[i].ServerCode + 1;
						gCMacroUIEx.lastSwitch = GetTickCount();
						gCMacroUIEx.macroSwitchServer->data->state = 0;
					}
				}
			}else {
				if (nInterface.IsWorkZone(X + 11, Y + 21.5 + 14.65 * i, 110, 14)){
					showToolTip = true;
				}
			}
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			if (ConnectServer.SrvStat[i].type == 0)
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
			else if (ConnectServer.SrvStat[i].type == 1)
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
			else
				pSetTextColor(pTextThis(), 160, 160, 160, 255);
			//wsprintf(Cord, "SV: %d", ConnectServer.SrvStat[i].ServerCode + 1);
			//pDrawText(pTextThis(), X + 17.5, Y + 23.5 + 14.65 * i, Cord, 30, 0, (LPINT)0, 0);
			pSetTextColor(pTextThis(), 120, 120, 120, 200);
			//new
			char* ServerTypeName[] = { "[Gold]","[Gold(PvP)]", "[NoN-PvP]", "[Normal]", "[Unknow]" };
			if(ConnectServer.SrvStat[i].ServerCode >= 0 && ConnectServer.SrvStat[i].ServerCode <= 3){
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[0], 30, 0, (LPINT)0, 0);
			}else if(ConnectServer.SrvStat[i].ServerCode == 4){
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[1], 30, 0, (LPINT)0, 0);
			}else if(ConnectServer.SrvStat[i].ServerCode >= 5 && ConnectServer.SrvStat[i].ServerCode <= 8){
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[2], 30, 0, (LPINT)0, 0);
			}else if(ConnectServer.SrvStat[i].ServerCode >= 9 && ConnectServer.SrvStat[i].ServerCode <= 20){
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[3], 30, 0, (LPINT)0, 0);
			}else{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[4], 30, 0, (LPINT)0, 0);
			}
			if (ConnectServer.SrvStat[i].UserTotal < 100){
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
				wsprintf(Cord, "%d%%", ConnectServer.SrvStat[i].UserTotal);
			}else{
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
				wsprintf(Cord, "Đầy");
			}
			pDrawText(pTextThis(), X + 102.5, Y + 23.5 + 14.65 * i, Cord, 30, 4, (LPINT)0, 0);
		}
		nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerSliderUp, "");
		nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerSliderDown, "");
		if (showToolTip){
			textSize tS = nInterface.getTextSize("Sub Hiện Tại");
			nInterface.DrawToolTipBG(pCursorX + 25, pCursorY, tS.resize_width + 10, tS.resize_height + 4);
			pSetTextColor(pTextThis(), 160, 160, 160, 255);
	
			pDrawText(pTextThis(), pCursorX + 25, pCursorY + 4, "Sub Hiện Tại", tS.resize_width + 10, 0, (LPINT)3, 0);
		}
	}
	
	
	if (gCMacroUIEx.macroAuto->data->state)
		nInterface.Drawbutton(gCMacroUIEx.macroPauseAuto, "");
	
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);

	if (World >= 82 && World <= 106)
	{
		pDrawText(pTextThis(), X + 60, Y + 38, pGetTextLine(pTextLineThis, (3810 + World - 82)), 45, 0, (LPINT)3, 0);
	}
	else
	{
		pDrawText(pTextThis(), X + 60, Y + 38, pMapName(World), 45, 0, (LPINT)3, 0);
	}
	
	///
	DWORD Color = Color4f(255, 189, 25, 255);
	pGLSwitch();
	EnableAlphaTest(0);
	//end ------------------
	return;
	
}

void CNewUIMacro::Button(DWORD Event){
	DWORD CurrentTick = GetTickCount();
}

//-- (007D25C0)
__declspec(naked) void MuHelperRemake_012()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = gCMacroUIEx.macroConfig->data->Width;
	static DWORD H = gCMacroUIEx.macroConfig->data->Height;
	static DWORD X = gCMacroUIEx.macroConfig->data->X;
	static DWORD Y = gCMacroUIEx.macroConfig->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x18]; |
			PUSH Y; | Arg4
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0x14]; |
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0xC]; |
			LEA EDX, DWORD PTR DS : [EDX + ECX + 0x29]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_022()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = gCMacroUIEx.macroAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroAuto->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_032()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = gCMacroUIEx.macroPauseAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroPauseAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroPauseAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroPauseAuto->data->Y;

	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}

//tue add atm boxx
/////////////////////////
#define pHelperMouseClick		((char(__thiscall*)(int a1)) 0x007D2920)

//char FixHelperMouseClick(int a1)
//{
//	if (gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
//		return 0;
//
//	return pHelperMouseClick(a1);
//}
bool CheckCursor(int x, int y, int w, int h)
{
	bool Check = false; // al@2
	return Check = pCheckMouseOver(1, 1, 200, 40);
}
__declspec(naked) void MoveTextArrow()
{
	static DWORD Addr_main = 0x007DF898;
	static DWORD MOVEY = -99;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x4]
		ADD ECX, MOVEY; |
		PUSH ECX; / Arg2
		MOV EDX, DWORD PTR SS : [EBP - 0x8] ; |
		MOV EAX, DWORD PTR DS : [EDX + 0x10] ; |
		PUSH EAX; | Arg1
		MOV ECX, DWORD PTR SS : [EBP - 0x8] ; |
		JMP[Addr_main]
	}
}
//////////////////////////////
//-----


void CNewUIMacro::Load(){
	this->isSwitchServer = false;
	this->lastSwitch = GetTickCount() - DelaySwitchServer;
	this->macroSwitchServerHoving = false;
	//tue add atm boxx
	//SetCompleteHook(0xE8, 0x007D2B0C, &FixHelperMouseClick);
	SetCompleteHook(0xE8, 0x007D2B3D, &CheckCursor);
	SetCompleteHook(0xE9, 0x007DF88A, &MoveTextArrow);
	//------
	SetCompleteHook(0xE9, 0x007D2BC0, &CNewUIMacro::RenderFrame);
	SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_012);
	SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_022);
	SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_032);
}
