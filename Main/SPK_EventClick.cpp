#include "stdafx.h"
#include "Interface.h"
#include "Ranking.h"
#include "Defines.h"
#include "SPK_DrawBoxAtm.h"
#include "SPK_MocNapNew.H"
#include "SPK_ItemLocker.h"
//#include "CNewUIWindowsClient.h"
#include "Common.h"
#include "Util.h"
#include "Config.h"
//tue add Open VONG QUAY
#include "CustomLuckySpin.h"
//tue add Tu Chan //
#include "SPK_TuChan.h"	
//--- 
// tue add Hon Hoan 
#include "SPK_HonHoan.h"	 
//====================
// //tue add thue flag
#include "ThueFlag.h"
//---------------------
//////////////


void HadleClickClose()
{
	gRanking.Show = false;
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	gInterface.Data[eJewelBank_MAIN].OnShow = false;
	gInterface.Data[eWindowInfo].OnShow = false;
	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
	gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;
	gInterface.Data[eCommand_MAIN].OnShow = false;
	gInterface.Data[eWindow_NangCapHonHoan].OnShow = false;
	gInterface.Data[eWindow_NangCapQuanHam].OnShow = false;
	gInterface.Data[eWindow_NangCapTuChan].OnShow = false;
	gInterface.Data[eWindow_NangCapDanhHieu].OnShow = false;
	gInterface.Data[eWindow_NangCapNewVip].OnShow = false;
	gInterface.Data[eChangePass_Main].OnShow = false;
	gInterface.Data[TMC_MAIN].OnShow = false;
	gInterface.Data[eCTCMiniWindow].OnShow = false;
	gInterface.Data[SPK_RsChange_Main].OnShow = false;
	gInterface.Data[SPK_Ranking_Main].OnShow = false;
	gInterface.Data[SPK_ThueFlag_Main].OnShow = false;
	gInterface.Data[eMenu_MAIN].OnShow = false;
	gInterface.Data[eTopDame].OnShow = false;
	gInterface.Data[eSTATSADD_MAIN].OnShow = false;
	gInterface.Data[eRESETSTATS_MAIN].OnShow = false;
	gInterface.Data[SpkRelife_MainBox].OnShow = false;
	gInterface.Data[eCustomShop].OnShow = false;
	gInterface.Data[eWindowMocNap].OnShow = false;
	gInterface.Data[eWindowIntros].OnShow = false;
	gInterface.Data[eWindowInfo].OnShow = false;
	gInterface.Data[eWindowHarmony].OnShow = false;
	gInterface.Data[eWindowDungLuyenItem].OnShow = false;
	gInterface.Data[BAUCUA_MAIN].OnShow = false;
}
bool Interface::HandleCloseEvent(DWORD Event, int btnCloseID, int windowID)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[btnCloseID].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(btnCloseID))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[btnCloseID].OnClick = true;
		return true;
	}
	this->Data[btnCloseID].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[btnCloseID].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.Data[windowID].OnShow = false;
	return false;
}
bool Interface::SPK_OpenBoxCfg(DWORD Event)
{
	#define OKMENU SPK_CONFIG_BOX
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.OpenConfig(0);
	return false;
}
bool Interface::SPK_OpenBoxBSK(DWORD Event)
{
#define OKMENU SPK_MAIN_BOXSK
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	PMSG_RESET_SEND pMsg;
	pMsg.header.set(0xF7, 0x02, sizeof(pMsg));
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
	//tue add Hon Hoan
	// Hon Hoan
	gHonHoan.SendMenuButton();
	//===============
	return false;
}
bool Interface::SPK_OpenBoxAtm(DWORD Event)
{
#define OKMENU SPK_MAIN_ATM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gBoxAtm.OpenDrawBoxAtm();
	//ShellExecute(NULL, "open", "https://zalo.me/g/ggyzzf089", NULL, NULL, SW_SHOWNORMAL);
	//ShellExecute(NULL, "open", "https://www.facebook.com/profile.php?id=61565721511382", NULL, NULL, SW_SHOWNORMAL);
	gLuckySpin.SwitchLuckySpinWindowState();
	//Tu Chan
	gTuLuyen.SendMenuButton();
	//==========
	// Hon Hoan
	//gHonHoan.SendMenuButton();
	//===============
	//tue add Open window Ngu Hanh ///
	/*if ((GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
	{
		gInterface.Data[eWindow_NangCapHonHoan].OnShow ^= 1;
		gInterface.Data[eWindow_NangCapHonHoan].EventTick = GetTickCount();
	}

	if ((GetTickCount() - gInterface.Data[eNGUHANH].EventTick) > 300)
	{
		gInterface.Data[eNGUHANH].OnShow ^= 1;
		gInterface.Data[eNGUHANH].EventTick = GetTickCount();
	}*/

	return false;
}
//tue add Vong Quay box
void Interface::SPK_OpenVongQuay(DWORD Event)
{
	#define OKMENU BOX_MAIN_VONGQUAY
	//gInterface.Data[eLuckySpin].Close();
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[OKMENU].EventTick);
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OKMENU].OnClick = true;
		gInterface.Data[eLuckySpin].OnClick = true;
		pSetCursorFocus = true;
		
		return ;
	}
	// ----
	gInterface.Data[OKMENU].OnClick = false;
	gInterface.Data[eLuckySpin].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return ;
	}
	gInterface.Data[OKMENU].EventTick = GetTickCount();
	gInterface.Data[eLuckySpin].EventTick = GetTickCount();
	
	// ----
#if(VONGQUAY_NEW)
	//gLuckySpin.SwitchLuckySpinWindowState();
	
#endif
	return ;
	
}
//bool Interface::SPK_OpenVongQuay(DWORD Event)
//{
//#define OKMENU BOX_MAIN_VONGQUAY
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
//
//	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
//	{
//		return false;
//	}
//
//	if (Event == WM_LBUTTONDOWN)
//	{
//		this->Data[OKMENU].OnClick = true;
//		HadleClickClose();
//		return true;
//	}
//	this->Data[OKMENU].OnClick = false;;
//	if (Delay < 500)
//	{
//		return false;
//	}
//	gLuckySpin.SwitchLuckySpinWindowState();
//	//this->Data[OKMENU].EventTick = GetTickCount();
//	//this->CloseMenuWindow();
//	//gBoxAtm.OpenDrawBoxAtm();
//	//gLuckySpin.SwitchLuckySpinWindowState();
//	//gLuckySpin.EventWindow_Main(Event);
//	return false;
//}
//////////////////
bool Interface::SPK_RsCamera3D(DWORD Event)
{
	#define OKMENU SPK_MAIN_ZMCAM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.SwitchCamera();
	return false;
}
bool Interface::SPK_Camera3D(DWORD Event)
{
#define OKMENU SPK_MAIN_RSCAM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.CameraInit();
	//tue add Open window Ngu Hanh ///
	pDrawMessage("tue add Open window Ngu Hanh", 1);
	if ((GetTickCount() - gInterface.Data[eNGUHANH].EventTick) > 300)
	{
		gInterface.Data[eNGUHANH].OnShow ^= 1;
		gInterface.Data[eNGUHANH].EventTick = GetTickCount();
	}

	return false;
}
//tue fixx///////////////////////////////////
//bool Interface::SPK_ResetAuto(DWORD Event)
//{
//	#define OKMENU SPK_MAIN_ARESET
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
//	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
//	{
//		return false;
//	}
//	if (Event == WM_LBUTTONDOWN)
//	{
//		this->Data[OKMENU].OnClick = true;
//		HadleClickClose();
//		return true;
//	}
//	this->Data[OKMENU].OnClick = false;;
//	if (Delay < 500)
//	{
//		return false;
//	}
//	this->Data[OKMENU].EventTick = GetTickCount();
//	this->CloseMenuWindow();
//	PMSG_TICKET_SEND pMsg;
//	pMsg.header.set(0xFC, 102, sizeof(pMsg)); // AutoReset Send
//	DataSend((BYTE*)&pMsg, pMsg.header.size);
//	return false;
//}

bool Interface::SPK_ResetAuto(DWORD Event)
{
	#define OKMENU SPK_MAIN_ARESET
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//gNewMocNap.OpenWindowMocNap();
	//tue add thue flag 
	ThueFlag.OpenFlag();
	//--------------------
	return false;
}


bool Interface::SPK_BomMauAuto(DWORD Event)
{
	#define OKMENU SPK_AUTO_HP
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 103, sizeof(pMsg)); // Bom mau Send
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	return false;
}
bool Interface::SPK_BuffAuto(DWORD Event)
{
	#define OKMENU SPK_AUTO_BF
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, 104, sizeof(pMsg)); // Buff Send
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	return false;
}
bool Interface::SPK_ItemBlock(DWORD Event)
{
	#define OKMENU SPK_ITEM_BLOCK
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//nInterface.OpenWindowLock();
	nInterfaceSPK.OpenWindowLock();
	return false;
}
bool Interface::SPK_Pklock(DWORD Event)
{
#define OKMENU SPK_PK_LOCK
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	PVPAttack = !PVPAttack;
	if (PVPAttack != 0)
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[16]);
		SetByte(0x0059AF53 + 2, 0);
		SetByte(0x0059B248 + 2, 0);
	}
	else
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[17]);
		SetByte(0x0059AF53 + 2, 1);
		SetByte(0x0059B248 + 2, 1);
	}
	return false;
}
bool Interface::SPK_DrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	#define EVENTICK eMenu_CLOSE
	DWORD Delay = (CurrentTick - this->Data[EVENTICK].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(EVENTICK))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EVENTICK].OnClick = true;
		return true;
	}
	this->Data[EVENTICK].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EVENTICK].EventTick = GetTickCount();
	this->CloseMenuWindow();
	return false;
}

bool Interface::SPK_Ranking_Close(DWORD Event)
{
	#define OKMENU SPK_Ranking_BtnClose
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gRanking.Show = false;
	return false;
}
bool Interface::SPK_CtcMini_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_CtcMini_BtnClose, eCTCMiniWindow);
}
bool Interface::SPK_Comment_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_Comment_BtnClose, eCommand_MAIN);
}
bool Interface::SPK_TuChan_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_TuChan_BtnClose, eWindow_NangCapTuChan);
}
bool Interface::SPK_DanhHieu_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_DanhHieu_BtnClose, eWindow_NangCapDanhHieu);
}
bool Interface::SPK_QuanHam_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_QuanHam_BtnClose, eWindow_NangCapQuanHam);
}
bool Interface::SPK_HonHoan_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_HonHoan_BtnClose, eWindow_NangCapHonHoan);
}
bool Interface::SPK_ThueFlag_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_ThueFlag_BtnClose, SPK_ThueFlag_Main);
}
bool Interface::SPK_Relife_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_Relife_BtnClose, SpkRelife_MainBox);
}
bool Interface::SPK_LSpin_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_LSpin_BtnClose, eLuckySpin);
}
bool Interface::SPK_MocNap_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_MocNap_BtnClose, eWindowMocNap);
}
bool Interface::SPK_CuaHang_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_CuaHang_BtnClose, eCustomShop);
}
bool Interface::SPK_RsChange_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_RsChange_BtnClose, SPK_RsChange_Main);
}
bool Interface::SPK_NewVip_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_NewVip_BtnClose, eWindow_NangCapNewVip);
}
bool Interface::SPK_Harmony_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_Harmony_BtnClose, eWindowHarmony);
}
bool Interface::SPK_ItemTrade_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_ItemTrade_BtnClose, eWindowDoiItem);
}
bool Interface::SPK_Arena_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, Arena_CLOSE, eWindowNPCArenaPvP);
}
bool Interface::SPK_BoxAtm_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_BoxAtm_BtnClose, ATM_BOX_MAIN);
}
//tue add Vong Quay 
bool Interface::TUE_VONGQUAY_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, TUE_VONGQUAY_BtnClose, ATM_BOX_MAIN);
}
///
bool Interface::SPK_EventTime_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_EventTime_BtnClose, eEventTimePANEL_MAIN);
}
bool Interface::SPK_DungLuyen_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_DungLuyen_BtnClose, eWindowDungLuyenItem);
}
bool Interface::SPK_BxhArena_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_BxhArena_BtnClose, eWindowBXHArenaPvP);
}
bool Interface::SPK_Option_Close(DWORD Event)
{
	return this->HandleCloseEvent(Event, SPK_Option_BtnClose, Option_Main);
}