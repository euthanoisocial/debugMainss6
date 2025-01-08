#include "stdafx.h"
#include "Common.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "array.h"
#include "Offset.h"
#include "StatsAdvance.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "Ruud.h"
#include "Inter3.h"
#include "InterEx.h"
#include "Central.h"
#include "NPCRuud.h"
#include "NewInterface.h"
#include "ResetSystem.h"
#include "GrandResetSystem.h"
#include "ServerInfo.h"
#include "ChangeClass.h"
#include "MuHelper.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "MiniMap.h"
#include "GLFont.h"
#include "SItemOption.h"
#include "Other.h"
#include "CustomLuckySpin.h"
#include "CustomHeThong.h"
#include "CustomOfflineMode.h"
#include "CustomFont.h"
#include "CNewUIMacro.h"
#include "ShopSearch.h"
#include "LeoThap.h"
#include "MultiCharacter.h"
#include "Bytes.h"
#include "SCharFrameHIght.h"
#include "Protect.h"
#include "PartySearch.h"
#include "PartySearchSettings.h"
#include "SEASON3B.h"
#include "HuyHieuCuongHoa.h"
#include "CustomCuongHoaWing.h"
#include "CustomVKR.h"
#include "WideScreen.h"
#include "MocNap.h"
#include "QuaEvent.h"
#include "QuaEvent1.h"
#include "QuaEvent2.h"
#include "DanhHieu.h"
#include "QuanHam.h"
#include "QuanLyTaiKhoan.h"
#include "CustomJewelBank.h"
#include "NewsBoard.h"
#include "UIControl.h"
//tue add
#include "CustomBauCua.h"
//------
//tue add atm boxx
#include "SPK_DrawBoxAtm.h"
//------
//tue add Moc nap
#include "SPK_MocNapNew.h"
//------
//tue add Tu Chan ///
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "SPK_TuChan.h"
//tue add Hon Hoan //
#include "SPK_HonHoan.h"
//==================
// //tue add hieu ung duoi chan
#include "CustomMoveEffect.h"
#include "cape.h"
//tue add thue flag
#include "ThueFlag.h"
#include "Luna_CNewFlag.h"
//////////////////////
Interface gInterface;

int ItemOverInfo;
static const char* StoreName = "Teste";
Interface::Interface()
{
}

Interface::~Interface()
{
}
//tue add
#if(BAUCUA)
int Custom_dem;
bool Custom_dem_b;
float VitriX1 = 150.0;
float VitriY1 = 380.0;
bool QuayLai1 = false;
int res1 = 0;
int begin_time1 = 0;
DWORD IsClickTimer;
void RunGameMini()
{
	//điều kiện
	if (gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(FriendList)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Quest)
		|| gInterface.CheckWindow(NPC_Devin)
		|| gInterface.CheckWindow(Guild)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(CommandWindow)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(DevilSquare)
		|| gInterface.CheckWindow(BloodCastle)
		|| gInterface.CheckWindow(CreateGuild)
		|| gInterface.CheckWindow(GuardNPC)
		|| gInterface.CheckWindow(SeniorNPC)
		|| gInterface.CheckWindow(GuardNPC2)
		|| gInterface.CheckWindow(CastleGateSwitch)
		|| gInterface.CheckWindow(CatapultNPC)
		|| gInterface.CheckWindow(CrywolfGate)
		|| gInterface.CheckWindow(IllusionTemple)
		|| gInterface.CheckWindow(HeroList)
		|| gInterface.CheckWindow(ChatWindow)
		|| gInterface.CheckWindow(FastMenu)
		|| gInterface.CheckWindow(Options)
		|| gInterface.CheckWindow(FastDial)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(GoldenArcher1)
		|| gInterface.CheckWindow(GoldenArcher2)
		|| gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(LuckyCoin2)
		|| gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(Lugard)
		|| gInterface.CheckWindow(QuestList1)
		|| gInterface.CheckWindow(QuestList2)
		|| gInterface.CheckWindow(GensInfo)
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(MuHelper)
		|| gInterface.CheckWindow(PetInfo)
		|| gInterface.Data[eMenu_MAIN].OnShow
		|| gInterface.Data[eEventTimePANEL_MAIN].OnShow
		|| gInterface.Data[eCommand_MAIN].OnShow
		|| gInterface.Data[eChangePass_Main].OnShow
		|| gInterface.Data[SPK_Ranking_Main].OnShow
		|| gInterface.Data[eCONFIRM_MAIN].OnShow
		|| gInterface.Data[eJewelBank_MAIN].OnShow
		|| gInterface.Data[ePARTYSETTINGS_MAIN].OnShow
		|| gInterface.Data[ePARTYSEARCH_MAIN].OnShow
		|| gInterface.Data[BAUCUA_MAIN].OnShow
		|| pMapNumber == 40)

	{
		return;
	}
#if BAUCUA

	DWORD NUTBAUCUA;
	float x2, y2, w2, h2;
	x2 = 2.0f;
	y2 = 390.0f;
	w2 = 26.0f;
	h2 = 30.0f;
	RenderBitmap(12349, x2, y2, w2, h2, 0, 0, 1, 1, 1, 1, 0.0);
	if (pCheckMouseOver(x2, y2, w2, h2))
	{
		pSetCursorFocus = true;
		Custom_dem_b = false;
		Custom_dem = 0;

		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);

		pGLSwitch();
		EnableAlphaTest(0);
		RenderBitmap(12349, x2, y2, w2, h2, 0, 0, 1, 1, 1, 1, 0.0);

		if (pIsKeyRelease(VK_LBUTTON) && IsClickTimer <= GetTickCount())
		{
			IsClickTimer = GetTickCount();
			gCUSTOM_BAUCUA.SwitchStatsWindowState();
		}
	}
	else
	{
		Custom_dem_b = true;
	}
	if (Custom_dem_b == true)
	{
		if (!QuayLai1 && VitriX1 < 3)
		{
			VitriX1++;
		}
		else
		{
			VitriX1 = 0;
			res1++;
		}

		if (res1 > 3)
		{
			res1 = 0;
		}
		if (res1 == 3)
		{
			RenderBitmap(12349, x2, y2, w2, h2, 0, 0, 1, 1, 1, 1, 0.0);
		}
	}
	EnableAlphaTest(0);
#endif
}
#endif

//-------

void Interface::RenderObjectSystem()
{
	//tue add
#if BAUCUA
	gCUSTOM_BAUCUA.LOADBIN();
#endif
	//-----
	//tue add ATM boxx ////////////////////////////////////////////////
	this->BindObject(SPK_Ranking_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_Comment_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_TuChan_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_DanhHieu_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_QuanHam_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_HonHoan_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_ThueFlag_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_Relife_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_LSpin_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_MocNap_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_CuaHang_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_RsChange_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_NewVip_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_Harmony_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_ItemTrade_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_BoxAtm_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_EventTime_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_DungLuyen_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_BxhArena_BtnClose, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(SPK_Option_BtnClose, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(SPK_MAIN_ATM, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_MAIN_ARESET, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_MAIN_RSCAM, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_MAIN_ZMCAM, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_MAIN_BOXSK, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_ITEM_BLOCK, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_PK_LOCK, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_AUTO_HP, 0xC942, 13, 13, -1, -1);
	this->BindObject(SPK_AUTO_BF, 0xC942, 13, 13, -1, -1);
	//tue add Open Vong Quay
	this->BindObject(BOX_MAIN_VONGQUAY, 0xC942, 13, 13, -1, -1);
	//--------
	// //tue add thue flag 
#if(HT_THUE_FLAG)
	ThueFlag.Bind();
#endif	
	// /////////////////////
	/////////////////////////////////////////////////////

	if(gProtect.m_MainInfo.MonitorMS == 1){
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}
	if(gProtect.m_MainInfo.MonitorFPS == 1){
		gInterface.iniciador = 1;
	}
#if (SELECTCHARACTER==1)
		this->BindObject(eSELECTCHAR_LEFT, 0x7912, 25, 40, -1, -1);
		this->BindObject(eSELECTCHAR_RIGHT, 0x7911, 25, 40, -1, -1);
#endif

	gHuyHieuCuongHoa.BinObeject();

	gCuongHoaWing.BinObeject();

	gVuKhiRong.BinObeject();

	gPartySearch.loadBind();

	gCustomEventTime.BinObeject();

	gOfflineMode.BinObeject();

    G_QUAN_LY_TK.BinObeject();

	G_BEXO_HE_THONG.BinObeject();

	gResetSystem.BinObeject();

	gGrandResetSystem.BinObeject();

	this->BindObject(eTVTHUD, 0x9912, 200, 27, -1, -1);
	this->BindObject(eCHAR_POINT, 32506, 4, 4, -1, -1); //Char Other
	this->BindObject(eOTHERCHAR_POINT, 32507, 4, 4, -1, -1); //Monter
	//**********************************************************************//
#if(SACHTHUOCTINH_NEW)
	this->BindObject(eSACHTHUOCTINH_INTERFACE, 31461, 35, 35, -1, -1);  // 31461
	this->BindObject(eSACHTHUOCTINH_02, 10003, 40, 40, -1, -1);
	this->BindObject(eSACHTHUOCTINH_03, 10003, 40, 40, -1, -1);
	this->BindObject(eSACHTHUOCTINH_04, 10003, 40, 40, -1, -1);
	this->BindObject(eSACHTHUOCTINH_05, 10003, 40, 40, -1, -1);
	this->BindObject(eSACHTHUOCTINH_06, 10003, 40, 40, -1, -1);
	this->BindObject(eSACHTHUOCTINH_07, 10003, 40, 40, -1, -1);
#endif
#if(RINGPEDAN_NEW)
	this->BindObject(ePEDAN_01_INTERFACE, 31461, 16, 24, -1, -1);  // 31461
	this->BindObject(ePEDAN_02_INTERFACE, 31461, 16, 24, -1, -1);  // 31461
	this->BindObject(eRING_01_INTERFACE, 31461, 16, 24, -1, -1);  // 31461
	this->BindObject(eRING_02_INTERFACE, 31461, 16, 24, -1, -1);  // 31461

	this->BindObject(eSEND_PEDAN_01_INTERFACE, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eSEND_PEDAN_02_INTERFACE, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eSEND_RING_01_INTERFACE, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eSEND_RING_02_INTERFACE, 31461, 35, 14, -1, -1);  // 31461

#endif
	//----------------------------------------------------------------------------------------
#if(CHARACTER_NEW)
	this->BindObject(XOAHOMDO_CHARACTER, 31461, 17, 17, -1, -1);  // 31461
	this->BindObject(TINHNANG_CHARACTER, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(RINGPEDAN_CHARACTER, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eAUTORESET, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(eATTACK, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(XOAHOMDO_MAIN, 31461, 900, 1000, -1, -1);  // 31461
	this->BindObject(TINHNANG_MAIN, 31461, 900, 1000, -1, -1);  // 31461
	this->BindObject(RINGPEDAN_MAIN, 31461, 900, 1000, -1, -1);  // 31461

	this->BindObject(BUTTON_YES, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO, 31461, 35, 14, -1, -1);  // 31461

	this->BindObject(BUTTON_YES1, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO1, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_YES2, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO2, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_YES3, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO3, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_YES4, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO4, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_YES5, 31461, 35, 14, -1, -1);  // 31461
	this->BindObject(BUTTON_NO5, 31461, 35, 14, -1, -1);  // 31461
#endif

#if(OANTUTY)
	//
	this->BindObject(eRock, 0x9323, 36, 28, -1, -1);
	this->BindObject(ePaper, 0x9324, 36, 28, -1, -1);
	this->BindObject(eScissors, 0x9325, 36, 28, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------

	this->BindObject(eCheck, 0x9991, 15, 15, -1, -1);
	this->BindObject(eUnCheck, 0x9992, 15, 15, -1, -1);
	
	//----------------------------------------------------------------------------------------
	this->BindObject(eRankPANEL_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eEventTimePANEL_MAIN, 31461, 640, 419, -1, -1);  // 31461
	//----------------------------------------------------------------------------------------
#if(MENU_NEW)
	this->BindObject(eMENU_MAIN, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eMENU_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eBUTTON_MENU_1, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_2, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_3, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_4, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_5, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_6, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_7, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_8, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_9, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_10, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_11, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_12, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_13, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_14, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_15, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_16, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_17, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_18, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_19, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_20, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_21, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eBUTTON_MENU_22, 0x7A5E, 108, 29, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
#if(VONGQUAY_NEW)
	this->BindObject(eLuckySpin, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eLuckySpinRoll, 0x7A5E, 108, 29, -1, -1);
	this->BindObject(eLuckySpinClose, 0x7EC5, 36, 29, -1, -1);
#endif
	//----------------------------------------------------------------------------------------
	//--
	this->BindObject(eTIME, 30847, 131, 70, -10, 359);
	//--
	//tue add
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);
	//--
	//---------------
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);
	//--
	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eEventTime_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eEventTime_CLOSE, 0x7EC5, 36, 29, -1, -1);
	//--
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);
	//Custom Store
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		this->BindObject(eOFFTRADE_JoB, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 51522, 40, 17, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 51522, 108, 30, -1, -1);
	}
	else
	{
		this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
		this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	}
	//-- custom
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	this->BindObject(eTIECRUOU_MAIN, 0x7A5A, 222, 235, -1, -1);
	this->BindObject(eTIECRUOU_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eTIECRUOU_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eTIECRUOU_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eTIECRUOU_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eTIECRUOU_CLOSE, 0x7A5C, 54, 30, -1, -1);
	this->BindObject(eTIECRUOU_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eTIECRUOU_INFOBG2, 0x7AA1, 170, 21, -1, -1);

	this->BindObject(eMOIRUOU_MAIN, 0x7A5A, 222, 200, -1, -1);
	this->BindObject(eMOIRUOU_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eMOIRUOU_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eMOIRUOU_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eMOIRUOU_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eMOIRUOU_CLOSE, 0x7A5C, 54, 30, -1, -1);

	this->BindObject(eMUARUOU_OK, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eMOIRUOU_ZEN, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eMOIRUOU_WC, 0x7A5E, 106, 29, -1, -1);
	//Minimap
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eLORENCIA_MAP, 31462, 128, 128, -1, -1);
	this->BindObject(eDUNGEON_MAP, 31463, 128, 128, -1, -1);
	this->BindObject(eDEVIAS_MAP, 31464, 128, 128, -1, -1);
	this->BindObject(eNORIA_MAP, 31465, 128, 128, -1, -1);
	this->BindObject(eLOSTTOWER_MAP, 31466, 128, 128, -1, -1);
	this->BindObject(eSTADIUM_MAP, 61465, 128, 128, -1, -1);
	this->BindObject(eATLANS_MAP, 31467, 128, 128, -1, -1);
	this->BindObject(eTarkan_MAP, 31468, 128, 128, -1, -1);
	this->BindObject(eElbeland_MAP, 31469, 128, 128, -1, -1);
	this->BindObject(eICARUS_MAP, 31470, 128, 128, -1, -1);
	this->BindObject(eLANDOFTRIALS_MAP, 31461, 128, 128, -1, -1);
	this->BindObject(eAIDA_MAP, 31472, 128, 128, -1, -1);
	this->BindObject(eCRYWOLF_MAP, 31473, 128, 128, -1, -1);
	this->BindObject(eKANTRU_MAP, 31474, 128, 128, -1, -1);
	this->BindObject(eKANTRU3_MAP, 31475, 128, 128, -1, -1);
	this->BindObject(eBARRACKS_MAP, 31476, 128, 128, -1, -1);
	this->BindObject(eCALMNESS_MAP, 31477, 128, 128, -1, -1);
	this->BindObject(eRAKLION_MAP, 31478, 128, 128, -1, -1);
	this->BindObject(eVULCANUS_MAP, 31479, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN_MAP, 31480, 128, 128, -1, -1);
	this->BindObject(eKALRUTAN2_MAP, 31481, 128, 128, -1, -1);

	this->BindObject(eNextCommand, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevCommand, 31658, 17, 18, -1, -1);
	this->BindObject(eNextEvent, 31659, 17, 18, -1, -1);
	this->BindObject(ePrevEvent, 31658, 17, 18, -1, -1);

	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	this->Data[eTIME].OnShow = true;
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);

	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
	case 1:
	case 2:
	
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		if(gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 383.5);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 383.5);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
		}
		//-> Custom Interface S2
		if(gProtect.m_MainInfo.CustomInterfaceType == 2){
		this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		}
		break;
	case 3:
	case 4:
		this->BindObject(eButton1, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton2, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton3, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton4, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
		this->BindObject(eButton5, 61525, 43.0f, 17.0f, -43.0f, -17.0f);
	    this->BindObject(eMenu, 51522, 19, 19, -1, -1);
	    this->BindObject(eMenuBG, 51522, 36, 18, 174, 0);
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eQuest, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCommunity, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eSystem, 51522, 19.5f, 19.5f, -1, -1);
		break;
	default:
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
		break;
	}
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		this->BindObject(eMoney1, 0x7909, 75, 13, -1, -1);
		this->BindObject(eMoney2, 0x7910, 75, 13, -1, -1);
	}
	//---
	this->BindObject(eWAREHOUSE_MAIN, 0x7A5A, 222, 211, -1, -1);
	this->BindObject(eWAREHOUSE_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eWAREHOUSE_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eWAREHOUSE_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eWAREHOUSE_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eWAREHOUSE_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM1, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM2, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM3, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM4, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM5, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM6, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM7, 0x7A5E, 106, 29, -1, -1);
	this->BindObject(eWAREHOUSE_NUM8, 0x7A5E, 106, 29, -1, -1);

	this->BindObject(eSTATSADD_MAIN, 0x7A5A, 222, 226, -1, -1);
	this->BindObject(eSTATSADD_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eSTATSADD_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eSTATSADD_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eSTATSADD_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eSTATSADD_TEXTBOX01, 400004, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX01, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX02, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX03, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX04, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_STATBOX05, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(eSTATSADD_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eSTATSADD_STEP10, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSTATSADD_STEP100, 0x7BAE, 15, 15, -1, -1);
	this->BindObject(eSTATSADD_STEP1000, 0x7BAE, 15, 15, -1, -1);

	///muun
	this->BindObject(eCONFIRM_MUUNBTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_MUUNBTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	////new
	this->BindObject(eNEWS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eNEWS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eNEWS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eNEWS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eNEWS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eNEWS_INFOBG, 0x787D, 170, 21, -1, -1);
	this->BindObject(eNEWS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eNEWS_BACK, 0x7A5E, 128, 29, -1, -1);

	///emoji
	if ( gProtect.m_MainInfo.PutoEllQueLoLea != 0)
	{
	//myheart::MUEmoji::Init(TEXTURE_EMOJI_LIST_ARROW, TEXTURE_EMOJI_LIST_ON, TEXTURE_EMOJI_LIST_BTN, 20, 14,	4, 0);
	//myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST1, 361);
	//myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST2, 309);
	//myheart::MUEmoji::AddTexture(TEXTURE_EMOJI_LIST3, 118);
	}
	////
	
	this->BindObject(SOLAR_NEW_MENU_MAIN, 31461, 640, 419, -1, -1);  // 31461
	///leothap
#if(LEOTHAP == 1)
	// Leo thap
	this->BindObject(eLEOTHAP_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eLEOTHAP_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eLEOTHAP_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eLEOTHAP_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eLEOTHAP_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eLEOTHAP_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eLEOTHAP_POINT, 0x7B68, 10, 10, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE1, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE2, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE3, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE4, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eLEOTHAP_BUTTON_GATE5, 0x7A5B, 54, 30, -1, -1);
#endif

	this->BindObject(eCHARINFO_BTN_STAT, 0x7AA4, 16, 15, -1, -1);

#if(DEV_DAMAGE_TABLE)
	this->m_EnableDamageTable = false;
#endif

	gNewInterface.Load();

	gChangeClass.BinObeject();

#if (SHOPSEARCH)
g_PersonalShopEx.BindImages();
#endif

//	g_ExWinQuestSystem.BindImages();

	#if (SELECTCHARACTER==1)
		SetCompleteHook(0xFF, 0x004D5EE6, &gMultiCharacter.SelectChar);
		gMultiCharacter.m_CharacterPage = 1;
	#endif
	
	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);

	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);

	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP);
		SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	}

#if (MOCNAP == 1)
		G_BEXO_MOCNAP.BIND();
#endif
#if (QUAEVENT == 1)
		G_BEXO_QUATOP1.BIND();
		G_BEXO_QUATOP2.BIND();
		G_BEXO_QUATOP3.BIND();
#endif

				//Jewel Bank
	this->BindObject(eJewelBank_MAIN, 0x7A5A, 222, 240, -1, -1);
	this->BindObject(eJewelBank_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eJewelBank_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eJewelBank_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eJewelBank_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eJewelBank_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eJewelBank_NEXT, 0x7903, 25, 40, -1, -1);
	this->BindObject(eJewelBank_PREV, 0x7904, 25, 40, -1, -1);

	for (int i=0; i < 50;i++)
	{
		this->BindObject(eJewelBank_WITHDRAW+i, 31743, 16, 32, -1, -1);
	}
}

	
void Interface::NewLoadInterface()
{
	
		gHuyHieuCuongHoa.DrawHuyHieu();
	
}
#include "NewUIMyInventory.h"

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10;
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width
	char Precio[50];
	

	char MoneyBuff1[50], MoneyBuff2[50], MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite, v11, v10 + 12, 190, 3, "%s [%d]",pGetTextLine(pTextLineThis, 223) , TypeInventory);
	//--
	gInterface.DrawGUI(eMoney1, v11 + 18, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 21, v10 + 367, 20, 1, "Zen");
	gInterface.DrawFormat(eRed, v11 + 40, v10 + 367, 50, 3, "%s", MoneyBuff1);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 365);
	gInterface.DrawFormat(eBlack, v11 + 106, v10 + 367, 20, 1, "GP");
	gInterface.DrawFormat(eWhite, v11 + 128, v10 + 367, 45, 4, "%s", MoneyBuff2);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 18, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 21, v10 + 380, 20, 1, "WC");
	gInterface.DrawFormat(eGold, v11 + 38, v10 + 381, 50, 4, "%s", MoneyBuff3);
	//--
	gInterface.DrawGUI(eMoney2, v11 + 102, v10 + 378);
	gInterface.DrawFormat(eBlack, v11 + 103, v10 + 380, 20, 1, "WCP");
	gInterface.DrawFormat(eBlue, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);


	float Solarx;

	float MainWidth = 200.0;
	float MainHeight = 180.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if ( gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
	if (gInterface.CheckWindow(Character))
	{
		Solarx = StartX-190;
	}
	else
	{
		Solarx = StartX;
	}
	}
	else
	{
	    Solarx = StartX;
	}

	if (gInterface.CheckWindow(Inventory))
	{
		if(gProtect.m_MainInfo.CustomInterfaceType == 0)
		{
			if(gHuyHieuCuongHoa.huyhieu >=1)
			{
				pDrawGUI(59990, Solarx + 347, StartY -37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Solarx + 347, StartY -37, 22, 22);
			}
		}
		else if(gProtect.m_MainInfo.CustomInterfaceType ==0)
		{
			if(gHuyHieuCuongHoa.huyhieu >=1)
			{
				pDrawGUI(59990, Solarx + 347, StartY -37, 22, 22);
			}
			else
			{
				pDrawGUI(59999, Solarx + 347, StartY -37, 22, 22);
			}
		}

	}
	////----

#if(HUY_HIEU_CUONG_HOA)

	gInterface.DrawGUI(eSachThuocTinh1, v11 + 11, v10 + 365);

	pSetFont(pTextThis(), (int)pFontBold);
	pSetTextColor(pTextThis(), 225, 0, 0, 255);
	wsprintf(Precio, "%s", MoneyBuff1);
	pDrawText(pTextThis(), v11 + 52, v10 + 372, Precio, 0, 0, (LPINT)3, 0);
	gInterface.DrawGUI(eSachThuocTinh, v11 + 120, v10 + 94);

	gInterface.DrawItem2(v11 + 120, v10 + 93, 18, 18, ITEM(13, 23), 11, 0, 0, 0); 

	if (gObjUser.m_HHCH == 1)
	{
		if (pCheckMouseOver(v11 + 120, v10 + 94, 15, 15))
		{
			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;
			int LineW = 0;

			char Buff[256] = { 0 };
			char BuffDate[256] = { 0 };
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Huy Hiệu Cường Hoá +11");
			ColorTexto[LineW] = 4;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			wsprintf(TooltipLine[LineW], "(Kích Hoạt Khi Mặc Đủ Sét Item)");
			ColorTexto[LineW] = 14;
			LineWeight[LineW++] = 0;

			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Độ Bền: [Vĩnh viễn]");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;

			wsprintf(TooltipLine[LineW], "Cấp Độ Yêu Cầu: 0");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			//-- Thong tin kich hoat
			wsprintf(TooltipLine[LineW], "%s", "Lượng Máu Tăng + 4%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "%s", "Trang Bị Đủ Set Item +11 Kich Hoạt Dòng");
			ColorTexto[LineW] = 3;
			LineWeight[LineW++] = 1;
			//
			pMultiLineTooltip(v11 - 58, v10 + 93, LineW, 0, 3, 0, 1);
		}
	}

	 else if (gObjUser.m_HHCH == 2)
	{
		if (pCheckMouseOver(v11 + 120, v10 + 94, 15, 15))
		{
			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;
			int LineW = 0;

			char Buff[256] = { 0 };
			char BuffDate[256] = { 0 };
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Huy Hiệu Cường Hoá +12");
			ColorTexto[LineW] = 4;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			wsprintf(TooltipLine[LineW], "(Kích Hoạt Khi Mặc Đủ Sét Item)");
			ColorTexto[LineW] = 14;
			LineWeight[LineW++] = 0;

			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Độ Bền: [Vĩnh viễn]");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			wsprintf(TooltipLine[LineW], "Cấp Độ Yêu Cầu: 0");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//-- Thong tin kich hoat
			//
			wsprintf(TooltipLine[LineW], "%s", "Phòng Thủ + 4%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Lượng Máu Tăng + 8%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "%s", "Trang Bị Đủ Set Item +12 Kich Hoạt Dòng");
			ColorTexto[LineW] = 3;
			LineWeight[LineW++] = 1;
			//

			pMultiLineTooltip(v11 - 58, v10 + 93, LineW, 0, 3, 0, 1);
		}
	}

	 else if (gObjUser.m_HHCH == 3)
	{
		if (pCheckMouseOver(v11 + 120, v10 + 94, 15, 15))
		{
			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;
			int LineW = 0;

			char Buff[256] = { 0 };
			char BuffDate[256] = { 0 };
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Huy Hiệu Cường Hoá +13");
			ColorTexto[LineW] = 4;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			wsprintf(TooltipLine[LineW], "(Kích Hoạt Khi Mặc Đủ Sét Item)");
			ColorTexto[LineW] = 14;
			LineWeight[LineW++] = 0;

			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Độ Bền: [Vĩnh viễn]");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			wsprintf(TooltipLine[LineW], "Cấp Độ Yêu Cầu: 0");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			//-- Thong tin kich hoat
			//
			wsprintf(TooltipLine[LineW], "%s", "Phòng Thủ + 7%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Lượng Máu Tăng + 12%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Bỏ Qua Phòng Ngự + 3%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "%s", "Trang Bị Đủ Set Item +13 Kich Hoạt Dòng");
			ColorTexto[LineW] = 3;
			LineWeight[LineW++] = 1;
			//
			pMultiLineTooltip(v11 - 58, v10 + 93, LineW, 0, 3, 0, 1);
		}
	}

	else if (gObjUser.m_HHCH == 4)
	{
		if (pCheckMouseOver(v11 + 120, v10 + 94, 15, 15))
		{
			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;
			int LineW = 0;

			char Buff[256] = { 0 };
			char BuffDate[256] = { 0 };
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Huy Hiệu Cường Hoá +14");
			ColorTexto[LineW] = 4;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			wsprintf(TooltipLine[LineW], "(Kích Hoạt Khi Mặc Đủ Sét Item)");
			ColorTexto[LineW] = 14;
			LineWeight[LineW++] = 0;

			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Độ Bền: [Vĩnh viễn]");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			wsprintf(TooltipLine[LineW], "Cấp Độ Yêu Cầu: 0");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			//-- Thong tin kich hoat

			wsprintf(TooltipLine[LineW], "%s", "Phòng Thủ + 10%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Lượng Máu Tăng + 16%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Bỏ Qua Phòng Ngự + 6%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "%s", "Trang Bị Đủ Set Item +14 Kich Hoạt Dòng");
			ColorTexto[LineW] = 3;
			LineWeight[LineW++] = 1;
			//

			pMultiLineTooltip(v11 - 58, v10 + 93, LineW, 0, 3, 0, 1);
		}
	}
	
	else if (gObjUser.m_HHCH == 5)
	{
		if (pCheckMouseOver(v11 + 120, v10 + 94, 15, 15))
		{
			tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
			int * ColorTexto = (int*)NewAddressData1;
			int * LineWeight = (int*)NewAddressData2;
			int LineW = 0;

			char Buff[256] = { 0 };
			char BuffDate[256] = { 0 };
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Huy Hiệu Cường Hoá +15");
			ColorTexto[LineW] = 4;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			wsprintf(TooltipLine[LineW], "(Kích Hoạt Khi Mặc Đủ Sét Item)");
			ColorTexto[LineW] = 14;
			LineWeight[LineW++] = 0;

			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "Độ bền: [Vĩnh viễn]");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			wsprintf(TooltipLine[LineW], "Cấp độ yêu cầu: 0");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 1;
			//--
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;

			//-- Thong tin kich hoat
			wsprintf(TooltipLine[LineW], "%s", "Phòng Thủ+ 15%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Lượng Máu Tăng + 20%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Bỏ Qua Phòng Ngự + 9%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "%s", "Sát Thương X2 + 5%");
			ColorTexto[LineW] = 6;
			LineWeight[LineW++] = 1;
			//
			wsprintf(TooltipLine[LineW], "\n");
			ColorTexto[LineW] = 0;
			LineWeight[LineW++] = 0;
			//--
			wsprintf(TooltipLine[LineW], "%s", "Trang Bị Đủ Sét Item + 15 Kích Hoạt Dòng");
			ColorTexto[LineW] = 3;
			LineWeight[LineW++] = 1;

			pMultiLineTooltip(v11 - 58, v10 + 93, LineW, 0, 3, 0, 1);
		}
	}

#endif
}

void Interface::LoadModels()
{

	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	pLoadModel(10001, "Data\\Object1\\", "FlagRong", -1);
	pLoadTexture(10001, "Object1\\", 0x2901, 0x2600, 1);
	pLoadModel(10002, "Data\\Object55\\", "FlagRong", -1);
	pLoadTexture(10002, "Object55\\", 0x2901, 0x2600, 1);
	pLoadModel(10003, "Data\\Object65\\", "FlagRong", -1);
	pLoadTexture(10003, "Object65\\", 0x2901, 0x2600, 1);
	pLoadModel(10004, "Data\\Object92\\", "FlagRong", -1);
	pLoadTexture(10004, "Object92\\", 0x2901, 0x2600, 1);
	pInitModelData2();

	pInitModelData2();
}

void Interface::LoadImages()
{
	//tue add
#if BAUCUA
	pLoadImage("WZen\\MiniGame\\ICONBAUCUA.tga", 12349, 0x2601, 0x2901, 1, 0);
	pLoadImage("WZen\\MiniGame\\NewsBoard_Title2.tga", 12344, 0x2601, 0x2901, 1, 0);
	pLoadImage("WZen\\MiniGame\\BAUCUA.tga", 12348, 0x2601, 0x2901, 1, 0);
	pLoadImage("WZen\\MiniGame\\Bau.tga", 11149, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("WZen\\MiniGame\\Cua.tga", 11150, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("WZen\\MiniGame\\Tom.tga", 11151, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("WZen\\MiniGame\\Ca.tga", 11152, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("WZen\\MiniGame\\Ga.tga", 11153, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("WZen\\MiniGame\\Nai.tga", 11154, GL_LINEAR, GL_CLAMP, 1, 0);
#endif
	//--------
	//tue add atm boxx
	pLoadImage("WZen\\Other\\ATM.tga", 0x17918, GL_LINEAR, GL_REPEAT, 1, 0);
	//-----
	//tue add icon button atm boxx
	LoadBitmapA("WZen\\MacroUI\\Btn_A_Buff.tga", 151562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BResetAuto.tga", 151554, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BDanhHieu.tga", 151555, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BReset.tga", 151556, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BCamera.tga", 151557, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BAtm.tga", 151558, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BInfo.tga", 151559, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_BBlock.tga", 151560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\Btn_A_AutoHP.tga", 151561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\Btn_A_Buff.tga", 151562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("WZen\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
	//Fix load icons
	LoadBitmapA("WZen\\Nop\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
	//endadd----------------------
	//-----------------------------
	//tue add tu chan //////////////////
#if(SPK_HONHOAN)
	gHonHoan.LoadImageHonHoan();
	////////////////////
	//=== Hon Hoan
	pLoadImage("Custom\\HonHoan\\1.jpg", eImgHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\2.jpg", eImgHonHoan + 1, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\3.jpg", eImgHonHoan + 2, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\4.jpg", eImgHonHoan + 3, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\5.jpg", eImgHonHoan + 4, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\6.jpg", eImgHonHoan + 5, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\7.jpg", eImgHonHoan + 6, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\8.jpg", eImgHonHoan + 7, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\9.jpg", eImgHonHoan + 8, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\10.jpg", eImgHonHoan + 9, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\11.jpg", eImgHonHoan + 10, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\12.jpg", eImgHonHoan + 11, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\13.jpg", eImgHonHoan + 12, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\14.jpg", eImgHonHoan + 13, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\15.jpg", eImgHonHoan + 14, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\16.jpg", eImgHonHoan + 15, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\17.jpg", eImgHonHoan + 16, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\18.jpg", eImgHonHoan + 17, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\19.jpg", eImgHonHoan + 18, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\20.jpg", eImgHonHoan + 19, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\21.jpg", eImgHonHoan + 20, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\22.jpg", eImgHonHoan + 21, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\23.jpg", eImgHonHoan + 22, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\24.jpg", eImgHonHoan + 23, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\25.jpg", eImgHonHoan + 24, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\26.jpg", eImgHonHoan + 25, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\27.jpg", eImgHonHoan + 26, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\28.jpg", eImgHonHoan + 27, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\29.jpg", eImgHonHoan + 28, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\30.jpg", eImgHonHoan + 29, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\31.jpg", eImgHonHoan + 30, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\32.jpg", eImgHonHoan + 31, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\33.jpg", eImgHonHoan + 32, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\34.jpg", eImgHonHoan + 33, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\35.jpg", eImgHonHoan + 34, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\36.jpg", eImgHonHoan + 35, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\37.jpg", eImgHonHoan + 36, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\38.jpg", eImgHonHoan + 37, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\39.jpg", eImgHonHoan + 38, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\40.jpg", eImgHonHoan + 39, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\41.jpg", eImgHonHoan + 40, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\42.jpg", eImgHonHoan + 41, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\43.jpg", eImgHonHoan + 42, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\44.jpg", eImgHonHoan + 43, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\45.jpg", eImgHonHoan + 44, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\46.jpg", eImgHonHoan + 45, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\47.jpg", eImgHonHoan + 46, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\48.jpg", eImgHonHoan + 47, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\49.jpg", eImgHonHoan + 48, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\50.jpg", eImgHonHoan + 49, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\HonHoan\\DemoHonHoan.tga", eDemoHonHoan, GL_LINEAR, GL_CLAMP, 1, 0);
	////////////////////
#endif
#if SPK_DANHHIEU
	//gDanhHieu.LoadImageDanhHieu();
#endif
#if SPK_QUANHAM
	//gQuanHam.LoadImageQuanHam();
#endif
#if SPK_TUCHAN
	gTuLuyen.LoadImageTuLuyen();
#endif
#if SPK_NEWVIP 
	//gNewVip.LoadImageNewVip();
#endif
	///////////////////////////////////
	gCMacroUIEx.LoadImages();
	//-- Mensaje Bienvenida pantalla
	pDrawMessage(gCustomMessage.GetMessage(69), 0);
	pLoadSomeForm();

	gPartySearch.LoadImgPT();

	G_BEXO_HE_THONG.LoadImages();

	G_QUAN_LY_TK.LoadImages();

#if _NEW_PARTY_SYSTEM_ == TRUE
	g_Party.LoadIMG();
#endif

	pLoadImage("Custom\\Interface\\Progress.tga", 0x0897, 0x2601, 0x2901, 1, 0);

	pLoadImage("Custom\\Interface\\tvt_hud.tga", 0x9912, 0x2601, 0x2900, 1, 0);

	LoadBitmapA("Custom\\rong\\Rong 1.tga", 631117, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 2.tga", 631118, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 3.tga", 631119, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 4.tga", 631120, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 5.tga", 631121, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 6.tga", 631122, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 7.tga", 631123, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 8.tga", 631124, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 9.tga", 631125, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 10.tga", 631126, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 11.tga", 631127, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 12.tga", 631128, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 13.tga", 631129, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 14.tga", 631130, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 15.tga", 631131, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 16.tga", 631132, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 17.tga", 631133, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 18.tga", 631134, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 19.tga", 631135, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 20.tga", 631136, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 21.tga", 631137, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 22.tga", 631138, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 23.tga", 631139, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 24.tga", 631140, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 25.tga", 631141, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 26.tga", 631142, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 27.tga", 631143, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 28.tga", 631144, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 29.tga", 631145, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 30.tga", 631146, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 31.tga", 631147, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 32.tga", 631148, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 33.tga", 631149, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 34.tga", 631150, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 35.tga", 631151, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 36.tga", 631152, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 37.tga", 631153, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 38.tga", 631154, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 39.tga", 631155, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 40.tga", 631156, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 41.tga", 631157, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 42.tga", 631158, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 43.tga", 631159, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 44.tga", 631160, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 45.tga", 631161, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 46.tga", 631162, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 47.tga", 631163, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 48.tga", 631164, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 49.tga", 631165, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 50.tga", 631166, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 51.tga", 631167, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 52.tga", 631168, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 53.tga", 631169, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 54.tga", 631170, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 55.tga", 631171, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 56.tga", 631172, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 57.tga", 631173, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 58.tga", 631174, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 59.tga", 631175, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\rong\\Rong 60.tga", 631176, GL_LINEAR, GL_CLAMP, 1, 0);
	/////////
	////abcd
	LoadBitmapA("Custom\\Event\\NhanVat\\1.tga", 531008, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DK1.tga", 531009, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DW1.tga", 531010, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\ELF1.tga", 531011, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\MG1.tga", 531012, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\DL1.tga", 531013, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\SM1.tga", 531014, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Event\\NhanVat\\RF1.tga", 531015, GL_LINEAR, GL_CLAMP, 1, 0);
	/////


#if(SACHTHUOCTINH_NEW)
	pLoadImage("Interface\\GFx\\ex700\\Interface\\SachThuocTinh_UI.tga", 10000, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\ex700\\Interface\\Button-ThuocTinh.tga", 10003, 0x2601, 0x2900, 1, 0); // NÚT XÓA HÒM ĐỒ
#endif

#if(RINGPEDAN_NEW)
	pLoadImage("Interface\\GFx\\ex700\\Interface\\Pedan_UI.tga", 10001, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\ex700\\Interface\\Ring_UI.tga", 10002, 0x2601, 0x2901, 1, 0);
#endif

	pLoadImage("Custom\\Interface\\TimeLeoThap.tga", 81528, 0x2601, 0x2900, 1, 0); //leothap

	pLoadImage("Custom\\Interface\\SmallBackground\\ChieuNgang.tga", 0x501A, 0x2601, 0x2900, 1, 0); // THANH NGANG
	pLoadImage("Custom\\Interface\\SmallBackground\\ChieuDoc.tga", 0x502A, 0x2601, 0x2900, 1, 0); // THANH DỌC
	
	pLoadImage("Interface\\GFx\\Upgrade\\PetInventoryFrame_I3.tga", 0xF1003, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\check.jpg", 0x9991, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\uncheck.jpg", 0x9992, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\Button-30-20.tga", 10099, 0x2601, 0x2900, 1, 0);

	// CAMERA 3D
	pLoadImage("Custom\\Interface\\CameraUI_BG.tga", 0x787A, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Switch.tga", 0x787B, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\CameraUI_Reset.tga", 0x787C, 0x2601, 0x2900, 1, 0);
	//--
	if(gProtect.m_MainInfo.InventoryUPGRADE == 1)
	{
		pLoadImage("Custom\\Interface\\Money\\item_money.tga", 0x7909, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Money\\item_money2.tga", 0x7910, 0x2601, 0x2901, 1, 0);
	}
	//tue add
	//
	//pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Rank01.tga", 0x7880, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank02.tga", 0x7881, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank03.tga", 0x7882, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank04.tga", 0x7883, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank05.tga", 0x7884, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank06.tga", 0x7885, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank07.tga", 0x7886, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank08.tga", 0x7887, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank09.tga", 0x7888, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank10.tga", 0x7889, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank11.tga", 0x7890, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank12.tga", 0x7891, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank13.tga", 0x7892, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank14.tga", 0x7893, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank15.tga", 0x7894, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank16.tga", 0x7895, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank17.tga", 0x7896, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank18.tga", 0x7897, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank19.tga", 0x7898, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank20.tga", 0x7899, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank21.tga", 0x7900, 0x2601, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Rank22.tga", 0x7901, 0x2601, GL_CLAMP, 1, 0);
	//-------
	pLoadImage("Custom\\Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		pLoadImage("Custom\\Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Custom\\Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//--
	//--Interface MiniMap 97/99/S2/S6
	if(MiniMapType == 0)
	{
	pLoadImage("Custom\\Maps\\edBtUcx_old.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\timeold.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--Interface MiniMap ex700/Legends
	if(MiniMapType == 1)
	{
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\time700.tga", 31458, 0x2601, 0x2900, 1, 0); //-- Dungeon
	}
	//--
	pLoadImage("Custom\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31459, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("Custom\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("Custom\\Maps\\mini_map_ui_monstergold.tga", 31473, 0x2601, 0x2900, 1, 0); //-- Dungeon Gold
	//////////effecsolar
	if ( gProtect.m_MainInfo.PutoEllQueLoLea != 0)
	{
	   //pLoadImage("Interface\\GFx\\emojis_f.tga", TEXTURE_EMOJI_LIST1, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\emojis_f2.tga", TEXTURE_EMOJI_LIST2, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\emojis_f3.tga", TEXTURE_EMOJI_LIST3, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\emoji_list_btn.tga", TEXTURE_EMOJI_LIST_BTN, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\newui_chat_emoji_on.jpg", TEXTURE_EMOJI_LIST_ON, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\btn_arrow.tga", TEXTURE_EMOJI_LIST_ARROW, GL_LINEAR, GL_CLAMP, 1, 0);
	   //pLoadImage("Interface\\GFx\\newui_chat_back.jpg", 31279, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//=== CTC Mini UI ==//
	pLoadImage("Custom\\CTCMini\\UiCtc.tga", 32584, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\CTCMiniMap.tga", 32583, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\StartCTC.tga", 32585, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\WinCTC.tga", 32586, 9729, 10496, 1, 0);
	pLoadImage("Custom\\CTCMini\\LoseCTC.tga", 32589, 9729, 10496, 1, 0); //Trung voi ID effect 32587
	pLoadImage("Custom\\CTCMini\\DialogCTC.tga", 32588, 9729, 10496, 1, 0);
    pLoadImage("Custom\\CTCMini\\CharPoint.tga", 32506, 9729, 10496, 1, 0);
    pLoadImage("Custom\\CTCMini\\OtherCharPoint.tga", 32507, 9729, 10496, 1, 0);
	//==============================//
#if (SELECTCHARACTER==1)
		pLoadImage("Custom\\Interface\\Next_Char.tga", 0x7911, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\Interface\\Previous_Char.tga", 0x7912, 0x2601, 0x2901, 1, 0);
#endif

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	if(gProtect.m_MakeViewTRSData.TooltipS15 == 1)
	{
		//-- itemtooltip
		pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	}
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	//--
	pLoadImage("Interface\\GFx\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\GFx\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	//--
	//Party Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}
	//--
	//--Party Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Custom\\Party\\Ex700\\PartyBar.tga", 81525, GL_LINEAR, GL_CLAMP, 1, 0);
    pLoadImage("Custom\\Party\\Ex700\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("Custom\\Party\\Ex700\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);
	}

	//--
	LoadBitmapA("Interface\\newui_number1.tga", 31337, 9729, 10496, 1, 0);
#if(OANTUTY)
	pLoadImage("Custom\\RPSMode\\rock.tga", 0x9323, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RPSMode\\paper.tga", 0x9324, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\RPSMode\\scissors.tga", 0x9325, 0x2601, 0x2900, 1, 0);
#endif
	//Interface Minimapa 97/99
	//LoadBitmapA("Interface\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	LoadBitmapA("Interface\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\InventoryFrame_RuudShop.tga", 61560, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_RuudShopFrame.tga", 61561, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\Menu_Button03.tga", 61562, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar ex700/Legends
	if(MiniMapType == 1)
	{
	LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//-- Pet Bar 97/99/S2/S6
	if(MiniMapType == 0)
	{
	LoadBitmapA("Custom\\Party\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//--
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
	case 1:
	case 2:
	if(gProtect.m_MainInfo.CustomInterfaceType == 1||gProtect.m_MainInfo.CustomInterfaceType == 2){
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\Interface\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}else
		{
			LoadBitmapA("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			LoadBitmapA("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		}
		LoadBitmapA("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		LoadBitmapA("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//--
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		//Interface Character
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- chat
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
	}
		break;
	case 3:
		/*//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);*/
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 59000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I1.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);
		goto LOAD_GFX;
	case 4:
		LoadBitmapA("Interface\\GFx\\Legends\\Main_IE.tga", 31293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I3.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp.tga", 31296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_mp_1.tga", 51501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_green.tga", 31297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp.tga", 31298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\guege_hp_1.tga", 51502, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("Interface\\GFx\\Legends\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\newui_skillbox.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);
LOAD_GFX:
		LoadBitmapA("Interface\\GFx\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		//-- Botones del Main
		LoadBitmapA("Custom\\Interface\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Custom\\Interface\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Custom\\Interface\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}//--Finaliza
	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 61523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 61524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 61526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_E.tga", 61536, GL_LINEAR, GL_CLAMP, 1, 0); //-- Windows Party/Pet/Gens and Others
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3_C.tga", 61558, GL_LINEAR, GL_CLAMP, 1, 0); //-- Window Chaos Mix
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 61527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 61528, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 61529, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 61532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 61533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 61535, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 61538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 61539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 61540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 61541, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 61542, GL_LINEAR, GL_CLAMP, 1, 0); //Boton Shop Ruud
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 61543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 61544, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	//-- MuHelper ex700
	if(gProtect.m_MainInfo.MuHelperType == 1)
	{
	//-- Folder MacroUI
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Main.tga", 51550, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BSetup.tga", 51546, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_BStart.tga", 51547, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Stop.tga", 51548, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Bar.jpg", 51549, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\MacroUI\\MacroUI_Menu.tga", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
	}
	//RuudCoin Interface S6/97/S2/Legends
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
	LoadBitmapA("Custom\\Interface\\RuudHeadOld.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	else if (gProtect.m_MainInfo.CustomInterfaceType == 3 ||gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	LoadBitmapA("Custom\\Interface\\RuudHeadLegends.tga", 0x7877, 0x2601, 0x2901,1,0);
	}
	//TimerBar
	LoadBitmapA("Custom\\Interface\\TimeBarex700.tga", 0x7878, 0x2601, 0x2901,1,0);

	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x7879, 0x2601, 0x2901,1,0);

	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--
if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}

	pLoadImage("Custom\\Interface\\button-main-big.tga", 270593, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Custom\\Interface\\Title.tga", 400001, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\PartySearch_Title.tga", 400002, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\Info_Block.tga", 400003, 0x2601, 0x2900, 1, 0);

	pLoadImage("Custom\\Interface\\newui_cha_textbox01.tga", 400004, 0x2601, 0x2900, 1, 0);

	pLoadImage("Logo\\Mu-logo_g.jpg",  531019, GL_LINEAR, GL_REPEAT, 1, 0);

	pLoadImage("Logo\\Mu-logo.tga",  531018, GL_LINEAR, GL_REPEAT, 1, 0);

	LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("Interface\\GFx\\Legends\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("Interface\\newui_Figure_blood.tga", 0x6863, 0x2601, 0x2901, 1, 0);

	LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Custom\\Interface\\TimeBarS6.tga", 0x787E, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Interface\\Decor.tga", 87968, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Custom\\Interface\\InterfaceBar.tga", 87969, 0x2601, 0x2901, 1, 0);


	pLoadImage("Custom\\Desig\\eventbar.tga", 91990, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\eventbar2.tga", 91991, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\bg460.tga", 631177, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\khung1.tga", 500001, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Desig\\Rong1.tga", 500004, 0x2601, 0x2900, 1, 0);
	LoadBitmapA("Custom\\Desig\\BXH.tga", 531116, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\Muun4.tga", 11111, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Desig\\1000.tga", 0x9960, 0x2601, 0x2900, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_auto.tga", 531141, GL_NEAREST, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\NewsBoard_Title.tga", 0x787D, 0x2601, 0x2900, 1, 0);

	LoadBitmapA("Custom\\Desig\\Login.tga", 71621, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\1.tga", 71622, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\2.tga", 71623, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\3.tga", 71624, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\4.tga", 71625, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\5.tga", 71626, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\6.tga", 71627, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\8.tga", 71629, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\9.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\10.tga", 71630, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\login_back.tga", 71631, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\Desig\\reloadcap.jpg", 71632, GL_LINEAR, GL_CLAMP, 1, 0);


	gHuyHieuCuongHoa.ImageLoad();

	gCuongHoaWing.ImageLoad();

	gVuKhiRong.ImageLoad();
	//------
	//tueadd
	pLoadImage("Local\\mutue-mini-season19.tga", 12359, 0x2601, 0x2901, 1, 0);
	//endadd
	//LoadBitmapA("Custom\\Interface\\TimeBar.tga", 0x787F, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\timerserver-bar2.tga", 0x4045, 0x2601, 0x2901, 1, 0);
	//tue add
	pLoadImage("Custom\\Interface\\FaceBook.tga", 0x4043, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Zalo.tga", 0x4044, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\Donate.tga", 0x4046, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\timerserver-bar.tga", 0x4047, GL_LINEAR, GL_CLAMP, 1, 0);
	//pLoadImage("Custom\\Interface\\B_FACEBOOK.tga", 0x4048, GL_LINEAR, GL_REPEAT, 1, 0);
	//endadd----



	pLoadSomeForm();
}

void Interface::WindowsKG(){
	if (gProtect.m_MainInfo.CustomInterfaceType >= 0){
		char interaltas[500];
		if (gInterface.validar == 0){
			if (gInterface.ultimo_Ping > 0)
			{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Reset: %d/%d - ReLife: %d || WCoinC: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, ViewReset,this->m_GHRS, ViewGReset, Coin1);
			}
			else{
				sprintf_s(interaltas, sizeof(interaltas), " %s || Player: %s || Reset: %d/%d - ReLife: %d || WCoinC: %d", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, ViewReset,this->m_GHRS, ViewGReset, Coin1);
			}
			SetWindowText(pGameWindow, interaltas);
		}
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	//RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1, 1.0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	//RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
	//tue add fix
	//glColor3f(1.0, 1.0, 1.0);
	//pSetBlend(true);
	//pGLSwitchBlend();
	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1, 1.0);
	//pGLSwitch();
	//-------
	//glColor3f(1.0, 1.0, 1.0);
	//----end fixx
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}
///////////////
	// ----hieu ung duoi chan 
#define WorldTime				*(float*)0x005EF5A1C
#define EnableAlphaBlend					((void(__cdecl*)()) 0x636070)
#define DisableAlphaBlend				((void(__cdecl*)()) 0x00635F50)
#define RenderTerrainAlphaBitmap             			((void(__cdecl*)(int Texture,float xf,float yf,float SizeX,float SizeY,vec3_t Light,float Rotation,float Alpha,float Height, char a10)) 0x005DAD80)

void __cdecl RenderCharacter(ObjectPreview* a4, ObjectModel* a5, int Select)
{
	vec3_t vLight;
	Vector(1.0f, 1.0f, 1.f, vLight);
	float fLumi = sinf(WorldTime * 0.0015f) * 0.3f + 0.5f;
	Vector(fLumi * vLight[0], fLumi * vLight[1], fLumi * vLight[2], vLight);
	EnableAlphaBlend();
	RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 5.8f, 5.8f, vLight, WorldTime * 0.11f, 1.0, 5, 1);
	RenderTerrainAlphaBitmap(32280, a4->m_Model.VecPos.X, a4->m_Model.VecPos.Y, 3.8f, 3.8f, vLight, -WorldTime * 0.01f, 1.0, 5, 1);
	DisableAlphaBlend();
}

// 	//-------------------------------------------------------------------
///////////////
void Interface::Work()
{

	//tue add
#if BAUCUA
	RunGameMini();
	gCUSTOM_BAUCUA.DrawStatsAddWindow();
#endif
	//------
//tue add Moc nap
#if(B_MOCNAP)
	gNewMocNap.DrawWindowMocNap();
#endif	
// ------	
	//tue add tu chan ///////////////////
	#if(SPK_HONHOAN)
		gHonHoan.DrawWindowNangCapHonHoan();
	#endif
	#if SPK_DANHHIEU
		//gDanhHieu.DrawWindowNangCapDanhHieu();
	#endif
	#if SPK_QUANHAM
		//gQuanHam.DrawWindowNangCapQuanHam();
	#endif
	#if SPK_TUCHAN
		gTuLuyen.DrawWindowNangCapTuLuyen();
	#endif
	#if SPK_NEWVIP
		//gNewVip.DrawWindowNangCapNewVip();
	#endif
//tue flag /////////////
#if(HT_THUE_FLAG)
		ThueFlag.Draw();
#endif
//========================= 
	///////////////////////////////////
	gInterface.RightMiniInfoY = 130;
	#if(DEV_DAMAGE_TABLE)
	//gInterface.DrawDamageTable();
	#endif
	gCamera.SmartCameraZoom();

	gCustomEventTime.Notice();

	gHuyHieuCuongHoa.DrawHuyHieu();

	gHuyHieuCuongHoa.DrawChiSo();

	gCuongHoaWing.DrawHuyHieu();

	gCuongHoaWing.DrawChiSo();

	gVuKhiRong.DrawHuyHieu();

	gVuKhiRong.DrawChiSo();

	G_QUAN_LY_TK.DRAW_QUAN_LY();

	gInterface.HideNameinCC();

	gNewsBoard.DrawNewsWindow();

#if(MOCNAP == 1)
		G_BEXO_MOCNAP.DRAW_MOCNAP();
#endif
#if(QUAEVENT == 1)
		G_BEXO_QUATOP1.DRAW_QUATOP1();
		G_BEXO_QUATOP2.DRAW_QUATOP2();
		G_BEXO_QUATOP3.DRAW_QUATOP3();
#endif
#if(THANMA)
		gInterface.DrawTMAllWindows();
#endif

#if(DANHHIEU_NEW)
	G_BEXO_DANH_HIEU.DRAW_DANH_HIEU();
	G_BEXO_QUAN_HAM.DRAW_QUAN_HAM();
#endif

#if(BOSS_GUILD == 1)
	gInterface.DrawBossGuildWindow();
	gInterface.DrawBossGuildMap(); // Time
#endif
	//tue add atm boxx
	gBoxAtm.DrawAtmWork();
	//---

	//---------------------------------------------------------
if (*(BYTE *)0x004DA3E0 != 40 || *(BYTE *)0x00D2360A != 64 || *(BYTE *)0x00D2360B != 65)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)0x005DE171 != 137 || *(BYTE*)0x005DE172 != 138
		|| *(BYTE*)0x005DE173 != 160 || *(BYTE*)0x005DE174 != 0
		|| *(BYTE*)0x005DE175 != 0 || *(BYTE*)0x005DE176 != 0
		|| *(BYTE*)0x005B5FFF != 245 || *(BYTE*)0x005B6000 != 0
		|| *(BYTE*)0x005B6001 != 0 || *(BYTE*)0x005B6002 != 0)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)0x005A1797 != 141 || *(BYTE*)0x005A1798 != 212
		|| *(BYTE*)0x005A1799 != 247 || *(BYTE*)0x005A179A != 255
		|| *(BYTE*)0x005A179B != 255
		|| *(BYTE*)0x005AD824 != 141 || *(BYTE*)0x005AD825 != 172 || *(BYTE*)0x005AD826 != 239 || *(BYTE*)0x005AD827 != 255 || *(BYTE*)0x005AD828 != 255
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E != 28 || *(BYTE*)0x005AF96F != 142 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		|| *(BYTE*)0x0059C79D != 141 || *(BYTE*)0x0059C79E != 212 || *(BYTE*)0x0059C79F != 247 || *(BYTE*)0x0059C7A0 != 255 || *(BYTE*)0x0059C7A1 != 255
		|| *(BYTE*)0x005AFBF1 != 141 || *(BYTE*)0x005AFBF2 != 4 || *(BYTE*)0x005AFBF3 != 134 || *(BYTE*)0x005AFBF4 != 255 || *(BYTE*)0x005AFBF5 != 255
		|| *(BYTE*)0x0059CEDC != 141 || *(BYTE*)0x0059CEDD != 228 || *(BYTE*)0x0059CEDE != 247 || *(BYTE*)0x0059CEDF != 255 || *(BYTE*)0x0059CEE0 != 255
		|| *(BYTE*)0x005B1CCB != 141 || *(BYTE*)0x005B1CCC != 4 || *(BYTE*)0x005B1CCD != 151 || *(BYTE*)0x005B1CCE != 255 || *(BYTE*)0x005B1CCF != 255
		|| *(BYTE*)0x005B170A != 141 || *(BYTE*)0x005B170B != 52 || *(BYTE*)0x005B170C != 175 || *(BYTE*)0x005B170D != 255 || *(BYTE*)0x005B170E != 255
		|| *(BYTE*)0x005B0C07 != 141 || *(BYTE*)0x005B0C08 != 124 || *(BYTE*)0x005B0C09 != 207 || *(BYTE*)0x005B0C0A != 255 || *(BYTE*)0x005B0C0B != 255
		|| *(BYTE*)0x005B187C != 141 || *(BYTE*)0x005B187D != 36 || *(BYTE*)0x005B187E != 167 || *(BYTE*)0x005B187F != 255 || *(BYTE*)0x005B1880 != 255
		|| *(BYTE*)0x0059D1E2 != 141 || *(BYTE*)0x0059D1E3 == 144 || *(BYTE*)0x0059D1E4 != 231 || *(BYTE*)0x0059D1E5 != 255 || *(BYTE*)0x0059D1E6 != 255
		|| *(BYTE*)0x005B1AA9 != 141 || *(BYTE*)0x005B1AAA != 20 || *(BYTE*)0x005B1AAB != 159 || *(BYTE*)0x005B1AAC != 255 || *(BYTE*)0x005B1AAD != 255
		|| *(BYTE*)0x005AC554 != 141 || *(BYTE*)0x005AC555 != 116 || *(BYTE*)0x005AC556 != 182 || *(BYTE*)0x005AC557 != 255 || *(BYTE*)0x005AC558 != 255
		|| *(BYTE*)0x0059D6AD != 141 || *(BYTE*)0x0059D6AE != 204 || *(BYTE*)0x0059D6AF != 239 || *(BYTE*)0x0059D6B0 != 255 || *(BYTE*)0x0059D6B1 != 255
		|| *(BYTE*)0x005AC22C != 141 || *(BYTE*)0x005AC22D != 252 || *(BYTE*)0x005AC22E != 190 || *(BYTE*)0x005AC22F != 255 || *(BYTE*)0x005AC230 != 255
		|| *(BYTE*)0x00534FD2 != 141 || *(BYTE*)0x00534FD3 == 144 || *(BYTE*)0x00534FD4 != 247 || *(BYTE*)0x00534FD5 != 255 || *(BYTE*)0x00534FD6 != 255
		|| *(BYTE*)0x0059DED9 != 141 || *(BYTE*)0x0059DEDA == 144 || *(BYTE*)0x0059DEDB != 239 || *(BYTE*)0x0059DEDC != 255 || *(BYTE*)0x0059DEDD != 255
		|| *(BYTE*)0x0059DC87 != 141 || *(BYTE*)0x0059DC88 == 144 || *(BYTE*)0x0059DC89 != 247 || *(BYTE*)0x0059DC8A != 255 || *(BYTE*)0x0059DC8B != 255
		//hetsum
		|| *(BYTE*)0x005B2C98 != 141 || *(BYTE*)0x005B2C99 != 108 || *(BYTE*)0x005B2C9A != 110 || *(BYTE*)0x005B2C9B != 255 || *(BYTE*)0x005B2C9C != 255
		//Rf damdat
		|| *(BYTE*)0x0059F471 != 141 || *(BYTE*)0x0059F472 != 36 || *(BYTE*)0x0059F473 != 191 || *(BYTE*)0x0059F474 != 255 || *(BYTE*)0x0059F475 != 255
		//vatnga
		|| *(BYTE*)0x005AF96D != 141 || *(BYTE*)0x005AF96E == 144 || *(BYTE*)0x005AF96F == 144 || *(BYTE*)0x005AF970 != 255 || *(BYTE*)0x005AF971 != 255
		//AALH1
		|| *(BYTE*)0x0059F211 != 141 || *(BYTE*)0x0059F212 != 68 || *(BYTE*)0x0059F213 != 199 || *(BYTE*)0x0059F214 != 255 || *(BYTE*)0x0059F215 != 255
		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 144 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		|| *(BYTE*)0x0050FB50 != 141 || *(BYTE*)0x0050FB51 == 90 || *(BYTE*)0x0050FB52 != 247 || *(BYTE*)0x0050FB53 != 255 || *(BYTE*)0x0050FB54 != 255
		//manhlong		
		|| *(BYTE*)0x0050F357 != 141 || *(BYTE*)0x0050F358 != 180 || *(BYTE*)0x0050F359 != 239 || *(BYTE*)0x0050F35A != 255 || *(BYTE*)0x0050F35B != 255

		//MG
		|| *(BYTE*)0x005ADE26 != 141 || *(BYTE*)0x005ADE27 != 116 || *(BYTE*)0x005ADE28 != 223 || *(BYTE*)0x005ADE29 != 255 || *(BYTE*)0x005ADE2A != 255
		|| *(BYTE*)0x005ADACC != 141 || *(BYTE*)0x005ADACD != 140 || *(BYTE*)0x005ADACE != 231 || *(BYTE*)0x005ADACF != 255 || *(BYTE*)0x005ADAD0 != 255
		|| *(BYTE*)0x005AE854 != 141 || *(BYTE*)0x005AE855 != 188 || *(BYTE*)0x005AE856 != 206 || *(BYTE*)0x005AE857 != 255 || *(BYTE*)0x005AE858 != 255
		//DL
		|| *(BYTE*)0x005AF1B1 != 141 || *(BYTE*)0x005AF1B2 != 92 || *(BYTE*)0x005AF1B3 != 166 || *(BYTE*)0x005AF1B4 != 255 || *(BYTE*)0x005AF1B5 != 255
		|| *(BYTE*)0x005AE1B5 != 141 || *(BYTE*)0x005AE1B6 != 236 || *(BYTE*)0x005AE1B7 != 214 || *(BYTE*)0x005AE1B8 != 255 || *(BYTE*)0x005AE1B9 != 255
		//saitama
		|| *(BYTE*)0x0064CF51 != 51 || *(BYTE*)0x0064CF52 != 1 || *(BYTE*)0x0064CF53 != 0 || *(BYTE*)0x0064CF54 != 0 	
		)

	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)0x00564D30 == 233)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if (*(BYTE *)0x0073A641 != 91 || *(BYTE *)0x0055D515 == 100 || *(BYTE *)0x0055D515 != 4)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if (*(BYTE*)(*(DWORD*)(0x7BC4F04) + 0x397) > 65)// loi khi su dung /Dance
	{
		MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 2", "[MuOnLine]", ERROR);	 //hithack ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
		return;
	}
	if (*(DWORD *)0x0054539E == 1166749052 || *(DWORD *)0x00545248 == 1300967031
		|| *(BYTE *)0x0054539E == 118 || *(BYTE *)0x0054539E == 124
		|| *(BYTE *)0x00545248 == 117 || *(BYTE *)0x00545248 == 119
		|| *(BYTE *)0x00545248 == 123 || *(BYTE *)0x0054539E != 117
		|| *(BYTE *)0x00545248 != 122 || *(BYTE *)0x005B5FFA == 233)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if (*(BYTE *)0x00561746 == 0 || *(BYTE *)0x00561746 != 1)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if (*(BYTE *)0x0065FC76 == 235 || *(BYTE *)0x0065FC76 != 117 || *(BYTE *)0x0064B04A == 0) //	Hoi sinh khi chet 
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(BYTE *)0x005DE16C != 102)
	{
		MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if ((*(BYTE *)0x006407C0 == 195)		//khang day lui ok
		/*|| (*(BYTE *)0x005528A0 == 195)*/	//khang sat thuong ok // offset xoa bo hieu ung phan chieu
		|| (*(BYTE *)0x00749A30 == 195)		//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 == 195)	// khang hieu ung xu ok
		|| (*(BYTE *)0x00596500 == 195)	// Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 == 195))	//khangtele dw ok
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 3", "[ElfCheat]", ERROR); // ok
		//		system("shutdown -s -t 0"); mo cai nay ra la xap nguon khi hack vao cai nay
		ExitProcess(0);
	}


	if ((*(BYTE *)0x006407C0 != 85)		//khang day lui ok
		/*|| (*(BYTE *)0x005528A0 != 85)*/	//khang sat thuong ok offset xoa bo hieu ung phan chieu
		|| (*(BYTE *)0x00749A30 != 236)		//khang sat thuong ok
		|| (*(BYTE *)0x004C8F00 != 85)	// khang hieu ung x?u ok
		|| (*(BYTE *)0x00596500 != 85)	// Xoa hoi chieu va noi luc
		|| (*(BYTE *)0x0057D760 != 85)	//khangtele dw ok  
		)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 4", "[ElfCheat]", ERROR); // ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0073A641 != 91 || *(BYTE *)0x0055D515 == 100 || *(BYTE *)0x0055D515 != 4)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 5", "[ElfCheat]", ERROR);	  //Evilhit ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(DWORD *)0x0054539E == 1166749052 || *(DWORD *)0x00545248 == 1300967031 || *(DWORD *)0x005965C8 <= 0 
		|| *(BYTE *)0x0054539E == 118 || *(BYTE *)0x0054539E == 124
		|| *(BYTE *)0x00545248 == 117 || *(BYTE *)0x00545248 == 119
		|| *(BYTE *)0x00545248 == 123 || *(BYTE *)0x0054539E != 117
		|| *(BYTE *)0x00545248 != 122 || *(BYTE *)0x005B5FFA == 233)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 7", "[ElfCheat]", ERROR);	  //?nh lin skill ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(DWORD *)0x005965C8 <= 0 || *(DWORD *)0x00895339 <= 10 /*|| *(DWORD *)0x08793738 < 10*/ )
	{
		MessageBoxA(NULL, "moi them hack", "[Cheat]", ERROR);	  //?nh lin skill ok
		ExitProcess(0);
	}
	


	if (*(BYTE *)0x00561746 == 0 || *(BYTE *)0x00561746 != 1)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 8", "[ElfCheat]", ERROR);	  //skill trong thanh ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x0065FC76 == 235 || *(BYTE *)0x0065FC76 != 117)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 9", "[ElfCheat]", ERROR);	  //godmode ok
		//		system("shutdown -s -t 0");
		ExitProcess(0);
	}

	if (*(BYTE *)0x005DE16C != 102)
	{
		ExitProcess(0);
	}

	if ((*(BYTE*)*(DWORD *)0x5B1705 == 10)			//quayrong
		|| (*(BYTE*)*(DWORD *)0x5A1792 == 10)		//danh thuong Dk
		|| (*(BYTE*)*(DWORD *)0x5AD81F == 10)		//xoay kiem
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)
		//----DW
		|| (*(BYTE*)*(DWORD *)0x59CED7 == 10)		//skill don
		|| (*(BYTE*)*(DWORD *)0x5B1CC6 == 10)		//muabangtuyet
		|| (*(BYTE*)*(DWORD *)0x5B0C02 == 10)		//Lua Dia Nguc
		|| (*(BYTE*)*(DWORD *)0x59D1DD == 10)		//muasaobang
		|| (*(BYTE*)*(DWORD *)0x5B1877 == 10)		//Kame
		|| (*(BYTE*)*(DWORD *)0x5B05C6 == 10)		//Nova
		|| (*(BYTE*)*(DWORD *)0x5B071D == 10)		//Nova1
		|| (*(BYTE*)*(DWORD *)0x5B1AA4 == 10)		//Cot lua
		//-------EFL
		|| (*(BYTE*)*(DWORD *)0x5AC54F == 10)		//Ngu Tien
		|| (*(BYTE*)*(DWORD *)0x59D6A8 == 10)		//Ban bang
		|| (*(BYTE*)*(DWORD *)0x5AC227 == 10)		//Buff mau
		//--------SUM
		|| (*(BYTE*)*(DWORD *)0x534FCD == 10)		//Skill sach
		|| (*(BYTE*)*(DWORD *)0x59DED4 == 10)		//Giat Set
		|| (*(BYTE*)*(DWORD *)0x59DC82 == 10)		//Hut Mau
		|| (*(BYTE*)*(DWORD *)0x5B2C93 == 10)		//Shok Dien
		//--------RF
		|| (*(BYTE*)*(DWORD *)0x59F46C == 10)		//Dm t
		|| (*(BYTE*)*(DWORD *)0x59F20C == 10)		//AALH
		//--------MG
		|| (*(BYTE*)*(DWORD *)0x5ADE21 == 10)		//C chm
		|| (*(BYTE*)*(DWORD *)0x5ADAC7 == 10)		//Chem Lua
		|| (*(BYTE*)*(DWORD *)0x5AE84F == 10)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)*(DWORD *)0x59C798 == 10)		//Quat xich
		|| (*(BYTE*)*(DWORD *)0x5AF1AC == 10)		//Hoa Am
		|| (*(BYTE*)*(DWORD *)0x5AE1B0 == 10)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))				//So lan Xdame	
	{
		//MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		system("shutdown -s -t 10");
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)(*(DWORD*)(0x0400000) + 0x00927C88) != 0)
	{
		//MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(DOUBLE*)0x00400020 > 0)
	{
		//MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if ((*(BYTE*)0x005B1705 != 106)			//quayrong
		|| (*(BYTE*)0x005A1792 != 106)		//danh thuong Dk
		|| (*(BYTE*)0x005AD81F != 106)		//xoay kiem
		|| (*(BYTE*)0x0059C798 != 106)
		//----DW
		|| (*(BYTE*)0x0059CED7 != 106)		//skill don
		|| (*(BYTE*)0x005B1CC6 != 106)		//muabangtuyet
		|| (*(BYTE*)0x005B0C02 != 106)		//Lua Dia Nguc
		|| (*(BYTE*)0x0059D1DD != 106)		//muasaobang
		|| (*(BYTE*)0x005B1877 != 106)		//Kame
		|| (*(BYTE*)0x005B05C6 != 106)		//Nova
		|| (*(BYTE*)0x005B071D != 106)		//Nova1
		|| (*(BYTE*)0x005B1AA4 != 106)		//Cot lua
		//-------EFL
		|| (*(BYTE*)0x005AC54F != 106)		//Ngu Tien
		|| (*(BYTE*)0x0059D6A8 != 106)		//Ban bang
		|| (*(BYTE*)0x005AC227 != 106)		//Buff mau
		//--------SUM
		|| (*(BYTE*)0x00534FCD != 106)		//Skill sach
		|| (*(BYTE*)0x0059DED4 != 106)		//Giat Set
		|| (*(BYTE*)0x0059DC82 != 106)		//Hut Mau
		|| (*(BYTE*)0x005B2C93 != 106)		//Shok Dien
		//--------RF
		|| (*(BYTE*)0x0059F46C != 106)		//Dm t
		|| (*(BYTE*)0x0059F20C != 106)		//AALH
		//--------MG
		|| (*(BYTE*)0x005ADE21 != 106)		//C chm
		|| (*(BYTE*)0x005ADAC7 != 106)		//Chem Lua
		|| (*(BYTE*)0x005AE84F != 106)		//Hoa Diem
		//--------DL
		|| (*(BYTE*)0x0059C798 != 106)		//Quat xich
		|| (*(BYTE*)0x005AF1AC != 106)		//Hoa Am
		|| (*(BYTE*)0x005AE1B0 != 106)		//Hon loan
		|| (*(BYTE *)0x00400354 != 0))		//So lan Xdame
	{
		//MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)0x004DA3E4 != 139 || *(BYTE*)0x004DA3E9 != 255)
	{
		//MessageBoxA(NULL, "Phat hien nghi van hach", "[MuOnLine]", ERROR);	  //hack speed
		ExitProcess(0);
		return;
	}
	if (*(BYTE*)0x00596343 == 233)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 17", "[ElfCheat]", ERROR);	//hack danh xa
		ExitProcess(0);
		return;
	}

	if (*(BYTE*)0x0054539E != 117 || *(BYTE*)0x004DA3E9 == 124)
	{
		//MessageBoxA(NULL, "Khuyen ban khong gian lan khi choi game! 160", "[ElfCheat]", ERROR);	// loai bo hanh dong
		ExitProcess(0);
		return;
	}

	if (*(BYTE *)0x004DA3E0 != 40)
	{
		MessageBoxA(NULL, "Speed-Hack Detected.", "[MUONLINE]", ERROR);
		ExitProcess(0);
	}


	//---------------------------------------------------------
	//-- Advance Status Custom Low Interfaces
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		if(gProtect.m_MainInfo.DisableAdvance == 0)
		{
			g_StatsAdvance.DrawInfo();
		}
	}
	//--

	//--Bar MiniMap
	if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
	if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
	{
			gInterface.MiniMapMini();
		}
	}
	//--
	//--Bar Pet
	///*if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 || gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	//{
	//	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535)
	//	{
	//		gCRenderEx700.BarPetMuun();
	//	}
	//}*/
	

	//gInterface.BarPartyNew();

	//--
	gObjUser.Refresh();
	//char windowtext[500];
	//sprintf_s(windowtext, sizeof(windowtext), " %s | Name: %s | Level: %d | Reset: %d | WcoinC: %d | WcoinP: %d | Goblin Points: %d ", gProtect.m_MainInfo.WindowName, gObjUser.lpPlayer->Name, gObjUser.lpPlayer->Level, ViewReset, Coin1, Coin2, Coin3);
	//SetWindowText(pGameWindow, windowtext);

	jCRenderRuud.CheckOpen();
	
	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;
		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}else
	{
		gInterface.PetX = 0;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{	gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}

	gInterface.DrawMiniMap();

	if (gProtect.m_MainInfo.CustomInterfaceType == 0)
	{
		//gInterface.DrawTimeUI();
	}

	gCustomRanking.DrawRankPanelWindow();

	gCustomEventTime.DrawEventTimePanelWindow();
	
	ReconnectMainProc();

	gCustomJewelBank.DrawJewelBankWindow();

	gInterface.TvTEvent();

	// Leo thap
	gInterface.DrawLeoThap();
	gLeoThap.LeoThapCountdown();
	gLeoThap.LeoThapDelayTime();

	gInterface.DrawTiecRuouWindow();
	gInterface.DrawEventTiecRuou();
	gInterface.DrawMoiRuouWindow();

#if(MENU_NEW)
	gInterface.DrawMenuWindow();
#endif
if( gProtect.m_MainInfo.Disablevongquay == 0 )
{

}
#if(VONGQUAY_NEW)
gLuckySpin.Draw();
#endif

#if (SHOPSEARCH)
	g_PersonalShopEx.Draw();
#endif
	G_BEXO_HE_THONG.DRAW_HE_THONG();

	//G_BEXO_THUONG_GIA.DRAW_THUONG_GIA();

	gInterface.DrawMenu();
	
	gInterface.DrawAutoReset();

	gInterface.DrawAttack();

	gInterface.DrawConfirmOpen();

	gNewInterface.Work();

	gGrandResetSystem.draw_grand_reset_system();

	gResetSystem.draw_reset_system();

	gInterface.DrawChangingClassWindow();

	gInterface.DrawWarehouseWindow();

	gInterface.DrawStatsAddWindow();

	gInterface.DrawCTCMiNiMap(); //LOad de draw

	gInterface.DrawCTCMiniWindow();//LOad de draw

	#if(CHIEN_TRUONG_CO)
	gInterface.DrawChienTruongCo();
	gInterface.DrawTimeCTC();
#endif

	//gInterface.DrawTextTTTTTT();

	gInterface.WindowsKG();

	if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}

	pDrawInterface();


	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			gInterface.DrawInterface97Menu();
		}
		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			gInterface.DrawInterfaceS2Menu();
		}
	}
	//========DRAW WINDOW
	//============
	if (GetForegroundWindow() == pGameWindow)
	{
		if (GetKeyState(VK_SNAPSHOT) < 0)
		{
			gInterface.DrawLogo(1);
		}

#if(OANTUTY)
	gInterface.DrawRPS();
#endif
		if (GetKeyState('H') & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow)&& !gInterface.CheckWindow(ObjWindow::Guild))
			{
			gCustomEventTime.OpenWindow();
			}
		}

		if (GetKeyState(VK_F5) & 0x4000) 
		{
			
			if((GetTickCount()-gInterface.Data[eMENU_MAIN].EventTick) > 300)
			{
				if (gInterface.CHECK_MENU())
				{
					gInterface.Data[eMENU_MAIN].EventTick = GetTickCount();
					gInterface.CLOSE_MENU();
				}
				else
				{
					gInterface.Data[eMENU_MAIN].EventTick = GetTickCount();
					gInterface.CLOSE_MENU();
					gInterface.SwitchMenuWindowState();
				}
			}
		}
		
		if (GetKeyState('O') & 0x4000) 
		{
		if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow)&& !gInterface.CheckWindow(ObjWindow::Guild))
			{
			      if (MinimizarOfRank == 0)
			      {
			           MinimizarOfRank = 1;
			      }
			     else
			       {
			            MinimizarOfRank = 0;  
			       }
			 }
		}

		if( GetForegroundWindow() == pGameWindow )
	         {
	         
	         	if (GetKeyState('L') & 0x4000) 
	         	{
	         		gInterface.OpenConfig2(0);
	         	}
	         }

		if (GetKeyState(VK_END) <0 ) 
		{
			{		
				gObjUser.ToggleAuto();
			}
		}

		if (GetKeyState(VK_INSERT) <0 ) 
		{
			{		
				gObjUser.ToggleAutoTron();
			}

		}

		if (GetKeyState('J') & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow)&& !gInterface.CheckWindow(ObjWindow::Guild))
			{
			gCustomJewelBank.OpenWindow();
			}
		}

		if (GetKeyState(VK_F6) & 0x4000) 
		{
			gInterface.SwitchChatExpand();

		}
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			gCustomRanking.OpenWindow();
		}

		if (GetKeyState('N') & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow)&& !gInterface.CheckWindow(ObjWindow::Guild))
			{
			gNewsBoard.ReqOpenMain();	
			}
		}

		if (GetKeyState(VK_F10) & 0x4000) 
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000) 
		{
			gInterface.CameraInit();
		}
		if (GetKeyState(VK_F12) & 0x4000) 
		{
			if( gTrayMode.TempWindowProc == NULL )
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}

		if (GetKeyState('S') & 0x4000  && GetTickCount() >= g_PersonalShopEx.OpenStoreSearchDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow)&& !gInterface.CheckWindow(ObjWindow::Guild))
			{
				if (g_PersonalShopEx.CheckStoreWindow())
				{
					g_PersonalShopEx.CloseStoreWindow();
					pSetCursorFocus = false;
				}
				else
				{
					g_PersonalShopEx.OpenStoreWindow();
					pSetCursorFocus = true;
				}
				g_PersonalShopEx.OpenStoreSearchDelay = GetTickCount();
			}
		}


		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 0 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.Data[eMENU_MAIN].OnShow == true)
			{
				gInterface.Data[eMENU_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 0 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.Data[eRankPANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 0 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				
	if(gProtect.m_MainInfo.CustomInterfaceType != 0 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
			}

		}
	}

//	gCRuudShop.RuudShop();

	gInterface.DrawLogo(0);

	#if(PARTYSEARCH==1)
		gPartySearch.DrawPartySearchWindow();
		gPartySearch.DrawPartySettingsWindow();
		gPartySearch.draw_party_password();
	#endif
		//tueadd
		float x2 = 230.0f;
		float y2 = 340.0f;
		float w2 = 180.0;
		float h2 = 80.0;
		RenderBitmap(12359, x2, y2, w2, h2, 0, 0, 1, 1, 1, 1, 1.5);
		//pDrawGUI(12359, x2, y2, w2, h2);
		//print to screen 
		gInterface.DrawFormat(eGold, 5.0f, 320.0f, 25.0f, 0, "** Phát hiện hack, Zalo Admin nhận thưởng: (+84)813.583.027 **");
		//gInterface.DrawFormat(eGold150, 5.0f, 315.0f, 25.0f, 0, "* Các Lệnh thường dùng: /tanthu, /reset, /taydiem ...");
		//endadd-----
		//tue add facebook Zalo button
		gInterface.DrawShowIcon();
		//timer server 
		gInterface.DrawTimeUI();
		//----
		//tue add 
		gPostInterface.Work2();
		//gInterface.UPDATE_FPS();
		//gInterface.SendPingRecv();
		//gInterface.DrawPing();
		//----
		//-----
		
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, "MiniMap Window [OFF]");
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "MiniMap Window [ON]");
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

//void Interface::DrawTimeUI()
//{
//		//---
//	//-- Time Bar Custom
//	if(TimerBar == 0
//		|| (this->CheckWindow(ObjWindow::CashShop) 
//		//|| this->CheckWindow(ObjWindow::FriendList)
//		|| this->CheckWindow(ObjWindow::MoveList)
//		//|| this->CheckWindow(ObjWindow::Party)
//		//|| this->CheckWindow(ObjWindow::Quest)
//		//|| this->CheckWindow(ObjWindow::NPC_Devin)
//		//|| this->CheckWindow(ObjWindow::Guild)	
//		//|| this->CheckWindow(ObjWindow::Trade)
//		//|| this->CheckWindow(ObjWindow::Warehouse)
//		//|| this->CheckWindow(ObjWindow::ChaosBox)
//		//|| this->CheckWindow(ObjWindow::CommandWindow)
//		//|| this->CheckWindow(ObjWindow::PetInfo)
//		|| this->CheckWindow(ObjWindow::Shop)
//		//|| this->CheckWindow(ObjWindow::Inventory)
//		//|| this->CheckWindow(ObjWindow::Store)
//		//|| this->CheckWindow(ObjWindow::OtherStore)
//		|| this->CheckWindow(ObjWindow::Character)
//		//|| this->CheckWindow(ObjWindow::DevilSquare)
//		//|| this->CheckWindow(ObjWindow::BloodCastle)
//		//|| this->CheckWindow(ObjWindow::CreateGuild)
//		//|| this->CheckWindow(ObjWindow::GuardNPC)
//		//|| this->CheckWindow(ObjWindow::SeniorNPC)
//		//|| this->CheckWindow(ObjWindow::GuardNPC2)
//		//|| this->CheckWindow(ObjWindow::CastleGateSwitch)
//		//|| this->CheckWindow(ObjWindow::CatapultNPC)
//		//|| this->CheckWindow(ObjWindow::CrywolfGate)
//		//|| this->CheckWindow(ObjWindow::IllusionTemple)
//		//|| this->CheckWindow(ObjWindow::HeroList)
//	    //|| this->CheckWindow(ObjWindow::ChatWindow)
//		//|| this->CheckWindow(ObjWindow::FastMenu)
//		//|| this->CheckWindow(ObjWindow::Options)	
//		|| this->CheckWindow(ObjWindow::Help)
//		//|| this->CheckWindow(ObjWindow::FastDial)
//		|| this->CheckWindow(ObjWindow::SkillTree)
//		//|| this->CheckWindow(ObjWindow::GoldenArcher1)
//		//|| this->CheckWindow(ObjWindow::GoldenArcher2)
//		//|| this->CheckWindow(ObjWindow::LuckyCoin1)
//		//|| this->CheckWindow(ObjWindow::LuckyCoin2)
//		//|| this->CheckWindow(ObjWindow::NPC_Duel)
//		//|| this->CheckWindow(ObjWindow::NPC_Titus)
//		|| this->CheckWindow(ObjWindow::CashShop)
//		|| this->CheckWindow(ObjWindow::Lugard)
//		//|| this->CheckWindow(ObjWindow::QuestList1)
//		//|| this->CheckWindow(ObjWindow::QuestList2)
//		|| this->CheckWindow(ObjWindow::Jerint)
//		|| this->CheckWindow(ObjWindow::FullMap)
//		|| this->CheckWindow(ObjWindow::NPC_Dialog)
//		//|| this->CheckWindow(ObjWindow::GensInfo)
//		|| this->CheckWindow(ObjWindow::NPC_Julia)
//		|| this->CheckWindow(ObjWindow::NPC_ChaosMix)
//		//|| this->CheckWindow(ObjWindow::ExpandInventory)
//		//|| this->CheckWindow(ObjWindow::ExpandWarehouse)
//		//|| this->CheckWindow(ObjWindow::MuHelper)
//		|| pMapNumber == 34 
//		|| pMapNumber == 30 ))
//	{
//		return;
//	}
//	if (jCRenderRuud.OpeningRuud)
//	{
//		return;
//	}
//	//--
//	time_t TimeServer;
//	struct tm * ServerT;
//	time(&TimeServer);
//	// ----
//	ServerT = gmtime(&TimeServer);
//	// ----
//	char ServerTime[30];
//
//	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT)%24, ServerT->tm_min, ServerT->tm_sec);
//	// -----
//	pSetBlend(true);
//	glColor4f(1.0, 1.0, 1.0, 1.0);
//	if(gProtect.m_MainInfo.MuHelperType == 0)
//	{
//		if(gProtect.m_MainInfo.DisableHelper == 0)
//		{
//		RenderBitmap(0x7879, ReturnX(TransForX(42)), ReturnY(TransForY(16)), ReturnX(TransForX(80)), ReturnY(TransForY(20)), 0, 0, 0.821, 0.751, 0.8, 1, 0); //TimeBar
//		this->DrawFormat(eWhite, ReturnX(TransForX(63)), ReturnY(TransForY(19)), ReturnX(TransForX(100)), ReturnY(TransForY(1)), ServerTime);
//		}
//	}
//	else if(gProtect.m_MainInfo.MuHelperType == 1)
//	{
//		if(gProtect.m_MainInfo.DisableHelper == 0)
//		{
//		RenderBitmap(0x7878, ReturnX(TransForX(24)), ReturnY(TransForY(18)), ReturnX(TransForX(80)), ReturnY(TransForY(20)), 0, 0, 0.821, 0.751, 0.8, 1, 0); //TimeBar ex700
//		this->DrawFormat(eWhite, ReturnX(TransForX(40)), ReturnY(TransForY(20)), ReturnX(TransForX(100)), ReturnY(TransForY(1)), ServerTime);
//		}
//	}
//	// ----
//	pGLSwitchBlend();
//	pGLSwitch();
//	pSetBlend(false);
//}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;

}
bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

#if(OFFLINE_MODE_NEW>1  )
void Interface::DrawColoredButton4(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	 ----
	pDrawColorButton2(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx4(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	 ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	 ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char * Line = strtok(Buff2, "\n");
	 ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 0.8);
	pDrawBarForm(PosX - 10, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);

	this->DrawFormat(eYellow170, PosX, PosY, Width, Align, Buff);
	return 0;
}

bool Interface::IsWorkZone4(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

#endif
bool Interface::IsWorkZone5(float X, float Y, float MaxX, float MaxY,bool f)
{
	if (f == 0)
	{
		X = ::GetResizeX<float>(X);
		Y = ::GetResizeY<float>(Y);
		MaxX = ::GetResizeX<float>(MaxX);
		MaxY = ::GetResizeY<float>(MaxY);
	}

	return (float)gObjUser.m_CursorX >= X && (float)gObjUser.m_CursorY >= Y && (float)gObjUser.m_CursorX <= X+MaxX && (float)gObjUser.m_CursorY <= Y+MaxY;
}
bool Interface::IsWorkZone3(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}

bool Interface::IsWorkZone4(short ObjectID,float X, float Y, float MaxX, float MaxY)
{
	float Z = this->Data[ObjectID].MaxY;
	if( (pCursorX < X || pCursorX > this->Data[ObjectID].MaxX - (gInterface.CheckWindow(ObjWindow::Character)?MaxX:0)) || (pCursorY > Y || pCursorY > this->Data[ObjectID].MaxY || pCursorY < ( Z - MaxY) ))
		return false;
	
	return true;
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}
float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y,float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY,ScaleX,ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}



//=========================================================================================================================================
//=========================================================================================================================================
#if(MENU_NEW)
void Interface::DrawMenuWindow()
{

	if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(Inventory) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse))
		return;

	if (!this->Data[eMENU_MAIN].OnShow)
	{
		return;
	}

	if (this->Data[eMENU_MAIN].ByClose == false)
	{
		if (this->Data[eMENU_MAIN].OpenedValue < 0)
		{
			this->Data[eMENU_MAIN].OpenedValue += this->Data[eMENU_MAIN].Speed;

			if (this->Data[eMENU_MAIN].OpenedValue >= -150)
			{
				this->Data[eMENU_MAIN].Speed = 15;
			}

			if (this->Data[eMENU_MAIN].OpenedValue > 0)
			{
				this->Data[eMENU_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (this->Data[eMENU_MAIN].OpenedValue > -226)
		{
			this->Data[eMENU_MAIN].OpenedValue -= this->Data[eMENU_MAIN].Speed;

			if (this->Data[eMENU_MAIN].OpenedValue <= -150)
			{
				this->Data[eMENU_MAIN].Speed = 20;
			}

			if (this->Data[eMENU_MAIN].OpenedValue <= -226)
			{
				this->Data[eMENU_MAIN].Close();

			}
		}
	}

	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = this->Data[eMENU_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//---------------------------------------------------------------------------------------//
	//this->DrawAnimatedGUI(eMENU_MAIN, StartX, StartY - 177);
	//---------------------------------------------------------------------------------------//
	if (this->IsWorkZone(eMENU_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	//gCItemSetOption.ItemTooltipS15(StartX + 0, this->Data[eMENU_MAIN].Y + 80, 140, 330, 0.0, 0);

	RenderBitmap(500001,StartX + 0, this->Data[eMENU_MAIN].Y + 80, 0, 330, 0, 0, 1, 1, 1, 1, 0.0);

	//gCItemSetOption.ItemTooltipS15(StartX + 10, this->Data[eMENU_MAIN].Y + 90, 120, 310, 0.0, 0);
	//---------------------------------------------------------------------------------------//
	this->DrawAnimatedGUI(eBUTTON_MENU_1, StartX + 17, this->Data[eMENU_MAIN].Y +  100);
	this->DrawAnimatedGUI(eBUTTON_MENU_2, StartX + 17, this->Data[eMENU_MAIN].Y +  129);
	this->DrawAnimatedGUI(eBUTTON_MENU_3, StartX + 17, this->Data[eMENU_MAIN].Y +  158);
	this->DrawAnimatedGUI(eBUTTON_MENU_4, StartX + 17, this->Data[eMENU_MAIN].Y +  187);
	if( gProtect.m_MainInfo.Disablevongquay == 0 )
	{
	//this->DrawAnimatedGUI(eBUTTON_MENU_5, StartX + 17, this->Data[eMENU_MAIN].Y +  216);
	}
	this->DrawAnimatedGUI(eBUTTON_MENU_6, StartX + 17, this->Data[eMENU_MAIN].Y +  216);
	//this->DrawAnimatedGUI(eBUTTON_MENU_7, StartX + 17, this->Data[eMENU_MAIN].Y +  274);
	this->DrawAnimatedGUI(eBUTTON_MENU_8, StartX + 17, this->Data[eMENU_MAIN].Y +  245);
	this->DrawAnimatedGUI(eBUTTON_MENU_9, StartX + 17, this->Data[eMENU_MAIN].Y +  274);
	this->DrawAnimatedGUI(eBUTTON_MENU_10, StartX + 17, this->Data[eMENU_MAIN].Y + 303);
	//---------------------------------------------------------------------------------------//
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 110, 210, 3, gOther.TextVN[1]);
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 139, 210, 3, gOther.TextVN[2]);
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 168, 210, 3, gOther.TextVN[3]);
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 197, 210, 3, gOther.TextVN[4]);
	if( gProtect.m_MainInfo.Disablevongquay == 0 )
	{
	//this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 226, 210, 3, gOther.TextVN[5]);
	}
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 226, 210, 3, gOther.TextVN[9]);
	//this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 284, 210, 3, "MOCNAP");
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 255, 210, 3, "Quản Lý Tài Khoản");
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 284, 210, 3, gOther.TextVN[22]);
	this->DrawFormat(eWhite, StartX - 35, this->Data[eMENU_MAIN].Y + 313, 210, 3, gOther.TextVN[23]);
	//---------------------------------------------------------------------------------------//
	// Hiển thị màu khi click vào nút button
	if (this->IsWorkZone(eBUTTON_MENU_1))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_1, this->Data[eBUTTON_MENU_1].X, this->Data[eBUTTON_MENU_1].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_2))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_2, this->Data[eBUTTON_MENU_2].X, this->Data[eBUTTON_MENU_2].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_3))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_3, this->Data[eBUTTON_MENU_3].X, this->Data[eBUTTON_MENU_3].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_4))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_4, this->Data[eBUTTON_MENU_4].X, this->Data[eBUTTON_MENU_4].Y, Color);
	}
	if( gProtect.m_MainInfo.Disablevongquay == 0 )
	{
	if (this->IsWorkZone(eBUTTON_MENU_5))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_5, this->Data[eBUTTON_MENU_5].X, this->Data[eBUTTON_MENU_5].Y, Color);
	}
	}
	if (this->IsWorkZone(eBUTTON_MENU_6))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_6, this->Data[eBUTTON_MENU_6].X, this->Data[eBUTTON_MENU_6].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_7))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_7, this->Data[eBUTTON_MENU_7].X, this->Data[eBUTTON_MENU_7].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_8))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_8, this->Data[eBUTTON_MENU_8].X, this->Data[eBUTTON_MENU_8].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_9))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_9, this->Data[eBUTTON_MENU_9].X, this->Data[eBUTTON_MENU_9].Y, Color);
	}
	if (this->IsWorkZone(eBUTTON_MENU_10))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eBUTTON_MENU_10, this->Data[eBUTTON_MENU_10].X, this->Data[eBUTTON_MENU_10].Y, Color);
	}
	//--------------------------------------------------------------------------------------------------------------
	if (this->Data[eMENU_MAIN].FirstLoad == true)
	{
		this->Data[eMENU_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------
void Interface::EventMenuWindow(DWORD Event)
{
	this->EventMenuWindow_Close(Event);

	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_1].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_1].EventTick = GetTickCount();
		// ----
		gCustomRanking.OpenWindow();
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
//	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_2].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_2].EventTick = GetTickCount();
		// ----
#if(OFFLINE_MODE_NEW)
		this->SwitchOffExpWindoState();
#endif
		
		//gCustomEventTime.OpenWindow();
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
//	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_3].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_3].EventTick = GetTickCount();
		// ----cho nay la tao parrty

		
			if (GetForegroundWindow() == pGameWindow)
			{
				gPartySearch.OpenWindow();
			}

		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
//	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_4].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_4].EventTick = GetTickCount();
		// ----cho nay la tim
		if (GetForegroundWindow() == pGameWindow)
		{
			UP_PARTYSEARCH_REQ pMsg;
			pMsg.h.set(0xF3, 0x25, sizeof(pMsg));
			DataSend((BYTE*)&pMsg, pMsg.h.size);
		
		}
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
	if( gProtect.m_MainInfo.Disablevongquay == 0 )
	{
//	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_5].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_5].EventTick = GetTickCount();
		// ----
#if(VONGQUAY_NEW)
		gLuckySpin.SwitchLuckySpinWindowState();
#endif

		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
	}
	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_7))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_7].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_7].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_7].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_7].EventTick = GetTickCount();
		// ----
		// ----
//		this->BUY_QUEST(15);
		//G_BEXO_MOCNAP.OPEN_WINDOW_MOCNAP();
		gInterface.BUY_TINH_NANG_GAME(19); // Update
		gInterface.BUY_TINH_NANG_GAME(33); // Update
		gInterface.BUY_TINH_NANG_GAME(35); // Update
		gInterface.BUY_TINH_NANG_GAME(37); // Update
		// ----
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
//	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_8))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_8].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_8].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_8].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_8].EventTick = GetTickCount();
		// ----
		
		G_QUAN_LY_TK.OPEN_WINDOW_QUAN_LY_TK();
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_9))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_9].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_9].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_9].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_9].EventTick = GetTickCount();
		// ----
		gInterface.Data[eCHANGINGCLASS_MAIN].Open();
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
	//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_10))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_10].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_10].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_10].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_10].EventTick = GetTickCount();
		// ----
		G_BEXO_HE_THONG.OPEN_WINDOW_HE_THONG();
		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}


//------------------------------------------------------------------------------
	if (gInterface.Data[eMENU_MAIN].OnShow && gInterface.IsWorkZone(eBUTTON_MENU_6))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eBUTTON_MENU_6].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eBUTTON_MENU_6].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		gInterface.Data[eBUTTON_MENU_6].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eBUTTON_MENU_6].EventTick = GetTickCount();
		// ----
		gCustomJewelBank.OpenWindow();

		// ----
		Data[eMENU_MAIN].CloseAnimated(15);
	}
//	//------------------------------------------------------------------------------
//
	return;
}
//----------------------------------------------------------------//
void Interface::EventMenuWindow_Close(DWORD Event)
{
	if (!this->Data[eMENU_MAIN].OnShow)
	{
		return;
	}
	DWORD CurrentTick = GetTickCount();

	if (IsWorkZone(eMENU_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eMENU_CLOSE].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eMENU_CLOSE].OnClick = true;
			return;
		}
		this->Data[eMENU_CLOSE].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eMENU_CLOSE].EventTick = GetTickCount();
		Data[eMENU_MAIN].CloseAnimated(15);
	}
	return;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================



void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 100)
	{
		return false;
	}
	
	// ----
		this->Data[eMenu].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		this->SwitchMenuWindowState();
	}
	// ----

	// ----
	return false;
}

void Interface::DrawAutoReset()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eAUTORESET].OnShow)
	{
		this->Data[eAUTORESET].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList)
		|| this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}
	//if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	//{
	//if (pCheckMouseOver(285, 420, 43, 17))
	//	{
	//		pSetCursorFocus = true;
	//	}
	//	if (pCheckMouseOver(285, 420, 43, 17))

	//		gInterface.DrawGUI(eAUTORESET, 285, 420);

	//	if (CheckButtonPressed( 285,  420, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	//	{
	//		RenderBitmap(61535, 285, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	//	}
	//	else
	//	{
	//		RenderBitmap(61535, 285, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	//	}
	//	gInterface.DrawFormat(eWhite, 290, 423, 210, 1, gOther.TextVN[138]); // Auto Reset
	//	//--------------------------------------------------------------------------------------------
	//}
	this->Data[eAUTORESET].OnShow = true;

		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_YELLOW);
	    g_pRenderText.RenderText(5, 390, "• HƯỚNG DẪN : Phím (N) • ẨN DANH HIỆU : Phím (O)•", 208, 0, RT3_SORT_LEFT);

		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_WHITE);
	    g_pRenderText.RenderText(5, 400, "• /reset auto , /nv3 , /taymt ( tẩy master ) •", 208, 0, RT3_SORT_LEFT);
	
		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_ORANGE);
	    g_pRenderText.RenderText(5, 410, "• /taydiem , /xoado  , /xoatoi •", 208, 0, RT3_SORT_LEFT);
	

		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_GREEN);
	    g_pRenderText.RenderText(5, 420, "• Menu Game (Phím F5)-Ngân Hàng Ngọc (Phím J)•", 208, 0, RT3_SORT_LEFT);
	

		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_BR_BLUE);
	    g_pRenderText.RenderText(5, 430, "• Event Time (Phím H)-Tìm Kiếm Mua Đồ (Phím S) •", 208, 0, RT3_SORT_LEFT);
	

		g_pRenderText.SetFont(g_hFontBold);
	    g_pRenderText.SetBgColor(0);
	    g_pRenderText.SetTextColor(CLRDW_BR_OCHER);
	    g_pRenderText.RenderText(5, 440, "•Xem Top All (Phím F8) - Zoom Cam (Phím F10)•", 208, 0, RT3_SORT_LEFT);
	
	gRenderMap.AutoSendMove();
}

bool Interface::EventDrawAutoReset_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eAUTORESET].EventTick);
	// ----
	if (!this->Data[eAUTORESET].OnShow || !IsWorkZone(eAUTORESET))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eAUTORESET].OnClick = true;
		return true;
	}
	// ----
	this->Data[eAUTORESET].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eAUTORESET].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		this->BUY_TINH_NANG_GAME(5);
	}
	return false;
}

void Interface::DrawAttack()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eATTACK].OnShow)
	{
		this->Data[eATTACK].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Character))
		|| (this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)))
	{
		return;
	}

	this->Data[eATTACK].OnShow = true;	
		//--------------------------------------------------------------------------------------------
	//if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	//{
	//	if (pCheckMouseOver(325, 420, 43, 17))
	//	{
	//		pSetCursorFocus = true;
	//	}
	//	if (pCheckMouseOver(325, 420, 43, 17))

	//		gInterface.DrawGUI(eATTACK, 325, 420);

	//	if (CheckButtonPressed(325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	//	{
	//		RenderBitmap(61535, 325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	//	}
	//	else
	//	{
	//		RenderBitmap(61535, 325, 420, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	//	}
	//	gInterface.DrawFormat(eWhite, 330, 423, 210, 1, gOther.TextVN[139]); // Tự đánh
	////	//--------------------------------------------------------------------------------------------
	////	//=======================================================
	//}
}

bool Interface::EventDrawAttack_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eATTACK].EventTick);
	// ----
	if (!this->Data[eATTACK].OnShow || !IsWorkZone(eATTACK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{

		if (gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		this->Data[eATTACK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eATTACK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}

	// ----
	this->Data[eATTACK].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		this->BUY_TINH_NANG_GAME(6);
	}

	return false;
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

/*bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Stadium:
			return false;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}*/

void Interface::CloseCustomWindow()
{
	//tue add Tu Chan //////////////////
	this->Data[SPK_Ranking_Main].OnShow = false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow = false;

	this->Data[eWindow_NangCapHonHoan].OnShow = false;
	this->Data[eWindow_NangCapDanhHieu].OnShow = false;
	this->Data[eWindow_NangCapQuanHam].OnShow = false;
	this->Data[eWindow_NangCapTuChan].OnShow = false;
	this->Data[eChangePass_Main].OnShow = false;
	/////////////////////////////////////
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
		this->Data[eEventTimePANEL_MAIN].OnShow = false;
	//this->Data[eCommand_MAIN].OnShow		= false;
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

#if(VONGQUAY_NEW)

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	//float X = ull_to_float2(*(QWORD*)0xE61E58);
	//float Y = ull_to_float2(*(QWORD*)0xE61E58+1);

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	//float v2 = (X / (Y / 100.0f)) / 100.0f;//(*(float*)MAIN_RESOLUTION_X / (*(float*)MAIN_RESOLUTION_Y / 100.0f)) / 100.0f;
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();


	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	//sub_637770_Addr();

	glColor3f(1, 1, 1);
	pSetBlend(false);
}
#endif

bool Interface::DrawItem3(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, char ScaleUp, float ScaleX, float ScaleY){
	pSetBlend(true);
    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();
    sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
    sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();
    sub_635830_Addr((LPVOID)0x87933A0);
    sub_635DE0_Addr();
    sub_635E40_Addr();
    pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, ScaleUp);
    testfunc();
    glColor3f(1,1,1);
    pSetBlend(false);
	if (pCursorX <= PosX + Width&& pCursorX >= PosX&& pCursorY <= PosY + Height && pCursorY >= PosY){
		return true;
	}
	return false;
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		// ----
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		// ----
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}

}


bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	// ----
	return false;
}

//-- advance
void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}

//---- cosas peladas

void Interface::UPDATE_FPS(){
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}

	this->DrawFormat(eGold, 600, 5, 80, 1, gInterface.FPS_REAL);
}

void Interface::guiMonitore(){
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(460.0, 0.0, 180.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::DrawPing()
{
	gInterface.msPing = GetTickCount() - gInterface.lastSend;
	gInterface.iniciador = 3;
}

struct PMSG_PING
{
	PBMSG_HEAD h;
};

void Interface::SendPingRecv()
{
	if(gInterface.iniciador == 1)
	{
		PMSG_PING pMsgPing;
		pMsgPing.h.set(0x80,sizeof(pMsgPing));
		gInterface.lastSend = GetTickCount();
		DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
		gInterface.iniciador=2;
	}
	else if(gInterface.iniciador == 3)
	{
		if (GetTickCount() >= gInterface.lastSend + 1000){
			PMSG_PING pMsgPing;
			pMsgPing.h.set(0x80,sizeof(pMsgPing));
			gInterface.lastSend = GetTickCount();
			DataSend((BYTE*)&pMsgPing,sizeof(pMsgPing));
			gInterface.iniciador=2;
		}
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(MoveList) || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	sprintf(gInterface.ServerRTT, "RTT: %d ms", gInterface.msPing);
	sprintf(gInterface.ServerPing, "PING: %d ms", (gInterface.msPing/2));
	// ----
	gInterface.validar=0;

	if(gInterface.msPing > 0){
		//----
		this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
		this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		//--
		sprintf(gInterface.ultimoRTT, gInterface.ServerRTT);
		sprintf(gInterface.ultimoPing, gInterface.ServerPing);
		//--
		gInterface.ultimo_RTT = gInterface.msPing;
		gInterface.validar=1;
	}

	if(gInterface.validar==0)
	{
		if(gInterface.ultimo_RTT > 0)
		{
			this->DrawFormat(eGold, 470, 5, 80, 1, gInterface.ultimoRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ultimoPing);
		}
		else
		{
			this->DrawFormat(eGold, 470, 5, 120, 1, gInterface.ServerRTT);
			this->DrawFormat(eGold, 530, 5, 120, 1, gInterface.ServerPing);
		}
	}
}

void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, "Chat Window Separate [OFF]");
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, "Chat Window Separate [ON]");
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
	gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type = 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
//-- SwitchCamera
void Interface::SwitchCamera()
{
	if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
	{
		return;
	}

	if( pMapNumber == 62 )
	{
		gInterface.DrawMessage(1, "Camera3D not available for this map");
		gCamera.Restore();
	}

	gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

	gCamera.Toggle();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera3D [ON]");
	}
	else
	{
		gInterface.DrawMessage(1, "Camera3D [OFF]");
	}
}
//-- CameraInit
void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, "Camera Restore [DEFAULT]");
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory))
		{
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList))
		{
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild))
		{
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawInterfaceDragonLS3()
{
	/*if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		|| this->Data[eTIME].OnShow
		)
	{
		return;
	}*/
	//-> Disable Move List
	if(this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap) 
		//|| this->CheckWindow(ObjWindow::ChatWindow) 
		|| this->CheckWindow(ObjWindow::SkillTree)
		//|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->CheckWindow(ObjWindow::FriendList) || this->CheckWindow(ObjWindow::Party) || this->CheckWindow(ObjWindow::Quest) || this->CheckWindow(ObjWindow::Guild)
	||  (this->CheckWindow(CommandWindow) || this->CheckWindow(Inventory) || this->CheckWindow(Character) || this->CheckWindow(FastMenu) || this->CheckWindow(SkillTree)
	|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap) || this->CheckWindow(MuHelper)) || pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
		this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawStatsAddWindow()
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	char szCharNames[5][32] =
	{
		"Strength:",
		"Agility:",
		"Vitality:",
		"Energy:",
		"Command:",
	};

	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	if (this->Data[eSTATSADD_MAIN].ByClose == false)
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue < 0)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue += this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue >= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 15;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue > 0)
			{
				this->Data[eSTATSADD_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (this->Data[eSTATSADD_MAIN].OpenedValue > -226)
		{
			this->Data[eSTATSADD_MAIN].OpenedValue -= this->Data[eSTATSADD_MAIN].Speed;

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -150)
			{
				this->Data[eSTATSADD_MAIN].Speed = 20;
			}

			if (this->Data[eSTATSADD_MAIN].OpenedValue <= -226)
			{
				//this->Data[eSTATSADD_MAIN].OpenedValue = 100;
				this->Data[eSTATSADD_MAIN].Close();

				this->Data[eSTATSADD_STEP10].Attribute = 0;
				this->Data[eSTATSADD_STEP100].Attribute = 0;
				this->Data[eSTATSADD_STEP1000].Attribute = 0;
				for (int i = 0; i<ObjectCount; i++)
				{
					this->Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}
	pSetCursorFocus = true;
	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = this->Data[eSTATSADD_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawAnimatedGUI(eSTATSADD_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eSTATSADD_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eSTATSADD_FRAME, StartX, StartY + 67.0, 8);
	this->DrawAnimatedGUI(eSTATSADD_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eSTATSADD_CLOSE, StartX + MainWidth - this->Data[eSTATSADD_CLOSE].Width, this->Data[eSTATSADD_MAIN].Y - 2);
	// ----

	// ----
	if (this->IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eSTATSADD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eSTATSADD_CLOSE, this->Data[eSTATSADD_CLOSE].X, this->Data[eSTATSADD_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eSTATSADD_CLOSE].X + 5, this->Data[eSTATSADD_CLOSE].Y + 25, "Close");
	}
	// ----
	DWORD StatPoints = ViewPoint;

	for (int i = 0; i<ObjectCount; i++)
	{
		StatPoints -= atoi(this->Data[ObjectIDs[i]].StatValue);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 8, 210, 3, "Add Points");

	this->DrawAnimatedGUI(eSTATSADD_TEXTBOX01, ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 28);
	this->DrawFormat(eWhite, StartX - 40, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "Free Points:");

	char Value[50];
	ZeroMemory(Value, sizeof(Value));
	pGetMoneyFormat((double)StatPoints, Value, 0);
	GetFormat(Value, ',', ' ');

	////console.Log("", "Point %d Value %s",StatPoints,Value);

	this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 34, 210, 3, "%s", Value);

	this->DrawFormat(eWhite, StartX + 10, this->Data[eSTATSADD_MAIN].Y + 55, 210, 3, "Please set where you want add free points");

	this->DrawFormat(eWhite, StartX + 30, this->Data[eSTATSADD_MAIN].Y + 69, 30, 3, "Step value:");

	this->DrawFormat(eWhite, StartX + 80, this->Data[eSTATSADD_MAIN].Y + 70, 10, 3, "10");
	this->DrawFormat(eWhite, StartX + 120, this->Data[eSTATSADD_MAIN].Y + 70, 15, 3, "100");
	this->DrawFormat(eWhite, StartX + 162, this->Data[eSTATSADD_MAIN].Y + 70, 20, 3, "1000");

	if (this->Data[eSTATSADD_STEP10].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP10, StartX + 90, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP100].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP100, StartX + 135, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_STEP1000].Attribute == true)
	{
		this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 15);
	}
	else
	{
		this->DrawAnimatedButton(eSTATSADD_STEP1000, StartX + 180, this->Data[eSTATSADD_MAIN].Y + 66, 0, 0);
	}

	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
		{
			sprintf(this->Data[ObjectIDs[i]].StatValue, "0");
			this->Data[eSTATSADD_STEP100].Attribute = true;
		}
		this->DrawAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21));
		this->DrawFormat(eWhite, StartX - 38, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, szCharNames[i]);
		this->DrawFormat(eWhite, StartX + 45, this->Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, this->Data[ObjectIDs[i]].StatValue);
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (this->Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			this->DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX - 35, this->Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21), Color);
		}
	}

	this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, 0);

	if (this->IsWorkZone(eSTATSADD_BTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (this->Data[eSTATSADD_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, this->Data[eSTATSADD_MAIN].Y + 194, 0, ScaleY);
	}

	//login_me
	//newui_button_cancel
	//newui_button_ok
	if (this->Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		this->Data[eSTATSADD_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------

void Interface::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}

void Interface::EventStatsAddWindow_Close(DWORD Event)
{
	if (!this->Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[8] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
		eSTATSADD_STEP10,
		eSTATSADD_STEP100,
		eSTATSADD_STEP1000,
	};

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	for (int i = 0; i<ObjectCount; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j<ObjectCount; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 5; i<8; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 500)
			{
				return;
			}
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 5; j<8; j++)
			{
				this->Data[ObjectIDs[j]].Attribute = 0;
			}

			this->Data[ObjectIDs[i]].Attribute = 1;
		}
	}


	if (IsWorkZone(eSTATSADD_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_BTN_OK].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_BTN_OK].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
		PMSG_UPDATE_STATS_SEND pMsg;
		pMsg.Str = atoi(this->Data[eSTATSADD_STATBOX01].StatValue);
		pMsg.Agi = atoi(this->Data[eSTATSADD_STATBOX02].StatValue);
		pMsg.Vit = atoi(this->Data[eSTATSADD_STATBOX03].StatValue);
		pMsg.Ene = atoi(this->Data[eSTATSADD_STATBOX04].StatValue);
		pMsg.Com = 0;
		if (ObjectCount == 5)
		{
			pMsg.Com = atoi(this->Data[eSTATSADD_STATBOX05].StatValue);
		}
		CGSendStatsAdd(pMsg);
	}

	if (IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eSTATSADD_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eSTATSADD_CLOSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eSTATSADD_CLOSE].EventTick = GetTickCount();
		Data[eSTATSADD_MAIN].CloseAnimated(15);
	}

	// ----
	return;
}

void Interface::DrawWarehouseUI()
{
	float PosX = this->GetResizeX(eWAREHOUSE);
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	this->DrawGUI(eWAREHOUSE, PosX, 348);
	this->DrawGUI(eWAREHOUSE1, PosX + 45, 348);
	this->DrawFormat(eWhite, PosX + 33, 350, 10, 1, "%d/5", gObjUser.m_WarehouseNumber + 1);
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		if (this->Data[eWAREHOUSE].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE, PosX, 348, pMakeColor(255, 204, 20, 200));
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		if (this->Data[eWAREHOUSE1].OnClick)
		{
			this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(40, 20, 3, 130));
			return;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE1, PosX + 45, 348, pMakeColor(255, 204, 20, 200));
	}
}

// ----------------------------------------------------------------------------------------------

void Interface::EventWarehouseUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	// ----
	if (!this->CheckWindow(Warehouse))
	{
		return;
	}
	// ----
	if (IsWorkZone(eWAREHOUSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber > 0)
		{
			gObjUser.m_WarehouseNumber--;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
	else if (IsWorkZone(eWAREHOUSE1))
	{
		DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eWAREHOUSE1].OnClick = true;
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eWAREHOUSE1].EventTick = GetTickCount();
		// ----
		if (gObjUser.m_WarehouseNumber < 4)
		{
			gObjUser.m_WarehouseNumber++;
		}
		PMSG_CHANGEWAREHOUSE_RECV pRequest;
		pRequest.Number = gObjUser.m_WarehouseNumber;
		pRequest.header.set(0xF3, 0xE5, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.header.size);
	}
}

void Interface::DrawWarehouseWindow()
{

	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	if (gServerInfo.AnimatedWarehouse == 1)
	{
		if (this->Data[eWAREHOUSE_MAIN].OpenedValue > 100)
		{
			this->Data[eWAREHOUSE_MAIN].OpenedValue -= this->Data[eWAREHOUSE_MAIN].Speed;

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue <= 250)
			{
				this->Data[eWAREHOUSE_MAIN].Speed = 15;
			}

			if (this->Data[eWAREHOUSE_MAIN].OpenedValue < 100)
			{
				this->Data[eWAREHOUSE_MAIN].OpenedValue = 100;
			}
		}
	}

	// ----
	float MainWidth = 230.0;

	float StartY = 100;

	if (gServerInfo.AnimatedWarehouse == 1)
	{
		StartY = this->Data[eWAREHOUSE_MAIN].OpenedValue;//100.0;
	}

	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eWAREHOUSE_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eWAREHOUSE_FRAME, StartX, StartY + 67.0, 7);
	this->DrawAnimatedGUI(eWAREHOUSE_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eWAREHOUSE_CLOSE, StartX + MainWidth - this->Data[eWAREHOUSE_CLOSE].Width, this->Data[eWAREHOUSE_MAIN].Y - 2/* + this->Data[eWAREHOUSE_CLOSE].Height + 2*/);
	// ----
	if (this->IsWorkZone(eWAREHOUSE_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_CLOSE, this->Data[eWAREHOUSE_CLOSE].X, this->Data[eWAREHOUSE_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eWAREHOUSE_CLOSE].X + 5, this->Data[eWAREHOUSE_CLOSE].Y + 25, "Close");
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 8, 210, 3, "Kho đồ");

	this->DrawFormat(eBlue, StartX + 10, this->Data[eWAREHOUSE_MAIN].Y + 30, 210, 3, "Chào %s, vui lòng lựa chọn kho đồ...", gObjUser.lpPlayer->Name);
	this->DrawAnimatedGUI(eWAREHOUSE_DIV, StartX, this->Data[eWAREHOUSE_MAIN].Y + 33);
	// ----
	this->DrawAnimatedGUI(eWAREHOUSE_NUM1, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Kho đồ 1");
	// ----
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM2, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Kho đồ 2");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM3, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Kho đồ 3");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM4, ButtonX - 57, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX - 45, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Kho đồ 4");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM5, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 60);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 70, 210, 3, "Kho đồ 5");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM6, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 100, 210, 3, "Kho đồ 6");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM7, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 130, 210, 3, "Kho đồ 7");
	}
	// ----
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		this->DrawAnimatedGUI(eWAREHOUSE_NUM8, ButtonX + 52, this->Data[eWAREHOUSE_MAIN].Y + 150);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eWAREHOUSE_MAIN].Y + 160, 210, 3, "Kho đồ 8");
	}
	// ----
	if (IsWorkZone(eWAREHOUSE_NUM1))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eWAREHOUSE_NUM1].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eWAREHOUSE_NUM1, this->Data[eWAREHOUSE_NUM1].X, this->Data[eWAREHOUSE_NUM1].Y, Color);
	}
	if (gObjUser.m_MaxWarehouse >= 2)
	{
		if (IsWorkZone(eWAREHOUSE_NUM2))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM2].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM2, this->Data[eWAREHOUSE_NUM2].X, this->Data[eWAREHOUSE_NUM2].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 3)
	{
		if (IsWorkZone(eWAREHOUSE_NUM3))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM3].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM3, this->Data[eWAREHOUSE_NUM3].X, this->Data[eWAREHOUSE_NUM3].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 4)
	{
		if (IsWorkZone(eWAREHOUSE_NUM4))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM4].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM4, this->Data[eWAREHOUSE_NUM4].X, this->Data[eWAREHOUSE_NUM4].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 5)
	{
		if (IsWorkZone(eWAREHOUSE_NUM5))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM5].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM5, this->Data[eWAREHOUSE_NUM5].X, this->Data[eWAREHOUSE_NUM5].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 6)
	{
		if (IsWorkZone(eWAREHOUSE_NUM6))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM6].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM6, this->Data[eWAREHOUSE_NUM6].X, this->Data[eWAREHOUSE_NUM6].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 7)
	{
		if (IsWorkZone(eWAREHOUSE_NUM7))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM7].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM7, this->Data[eWAREHOUSE_NUM7].X, this->Data[eWAREHOUSE_NUM7].Y, Color);
		}
	}
	if (gObjUser.m_MaxWarehouse >= 8)
	{
		if (IsWorkZone(eWAREHOUSE_NUM8))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eWAREHOUSE_NUM8].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eWAREHOUSE_NUM8, this->Data[eWAREHOUSE_NUM8].X, this->Data[eWAREHOUSE_NUM8].Y, Color);
		}
	}
}

void Interface::EventWarehouseWindow_Main(DWORD Event)
{
	this->EventWarehouseWindow_Close(Event);
	// 4136

	DWORD CurrentTick = GetTickCount();

	if ((CurrentTick - this->Data[eWAREHOUSE_MAIN].EventTick) < 500)
	{
		return;
	}

	//DWORD Delay			= (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow)
	{
		return;
	}

	// || !IsWorkZone(eCHANGINGCLASS_MG) || !this->Data[eCHANGINGCLASS_MG].Attribute )

	int ObjectIDs[8] =
	{
		eWAREHOUSE_NUM1,
		eWAREHOUSE_NUM2,
		eWAREHOUSE_NUM3,
		eWAREHOUSE_NUM4,
		eWAREHOUSE_NUM5,
		eWAREHOUSE_NUM6,
		eWAREHOUSE_NUM7,
		eWAREHOUSE_NUM8
	};

	for (int i = 0; i < 8; i++)
	{
		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;;
			// ----
			if (Delay < 500)
			{
				return;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			////console.Log("", "Button %d", i);
			CGSendWarehouseOpen(i);
			this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
			//this->Data[eWAREHOUSE_MAIN].Attribute = MAX_WIN_HEIGHT;
			//this->Data[eWAREHOUSE_MAIN].Speed = 20;
		}
	}
}

void Interface::EventWarehouseWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eWAREHOUSE_CLOSE].EventTick);
	// ----
	if (!this->Data[eWAREHOUSE_MAIN].OnShow || !IsWorkZone(eWAREHOUSE_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eWAREHOUSE_CLOSE].OnClick = true;
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	this->Data[eWAREHOUSE_CLOSE].EventTick = GetTickCount();
	this->Data[eWAREHOUSE_MAIN].Close(MAX_WIN_HEIGHT, 20);
	// ----
	return;
}
#if(OANTUTY)
void Interface::DrawRPS()
{
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (this->CheckWindow(ObjWindow::Trade))
	{
		this->DrawGUI(eRock, StartX + 80, StartY + 85);
		this->DrawGUI(ePaper, StartX + 120, StartY + 85);
		this->DrawGUI(eScissors, StartX + 160, StartY + 85);

		if (this->IsWorkZone(eRock))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eRock].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eRock, this->Data[eRock].X, this->Data[eRock].Y, Color);
		}
		if (this->IsWorkZone(ePaper))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[ePaper].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(ePaper, this->Data[ePaper].X, this->Data[ePaper].Y, Color);
		}
		if (this->IsWorkZone(eScissors))
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eScissors].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eScissors, this->Data[eScissors].X, this->Data[eScissors].Y, Color);
		}
		if (this->Data[eRock].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eRock, gInterface.Data[eRock].X, gInterface.Data[eRock].Y, Color);
		}
		if (this->Data[ePaper].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(ePaper, gInterface.Data[ePaper].X, gInterface.Data[ePaper].Y, Color);
		}
		if (this->Data[eScissors].Attribute == 1)
		{
			DWORD Color = eYellow;
			gInterface.DrawColoredGUI(eScissors, gInterface.Data[eScissors].X, gInterface.Data[eScissors].Y, Color);
		}
	}
}

void Interface::EventRPS_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(ObjWindow::Trade))
	{
		return;
	}

	if (this->IsWorkZone(eRock))
	{
		DWORD Delay = (CurrentTick - this->Data[eRock].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eRock].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eRock].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eRock].EventTick = GetTickCount();
		//Func
		RPSMode(1);
		//pDrawMessage("Ban chon bua",1);
		this->Data[eRock].Attribute = 1;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(ePaper))
	{
		DWORD Delay = (CurrentTick - this->Data[ePaper].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[ePaper].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[ePaper].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[ePaper].EventTick = GetTickCount();
		//Func
		RPSMode(2);
		//pDrawMessage("Ban chon bao",1);
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 1;
		this->Data[eScissors].Attribute = 0;
	}
	//
	else if (this->IsWorkZone(eScissors))
	{
		DWORD Delay = (CurrentTick - this->Data[eScissors].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eScissors].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		// ----
		this->Data[eScissors].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eScissors].EventTick = GetTickCount();
		//Func
		this->Data[eRock].Attribute = 0;
		this->Data[ePaper].Attribute = 0;
		this->Data[eScissors].Attribute = 1;
		RPSMode(3);
		//pDrawMessage("Ban chon keo",1);
	}
}
#endif

void Interface::DrawChangingClassWindow()
{
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eCHANGINGCLASS_MAIN, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 100);

	//gCItemSetOption.ItemTooltipS15(StartX + 0, gInterface.Data[eCHANGINGCLASS_MAIN].Y + 1, 225, 260, 0.0, 0);

	RenderBitmap(500001,StartX -5, gInterface.Data[eCHANGINGCLASS_MAIN].Y + 1, 272, 390, 0.0, 0, 1, 1, 1, 1, 0.0);

	this->DrawGUI(eCHANGINGCLASS_CLOSE, StartX + 195, this->Data[eCHANGINGCLASS_MAIN].Y + 0);
	// ----
	if (this->IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		DWORD Color = eGray150;
		this->DrawColoredGUI(eCHANGINGCLASS_CLOSE, this->Data[eCHANGINGCLASS_CLOSE].X, this->Data[eCHANGINGCLASS_CLOSE].Y, Color);
	}
	// ----
	this->DrawFormat(eGold, StartX + 10, 110, 210, 3, gOther.TextVN[22]);
	// ----

	this->DrawGUI(eCHANGINGCLASS_MONEYBG, StartX + 30, this->Data[eCHANGINGCLASS_MAIN].Y + 190);
	this->DrawFormat(eWhite, StartX + 10, this->Data[eCHANGINGCLASS_MAIN].Y + 195, 210, 3, gOther.TextVN[141],gChangeClass.m_WCoinC);
	// ----

	// ----
	this->DrawGUI(eCHANGINGCLASS_DW, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 30);

	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 20));
	//pGetTextLine
	// ----
	this->DrawGUI(eCHANGINGCLASS_DK, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 30);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 40, 210, 3, "%s", pGetTextLine(pTextLineThis, 21));
	// ----
	this->DrawGUI(eCHANGINGCLASS_ELF, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 22));
	// ----
	this->DrawGUI(eCHANGINGCLASS_MG, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 60);
	this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 70, 210, 3, "%s", pGetTextLine(pTextLineThis, 23));
	// ----
	this->DrawGUI(eCHANGINGCLASS_DL, ButtonX - 57, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
	this->DrawFormat(eWhite, StartX - 45, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 24));
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 6)
	{
		this->DrawGUI(eCHANGINGCLASS_SUM, ButtonX + 52, this->Data[eCHANGINGCLASS_MAIN].Y + 90);
		this->DrawFormat(eWhite, StartX + 62, this->Data[eCHANGINGCLASS_MAIN].Y + 100, 210, 3, "%s", pGetTextLine(pTextLineThis, 1687));
	}
	// ----
	if (gProtect.m_MainInfo.CharsCount >= 7)
	{
		this->DrawGUI(eCHANGINGCLASS_RF, ButtonX, this->Data[eCHANGINGCLASS_MAIN].Y + 120);
		this->DrawFormat(eWhite, StartX + 8, this->Data[eCHANGINGCLASS_MAIN].Y + 130, 210, 3, "%s", pGetTextLine(pTextLineThis, 3150));
	}
	// ----
	this->DrawGUI(eCHANGINGCLASS_DIV, StartX, this->Data[eCHANGINGCLASS_MAIN].Y + 150);
	// ----
	this->Data[eCHANGINGCLASS_DW].Attribute = true;
	this->Data[eCHANGINGCLASS_DK].Attribute = true;
	this->Data[eCHANGINGCLASS_ELF].Attribute = true;
	this->Data[eCHANGINGCLASS_MG].Attribute = true;
	this->Data[eCHANGINGCLASS_DL].Attribute = true;
	this->Data[eCHANGINGCLASS_SUM].Attribute = true;
	this->Data[eCHANGINGCLASS_RF].Attribute = true;
	// ----
	if (IsWorkZone(eCHANGINGCLASS_DW))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DW].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DW, this->Data[eCHANGINGCLASS_DW].X, this->Data[eCHANGINGCLASS_DW].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DK, this->Data[eCHANGINGCLASS_DK].X, this->Data[eCHANGINGCLASS_DK].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_ELF))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_ELF].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_ELF, this->Data[eCHANGINGCLASS_ELF].X, this->Data[eCHANGINGCLASS_ELF].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_MG))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_MG].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_MG, this->Data[eCHANGINGCLASS_MG].X, this->Data[eCHANGINGCLASS_MG].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_DL))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eCHANGINGCLASS_DL].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eCHANGINGCLASS_DL, this->Data[eCHANGINGCLASS_DL].X, this->Data[eCHANGINGCLASS_DL].Y, Color);
	}
	if (IsWorkZone(eCHANGINGCLASS_SUM))
	{
		if (gProtect.m_MainInfo.CharsCount >= 6)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_SUM].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_SUM, this->Data[eCHANGINGCLASS_SUM].X, this->Data[eCHANGINGCLASS_SUM].Y, Color);
		}
	}
	if (IsWorkZone(eCHANGINGCLASS_RF))
	{
		if (gProtect.m_MainInfo.CharsCount >= 7)
		{
			DWORD Color = eGray100;
			// ----
			if (this->Data[eCHANGINGCLASS_RF].OnClick)
			{
				Color = eGray150;
			}
			// ----
			this->DrawColoredGUI(eCHANGINGCLASS_RF, this->Data[eCHANGINGCLASS_RF].X, this->Data[eCHANGINGCLASS_RF].Y, Color);
		}
	}

}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Main(DWORD Event)
{
	this->EventChangingClassWindow_Close(Event);
	this->EventChangingClassWindow_DW(Event);
	this->EventChangingClassWindow_DK(Event);
	this->EventChangingClassWindow_ELF(Event);
	this->EventChangingClassWindow_MG(Event);
	this->EventChangingClassWindow_DL(Event);
	this->EventChangingClassWindow_SUM(Event);
	this->EventChangingClassWindow_RF(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_CLOSE].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_CLOSE].EventTick = GetTickCount();
	this->Data[eCHANGINGCLASS_MAIN].Close();
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventChangingClassWindow_DW(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DW].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DW)
		|| !this->Data[eCHANGINGCLASS_DW].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DW].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DW].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(0);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DK].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DK)
		|| !this->Data[eCHANGINGCLASS_DK].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DK].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(16);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_ELF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_ELF].EventTick);

	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_ELF)
		|| !this->Data[eCHANGINGCLASS_ELF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_ELF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_ELF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(32);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_MG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_MG].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_MG)
		|| !this->Data[eCHANGINGCLASS_MG].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_MG].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_MG].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(48);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_DL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_DL].EventTick);
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_DL)
		|| !this->Data[eCHANGINGCLASS_DL].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_DL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_DL].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(64);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_SUM(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_SUM].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<6)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_SUM)
		|| !this->Data[eCHANGINGCLASS_SUM].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_SUM].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_SUM].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(80);
	// ----
	return false;
}
bool Interface::EventChangingClassWindow_RF(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCHANGINGCLASS_RF].EventTick);
	// ----
	if (gProtect.m_MainInfo.CharsCount<7)
	{
		return false;
	}
	// ----
	if (!this->Data[eCHANGINGCLASS_MAIN].OnShow || !IsWorkZone(eCHANGINGCLASS_RF)
		|| !this->Data[eCHANGINGCLASS_RF].Attribute)
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCHANGINGCLASS_RF].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCHANGINGCLASS_RF].EventTick = GetTickCount();
	gChangeClass.SendChangeClass(96);
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::ControlTextBox(KBDLLHOOKSTRUCT Hook)
{
	if (this->Data[eSTATSADD_MAIN].OnShow)
	{
		char Value[20];
		int IsBackspace = false;
		int IsDelete = false;
		int IsTab = false;
		int IsArrowUp = false;
		int IsArrowDown = false;
		int IsArrowLeft = false;
		int IsArrowRight = false;

		int Step = 100;

		if (this->Data[eSTATSADD_STEP10].Attribute == true)
		{
			Step = 10;
		}
		else if (this->Data[eSTATSADD_STEP100].Attribute == true)
		{
			Step = 100;
		}
		else if (this->Data[eSTATSADD_STEP1000].Attribute == true)
		{
			Step = 1000;
		}

		int ObjectCount = 4;
		if ((gObjUser.lpPlayer->Class & 7) == 4)
		{
			ObjectCount = 5;
		}

		int SelectedIndex = 0;

		if (Hook.vkCode == VK_BACK)
		{
			IsBackspace = true;
		}
		else if (Hook.vkCode == VK_DELETE)
		{
			IsDelete = true;
		}
		else if (Hook.vkCode == VK_TAB)
		{
			IsTab = true;
		}
		else if (Hook.vkCode == VK_UP)
		{
			IsArrowUp = true;
		}
		else if (Hook.vkCode == VK_DOWN)
		{
			IsArrowDown = true;
		}
		else if (Hook.vkCode == VK_LEFT)
		{
			IsArrowLeft = true;
		}
		else if (Hook.vkCode == VK_RIGHT)
		{
			IsArrowRight = true;
		}
		else if ((Hook.vkCode >= 0x30 && Hook.vkCode <= 0x39) || (Hook.vkCode >= 0x60 && Hook.vkCode <= 0x69))
		{
			int Symbol = GetSymbolFromVK(Hook.vkCode);
			if (Symbol == 0)
			{
				return 1;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(Value, buff);
			////console.Log("", buff);
			//int Value = atoi(buff);
		}
		else
		{
			return 1;
		}
		int ObjectIDs[5] =
		{
			eSTATSADD_STATBOX01,
			eSTATSADD_STATBOX02,
			eSTATSADD_STATBOX03,
			eSTATSADD_STATBOX04,
			eSTATSADD_STATBOX05,
		};

		for (int i = 0; i<ObjectCount; i++)
		{
			if (this->Data[ObjectIDs[i]].Attribute == 1)
			{
				SelectedIndex = i;
				if (IsBackspace == true)
				{
					this->Data[ObjectIDs[i]].StatValue[strlen(this->Data[ObjectIDs[i]].StatValue) - 1] = '\0';

					if (strlen(this->Data[ObjectIDs[i]].StatValue) == 0)
					{
						strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
					}
					break;
				}
				else if (IsDelete == true)
				{
					strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
				}
				else if (IsTab == true)
				{
					this->Data[ObjectIDs[i]].Attribute = 0;

					if (i == ObjectCount - 1)
					{
						this->Data[ObjectIDs[0]].Attribute = 1;
					}
					else
					{
						this->Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowUp == true)
				{
					if (i > 0)
					{
						this->Data[ObjectIDs[i]].Attribute = 0;
						this->Data[ObjectIDs[i - 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowDown == true)
				{
					if (i < ObjectCount - 1)
					{
						this->Data[ObjectIDs[i]].Attribute = 0;
						this->Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else if (IsArrowLeft == true)
				{
					int val = atoi(this->Data[ObjectIDs[i]].StatValue);
					val -= Step;
					if (val < 0)
					{
						val = 0;
					}
					//strcpy_s(this->Data[ObjectIDs[i]].StatValue, "0");
					sprintf_s(this->Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else if (IsArrowRight == true)
				{
					int val = atoi(this->Data[ObjectIDs[i]].StatValue);
					val += Step;
					if (val > 65535)
					{
						val = 65535;
					}
					sprintf_s(this->Data[ObjectIDs[i]].StatValue, "%d", val);
					break;
				}
				else
				{
					if (strlen(this->Data[ObjectIDs[i]].StatValue)<8)
					{
						if (!strcmp(this->Data[ObjectIDs[i]].StatValue, "0"))
						{
							strcpy_s(this->Data[ObjectIDs[i]].StatValue, Value);
						}
						else
						{
							strcat_s(this->Data[ObjectIDs[i]].StatValue, Value);
						}
					}
				}
			}
		}

		int StatPoints = 0;

		for (int i = 0; i<ObjectCount; i++)
		{
			if (i == SelectedIndex)
			{
				continue;
			}
			StatPoints += atoi(this->Data[ObjectIDs[i]].StatValue);
		}

		if (StatPoints + atoi(this->Data[ObjectIDs[SelectedIndex]].StatValue) > ViewPoint)
		{
			char buff[20];
			sprintf(buff, "%d", ViewPoint - StatPoints);
			strcpy_s(this->Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}

		if (atoi(this->Data[ObjectIDs[SelectedIndex]].StatValue) > gServerInfo.get_max_stat_point(ViewAccountLevel))
		{
			char buff[20];
			sprintf(buff, "%d", gServerInfo.get_max_stat_point(ViewAccountLevel));
			strcpy_s(this->Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}
		return 1;
	}

	return 0;
}

void Interface::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (!this->CheckWindow(Character))
	{
		return;
	}
	// ----
	if (IsWorkZone(eCHARINFO_BTN_STAT))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();
		this->SwitchStatsWindowState();
	}
}

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	//if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	//{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	//}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	this->Data[ObjectID].X = X;
	this->Data[ObjectID].Y = Y;
	this->Data[ObjectID].MaxX = X + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = Y + this->Data[ObjectID].Height;
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawColoredButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY, DWORD Color)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY, Color);
}

int Interface::DrawToolTipEx(DWORD Color, int PosX, int PosY, int Width, int Height, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	char Buff2[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----

	int LineCount = 0;

	strcpy(Buff2, Buff);

	char* Line = strtok(Buff2, "\n");
	// ----
	while (Line != NULL)
	{
		LineCount++;
		Line = strtok(NULL, "\n");
	}

	pSetBlend(true);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(PosX, PosY, Width, LineCount * 10, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	this->DrawText(eWhite, PosX, PosY, Width, Align, Buff);
	return 0;
}

void Interface::DrawText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...) // OK
{
	char Buff[2048];
	const int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	char * Line = strtok(Buff, "\n");

	while (Line != nullptr)
	{
		DrawInterfaceText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::DrawMessageBox(LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	CharTest v15;

	LPCSTR pText = Buff;
	sub_409A50_addr(&v15, (int)pText);
	pOpenInfoBox1(&v15, -1);
	sub_409AD0_Addr((LPVOID)&v15);
}

bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
		return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
	return false;
	return true;
}
//tue add Tu Chan ////////////
int Interface::SPKText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff) - 1;
	ZeroMemory(Buff, BuffLen);

	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);

	int LineCount = 0;

	char* Line = strtok(Buff, "\n");

	while (Line != NULL)
	{
		std::string str = Line;
		std::stringstream ss(str);
		std::string token;
		std::vector<std::string> tokens;
		while (getline(ss, token, ' ')) {
			tokens.push_back(token);
		}
		std::string num_str = tokens.back();
		int num = atoi(num_str.c_str());
		tokens.pop_back();
		std::string new_str = "";
		if (num < 1000) {
			new_str = num_str;
		}
		else {
			int num_digit = num_str.size();
			int num_commas = (num_digit - 1) / 3;
			int start = 0;
			for (int i = 0; i < num_commas; i++) {
				int end = num_digit - 3 * (i + 1);
				new_str = "," + num_str.substr(end, 3) + new_str;
				start = end;
			}
			new_str = num_str.substr(0, start) + new_str;
		}
		tokens.push_back(new_str);
		std::string new_line = "";
		for (int i = 0; i < tokens.size(); i++) {
			if (i != 0) new_line += " ";
			new_line += tokens[i];
		}
		pDrawColorText(new_line.c_str(), PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}

	return PosY;
}
////////////////////////////

signed int __cdecl ColorMoneyRuud(unsigned int a1)
{
	signed int color1 = eWhite; // eax@2

	if(a1 >= 1000 && a1 < 1000000)
	{
		color1 = eShinyGreen;
	}
	else if(a1 >= 1000000 && a1 < 10000000)
	{
		color1 = eGold;
	}
	else if(a1 >= 1000000 && a1 < 100000000)
	{
		color1 = eOrange;
	}
	else if(a1 >= 100000000)
	{
		color1 = eRed;
	}
	return color1;
}

//-- Shop Ruud
void InventoryWindows(DWORD id, float x, float y, float w, float h)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	//-- NPC RUUD
	//=============================
	jCRenderRuud.OpenRuud();
	//=============================
	pDrawGUI(id, x, y, w, h);
	
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
		{
			return;
		}
		//-- Ruud Coin Interface 97/99/S2/S6/Legends
		int x, y;
		char v10[255]; // ST24_4@1
		unsigned int v23; // [sp+128h] [bp-4h]@1
		char v22[260]; // [sp+24h] [bp-108h]@1
		int v15; // ST18_4@1
		int v639; // ST18_4@1

		x = 400;
		y = 400;
		
		ZeroMemory(v22, sizeof(v22));
		pGetMoneyFormat(Ruud, v22, 0);
		v15 = ColorMoneyRuud(Ruud);
		SetTextColorByHDC(pTextThis(), v15);

		//if(gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
		//{
		//	RenderBitmap(0x7877, x - 52, y + 10, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
		//	gInterface.DrawFormat(eBlack, x - 33, y + 16, 20, 1, "Ruud");
		//	gInterface.DrawFormat(eOrange, x - 19, y + 16, 50, 4, "%s", v22);
		//}
		/*else if(gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
		{
			RenderBitmap(0x7877, x + 93, y + 28, 120, 20, 0, 0, 0.5, 0.5, 0.5, 1, 0);
			gInterface.DrawFormat(eBlack, x + 112, y + 35, 20, 1, "Ruud");
			gInterface.DrawFormat(eOrange, x + 126, y + 35, 50, 4, "%s", v22);
			}*/
		}
	}
}
//-- EXP Bar
int sub_895600(float x, float y, int number)
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	int result; // eax@1

	pSetBlend( 1 );

	result = CRenderNumberEx(x, y, number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);

	return result;
	}
}
//--
//--Pet HPBar Activado
DWORD VKBUTTON_DELAY;
void CEx700::BarPetMuun()
{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		//|| gInterface.CheckWindow(ObjWindow::Store)
		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	int y = 50;
	int x = 35;

	//RenderBitmap(61545, 2, y + 6, Return2X(TransForX(59)), ReturnY(TransForY(16)), 0.0, 0.0, 0.75,0.1678999364, 1, 1, 0); //-- Barra
	////-- TitleName
	//pSetFont(pTextThis(), (int) pFontBold);
	//pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//pSetTextColor(pTextThis(), 240, 240, 240, 255);
	//pDrawText(pTextThis(), x + 4, y + 9, "Pet", 148.0, 0, (LPINT)1, 0);

	//if(pCheckMouseOver( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
	//{
	//	if(pCursorX >= Return2X(TransForX(61)))
	//	{
	//	pSetCursorFocus = true;
	//	}
	//}

	//if(MinimizarPet == 0)
	//{
	//	if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
	//	{
	//		RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
	//		if( GetTickCount() >= VKBUTTON_DELAY + 200 )
	//		{
	//			MinimizarPet = 1;
	//			VKBUTTON_DELAY = GetTickCount();
	//		}
	//	}
	//	else
	//	{
	//		RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
	//	}
	//}
	//else
	//{
	//	if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
	//	{
	//		RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
	//		if( GetTickCount() >= VKBUTTON_DELAY + 200 )
	//		{
	//			MinimizarPet = 0;
	//			VKBUTTON_DELAY = GetTickCount();
	//		}
	//	}
	//	else
	//		{
	//		RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
	//		}
	//	}
	}
}


//void Interface::BarNhiemVu()
//{
//	if (gInterface.CheckWindow(ObjWindow::CashShop)
//		//||gInterface.CheckWindow(ObjWindow::FriendList)
//		//|| gInterface.CheckWindow(ObjWindow::MoveList)
//		|| gInterface.CheckWindow(ObjWindow::Party)
//		//|| gInterface.CheckWindow(ObjWindow::Quest)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
//		//|| gInterface.CheckWindow(ObjWindow::Guild)	
//		//|| gInterface.CheckWindow(ObjWindow::Trade)
//		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
//		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
//		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
//		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
//		|| gInterface.CheckWindow(ObjWindow::Shop)
//		//|| gInterface.CheckWindow(ObjWindow::Inventory)
//		//|| gInterface.CheckWindow(ObjWindow::Store)
//		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
//		|| gInterface.CheckWindow(ObjWindow::Character)
//		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
//		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
//		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
//		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
//		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
//		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
//		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
//		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
//		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
//		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
//		//|| gInterface.CheckWindow(ObjWindow::HeroList)
//		//|| gInterface.CheckWindow(ObjWindow::ChatWindow)
//		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
//		//|| gInterface.CheckWindow(ObjWindow::Options)	
//		|| gInterface.CheckWindow(ObjWindow::Help)
//		//|| gInterface.CheckWindow(ObjWindow::FastDial)
//		|| gInterface.CheckWindow(ObjWindow::SkillTree)
//		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
//		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
//		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
//		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
//		|| gInterface.CheckWindow(ObjWindow::CashShop)
//		|| gInterface.CheckWindow(ObjWindow::Lugard)
//		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
//		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
//		|| gInterface.CheckWindow(ObjWindow::Jerint)
//		|| gInterface.CheckWindow(ObjWindow::FullMap)
//		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
//		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
//		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
//		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
//		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
//		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
//		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
//	{
//		return;
//	}
//	if (jCRenderRuud.OpeningRuud)
//	{
//		return;
//	}
//
//	if (gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
//	{
//		int y = 150;
//		int x = 580;
//
//		RenderBitmap(61545,x + 2, y + 6, Return2X(TransForX(59)), ReturnY(TransForY(16)), 0.0, 0.0, 0.75, 0.1678999364, 1, 1, 0); //-- Barra
//		//-- TitleName
//		pSetFont(pTextThis(), (int)pFontBold);
//		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
//		pSetTextColor(pTextThis(), 240, 240, 240, 255);
//		pDrawText(pTextThis(), x + 9, y + 8, "TitleName", 148.0, 0, (LPINT)1, 0);//Nhiệm vụ
//
//		if (pCheckMouseOver(x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
//		{
//			if (pCursorX >= x + Return2X(TransForX(61)))
//			{
//				pSetCursorFocus = true;
//			}
//		}
//
//		if (MinimizarNhiemVu == 0)
//		{
//			if (CheckButtonPressed(x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
//			{
//				RenderBitmap(61545, x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282, 1, 1, 0); //-- Boton Minimizar
//				if (GetTickCount() >= VKBUTTON_DELAY + 200)
//				{
//					MinimizarNhiemVu = 1;
//					VKBUTTON_DELAY = GetTickCount();
//				}
//			}
//			else
//			{
//				RenderBitmap(61545, x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282, 1, 1, 0); //-- Boton Minimizar
//			}
//		}
//		else
//		{
//			if (CheckButtonPressed(x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
//			{
//				RenderBitmap(61545, x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282, 1, 1, 0); //-- Boton Minimizar
//				if (GetTickCount() >= VKBUTTON_DELAY + 200)
//				{
//					MinimizarNhiemVu = 0;
//					VKBUTTON_DELAY = GetTickCount();
//				}
//			}
//			else
//			{
//				RenderBitmap(61545, x + Return2X(TransForX(61)), y + ReturnY(TransForY(6)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282, 1, 1, 0); //-- Boton Minimizar
//			}
//		}
//	}
//}
//--
//--Spirit BarHP Activado
void PetSpiritHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{
		if(gInterface.CheckWindow(ObjWindow::CashShop) 
		//||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		//|| gInterface.CheckWindow(ObjWindow::Party)
		//|| gInterface.CheckWindow(ObjWindow::Quest)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		//|| gInterface.CheckWindow(ObjWindow::Guild)	
		//|| gInterface.CheckWindow(ObjWindow::Trade)
		//|| gInterface.CheckWindow(ObjWindow::Warehouse)
		//|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		//|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		//|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		//|| gInterface.CheckWindow(ObjWindow::Inventory)
		//|| gInterface.CheckWindow(ObjWindow::Store)
		//|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		//|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		//|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		//|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		//|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		//|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		//|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		//|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		//|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		//|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		//|| gInterface.CheckWindow(ObjWindow::HeroList)
	    //|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		//|| gInterface.CheckWindow(ObjWindow::FastMenu)
		//|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		//|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		//|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		//|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		//|| gInterface.CheckWindow(ObjWindow::QuestList1)
		//|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		//|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		//|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix))
		//|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		//|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		//|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (jCRenderRuud.OpeningRuud)
	{
		return;
	}

	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	y += ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 ) ? 8 : 5;

	if( MinimizarPet == 0 )
		{
		RenderBitmap(61545, 2, y + 22, Return2X(TransForX( 74 )), ReturnY(TransForY( 24 )), 0.0, 0.1731800437, 0.75, 0.2378999293,1, 1, 0); //-- Fondo

		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 5, y + 27, (LPCTSTR)nameIndex, 0, 0, (LPINT) 1, 0);

		int v15 = (double)hp / (double)hpmax * 69.0;

		pSetBlend(1);
		glColor4f(0.4274, 0.0313, 0.1254, 0.798);

		pDrawBarForm(4, y + 38, Return2X(TransForX( v15 )), 4, 0, 0);
		pGLSwitch();
		pSetBlend(0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		}
	}
}
//--

void Interface::RenderObjectSystem2()
{
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	//-- Shop Ruud Activado
	//-- Number Stack
	SetCompleteHook(0xE9, 0x00895600, &sub_895600);
	//-- Windows Inventory Ruud
	SetCompleteHook(0xE8, 0x00836EF6, &InventoryWindows);
	}
	//--
	//--Spirit BarHP Activado
	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 4)
	{
	SetCompleteHook(0xE8, 0x007E020C, &PetSpiritHP); //-- PAJARRACO
	SetCompleteHook(0xE8, 0x007E0298, &PetSpiritHP);//-- PAJARRACO
	}
	//--
		// ----hieu ung duoi chan 
	//SetCompleteHook(0xE8, 0x404570 + 0x30D, &RenderCharacter);
	//SetCompleteHook(0xE8, 0x48E120 + 0x44C, &RenderCharacter);
	//SetCompleteHook(0xE8, 0x57D260 + 0x29F, &RenderCharacter);
	//SetCompleteHook(0xE8, 0x57D260 + 0x2B3, &RenderCharacter);
	//gMoveEffect.Init();
	gCapeAnimation.Load();
#if(HT_THUE_FLAG)
	Flag.Load();
#endif
	// 	//-------------------------------------------------------------------
}
//=========================================================================================================================================
//=========================================================================================================================================

#if(CHARACTER_NEW)

void Interface::BUY_TINH_NANG_GAME(int Number)
{
	BUY_TINH_NANG_REQ pMsg;
	pMsg.h.set(0xFC, 0x01, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

void Interface::GetInfoTinhNang(PMSG_TINHNANG_UPD * aRecv)
{
	//-----------------------------
	this->m_rResetLife = aRecv->rResetLife;
	this->m_CommandResetPoint_WCoinC = aRecv->CommandResetPoint_WCoinC;
	this->m_CommandResetMaster_WCoinC = aRecv->CommandResetMaster_WCoinC;
	this->m_CommandChange_WCoinC = aRecv->CommandChange_WCoinC;
	this->m_CommandRelife_Check_Level = aRecv->CommandRelife_Check_Level;
	this->m_CommandRelife_Check_Reset = aRecv->CommandRelife_Check_Reset;
	this->m_CommandRelife_Point = aRecv->CommandRelife_Point;
	this->m_CommandRelife_MaxClient = aRecv->CommandRelife_MaxClient;
}

void Interface::DrawCharacterWindow()
{
	if (this->CheckWindow(ObjWindow::ExpandWarehouse)  - CheckWindow(ObjWindow::OtherStore) - CheckWindow(ObjWindow::Trade) - CheckWindow(ObjWindow::ChaosBox) - CheckWindow(ObjWindow::SkillTree) - CheckWindow(ObjWindow::CashShop))
	{
		Data[XOAHOMDO_CHARACTER].OnShow = false;
		return;
	}

	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	if (this->CheckWindow(ObjWindow::Inventory))
	{
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(XOAHOMDO_CHARACTER, StartX + 255, StartY + 378);
		if (CheckButtonPressed(StartX + 255, StartY + 378,  Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 255, StartY + 378, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 255,StartY + 378, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 262, StartY + 381, 210, 1, gOther.TextVN[133]); // Xóa đồ
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(TINHNANG_CHARACTER, StartX + 291, StartY + 378);
		if (CheckButtonPressed(StartX + 291, StartY + 378, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 291, StartY + 378, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 291, StartY + 378, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 294, StartY + 381, 210, 1, gOther.TextVN[140]); // Tính năng
		//--------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------
		this->DrawGUI(RINGPEDAN_CHARACTER, StartX + 235, StartY + 174);
		if (CheckButtonPressed(StartX + 235, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17))))
		{
			RenderBitmap(61535, StartX + 235, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, StartX + 235, StartY + 174, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		this->DrawFormat(eWhite, StartX + 237, StartY + 177, 210, 1, gOther.TextVN[152]); // Trang sức
		//--------------------------------------------------------------------------------------------


		//--------------------------------------------------------------------------------------------
	}
}
bool Interface::EventCharacterWindow_XoaHomDo(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[XOAHOMDO_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(XOAHOMDO_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[XOAHOMDO_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[XOAHOMDO_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[XOAHOMDO_CHARACTER].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		if (gInterface.CheckXoaHomDoWindow())
		{
			gInterface.CloseXoaHomDoWindow();
			pSetCursorFocus = false;
		}
		else
		{
			gInterface.OpenXoaHomDoWindow();
		}
	}
	return true;
}
bool Interface::EventCharacterWindow_TinhNang(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[TINHNANG_CHARACTER].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(TINHNANG_CHARACTER))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[TINHNANG_CHARACTER].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[TINHNANG_CHARACTER].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[TINHNANG_CHARACTER].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow)
	{
		if (gInterface.CheckTinhNangWindow())
		{
			gInterface.CloseTinhNangWindow();
			pSetCursorFocus = false;
		}
		else
		{
			gInterface.OpenTinhNangWindow();
		}
	}

	this->BUY_TINH_NANG_GAME(10); 

	return true;
}
//bool Interface::EventCharacterWindow_RingPedan(DWORD Event)
//{
//	DWORD CurrentTick = GetTickCount();
//	DWORD Delay = (CurrentTick - this->Data[RINGPEDAN_CHARACTER].EventTick);
//	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(RINGPEDAN_CHARACTER))
//	{
//		return false;
//	}
//	if (Event == WM_LBUTTONDOWN)
//	{
//		this->Data[RINGPEDAN_CHARACTER].OnClick = true;
//		pSetCursorFocus = true;
//		return true;
//	}
//	this->Data[RINGPEDAN_CHARACTER].OnClick = false;
//	pSetCursorFocus = false;
//	// ----
//	if (Delay < 500)
//	{
//		return false;
//	}
//	this->Data[RINGPEDAN_CHARACTER].EventTick = GetTickCount();
//
//	if (GetForegroundWindow() == pGameWindow)
//	{
//		if (gInterface.CheckRingPedanWindow())
//		{
//			gInterface.CloseRingPedanWindow();
//			pSetCursorFocus = false;
//		}
//		else
//		{
//			gInterface.OpenRingPedanWindow();
//		}
//	}
//
//	this->BUG_RINGPEDAN(5);
//
//	return true;
//}
//===================================================================================================================
//===================================================================================================================
void Interface::DrawXoaHomDoWinDow()
{
	if (!this->Data[XOAHOMDO_MAIN].OnShow)
	{
		return;
	}
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(XOAHOMDO_MAIN, StartX, StartY);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[XOAHOMDO_MAIN].Y + 270, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	if (this->IsWorkZone(XOAHOMDO_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 210, gInterface.Data[XOAHOMDO_MAIN].Y + 275, 210, 1, gOther.TextVN[136]); // Xóa hòm đồ
	this->DrawFormat(eRed, StartX + 205, gInterface.Data[XOAHOMDO_MAIN].Y + 290, 210, 1, gOther.TextVN[137]);   // Chú ý đồ giá trị!
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES, StartX + 180, gInterface.Data[XOAHOMDO_MAIN].Y + 310);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[XOAHOMDO_MAIN].Y + 313, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO, StartX + 240, gInterface.Data[XOAHOMDO_MAIN].Y + 310);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[XOAHOMDO_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[XOAHOMDO_MAIN].Y + 313, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
}
bool Interface::EventXoaHomDoWinDow(DWORD Event)
{
	if (gInterface.Data[XOAHOMDO_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(8);
		this->CloseXoaHomDoWindow();
	}
	if (gInterface.Data[XOAHOMDO_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO].EventTick = GetTickCount();
		this->CloseXoaHomDoWindow();
	}
	return true;
}
//===================================================================================================================
//===================================================================================================================
void Interface::DrawTinhNangWinDow()
{
	if (!this->Data[TINHNANG_MAIN].OnShow)
	{
		return;
	}
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(TINHNANG_MAIN, StartX, StartY);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[TINHNANG_MAIN].Y + 10, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[TINHNANG_MAIN].Y + 75, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[TINHNANG_MAIN].Y + 140, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[TINHNANG_MAIN].Y + 205, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 168, gInterface.Data[TINHNANG_MAIN].Y + 270, 115, 60, 0.0, 0);
	//--------------------------------------------------------------------------------------------

	if (this->IsWorkZone(TINHNANG_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 210, gInterface.Data[TINHNANG_MAIN].Y + 15, 210, 1, gOther.TextVN[149]); // Tẩy điểm 
	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[TINHNANG_MAIN].Y + 30, 210, 1, gOther.TextVN[148], m_CommandResetPoint_WCoinC);  // WCoinC yêu cầu = %d
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES1, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 50);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[TINHNANG_MAIN].Y + 53, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO1, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 50);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 50, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[TINHNANG_MAIN].Y + 53, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 205, gInterface.Data[TINHNANG_MAIN].Y + 80, 210, 1, gOther.TextVN[147]); // Tẩy điểm Master
	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[TINHNANG_MAIN].Y + 95, 210, 1, gOther.TextVN[148],m_CommandResetMaster_WCoinC);  // WCoinC yêu cầu = %d
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES2, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 115);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[TINHNANG_MAIN].Y + 118, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO2, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 115);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 115, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[TINHNANG_MAIN].Y + 118, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 210, gInterface.Data[TINHNANG_MAIN].Y + 145, 210, 1, gOther.TextVN[145]); // Làm nhiệm vụ
	this->DrawFormat(eBlue, StartX + 190, gInterface.Data[TINHNANG_MAIN].Y + 160, 210, 1, gOther.TextVN[146]);  // Thăng cấp nhân vật Master!
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES3, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 180);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[TINHNANG_MAIN].Y + 183, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO3, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 180);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 180, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[TINHNANG_MAIN].Y + 183, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 210, gInterface.Data[TINHNANG_MAIN].Y + 205, 210, 1, gOther.TextVN[142]); // ResetLife
	this->DrawFormat(eExcellent, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 220, 210, 1, gOther.TextVN[143], m_CommandRelife_Check_Level, m_CommandRelife_Check_Reset);   // Yêu cầu Level %d, Reset %d = Point + %d
	this->DrawFormat(eYellow, StartX + 175, gInterface.Data[TINHNANG_MAIN].Y + 235, 210, 1, gOther.TextVN[144], m_CommandRelife_Point,m_rResetLife,m_CommandRelife_MaxClient);   //  Point + %d
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES4, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 245);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[TINHNANG_MAIN].Y + 248, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO4, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 245);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 245, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[TINHNANG_MAIN].Y + 248, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawFormat(eWhite, StartX + 205, gInterface.Data[TINHNANG_MAIN].Y + 275, 210, 1, gOther.TextVN[150]); // Triệu hồi đệ tử
	this->DrawFormat(eOrange, StartX + 190, gInterface.Data[TINHNANG_MAIN].Y + 290, 210, 1, gOther.TextVN[151]);   // Tăng sát thương + thể lực
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_YES5, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 310);
	if (CheckButtonPressed(StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 180, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 187, gInterface.Data[TINHNANG_MAIN].Y + 313, 210, 1, gOther.TextVN[134]); // Đồng ý
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(BUTTON_NO5, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 310);
	if (CheckButtonPressed(StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 240, gInterface.Data[TINHNANG_MAIN].Y + 310, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 247, gInterface.Data[TINHNANG_MAIN].Y + 313, 210, 1, gOther.TextVN[135]); // Từ chối
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
}
bool Interface::EventTinhNangWinDow(DWORD Event)
{
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES1].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(1);
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO1))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO1].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO1].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO1].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO1].EventTick = GetTickCount();
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES2].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(2);
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO2))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO2].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO2].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO2].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO2].EventTick = GetTickCount();
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES3].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(3);
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO3))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO3].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO3].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO3].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO3].EventTick = GetTickCount();
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES4].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(7);
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO4))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO4].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO4].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO4].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO4].EventTick = GetTickCount();
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_YES5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_YES5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_YES5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_YES5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_YES5].EventTick = GetTickCount();
		this->BUY_TINH_NANG_GAME(9);
		this->CloseTinhNangWindow();
	}
	if (gInterface.Data[TINHNANG_MAIN].OnShow && gInterface.IsWorkZone(BUTTON_NO5))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[BUTTON_NO5].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[BUTTON_NO5].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[BUTTON_NO5].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[BUTTON_NO5].EventTick = GetTickCount();
		this->CloseTinhNangWindow();
	}
	return true;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
#if(SACHTHUOCTINH_NEW)
void Interface::DrawSachThuocTinhInterface()
{
	int This = GetInventory(GetInstance());
	float x;
	float y;
	if (gProtect.m_MainInfo.CustomInterfaceType >= 3)
	{
		x = TransFor2X((double)*(signed int *)(This + 36));
		y = TransForY((double)*(signed int *)(This + 40));
	}
	else {
		x = (double)*(signed int *)(This + 36);
		y = (double)*(signed int *)(This + 40);
	}

	if (CheckWindow(ObjWindow::OtherStore) - CheckWindow(ObjWindow::SkillTree) - CheckWindow(ObjWindow::CashShop))
	{
		Data[eSACHTHUOCTINH_INTERFACE].OnShow = false;
		return;
	}
	float MainWidth = 30.0;
	float MainHeight = 20.0;
	float StartY = 20.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);


	if (this->CheckWindow(ObjWindow::Inventory))
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			gInterface.DrawGUI(eSACHTHUOCTINH_INTERFACE, Return2X(x + TransForX(287 - 155)), ReturnY(TransForY(180+18)));

			if (this->m_SachThuocTinh_01 >= 1)
			{
				gInterface.DrawItem2(Return2X(x + TransForX(310 - 155)), ReturnY(TransForY(205+18)), 0, 0, ITEM(14, 450), 0, 0, 5, 0);
			}

			if (gInterface.IsWorkZone(eSACHTHUOCTINH_INTERFACE))
			{
				DWORD Color = eGray150;
				gInterface.DrawColoredGUI(eSACHTHUOCTINH_INTERFACE, gInterface.Data[eSACHTHUOCTINH_INTERFACE].X, gInterface.Data[eSACHTHUOCTINH_INTERFACE].Y, Color);
			}


#if(RINGPEDAN_NEW)
			//==========================================================================================================
			gInterface.DrawGUI(ePEDAN_01_INTERFACE, Return2X(x + TransForX(216 - 155)), ReturnY(TransForY(78+18)));

			if (this->m_RingPedan1 >= 1)
			{
				gInterface.DrawItem2(Return2X(x + TransForX(228 - 155)), ReturnY(TransForY(95+18)), 0, 0, ITEM(14, 457), 0, 0, 5, 0);
			}
			//==========================================================================================================
			gInterface.DrawGUI(ePEDAN_02_INTERFACE, Return2X(x + TransForX(216 - 155)), ReturnY(TransForY(98+18)));

			if (this->m_RingPedan2 >= 1)
			{
				gInterface.DrawItem2(Return2X(x + TransForX(228 - 155)), ReturnY(TransForY(123+18)), 0, 0, ITEM(14, 459), 0, 0, 5, 0);
			}
			//==========================================================================================================

			gInterface.DrawGUI(eRING_01_INTERFACE, StartX + 276, StartY + 78);

			if (this->m_RingPedan3 >= 1)
			{
				gInterface.DrawItem2(Return2X(x + TransForX(284 - 155)), ReturnY(TransForY(93+18)), 0, 0, ITEM(14, 458), 0, 0, 5, 0);
			}
			//==========================================================================================================
			gInterface.DrawGUI(eRING_02_INTERFACE, Return2X(x + TransForX(276 - 155)), ReturnY(TransForY(108+18)));//-155,+18

			if (this->m_RingPedan4 >= 1)
			{
				//gInterface.DrawItem2(StartX + 284, StartY + 123, 0, 0, ITEM(14, 460), 0, 0, 5, 0);
				gInterface.DrawItem2(Return2X(x + TransForX(129)), ReturnY(TransForY(141)), 0, 0, ITEM(14, 460), 0, 0, 5, 0);
			}
			

			//==========================================================================================================

			if (this->m_RingPedan1 >= 1)
			{
				if (this ->Data[eSACHTHUOCTINH_MAIN].OnShow)
				{
					return;
				}

				if (pCheckMouseOver(Return2X(x + TransForX(216 - 155)), ReturnY(TransForY(78 + 18)), Return2X(TransForX(24)), ReturnY(TransForY(24))) == 1)
				{
					tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
					int * ColorTexto = (int*)NewAddressData1;
					int * LineWeight = (int*)NewAddressData2;

					int Line = 1;

					wsprintf(TooltipLine[0], "\n");
					ColorTexto[0] = 0;
					LineWeight[0] = 0;

					wsprintf(TooltipLine[Line], "\n");
					ColorTexto[Line] = 0;
					LineWeight[Line++] = 0;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[19], this->m_RingPedan1);
					ColorTexto[Line] = 4;
					LineWeight[Line++] = 2;

					wsprintf(TooltipLine[Line], "                                                                                           ");
					ColorTexto[Line] = 0;
					LineWeight[Line++] = 0;

					wsprintf(TooltipLine[Line], "\n");
					ColorTexto[Line] = 0;
					LineWeight[Line++] = 0;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[2]);
					ColorTexto[Line] = 5;
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[3]);
					ColorTexto[Line] = 14;
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[4]);
					ColorTexto[Line] = 14;
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], "\n");
					ColorTexto[Line] = 0;
					LineWeight[Line++] = 0;
					//----Option
					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[5]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 5) ? 3 : 10); 
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[6]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 5) ? 3 : 10); 
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[7]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 10) ? 3 : 10);
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[8]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 10) ? 3 : 10);
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[9]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 15) ? 3 : 10);
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[10]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 15) ? 3 : 10);
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], gOther.TextVN_RingPedan[11]);
					ColorTexto[Line] = ((this->m_RingPedan1 >= 15) ? 3 : 10);
					LineWeight[Line++] = 1;

					wsprintf(TooltipLine[Line], "\n");
					ColorTexto[Line] = 0;
					LineWeight[Line++] = 0;

					pMultiLineTooltip(Return2X(x - TransForX(110)), ReturnY(TransForY(100)), Line, 0, 3, 1, 1);
				}
			}

			if (this->m_RingPedan2 >= 1)
			{
				if (gInterface.IsWorkZone(ePEDAN_02_INTERFACE))
				{
					DWORD Color = eGray150;
					//-------------------------
					gCItemSetOption.ItemTooltipS15(340, 100, 148, 170, 0.0, 0);
					//-------------------------
					HFONT RING_01 = CreateFontA(12, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
					pSetTextFont(pTextThis(), RING_01);
					pSetTextColor(pTextThis(), 0, 225, 139, 255);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
					char Text_Ring[1024];
					sprintf(Text_Ring, gOther.TextVN_RingPedan[21], this->m_RingPedan2);
					pDrawText(pTextThis(), StartX + 40, StartY + 90, Text_Ring, 0, 0, (LPINT)0, 0);
					//------
					//Giải phóng
					DeleteObject(RING_01);
					//-------------------------
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 110, 100, 1, gOther.TextVN_RingPedan[2]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 120, 100, 1, gOther.TextVN_RingPedan[3]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 130, 100, 1, gOther.TextVN_RingPedan[4]);
					//-------------------------
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
					gInterface.DrawFormat(eGray100, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					//-------------------------
					if (this->m_RingPedan2 >= 5)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					}
					if (this->m_RingPedan2 >= 10)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					}
					if (this->m_RingPedan2 >= 15)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
						gInterface.DrawFormat(eYellow, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					}
					//-------------------------
					gInterface.DrawColoredGUI(ePEDAN_02_INTERFACE, gInterface.Data[ePEDAN_02_INTERFACE].X, gInterface.Data[ePEDAN_02_INTERFACE].Y, Color);
				}
			}


			if (this->m_RingPedan3 >= 1)
			{
				if (gInterface.IsWorkZone(eRING_01_INTERFACE))
				{
					DWORD Color = eGray150;
					//-------------------------
					gCItemSetOption.ItemTooltipS15(340, 100, 148, 170, 0.0, 0);
					//-------------------------
					HFONT RING_01 = CreateFontA(12, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
					pSetTextFont(pTextThis(), RING_01);
					pSetTextColor(pTextThis(), 0, 225, 139, 255);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
					char Text_Pedan01[1024];
					sprintf(Text_Pedan01, gOther.TextVN_RingPedan[20], this->m_RingPedan3);
					pDrawText(pTextThis(), StartX + 50, StartY + 90, Text_Pedan01, 0, 0, (LPINT)0, 0);
					//------
					//Giải phóng
					DeleteObject(RING_01);
					//-------------------------
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 110, 100, 1, gOther.TextVN_RingPedan[2]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 120, 100, 1, gOther.TextVN_RingPedan[3]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 130, 100, 1, gOther.TextVN_RingPedan[4]);
					//-------------------------
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
					gInterface.DrawFormat(eGray100, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					//-------------------------
					if (this->m_RingPedan3 >= 5)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					}
					if (this->m_RingPedan3 >= 10)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					}
					if (this->m_RingPedan3 >= 15)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
						gInterface.DrawFormat(eYellow, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					}
					//-------------------------
					gInterface.DrawColoredGUI(eRING_01_INTERFACE, gInterface.Data[eRING_01_INTERFACE].X, gInterface.Data[eRING_01_INTERFACE].Y, Color);
				}
			}


			if (this->m_RingPedan4 >= 1)
			{
				if (gInterface.IsWorkZone(eRING_02_INTERFACE))
				{
					DWORD Color = eGray150;
					//-------------------------
					gCItemSetOption.ItemTooltipS15(340, 100, 148, 170, 0.0, 0);
					//-------------------------
					HFONT RING_01 = CreateFontA(12, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
					pSetTextFont(pTextThis(), RING_01);
					pSetTextColor(pTextThis(), 0, 225, 139, 255);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
					char Text_Pedan02[1024];
					sprintf(Text_Pedan02, gOther.TextVN_RingPedan[22], this->m_RingPedan4);
					pDrawText(pTextThis(), StartX + 50, StartY + 90, Text_Pedan02, 0, 0, (LPINT)0, 0);
					//------
					//Giải phóng
					DeleteObject(RING_01);
					//-------------------------
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 110, 100, 1, gOther.TextVN_RingPedan[2]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 120, 100, 1, gOther.TextVN_RingPedan[3]);
					gInterface.DrawFormat(eWhite, StartX + 80, StartY + 130, 100, 1, gOther.TextVN_RingPedan[4]);
					//-------------------------
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
					gInterface.DrawFormat(eGray100, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
					gInterface.DrawFormat(eGray100, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					//-------------------------
					if (this->m_RingPedan4 >= 5)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 150, 200, 1, gOther.TextVN_RingPedan[5]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 160, 200, 1, gOther.TextVN_RingPedan[6]);
					}
					if (this->m_RingPedan4 >= 10)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 170, 200, 1, gOther.TextVN_RingPedan[7]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 180, 200, 1, gOther.TextVN_RingPedan[8]);
					}
					if (this->m_RingPedan4 >= 15)
					{
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 190, 200, 1, gOther.TextVN_RingPedan[9]);
						gInterface.DrawFormat(eYellow, StartX + 60, StartY + 200, 200, 1, gOther.TextVN_RingPedan[10]);
						gInterface.DrawFormat(eYellow, StartX + 50, StartY + 210, 200, 1, gOther.TextVN_RingPedan[11]);
					}
					//-------------------------
					gInterface.DrawColoredGUI(eRING_02_INTERFACE, gInterface.Data[eRING_02_INTERFACE].X, gInterface.Data[eRING_02_INTERFACE].Y, Color);
				}
			}
#endif

		}
	}
}
bool Interface::EventSachThuocTinhInterface(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eSACHTHUOCTINH_INTERFACE].EventTick);
	if (!this->CheckWindow(ObjWindow::Inventory) || !IsWorkZone(eSACHTHUOCTINH_INTERFACE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eSACHTHUOCTINH_INTERFACE].EventTick = GetTickCount();

	if (this->m_SachThuocTinh_01 >= 1)
	{
		if (GetForegroundWindow() == pGameWindow)
		{
			if (this->CheckSachThuocTinhWindow())
			{
				this->CloseSachThuocTinhWindow();
			}
			else
			{
				this->OpenSachThuocTinhWindow();
			}
		}
	}
	this->BUG_SACHTHUOCTINH(1);

	this->BUG_SACHTHUOCTINH(8);

	return true;
}
//=========================================================================================================================================
void Interface::DrawSachThuocTinh()
{
	{
		if (this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Warehouse) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse))
		return;
		//--------------------------------------------------------------
		if (!this->Data[eSACHTHUOCTINH_MAIN].OnShow)
		{
			return;
		}
		//--------------------------------------------------------------
		float MainWidth = 30.0;
		float MainHeight = 20.0;
		float StartY = 40.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		//--------------------------------------------------------------
		pDrawGUFULL(61526, StartX - 70, StartY - 25, 340, 620, 0, 0, 1, 1, 1, 1, 0.0);  // IMAGE MENU
		//--------------------------------------------------------------
		pSetCursorFocus = true;
		//--------------------------------------------------------------
		pDrawGUFULL(0x502A, StartX - 18, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
		pDrawGUFULL(0x502A, StartX + 38, StartY + 25, 2, 330, 0, 0, 1, 1, 1, 1, 0.0); // Dọc
		//--------------------------------------------------------------
		pDrawGUFULL(0x501A, StartX - 60, StartY + 50, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		pDrawGUFULL(0x501A, StartX - 60, StartY + 100, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		pDrawGUFULL(0x501A, StartX - 60, StartY + 150, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		pDrawGUFULL(0x501A, StartX - 60, StartY + 200, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		pDrawGUFULL(0x501A, StartX - 60, StartY + 250, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		pDrawGUFULL(0x501A, StartX - 60, StartY + 300, 200, 2, 0, 0, 1, 1, 1, 1, 0.0); // Ngang
		//--------------------------------------------------------------
		gInterface.DrawGUI(eSACHTHUOCTINH_02, StartX - 60, StartY + 51);  //
		gInterface.DrawGUI(eSACHTHUOCTINH_03, StartX - 60, StartY + 101); //
		gInterface.DrawGUI(eSACHTHUOCTINH_04, StartX - 60, StartY + 151); //
		gInterface.DrawGUI(eSACHTHUOCTINH_05, StartX - 60, StartY + 201); //
		gInterface.DrawGUI(eSACHTHUOCTINH_06, StartX - 60, StartY + 251); //
		gInterface.DrawGUI(eSACHTHUOCTINH_07, StartX - 60, StartY + 301); //
		//--------------------------------------------------------------
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_02))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_02, gInterface.Data[eSACHTHUOCTINH_02].X, gInterface.Data[eSACHTHUOCTINH_02].Y, Color);
		}
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_03))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_03, gInterface.Data[eSACHTHUOCTINH_03].X, gInterface.Data[eSACHTHUOCTINH_03].Y, Color);
		}
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_04))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_04, gInterface.Data[eSACHTHUOCTINH_04].X, gInterface.Data[eSACHTHUOCTINH_04].Y, Color);
		}
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_05))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_05, gInterface.Data[eSACHTHUOCTINH_05].X, gInterface.Data[eSACHTHUOCTINH_05].Y, Color);
		}
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_06))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_06, gInterface.Data[eSACHTHUOCTINH_06].X, gInterface.Data[eSACHTHUOCTINH_06].Y, Color);
		}
		if (gInterface.IsWorkZone(eSACHTHUOCTINH_07))
		{
			DWORD Color = eGray150;
			gInterface.DrawColoredGUI(eSACHTHUOCTINH_07, gInterface.Data[eSACHTHUOCTINH_07].X, gInterface.Data[eSACHTHUOCTINH_07].Y, Color);
		}
		//--------------------------------------------------------------
		gInterface.DrawItem2(StartX - 40, StartY + 81, 0, 0, ITEM(14, 451), 15, 63, 0, 0);
		gInterface.DrawItem2(StartX - 40, StartY + 131, 0, 0, ITEM(14, 452), 15, 63, 0, 0);
		gInterface.DrawItem2(StartX - 40, StartY + 181, 0, 0, ITEM(14, 453), 15, 63, 0, 0);
		gInterface.DrawItem2(StartX - 40, StartY + 231, 0, 0, ITEM(14, 454), 15, 63, 0, 0);
		gInterface.DrawItem2(StartX - 40, StartY + 281, 0, 0, ITEM(14, 455), 15, 63, 0, 0);
		gInterface.DrawItem2(StartX - 40, StartY + 331, 0, 0, ITEM(14, 456), 15, 63, 0, 0);
		//--------------------------------------------------------------
		HFONT SACHTHUOCTINH_01 = CreateFontA(18, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Tahoma");
		pSetTextFont(pTextThis(), SACHTHUOCTINH_01);
		pSetTextColor(pTextThis(), 255, 255, 255, 255); // Màu Trắng
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), StartX + 0, StartY - 2, gOther.TextVN_SachThuocTinh[0], 0, 0, (LPINT)0, 0); // "Load"
		//------
		//Giải phóng
		DeleteObject(SACHTHUOCTINH_01);
		//--------------------------------------------------------------
		gInterface.DrawFormat(eAncient, StartX - 60, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[15]);
		gInterface.DrawFormat(eAncient, StartX - 5, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[16]);
		gInterface.DrawFormat(eAncient, StartX + 65, StartY + 25, 1000, 1, gOther.TextVN_SachThuocTinh[17]);
		//--------------------------------------------------------------
		// Slot 2
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);

		if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_01)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_01);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 55, 1000, 1, gOther.TextVN_SachThuocTinh[2], this->m_OPTION_ACTIVE_01);
		}

		// Slot 3
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);

		if (this->m_SachThuocTinh_02 >= this->m_OPTION_LEVEL_02)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_02, this->m_OPTION_LEVEL_02);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 75, 1000, 1, gOther.TextVN_SachThuocTinh[3], this->m_OPTION_ACTIVE_02);
		}

		// Slot 4
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);

		if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_03)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_03);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 105, 1000, 1, gOther.TextVN_SachThuocTinh[4], this->m_OPTION_ACTIVE_03);
		}

		// Slot 5
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);

		if (this->m_SachThuocTinh_03 >= this->m_OPTION_LEVEL_04)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_03, this->m_OPTION_LEVEL_04);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 125, 1000, 1, gOther.TextVN_SachThuocTinh[5], this->m_OPTION_ACTIVE_04);
		}

		// Slot 6
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);

		if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_05)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_05);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 155, 1000, 1, gOther.TextVN_SachThuocTinh[6], this->m_OPTION_ACTIVE_05);
		}

		// Slot 7
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);

		if (this->m_SachThuocTinh_04 >= this->m_OPTION_LEVEL_06)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_04, this->m_OPTION_LEVEL_06);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 175, 1000, 1, gOther.TextVN_SachThuocTinh[7], this->m_OPTION_ACTIVE_06);
		}

		// Slot 8
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);

		if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_07)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_07);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 205, 1000, 1, gOther.TextVN_SachThuocTinh[8], this->m_OPTION_ACTIVE_07);
		}

		// Slot 9
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);

		if (this->m_SachThuocTinh_05 >= this->m_OPTION_LEVEL_08)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_05, this->m_OPTION_LEVEL_08);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 225, 1000, 1, gOther.TextVN_SachThuocTinh[9], this->m_OPTION_ACTIVE_08);
		}

		// Slot 10
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);

		if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_09)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_09);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 255, 1000, 1, gOther.TextVN_SachThuocTinh[10], this->m_OPTION_ACTIVE_09);
		}

		// Slot 11
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);

		if (this->m_SachThuocTinh_06 >= this->m_OPTION_LEVEL_10)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_06, this->m_OPTION_LEVEL_10);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 275, 1000, 1, gOther.TextVN_SachThuocTinh[11], this->m_OPTION_ACTIVE_10);
		}

		// Slot 12
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);

		if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_11)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_11);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 305, 1000, 1, gOther.TextVN_SachThuocTinh[12], this->m_OPTION_ACTIVE_11);
		}

		// Slot 13
		gInterface.DrawFormat(eWhite, StartX - 10, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

		gInterface.DrawFormat(eWhite, StartX + 50, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);

		if (this->m_SachThuocTinh_07 >= this->m_OPTION_LEVEL_12)
		{
			gInterface.DrawFormat(eYellow, StartX - 10, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[14], this->m_SachThuocTinh_07, this->m_OPTION_LEVEL_12);

			gInterface.DrawFormat(eYellow, StartX + 50, StartY + 325, 1000, 1, gOther.TextVN_SachThuocTinh[13], this->m_OPTION_ACTIVE_12);
		}

		//--------------------------------------------------------------
	}
}
bool Interface::EventSachThuocTinh(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------
	// TRANG 1
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_02))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_02].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_02].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_02].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_02].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(2);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_03))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_03].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_03].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_03].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_03].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(3);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_04))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_04].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_04].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_04].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_04].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(4);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_05))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_05].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_05].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_05].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_05].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(5);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_06))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_06].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_06].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_06].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_06].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(6);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[eSACHTHUOCTINH_MAIN].OnShow && gInterface.IsWorkZone(eSACHTHUOCTINH_07))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSACHTHUOCTINH_07].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSACHTHUOCTINH_07].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSACHTHUOCTINH_07].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSACHTHUOCTINH_07].EventTick = GetTickCount();
		this->BUG_SACHTHUOCTINH(7);
	}
	//-----------------------------------------------------------

	return true;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
#if(RINGPEDAN_NEW)
void Interface::DrawRingPedanWinDow()
{
	if (!this->Data[RINGPEDAN_MAIN].OnShow)
	{
		return;
	}
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 80.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(RINGPEDAN_MAIN, StartX, StartY);
	//--------------------------------------------------------------------------------------------
	gCItemSetOption.ItemTooltipS15(StartX + 120, gInterface.Data[RINGPEDAN_MAIN].Y + 30, 165, 190, 0.0, 0);

	gCItemSetOption.ItemTooltipS15(StartX + 125, gInterface.Data[RINGPEDAN_MAIN].Y + 50, 155, 30, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 125, gInterface.Data[RINGPEDAN_MAIN].Y + 90, 155, 30, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 125, gInterface.Data[RINGPEDAN_MAIN].Y + 130, 155, 30, 0.0, 0);
	gCItemSetOption.ItemTooltipS15(StartX + 125, gInterface.Data[RINGPEDAN_MAIN].Y + 170, 155, 30, 0.0, 0);
	//--------------------------------------------------------------------------------------------
	if (this->IsWorkZone(RINGPEDAN_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	////--------------------------------------------------------------------------------------------
	this->DrawGUI(eSEND_PEDAN_01_INTERFACE, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 55);
	if (CheckButtonPressed(StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 55, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 55, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 55, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 134, gInterface.Data[RINGPEDAN_MAIN].Y + 58, 210, 1, gOther.TextVN[153]); // Nâng cấp

	gInterface.DrawItem2(StartX + 180, gInterface.Data[RINGPEDAN_MAIN].Y + 68, 0, 0, ITEM(14, 457), 0, 0, 5, 0);

	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 58, 210, 1, gOther.TextVN[158], this->m_RingPedan1); // Nâng cấp
	this->DrawFormat(eExcellentS15, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 58, 210, 1, gOther.TextVN[154]); // Nâng cấp
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(eSEND_PEDAN_02_INTERFACE, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 95);
	if (CheckButtonPressed(StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 95, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 95, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 95, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 134, gInterface.Data[RINGPEDAN_MAIN].Y + 98, 210, 1, gOther.TextVN[153]); // Nâng cấp

	gInterface.DrawItem2(StartX + 180, gInterface.Data[RINGPEDAN_MAIN].Y + 105, 0, 0, ITEM(14, 459), 0, 0, 5, 0);

	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 98, 210, 1, gOther.TextVN[160], this->m_RingPedan2); // Nâng cấp
	this->DrawFormat(eExcellentS15, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 98, 210, 1, gOther.TextVN[156]); // Nâng cấp
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(eSEND_RING_01_INTERFACE, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 135);
	if (CheckButtonPressed(StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 135, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 135, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 135, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 134, gInterface.Data[RINGPEDAN_MAIN].Y + 138, 210, 1, gOther.TextVN[153]); // Nâng cấp
	gInterface.DrawItem2(StartX + 175, gInterface.Data[RINGPEDAN_MAIN].Y + 148, 0, 0, ITEM(14, 458), 0, 0, 5, 0);

	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 135, 210, 1, gOther.TextVN[159], this->m_RingPedan3); // Nâng cấp
	this->DrawFormat(eExcellentS15, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 135, 210, 1, gOther.TextVN[155]); // Nâng cấp
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	this->DrawGUI(eSEND_RING_02_INTERFACE, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 175);
	if (CheckButtonPressed(StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 175, Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 175, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, StartX + 130, gInterface.Data[RINGPEDAN_MAIN].Y + 175, Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	this->DrawFormat(eWhite, StartX + 134, gInterface.Data[RINGPEDAN_MAIN].Y + 178, 210, 1, gOther.TextVN[153]); // Nâng cấp
	gInterface.DrawItem2(StartX + 175, gInterface.Data[RINGPEDAN_MAIN].Y + 188, 0, 0, ITEM(14, 460), 0, 0, 5, 0);

	this->DrawFormat(eYellow, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 178, 210, 1, gOther.TextVN[161], this->m_RingPedan4); // Nâng cấp
	this->DrawFormat(eExcellentS15, StartX + 190, gInterface.Data[RINGPEDAN_MAIN].Y + 178, 210, 1, gOther.TextVN[157]); // Nâng cấp
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
}
bool Interface::EventRingPedanInterface(DWORD Event)
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	DWORD CurrentTick = GetTickCount();
	//-----------------------------------------------
	if (gInterface.Data[RINGPEDAN_MAIN].OnShow && gInterface.IsWorkZone(eSEND_PEDAN_01_INTERFACE))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSEND_PEDAN_01_INTERFACE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSEND_PEDAN_01_INTERFACE].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSEND_PEDAN_01_INTERFACE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSEND_PEDAN_01_INTERFACE].EventTick = GetTickCount();
		this->BUG_RINGPEDAN(1);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[RINGPEDAN_MAIN].OnShow && gInterface.IsWorkZone(eSEND_PEDAN_02_INTERFACE))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSEND_PEDAN_02_INTERFACE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSEND_PEDAN_02_INTERFACE].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSEND_PEDAN_02_INTERFACE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSEND_PEDAN_02_INTERFACE].EventTick = GetTickCount();
		this->BUG_RINGPEDAN(2);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[RINGPEDAN_MAIN].OnShow && gInterface.IsWorkZone(eSEND_RING_01_INTERFACE))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSEND_RING_01_INTERFACE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSEND_RING_01_INTERFACE].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSEND_RING_01_INTERFACE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSEND_RING_01_INTERFACE].EventTick = GetTickCount();
		this->BUG_RINGPEDAN(3);
	}
	//-----------------------------------------------------------
	if (gInterface.Data[RINGPEDAN_MAIN].OnShow && gInterface.IsWorkZone(eSEND_RING_02_INTERFACE))
	{
		DWORD CurrentTick = GetTickCount();
		DWORD Delay = (CurrentTick - gInterface.Data[eSEND_RING_02_INTERFACE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSEND_RING_02_INTERFACE].OnClick = true;
			pSetCursorFocus = true;
			return true;
		}
		// ----
		gInterface.Data[eSEND_RING_02_INTERFACE].OnClick = false;
		pSetCursorFocus = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		gInterface.Data[eSEND_RING_02_INTERFACE].EventTick = GetTickCount();
		this->BUG_RINGPEDAN(4);
	}
	//-----------------------------------------------------------
	return true;
}
#endif
//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEventEx(PMSG_TVTEVENT_UPD * aRecv)
{
	this->m_ScoreBlue = 0;
	this->m_ScoreBlue = aRecv->ScoreBlue;
	this->m_ScoreRed = 0;
	this->m_ScoreRed = aRecv->ScoreRed;
	this->m_KillCount = 0;
	this->m_KillCount = aRecv->KillCount;
	this->m_DieCount = 0;
	this->m_DieCount = aRecv->DieCount;
	this->m_TotalPlayer = 0;
	this->m_TotalPlayer = aRecv->TotalPlayer;
}

#if(SACHTHUOCTINH_NEW)
void Interface::GetInfoThuocTinh(PMSG_THUOCTINH_UPD * aRecv)
{
	//-----------------------------
	this->m_SachThuocTinh_02 = aRecv->SachThuocTinh_02;
	this->m_SachThuocTinh_03 = aRecv->SachThuocTinh_03;
	this->m_SachThuocTinh_04 = aRecv->SachThuocTinh_04;
	this->m_SachThuocTinh_05 = aRecv->SachThuocTinh_05;
	this->m_SachThuocTinh_06 = aRecv->SachThuocTinh_06;
	this->m_SachThuocTinh_07 = aRecv->SachThuocTinh_07;
}
void Interface::GetInfoThuocTinhAtive(PMSG_THUOCTINH_ATIVE_UPD * aRecv)
{
	//-----------------------------
	this->m_OPTION_LEVEL_01 = aRecv->OPTION_LEVEL_01;
	this->m_OPTION_LEVEL_02 = aRecv->OPTION_LEVEL_02;
	this->m_OPTION_LEVEL_03 = aRecv->OPTION_LEVEL_03;
	this->m_OPTION_LEVEL_04 = aRecv->OPTION_LEVEL_04;
	this->m_OPTION_LEVEL_05 = aRecv->OPTION_LEVEL_05;
	this->m_OPTION_LEVEL_06 = aRecv->OPTION_LEVEL_06;
	this->m_OPTION_LEVEL_07 = aRecv->OPTION_LEVEL_07;
	this->m_OPTION_LEVEL_08 = aRecv->OPTION_LEVEL_08;
	this->m_OPTION_LEVEL_09 = aRecv->OPTION_LEVEL_09;
	this->m_OPTION_LEVEL_10 = aRecv->OPTION_LEVEL_10;
	this->m_OPTION_LEVEL_11 = aRecv->OPTION_LEVEL_11;
	this->m_OPTION_LEVEL_12 = aRecv->OPTION_LEVEL_12;
	this->m_OPTION_ACTIVE_01 = aRecv->OPTION_ACTIVE_01;
	this->m_OPTION_ACTIVE_02 = aRecv->OPTION_ACTIVE_02;
	this->m_OPTION_ACTIVE_03 = aRecv->OPTION_ACTIVE_03;
	this->m_OPTION_ACTIVE_04 = aRecv->OPTION_ACTIVE_04;
	this->m_OPTION_ACTIVE_05 = aRecv->OPTION_ACTIVE_05;
	this->m_OPTION_ACTIVE_06 = aRecv->OPTION_ACTIVE_06;
	this->m_OPTION_ACTIVE_07 = aRecv->OPTION_ACTIVE_07;
	this->m_OPTION_ACTIVE_08 = aRecv->OPTION_ACTIVE_08;
	this->m_OPTION_ACTIVE_09 = aRecv->OPTION_ACTIVE_09;
	this->m_OPTION_ACTIVE_10 = aRecv->OPTION_ACTIVE_10;
	this->m_OPTION_ACTIVE_11 = aRecv->OPTION_ACTIVE_11;
	this->m_OPTION_ACTIVE_12 = aRecv->OPTION_ACTIVE_12;
}
#endif
//=====================================================================

void Interface::GetInfoRingPedan(PMSG_RINGPEDAN_UPD * aRecv)
{
	//-----------------------------
	this->m_SachThuocTinh_01 = aRecv->SachThuocTinh_01;
	//-----------------------------
	this->m_RingPedan1 = aRecv->RingPedan1;
	this->m_RingPedan2 = aRecv->RingPedan2;
	this->m_RingPedan3 = aRecv->RingPedan3;
	this->m_RingPedan4 = aRecv->RingPedan4;

	this->m_AutoResetEnable = aRecv->AutoResetEnable;
	this->m_AttackCustom = aRecv->AttackCustom;
	this->m_GHRS = aRecv->GHRS;
	this->m_DanhHieu = aRecv->DanhHieu;
	this->m_QuanHam = aRecv->QuanHam;
	this->m_Money = aRecv->Money;
	//tue add Tu Luyen
	this->m_TuLuyen = aRecv->Money;
}

//=====================================================================
//---------------------------------------------------------
#if(SACHTHUOCTINH_NEW)
void Interface::BUG_SACHTHUOCTINH(int Number)
{
	SACHTHUOCTINH_REQ pMsg;
	pMsg.h.set(0xFC, 0x09, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif
//---------------------------------------------------------
#if(RINGPEDAN_NEW)
void Interface::BUG_RINGPEDAN(int Number)
{
	BUY_RINGPEDAN_REQ pMsg;
	pMsg.h.set(0xFC, 0x10, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}
#endif
//---------------------------------------------------------
//=========================================================================================================================================
//=========================================================================================================================================
#if(EXBEXO_LOAD_TIME_EVENT)

void Interface::MOVE_EVENT_GAME(int Number)
{
	MOVE_EVENT_REQ pMsg;
	pMsg.h.set(0xFC, 0x11, sizeof(pMsg)); // Gửi Xuống Server Protocol.cpp
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

bool Interface::EventEventTimeWindow_Move_01(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_01].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_01))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_01].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_01].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_01].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(1);

	return true;
}
bool Interface::EventEventTimeWindow_Move_02(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_02].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_02))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_02].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_02].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_02].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(2);

	return true;
}
bool Interface::EventEventTimeWindow_Move_03(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_03].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_03))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_03].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_03].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_03].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(3);

	return true;
}
bool Interface::EventEventTimeWindow_Move_04(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_04].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_04))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_04].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_04].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_04].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(4);

	return true;
}
bool Interface::EventEventTimeWindow_Move_05(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_05].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_05))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_05].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_05].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_05].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(5);

	return true;
}
bool Interface::EventEventTimeWindow_Move_06(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_06].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_06))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_06].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_06].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_06].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(6);

	return true;
}
bool Interface::EventEventTimeWindow_Move_07(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_07].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_07))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_07].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_07].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_07].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(7);

	return true;
}
bool Interface::EventEventTimeWindow_Move_08(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_08].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_08))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_08].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_08].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_08].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(8);

	return true;
}
bool Interface::EventEventTimeWindow_Move_09(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_09].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_09))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_09].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_09].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_09].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(9);

	return true;
}
bool Interface::EventEventTimeWindow_Move_10(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_10].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_10))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_10].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_10].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_10].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(10);

	return true;
}
bool Interface::EventEventTimeWindow_Move_11(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_11].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_11))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_11].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_11].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_11].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(11);

	return true;
}
bool Interface::EventEventTimeWindow_Move_12(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_12].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_12))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_12].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_12].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_12].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(12);

	return true;
}
bool Interface::EventEventTimeWindow_Move_13(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_13].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_13))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_13].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_13].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_13].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(13);

	return true;
}
bool Interface::EventEventTimeWindow_Move_14(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_14].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_14))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_14].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_14].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_14].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(14);

	return true;
}
bool Interface::EventEventTimeWindow_Move_15(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_15].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_15))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_15].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_15].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_15].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(15);

	return true;
}
bool Interface::EventEventTimeWindow_Move_16(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_16].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_16))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_16].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_16].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_16].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(16);

	return true;
}
bool Interface::EventEventTimeWindow_Move_17(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_17].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_17))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_17].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_17].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_17].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(17);

	return true;
}
bool Interface::EventEventTimeWindow_Move_18(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_18].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_18))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_18].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_18].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_18].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(18);

	return true;
}
bool Interface::EventEventTimeWindow_Move_19(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_19].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_19))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_19].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_19].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_19].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(19);

	return true;
}
bool Interface::EventEventTimeWindow_Move_20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_20].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_20))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_20].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_20].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_20].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(20);

	return true;
}
bool Interface::EventEventTimeWindow_Move_21(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_21].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_21))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_21].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_21].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_21].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(21);

	return true;
}
bool Interface::EventEventTimeWindow_Move_22(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_22].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_22))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_22].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_22].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_22].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(22);

	return true;
}
bool Interface::EventEventTimeWindow_Move_23(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_23].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_23))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_23].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_23].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_23].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(23);

	return true;
}
bool Interface::EventEventTimeWindow_Move_24(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_24].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_24))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_24].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_24].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_24].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(24);

	return true;
}
bool Interface::EventEventTimeWindow_Move_25(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_25].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_25))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_25].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_25].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_25].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(25);

	return true;
}
bool Interface::EventEventTimeWindow_Move_26(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eEVENTTABLE_MOVE_26].EventTick);
	if (!this->Data[eEventTimePANEL_MAIN].OnShow || !IsWorkZone(eEVENTTABLE_MOVE_26))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eEVENTTABLE_MOVE_26].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	this->Data[eEVENTTABLE_MOVE_26].OnClick = false;
	pSetCursorFocus = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eEVENTTABLE_MOVE_26].EventTick = GetTickCount();

	this->MOVE_EVENT_GAME(26);

	return true;
}

#endif
//=========================================================================================================================================
//=========================================================================================================================================
#if(OFFLINE_MODE_NEW)
void Interface::DrawOffExpWindow()
{
	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return;
	}
	// ----
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0; // 100.0
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	//---------------------------------------------------------------------------------------//
	if (this->IsWorkZone(eOFFEXP_MAIN)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//---------------------------------------------------------------------------------------//
	pDrawMessage("", 0); // Không Cho Hiện Thông Báo Trên Màn Hình
	//---------------------------------------------------------------------------------------//
	this->DrawGUI(eOFFEXP_MAIN, StartX, StartY + 20);

	//gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 20, 260, 280, 0.0, 150);
	gCItemSetOption.ItemTooltipS15(StartX - 15, gInterface.Data[eOFFEXP_MAIN].Y + 30, 260, 260, 0.0, 150);

	//this->DrawGUI(eOFFEXP_TITLE, StartX, StartY);
	//StartY = this->DrawRepeatGUI(eOFFEXP_FRAME, StartX, StartY + 67.0, 13);
	//this->DrawGUI(eOFFEXP_FOOTER, StartX, StartY);

	this->DrawGUI(eOFFEXP_CLOSE, StartX + 217, this->Data[eOFFEXP_MAIN].Y + 25);
	// ----
	if (this->IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_CLOSE, this->Data[eOFFEXP_CLOSE].X, this->Data[eOFFEXP_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eOFFEXP_CLOSE].X + 5, this->Data[eOFFEXP_CLOSE].Y + 25, "Close");
	}
	// ----

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 5, 210, 3, "Treo Máy Offline"); // Treo Máy Offline

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 35, 210, 3, "Chào[%s]!Bạn đang bận việc và muốn treo máy ?", gObjUser.lpPlayer->Name); // "Chào [%s]! Bạn đang bận việc và muốn treo máy?"

	this->DrawFormat(eWhite, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 55, 210, 3, "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."); // "Ở chế độ này, bạn có thể cày level khi máy tính của bạn đã tắt."

	pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
	pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 78, 82.0, 2.0); // Äåëèòåëü ìåëêèé 2


	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	char szText[7][64] =
	{
		"Tự động Buff",
		"NULL",
		"Nhặt Zen",
		"Nhặt Ngọc",
		"Nhặt Item Hoàn hảo",
		"Nhặt Items Thần",
		"Nhặt Items có trong danh sách Auto train"
	};

	for (int i = 0; i<8; i++)
	{
		pDrawGUI(0x7B5E, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 1
		pDrawGUI(0x7B5E, StartX + 30 + 82, this->Data[eOFFEXP_MAIN].Y + 114 + (20 * i), 82.0, 2.0); // Äåëèòåëü ìåëêèé 2

		if (i != 1 && i != 7)
		{
			int btn = 1;
			if (i == 0 && gOfflineMode.DrawBuff == 0)
			{
				btn = 0;
			}

			if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
			{
				btn = 0;
			}

			this->DrawGUI(eOFFEXP_POINT, StartX + 30, this->Data[eOFFEXP_MAIN].Y + 120 + (20 * i)); //
			this->DrawFormat(eWhite, StartX + 45, this->Data[eOFFEXP_MAIN].Y + 121 + (20 * i), 200, 1, szText[i]);
			if (btn == 1)
			{
				this->DrawButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i));
			}
			else
			{
				this->DrawColoredButton(ObjectIDs[i], ButtonX + 117, this->Data[eOFFEXP_MAIN].Y + 117 + (20 * i), 0, 15 * gOfflineMode.GetCheckBox(i), eGray150);
			}

		}
	}

	this->DrawFormat(eGold, StartX + 10, this->Data[eOFFEXP_MAIN].Y + 141, 210, 3, "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."); // "Tùy chọn nhặt Item chỉ sử dụng cho tài khoản Vip."

	this->DrawGUI(eOFFEXP_BTN_OK, ButtonX - 3, this->Data[eOFFEXP_MAIN].Y + 260);
	this->DrawFormat(eWhite, StartX + 5, this->Data[eOFFEXP_MAIN].Y + 270, 210, 3, "Bắt Đầu"); // "Bắt Đầu"

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Color = eGray100;
		// ----
		if (this->Data[eOFFEXP_BTN_OK].OnClick)
		{
			Color = eGray150;
		}
		// ----
		this->DrawColoredGUI(eOFFEXP_BTN_OK, this->Data[eOFFEXP_BTN_OK].X, this->Data[eOFFEXP_BTN_OK].Y, Color);
	}

	gOfflineMode.DrawSkill(0, StartX);
	gOfflineMode.DrawSkill(1, StartX);
	gOfflineMode.DrawSkill(2, StartX);

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		if (this->IsWorkZone(StartX + (50 * (i + 1)), this->Data[eOFFEXP_MAIN].Y + 83, StartX + (50 * (i + 1)) + 20, this->Data[eOFFEXP_MAIN].Y + 83 + 28))
		{
			this->DrawToolTipEx(eWhite, StartX + (50 * (i + 1)) - 14, this->Data[eOFFEXP_MAIN].Y + 123, 50, 30, 3, gOfflineMode.SkillsName[i]);
		}
	}

	//if ((gObjUser.lpPlayer->Class & 7) == DarkWizard)
	//{
	//	pDrawGUI(0x1000, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1001, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1002, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkKnight)
	//{
	//	pDrawGUI(0x1003, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1004, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1005, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Elf)
	//{
	//	pDrawGUI(0x1006, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1007, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1008, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == MagicGladiator)
	//{
	//	pDrawGUI(0x1009, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1010, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1011, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == DarkLord)
	//{
	//	pDrawGUI(0x1012, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1013, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1014, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Summoner)
	//{
	//	pDrawGUI(0x1015, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1016, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1017, StartX + 150, this->Data[eOFFEXP_MAIN].Y + 83, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}
	//else if ((gObjUser.lpPlayer->Class & 7) == Monk)
	//{
	//	pDrawGUI(0x1018, StartX + 50, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1

	//	pDrawGUI(0x1019, StartX + 100, this->Data[eOFFEXP_MAIN].Y + 84, 20, 27); // Äåëèòåëü ìåëêèé 1
	//}

}
// ----------------------------------------------------------------------------------------------
bool Interface::EventOffExpWindow_Main(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->Data[eOFFEXP_MAIN].OnShow)
	{
		return false;
	}

	if (IsWorkZone(eOFFEXP_CLOSE))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_CLOSE].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_CLOSE].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].OnClick = false;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_CLOSE].EventTick = GetTickCount();

		this->SwitchOffExpWindoState();
		// ----
		return false;
	}

	if (IsWorkZone(eOFFEXP_BTN_OK))
	{
		DWORD Delay = (CurrentTick - this->Data[eOFFEXP_BTN_OK].EventTick);
		// ----
		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eOFFEXP_BTN_OK].OnClick = true;
			return true;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].OnClick = false;;
		// ----
		if (Delay < 500)
		{
			return false;
		}
		// ----
		this->Data[eOFFEXP_BTN_OK].EventTick = GetTickCount();
		gOfflineMode.SendOffExpData();
		this->SwitchOffExpWindoState();
	}

	int ObjectIDs[7] =
	{
		eOFFEXP_CHECKBOX_BUFF,
		0,
		eOFFEXP_CHECKBOX_PICK_ZEN,
		eOFFEXP_CHECKBOX_PICK_JEWELS,
		eOFFEXP_CHECKBOX_PICK_EXC,
		eOFFEXP_CHECKBOX_PICK_ANC,
		eOFFEXP_CHECKBOX_SELECTED_HELPER
	};

	for (int i = 0; i<7; i++)
	{
		if (i == 1) continue;

		if (i == 0 && gOfflineMode.DrawBuff == 0)
		{
			continue;
		}

		if ((i >= 2 && i <= 6) && gOfflineMode.DrawPick == 0)
		{
			continue;
		}

		if (this->IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - this->Data[ObjectIDs[i]].EventTick);
			// ----
			if (!this->Data[eOFFEXP_MAIN].OnShow)
			{
				return false;
			}
			// ----
			if (Event == WM_LBUTTONDOWN)
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if (Delay < 200)
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();
			gOfflineMode.ChangeCheckBox(i);
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (gOfflineMode.SkillsIndex[i] == 0)
		{
			continue;
		}

		float X = gOfflineMode.GetSkillX(i);
		float Y = gOfflineMode.GetSkillY(i);

		if (this->IsWorkZone(X, Y, X + 20, Y + 28))
		{
			DWORD Delay = (CurrentTick - gOfflineMode.m_SkillCoord[i].EventTick);

			if (Event == WM_LBUTTONDOWN)
			{
				continue;
			}
			// ----
			if (Delay < 500)
			{
				continue;
			}

			gOfflineMode.m_SkillCoord[i].EventTick = GetTickCount();

			if (gOfflineMode.SkillsData[i] == 0)
			{
				return false;
			}

			gOfflineMode.ClearSelectedSkill();
			gOfflineMode.SelectedSkill[i] = true;
		}
	}
	return false;
}
#endif


//=========================================================================================================================================
//=========================================================================================================================================
void Interface::TvTEvent()
{

	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	//===================================================================================================
	if (pMapNumber == 82)
	{
		this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);
		this->DrawFormat(eRed, MAX_WIN_WIDTH - 176, 3, 70, 3, "%d", this->m_ScoreRed);
		this->DrawFormat(eBlue, MAX_WIN_WIDTH - 150, 3, 70, 3, "%d", this->m_ScoreBlue);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", this->m_KillCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", this->m_DieCount);
		this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", this->m_TotalPlayer);
	}
	//===================================================================================================
	//if (gObjUser.m_SurvivorStart)
	//{
	//	this->DrawGUI(eTVTHUD, MAX_WIN_WIDTH - 162, 0);
	//	this->DrawFormat(eWhite, MAX_WIN_WIDTH - 112, 3, 70, 3, "%d", gObjUser.m_SurvivorKill);
	//	this->DrawFormat(eWhite, MAX_WIN_WIDTH - 82, 3, 70, 3, "%d", gObjUser.m_SurvivorDie);
	//	this->DrawFormat(eWhite, MAX_WIN_WIDTH - 52, 3, 70, 3, "%d", gObjUser.m_SurvivorTotal);
	//}
}
// ----------------------------------------------------------------------------------------------
//======================================================================================================================================================
#if(DEV_DAMAGE_TABLE)

void Interface::DrawDamageTable()
{
	if (MinimizarOfRank == 1)
			{
			}
			if (MinimizarOfRank == 0)
			{
	/////////
	
	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::ChatWindow)
		|| this->CheckWindow(ObjWindow::Store)
		|| this->CheckWindow(ObjWindow::Character)
		|| this->CheckWindow(ObjWindow::Inventory)
		|| this->CheckWindow(ObjWindow::Quest)
		|| this->CheckWindow(ObjWindow::MoveList))
	{
		return;
	}

	if(!gDamageTable)
	{
		return ;
	}
	
	if(!gObjUser.m_SecondInfo)
	{
		return;
	}

	if(this->MiniMapCheck() || this->CombinedChecks())
	{
		return;
	}

	/////////////////

	float Wind = 10;
	float Hig = 10 - 85;
	
	gInterface.RightMiniInfoY -= Hig;

	float PosX = 531;
	float PosY = gInterface.RightMiniInfoY - 30;

	this->DrawBarForm(PosX, PosY, 130, 130, 0, 0, 0, 255);
	//pDrawColorButton(0x7880, PosX, PosY, Wind, Hig, NULL, NULL, Color4f(0, 0, 0, 100));

	this->DrawFormat(eAncient, PosX, PosY, 100, 3, "Dev By Solar");

	this->DrawFormat(eGold180, PosX + 0, PosY + 20, 100, 1, "-ST Nhiều Nhất:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 30, 100, 1, "-Quái Đánh Mất HP:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 40, 100, 1, "-Dame Giết Người:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 50, 100, 1, "-ST Lớn Nhất:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 60, 100, 1, "-Tổng Phản ST:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 70, 100, 1, "-Giảm Sát Thương:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 80, 100, 1, "-Damage Chí Mạng:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 90, 100, 1, "-Damage Hoàn Hảo:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 100, 100, 1, "-Damage x2:");
	this->DrawFormat(eGold180, PosX + 0, PosY + 110, 100, 1, "-Bỏ Qua Phòng Thủ:");


	this->DrawFormat(eBlowPink, PosX + 70, PosY + 20, 100, 1, "%d", gObjUser.m_SecondDamage);
	this->DrawFormat(eBlowPink, PosX + 70, PosY + 30, 100, 1, "%d", gObjUser.m_SecondDefence);
	this->DrawFormat(eBlowPink, PosX + 70, PosY + 40, 100, 1, "%d", gObjUser.m_SecondReflect);
	this->DrawFormat(eBlowPink, PosX + 70, PosY + 50, 100, 1, "%d", gObjUser.m_SecondDamageMax);
	this->DrawFormat(eYellow, PosX + 70, PosY + 60, 100, 1, "%d%%", g_StatsAdvance.m_Data.TotalDamageReflect);
	this->DrawFormat(eYellow, PosX + 70, PosY + 70, 100, 1, "%d%%", g_StatsAdvance.m_Data.DamageReductionRate);
	this->DrawFormat(eYellow, PosX + 70, PosY + 80, 100, 1, "%d%%", g_StatsAdvance.m_Data.CriticalDamageRate);
	this->DrawFormat(eYellow, PosX + 70, PosY + 90, 100, 1, "%d%%", g_StatsAdvance.m_Data.ExellentDamageRate);
	this->DrawFormat(eYellow, PosX + 70, PosY + 100, 100, 1, "%d%%", g_StatsAdvance.m_Data.DoubleDamageRate);
	this->DrawFormat(eYellow, PosX + 70, PosY + 110, 100, 1, "%d%%", g_StatsAdvance.m_Data.IgnoreDefenceRate);
	
	/////////
	
}

}
#endif
//===========
void CGMoveCTCMini(int Type) 
{
	if(Type > 0) 
	{
	CTCMINI_CGPACKET pMsg;
	pMsg.header.set(0xF3, 0x39, sizeof(pMsg));	
	pMsg.CongVao = Type-1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}
DWORD ClickTickCount = 0;

void Interface::DrawCTCMiniWindow() 
{

	if(!this->Data[eCTCMiniWindow].OnShow) 
	{
		return;
	}
	float CuaSoW			=	250.0;
	float CuaSoH			=	250.0;

	float StartX			= (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY			= 45.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);
		if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;
	//======Close
	int CloseX = StartX+CuaSoW-40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY , 36.0f, 29.0f);
	if ( pCheckMouseOver(CloseX, CloseY, 36, 36) == 1 )
	{
      if ( GetTickCount() - ClickTickCount > 300 )
      {
        if ( GetKeyState(1) & 0x8000 )
        {
          glColor3f(1.0f, 0.0f, 0.0f);
		  gInterface.Data[eCTCMiniWindow].OnShow ^= 1;
          ClickTickCount = GetTickCount();
        }
      }
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX+15, CloseY+30, 0, 1, "Đóng");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "CTC Mini"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================
	StartY = StartY+ 45;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: + 5000 Wcoin khi Phá Cổng"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: + 10000 Wcoin khi Chiếm Trụ"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontNormal, StartX+(CuaSoW/10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Cả guild: + 20000 Wcoin khi Thắng Sự Kiện"); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontBold, StartX+(CuaSoW/10), StartY, 0x00FFCCFF, 0x0, CuaSoW, 0, 1, "Lưu ý: Guild Chiếm 2 trụ trở lên sẽ thắng."); //
	StartY = StartY+12;
	CustomFont.Draw(CustomFont.FontBold, StartX+(CuaSoW/10), StartY, 0x00FF90FF, 0x0, CuaSoW, 0, 1, "Guild Chiến Thắng Sự Kiện Trước Sẽ Được Vào 'Lãnh Địa'"); //
	StartY = StartY+25;
	pDrawGUI(32583, StartX, StartY, 128.0f, 128.0f); //Huong Dan CTC

	//============Button
	StartY = StartY+10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX+(CuaSoW/2);
	//=====================Button 1
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  CGMoveCTCMini(1);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 1"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 2
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(2);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 2"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 3
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(3);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 3"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button 4
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(4);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 4"); //Buoc Vao
	//=====================================
	StartY = StartY+22;
	//=====================Button Lanh Dia
	if ( pCheckMouseOver(StartX, StartY, SizeButtonW, SizeButtonH) == 1 && CheckVaoLanhDia)
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCTCMiniWindow].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  CGMoveCTCMini(5);
			  this->Data[eCTCMiniWindow].OnShow  = 0;
			  gInterface.Data[eCTCMiniWindow].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} 
	else if (!CheckVaoLanhDia) {
		glColor3f(0.42f, 0.42f, 0.42f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Lãnh Địa"); //Buoc Vao
	//=====================================
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawCTCMiNiMap() 
{	
	if(pPlayerState < GameProcess) {
		return;
	}
	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)	
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
	    || gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
		if(gObjUser.m_MapNumber != 98 ) {
				return;
		}
		float MainWidth = 138.0;
		float MainHeight = 265.0;
		float StartY = 264.0;
		float StartX = 512.0; //512

		pDrawGUI(32584, StartX, StartY , 128.0f, 157.0f); //UI
		pDrawGUI(32583, StartX, StartY+28.0 , 128.0f, 128.0f); //MAP
		//== Cong Vao 1
		if(CTCMINI_Cong[0] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 96 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}
		//== Cong Vao 2
		if(CTCMINI_Cong[1] == 0) {
		RenderBitmap(31681, (float)(StartX - 3 + 128 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}
		//== Cong Vao 3
		if(CTCMINI_Cong[2] == 0) {
		RenderBitmap(31681, (float)(StartX - 2.5 + 161 / 2), (float)(294 - 5 + (255 - 130) / 2), 7.0, 7.0, 0.0, 0.0, 0.875, 0.875, 1, 1, 0.0);
		}

		//Tru Chua Cong 1 //31683 Thuoc Ve Guild
		if(CTCMINI_Tru[0] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 96 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}
		//Tru Chua Cong 2
		if(CTCMINI_Tru[1] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 128 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}
		//Tru Chua Cong 3
		if(CTCMINI_Tru[2] == 0) {
		RenderBitmap(31680, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		} else  {
		RenderBitmap(31683, (float)(StartX - 4.5 + 161 / 2), (float)(294 - 6 + (255 - 165) / 2), 9.0, 8.0, 0.0, 0.0, 0.5625, 1.0, 1, 1, 0.0);
		}
		//pDrawGUI(32585, 640/2-(210/2), 480/2-(94/2),210,94);

		int Model;

		for(int i=0;i < 400 ;i++)
		{
			Model = pGetPreviewStruct(pPreviewThis(), i);
			if(!Model) {
				continue;
			}
			if ( Model
				&& *(BYTE *)(Model + 780)
				&&  *(BYTE *)(Model + 800) == emPlayer
				)
			{
				if(Model != *(DWORD *)0x7BC4F04) {
				  this->DrawGUI(eOTHERCHAR_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
				} else {
				  this->DrawGUI(eCHAR_POINT, (float)(StartX - 1 + *(DWORD *)(Model + 172) / 2), (float)(294 - 1 + (255 - *(DWORD *)(Model + 176)) / 2));
				}
				
			}
		}
}

#if(CHIEN_TRUONG_CO)
void Interface::DrawChienTruongCo() 
{
	if(!this->Data[eCuaSoCTC].OnShow) 
	{
		return;
	}

	float CuaSoW			=	230.0;
	float CuaSoH			=	200.0;

	float StartX			= (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY			= 45.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

		if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	//======Close
	int CloseX = StartX+CuaSoW-40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY , 36.0f, 29.0f);
	if ( pCheckMouseOver(CloseX, CloseY, 36, 36) == 1 )
	{
      if ( GetTickCount() - ClickTickCount > 300 )
      {
        if ( GetKeyState(1) & 0x8000 )
        {
          glColor3f(1.0f, 0.0f, 0.0f);
		  gInterface.Data[eCuaSoCTC].OnShow ^= 1;
          ClickTickCount = GetTickCount();
        }
      }
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX+15, CloseY+30, 0, 1, "Đóng");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+5, 0xB8E600FF, 0x0, CuaSoW, 0, 3,"Chiến Trường Cổ"); //
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	StartX = StartX+(CuaSoW / 8);
	StartY = StartY+45;
	//====================================
	int hours			= CTC_TimeConLai/3600;
	int minutes			= (CTC_TimeConLai/60) % 60;  
	int seconds			= CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xE6FCF7FF, 0x0, CuaSoW, 0, 1, "Thời gian còn lại:"); //
	CustomFont.Draw(CustomFont.FontBold, StartX+70, StartY, 0x16FAC1FF, 0x0, CuaSoW, 0, 1, "%02d:%02d:%02d", hours, minutes, seconds); //
	//===================================
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Tiêu Diệt Đủ %d Quái Nhận 1 Ngọc Ngẫu Nhiên",CTC_MonterYeuCau); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mỗi Ngày Miễn Phí 40 Phút", CTC_PartyKillPoint); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "- Mua Thêm 60 Phút Mất 50k Wcoin",CTC_PointKillQuai); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY, 0x26FFD0FF, 0x0, CuaSoW, 0, 1, "- Có Khả Năng Rớt Lông Vũ, HHHT"); //
	StartY = StartY+15;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY, 0xFF7226FF, 0x0, CuaSoW, 0, 1, "Lưu Ý : Khu vực PK Tự Do, Hãy Cẩn Thận"); //


	//============Button
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX-10;
	//=====================Button 1
	if ( pCheckMouseOver(StartX, StartY+40, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
		  
			  glColor3f(0.72f, 0.438f, 0.0432f);
			  

			  XULY_CGPACKET pMsg;
			  pMsg.header.set(0xF3, 0x38, sizeof(pMsg));	
			  pMsg.ThaoTac = 1;
			  DataSend((LPBYTE)&pMsg, pMsg.header.size);
			  this->Data[eCuaSoCTC].OnShow  = 0;
			  gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			  //pDrawMessage ( "Button 2", 0 );
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX, StartY+40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX, StartY+40 + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Bước Vào"); //Buoc Vao

	//=====================================
	//=====================Button 2
	if ( pCheckMouseOver(StartX+SizeButtonW+5, StartY+40, SizeButtonW, SizeButtonH) == 1 )
    {
		glColor3f(1.0f, 0.6742f, 0.15f);
		  if ( GetTickCount() - gInterface.Data[eCuaSoCTC].EventTick > 300 ) //Click
		  {
			if ( GetKeyState(1) & 0x8000 )
			{
			  glColor3f(0.72f, 0.438f, 0.0432f);

			  XULY_CGPACKET pMsg;
			  pMsg.header.set(0xF3, 0x38, sizeof(pMsg));	
			  pMsg.ThaoTac = 2;
			  DataSend((LPBYTE)&pMsg, pMsg.header.size);
			  //pDrawMessage ( "Button 2", 0 );		  
			  gInterface.Data[eCuaSoCTC].EventTick = GetTickCount();
			}
		  }
	} else {
		glColor3f(1.0f, 1.0f, 1.0f);
		
	}
	RenderBitmap(31563, StartX+SizeButtonW+5, StartY+40, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX+SizeButtonW+5, StartY+40 + (SizeButtonH/4), 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3,"Thêm Thời Gian"); //
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
	
}



void Interface::DrawTimeCTC() 
{

	if(gInterface.CheckWindow(ObjWindow::CashShop) 
		||gInterface.CheckWindow(ObjWindow::FriendList)
		||gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)	
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
	    || gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)	
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if(pMapNumber != 97) {
		return;
	}
	float CuaSoW			=	130.0;
	float CuaSoH			=	81.0;

	float StartX			= 516.0;
	float StartY			= 348.0;
	//RenderBitmap(31566, StartX, StartY, CuaSoW, CuaSoH, 0.0, 0.0, 1.0, 1.0, 1, 1, 0);
	pDrawGUI(31650, 412.0f, 342.0f, 227.0f, 87.0f);
	int PhanTramKill;
	if(CTC_MonterYeuCau > 0) {
		PhanTramKill = (CTC_QuaiVatDaKill * 100) / CTC_MonterYeuCau;
		if(PhanTramKill > 100) { PhanTramKill = 100;}
		CustomFont.Draw(CustomFont.FontNormal, StartX, StartY+5, 0xFF7226FF, 0x0, CuaSoW, 0, 3, "Đã Tiêu Diệt: %d/%d Quái",CTC_QuaiVatDaKill,CTC_MonterYeuCau); //
	}
	//================ Tinh Toan Time
	if((GetTickCount()-gInterface.Data[eTimeCTC].EventTick) > 1000)
		{
			if (CTC_TimeConLai > 0)
			{
				CTC_TimeConLai = CTC_TimeConLai-1;
			}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours			= CTC_TimeConLai/3600;
	int minutes			= (CTC_TimeConLai/60) % 60;  
	int seconds			= CTC_TimeConLai % 60;
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY+35, 0x16FAC1FF, 0x0, CuaSoW, 0, 3, "Thời Gian Còn Lại : %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================
	float TyLeTGA = (166.0 * PhanTramKill) / 100;
	if(TyLeTGA > 166.0) { TyLeTGA = 166.0;}
	pDrawGUI(31653, 471.5f, 421.0f, TyLeTGA, 7.0f);


}
#endif
/*float VitriX = 150.0;
float VitriY = 380.0;
bool QuayLai = false;
int res = 204;
int begin_time = 0*/;
//void Interface::DrawTextTTTTTT()
//{
//
//	
//		if (gInterface.CheckWindow(Inventory)
//		|| gInterface.CheckWindow(Character) //-- 13 & 16
//		|| gInterface.CheckWindow(Warehouse) //-- 8
//		|| gInterface.CheckWindow(Shop) //-- 12
//		|| gInterface.CheckWindow(ChaosBox) //-- 9
//		|| gInterface.CheckWindow(Trade) //-- 7
//		|| gInterface.CheckWindow(Store) //-- 14
//		|| gInterface.CheckWindow(OtherStore) //-- 15
//		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
//		|| gInterface.CheckWindow(NPC_ChaosMix)) //-- 76
//		{
//			return;
//		}
//
//		if (!QuayLai && VitriX < 650)
//		{
//
//			VitriX++;
//		}
//		else
//		{
//			VitriX = 70.0;
//			res++; 
//		}
//
//		if(res > 212)
//		{	
//		res = 204;
//		}
//
//		HFONT TextFontBold_1 = CreateFontA(15, 0, 0, 0, 700, 0, 0, 0, 0x1, 0, 0, 3, 0, "Arial");
//		pSetTextFont(pTextThis(), TextFontBold_1); //set font
//		pSetTextColor(pTextThis(), 255, 255, 0, 255); // color
//		//pSetBackgroundTextColor(pTextThis(), 173, 255, 47, 255);
//		pDrawText(pTextThis(),VitriX, VitriY, gOther.TextVN[res], 650, 0, (LPINT)0, 0);
//		DeleteObject(TextFontBold_1);
//
//}
// Leo thap
#if(LEOTHAP == 1)
void Interface::DrawLeoThap()
{
    if( !this->Data[eLEOTHAP_MAIN].OnShow )
    {
        return;
    }
    // ----
    DWORD ItemNameColor     = eWhite;
    float MainWidth         = 230.0;
    float MainHeight        = 313.0;
    float StartY            = 100.0;
    float StartX            = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
    float MainCenter        = StartX + (MainWidth / 3);
    float ButtonX           = MainCenter - (29.0 / 2);
    // ----
    this->DrawGUI(eLEOTHAP_MAIN, StartX - 170, StartY - 50);
    this->DrawGUI(eLEOTHAP_TITLE, StartX - 170, StartY - 50);
    StartY = this->DrawRepeatGUI(eLEOTHAP_FRAME, StartX - 170, StartY + 17.0, 13);
    this->DrawGUI(eLEOTHAP_FOOTER, StartX - 170, StartY);
    this->DrawGUI(eLEOTHAP_CLOSE, StartX + MainWidth - this->Data[eLEOTHAP_CLOSE].Width - 170, this->Data[eLEOTHAP_TITLE].Height + this->Data[eLEOTHAP_CLOSE].Height - 47);
    // ----
    if( IsWorkZone(eLEOTHAP_BUTTON_GATE1) )
    {
        if( this->Data[eLEOTHAP_BUTTON_GATE1].OnClick )
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 30);
        }
        else
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 29);
        }
    }
    else
    {
        this->DrawButton(eLEOTHAP_BUTTON_GATE1, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 28, 0, 0);
    }
 
    if( IsWorkZone(eLEOTHAP_BUTTON_GATE2) )
    {
        if( this->Data[eLEOTHAP_BUTTON_GATE2].OnClick )
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 30);
        }
        else
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 29);
        }
    }
    else
    {
        this->DrawButton(eLEOTHAP_BUTTON_GATE2, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 63, 0, 0);
    }
 
    if( IsWorkZone(eLEOTHAP_BUTTON_GATE3) )
    {
        if( this->Data[eLEOTHAP_BUTTON_GATE3].OnClick )
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 30);
        }
        else
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 29);
        }
    }
    else
    {
        this->DrawButton(eLEOTHAP_BUTTON_GATE3, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 98, 0, 0);
    }
 
    if( IsWorkZone(eLEOTHAP_BUTTON_GATE4) )
    {
        if( this->Data[eLEOTHAP_BUTTON_GATE4].OnClick )
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 30);
        }
        else
        {
            this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 29);
        }
    }
    else
    {
        this->DrawButton(eLEOTHAP_BUTTON_GATE4, ButtonX - 80, this->Data[eLEOTHAP_MAIN].Y + 133, 0, 0);
    }
 
	if( this->IsWorkZone(eLEOTHAP_CLOSE) )
    {
        DWORD Color = eGray100;
        // ----
        if( this->Data[eLEOTHAP_CLOSE].OnClick )
        {
            Color = eGray150;
        }
        // ----
        this->DrawColoredGUI(eLEOTHAP_CLOSE, this->Data[eLEOTHAP_CLOSE].X, this->Data[eLEOTHAP_CLOSE].Y, Color);
        this->DrawToolTip(this->Data[eLEOTHAP_CLOSE].X + 5, this->Data[eLEOTHAP_CLOSE].Y + 25, "Đóng");
    }
    // ----
    //this->DrawFormat(eGold, StartX - 160, 60, 210, 3, "Khiêu Chiến Boss");
	CustomFont.Draw(CustomFont.FontBold, 125, 60, 0xFFFF00FF, 0x0, 0, 0, 0, "VƯỢT THÁP");
    // ----
    this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 42); //
    this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 43, 200, 1, "Cổng vào số 1");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 43, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 60, 82.0, 2.0); // gạch ngang
    // ----
    this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 82-5); //
    this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 83-5, 200, 1, "Cổng vào số 2");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 83-5, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 100-5, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 100-5, 82.0, 2.0); // gạch ngang
    // ----
    this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 122-10); //
    this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 123-10, 200, 1, "Cổng vào số 3");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 123-10, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 140-10, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 140-10, 82.0, 2.0); // gạch ngang
    // ----
    this->DrawGUI(eLEOTHAP_POINT, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 162-15); //
    this->DrawFormat(eOrange, StartX - 135, this->Data[eLEOTHAP_MAIN].Y + 163-15, 200, 1, "Cổng vào số 4");
    //this->DrawToolTip(StartX - 80, this->Data[eLEOTHAP_MAIN].Y + 163-15, "1.000.000 Zen");
    pDrawGUI(0x7B5E, StartX - 60, this->Data[eLEOTHAP_MAIN].Y + 180-15, 82.0, 2.0); // gạch ngang
    pDrawGUI(0x7B5E, StartX - 60 - 82, this->Data[eLEOTHAP_MAIN].Y + 180-15, 82.0, 2.0); // gạch ngang
    // ----
	this->DrawFormat(eWhite, StartX - 150, this->Data[eLEOTHAP_MAIN].Y + 233-10, 200, 1, "Sau khi lựa chọn cổng vào phù hợp,hãy di chuyển và chuẩn bị tiêu diệt Boss");
	this->DrawFormat(eExcellent, StartX - 125, this->Data[eLEOTHAP_MAIN].Y + 248-10, 200, 1, "- Cẩn thận với những người chơi khác");
	this->DrawFormat(eExcellent, StartX - 125, this->Data[eLEOTHAP_MAIN].Y + 248+5, 200, 1, "- Khi Event diễn ra, lối vào sẽ đóng lại");
	CustomFont.Draw(CustomFont.FontBold, 55, 288, 0xFF0000FF, 0x0, 0, 0, 0, "Lưu ý: ");

	pSetCursorFocus = true;
}
#endif
// ----------------------------------------------------------------------------------------------

#if(LEOTHAP == 1)
bool Interface::EventLeoThap_Main(DWORD Event)
{
	this->EventLeoThap_All(Event);
	this->EventLeoThap_Close(Event);
	return true;
}

#endif
// ----------------------------------------------------------------------------------------------

#if(LEOTHAP == 1)
bool Interface::EventLeoThap_All(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	//DWORD Delay			= (CurrentTick - this->Data[eDIABLO_CLOSE].EventTick);
	if( !this->Data[eLEOTHAP_MAIN].OnShow )
	{
		return false;
	}

	int ObjectIDs[4] = 
	{ 
		eLEOTHAP_BUTTON_GATE1, 
		eLEOTHAP_BUTTON_GATE2, 
		eLEOTHAP_BUTTON_GATE3, 
		eLEOTHAP_BUTTON_GATE4, 
	};
	gLeoThap.ResetData();
	for (int i = 0; i < 4; i++)
	{
		if (IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay	= (CurrentTick - this->Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				this->Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			this->Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 500 )
			{
				return false;
			}
			// ----
			this->Data[ObjectIDs[i]].EventTick = GetTickCount();;
			this->Data[eLEOTHAP_MAIN].Close();
			PMSG_LEOTHAP_SEND pRequest;
			pRequest.Number = i;
			pRequest.header.set(0xFF,0x90,sizeof(pRequest));
			DataSend((BYTE*)&pRequest,pRequest.header.size);
		}
	}
	return false;
}
#endif
// ----------------------------------------------------------------------------------------------

#if(LEOTHAP == 1)
bool Interface::EventLeoThap_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eLEOTHAP_CLOSE].EventTick);
	// ----
	if( !this->Data[eLEOTHAP_MAIN].OnShow || !IsWorkZone(eLEOTHAP_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eLEOTHAP_CLOSE].OnClick = true;
		return true;
	}
	// ----
	this->Data[eLEOTHAP_CLOSE].OnClick = false;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eLEOTHAP_CLOSE].EventTick = GetTickCount();

	this->Data[eLEOTHAP_MAIN].Close();
	// ----
	return false;
}
#endif
// Leo thap End
#if(BOSS_GUILD == 1)

void CGMoveBossGuild(int Type)
{
	if (Type > 0)
	{
		BOSSGUILD_CGPACKET pMsg;
		pMsg.header.set(0xF3, 0x40, sizeof(pMsg));
		pMsg.CongVao = Type - 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
}

void Interface::DrawBossGuildWindow()
{

	if (!this->Data[eBossGuildWindow].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float CuaSoW = 200.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 95.0;

	gCentral.PrintDropBox(StartX, StartY, CuaSoW, CuaSoH, 0, 0);

	//======Close
	int CloseX = StartX + CuaSoW - 40;
	int CloseY = StartY;
	pDrawGUI(0x7EC5, CloseX, CloseY, 36.0f, 29.0f);
	if (pCheckMouseOver(CloseX, CloseY, 36, 36) == 1)
	{
		if (GetTickCount() - ClickTickCount > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				gInterface.Data[eBossGuildWindow].OnShow ^= 1;
				ClickTickCount = GetTickCount();
			}
		}
		pDrawColorButton(0x7EC5, CloseX, CloseY, 36, 29, 0, 0, pMakeColor(255, 204, 20, 130));
		gInterface.DrawFormat(eGold, CloseX + 15, CloseY + 30, 0, 1, "Close");
	}
	//================================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 5, 0xB8E600FF, 0x0, CuaSoW, 0, 3, "Boss Guild"); // cái đó em sửa sau 
	pDrawGUI(71520, StartX + (CuaSoW / 2) - (200 / 2), StartY + 30, 200, 1); //-- Divisor
	//====================================

	StartY = StartY + 45;
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Điều Kiện Tham Gia Boss Guild"); //
	StartY = StartY + 18;																				  
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Guild Bắt Buộc Phải Có Trên 10 Người Mới Được Tham Gia "); //
	StartY = StartY + 15;																				
	CustomFont.Draw(CustomFont.FontNormal, StartX + (CuaSoW / 10), StartY, 0xFFDE26FF, 0x0, CuaSoW, 0, 1, "Guild Kết Thúc Boss Nhận 30k Wcoin Cả Guild Và 100 Điểm Boss Guild"); //
	StartY = StartY + 12;
	//============Button
	StartY = StartY + 10;
	float SizeButtonW = 95.0;
	float SizeButtonH = 19.0;
	StartX = StartX + (CuaSoW / 2);
	int StartX1 = 50;
	int StartY1 = 10;
	//=====================Button 1
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);
				CGMoveBossGuild(1);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 1"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 2
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveBossGuild(2);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 2"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 3
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveBossGuild(3);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 3"); //Buoc Vao
	//=====================================
	StartY = StartY + 22;
	//=====================Button 4
	if (pCheckMouseOver(StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH) == 1)
	{
		glColor3f(1.0f, 0.6742f, 0.15f);
		if (GetTickCount() - gInterface.Data[eBossGuildWindow].EventTick > 300) //Click
		{
			if (GetKeyState(1) & 0x8000)
			{

				glColor3f(0.72f, 0.438f, 0.0432f);


				CGMoveBossGuild(4);
				this->Data[eBossGuildWindow].OnShow = 0;
				gInterface.Data[eBossGuildWindow].EventTick = GetTickCount();
				//pDrawMessage ( "Button 2", 0 );
			}
		}
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}
	RenderBitmap(31563, StartX - StartX1, StartY + StartY1, SizeButtonW, SizeButtonH, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
	CustomFont.Draw(CustomFont.FontNormal, StartX - StartX1, StartY + (SizeButtonH / 4) + StartY1, 0xE6FCF7FF, 0x0, SizeButtonW, 0, 3, "Cổng 4"); //Buoc Vao
	//=====================================
	glColor3f(1.0f, 1.0f, 1.0f); //Xoa mau
}

void Interface::DrawBossGuildMap()
{
	if (pPlayerState < GameProcess) {
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if (gObjUser.m_MapNumber != 105)
	{
		return;
	}
	float MainWidth = 138.0;
	float MainHeight = 265.0;
	float StartY = 264.0;
	float StartX = 512.0; //512

	pDrawGUI(31650, 412.0f, 362.0f, 227.0f, 87.0f);
	//================ Tinh Toan Time
	if ((GetTickCount() - gInterface.Data[eTimeCTC].EventTick) > 1000)
	{
		if (BossGuild_TimeConLai > 0)
		{
			BossGuild_TimeConLai = BossGuild_TimeConLai - 1;
		}
		gInterface.Data[eTimeCTC].EventTick = GetTickCount();
	}

	int hours = BossGuild_TimeConLai / 3600;
	int minutes = (BossGuild_TimeConLai / 60) % 60;
	int seconds = BossGuild_TimeConLai % 60;
	
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 110, eWhite, 0x0, 100, 0, 3, " Boss Guild"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + 23, StartY + 135, eYellow, 0x0, 100, 0, 3, " Thời gian còn lại"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 150, eWhite, 0x0, 100, 0, 3, " %02d:%02d:%02d", hours, minutes, seconds); //
	//=================================

}

#endif


void Interface::DrawTiecRuouWindow()
{

    if( !this->Data[eTIECRUOU_MAIN].OnShow )
    {
        return;
    }

    // ----
    DWORD ItemNameColor     = eWhite;
    float MainWidth         = 230.0;
    float MainHeight        = 313.0;
    float StartY            = 50.0;
    float StartX            = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
    float MainCenter        = StartX + (MainWidth / 3);
    float ButtonX           = MainCenter - (29.0 / 2);
	float ContentY = StartY;
    // ----
    this->DrawGUI(eTIECRUOU_MAIN, StartX, StartY + 2);
    this->DrawGUI(eTIECRUOU_TITLE, StartX, StartY);
    StartY = this->DrawRepeatGUI(eTIECRUOU_FRAME, StartX, StartY + 15.0, 12);
    this->DrawGUI(eTIECRUOU_FOOTER, StartX, StartY);

	gInterface.DrawGUI(eTIECRUOU_CLOSE, StartX + 70 + 62, StartY);

	if (gInterface.IsWorkZone(eTIECRUOU_CLOSE))
	{
		int ScaleY = 30;
		if (gInterface.Data[eTIECRUOU_CLOSE].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawButton(eTIECRUOU_CLOSE, gInterface.Data[eTIECRUOU_CLOSE].X, gInterface.Data[eTIECRUOU_CLOSE].Y, 0, ScaleY);
	}
 
 
	gInterface.DrawGUI(eTIECRUOU_OK, StartX + 30, StartY);

	gInterface.Data[eTIECRUOU_OK].Attribute = true;
	if (gInterface.IsWorkZone(eTIECRUOU_OK))
	{
		int ScaleY = 30;
		if (this->Data[eTIECRUOU_OK].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawButton(eTIECRUOU_OK, gInterface.Data[eTIECRUOU_OK].X, gInterface.Data[eTIECRUOU_OK].Y, 0, ScaleY);
	}
	//--
	this->DrawFormat(eGold, StartX, this->Data[eTIECRUOU_MAIN].Y + 9, 220, 3, "bi1");
	//--
	gInterface.DrawGUI(eTIECRUOU_DIV, StartX, gInterface.Data[eTIECRUOU_FOOTER].Y - 17);

	pSetFont(pTextThis(), (int) pFontBold);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu);
	pDrawText(pTextThis(), StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 43 - 5, "bi2", 0, 0, (LPINT)1, 0);
	//1
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 63 - 10, 220, 1, "bi3");
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 83 - 15, 220, 1, "bi4");
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 103 - 20, 220, 1, "bi5");
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 123 - 25, 220, 1, "bi6");
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 143 - 30, 220, 1, "bi7");
	//--2
	pSetFont(pTextThis(), (int) pFontBold);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu);
	pDrawText(pTextThis(), StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 163 - 35, "bi8", 0, 0, (LPINT)1, 0);
	this->DrawFormat(eWhite, StartX + 20, this->Data[eTIECRUOU_MAIN].Y + 183 - 40, 220, 1, "bi9");
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventTiecRuouWindow_Main(DWORD Event)
{
	this->EventTiecRuouWindow_All(Event);
	this->EventTiecRuouWindow_Close(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------
//
bool Interface::EventTiecRuouWindow_All(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eTIECRUOU_OK].EventTick);
	// ----
	if (!this->Data[eTIECRUOU_MAIN].OnShow || !IsWorkZone(eTIECRUOU_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eTIECRUOU_OK].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eTIECRUOU_OK].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eTIECRUOU_OK].EventTick = GetTickCount();

	UP_TVTEVENT_REQ pRequest;
	pRequest.h.set(0xFB, 0x67, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);

	this->Data[eTIECRUOU_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventTiecRuouWindow_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eTIECRUOU_CLOSE].EventTick);
	// ----
	if( !this->Data[eTIECRUOU_MAIN].OnShow || !IsWorkZone(eTIECRUOU_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eTIECRUOU_CLOSE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eTIECRUOU_CLOSE].OnClick = false;
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[eTIECRUOU_CLOSE].EventTick = GetTickCount();
	this->Data[eTIECRUOU_MAIN].Close();
	pSetCursorFocus = false;
	// ----
	return false;
}

DWORD TickCount3;

void Interface::DrawEventTiecRuou()
{
	float MainWidth			= 124.0;
	float MainHeight		= 313.0;
	float StartY			= 100.0;
	float StartX			= (MAX_WIN_WIDTH - MainWidth);
	//--

	if( pMapNumber == 107)
	{
		pDrawGUI(0x6863, StartX, StartY+249, 124, 81);	//hinh anh bar time

		//--Bam vao nut moi ruou

		if(pCheckMouseOver( StartX+10, StartY+249+35, 106, 29 ))
		{
			pSetCursorFocus = true;

			RenderBitmap(31563, StartX+10, StartY+249+35, 106.0, 29.0, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);

			if ( GetTickCount() - TickCount3 > 50 )
			{
				if ( GetKeyState(1) & 0x8000 )
				{
					gInterface.Data[eMOIRUOU_MAIN].OnShow = true;
				}
				TickCount3 = GetTickCount();
			}

			gInterface.DrawFormat(eWhite, StartX + 10, StartY + 249 + 35 + 10, 106.0, 3, "hi1");

		}
		else
		{
			RenderBitmap(31563, StartX+10, StartY+249+35, 106.0, 29.0, 0.0, 0.0, 0.64999998, 0.80000001, 1, 1, 0);
			gInterface.DrawFormat(eWhite, StartX + 10, StartY + 249 + 35 + 10, 106.0, 3, "hi1");
		}

		DWORD dwInSec = gObjUser.m_dwEventTimeTiecRuou;
	
		int minT = ( dwInSec / 60 );
		int secT = ( dwInSec % 60 );

		char szScore[10] = { 0 };
		sprintf(szScore, "Time: %02d:%02d", minT, secT);
		gInterface.DrawFormat(eYellow, StartX, StartY+249+12, 124, 3, szScore);

	}
}

void Interface::DrawMoiRuouWindow()
{

    if( !this->Data[eMOIRUOU_MAIN].OnShow )
    {
        return;
    }
	pSetCursorFocus = true;
    // ----
   // DWORD ItemNameColor     = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 50.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	// ----
	this->DrawGUI(eMOIRUOU_MAIN, StartX + 10, StartY + 2);
	this->DrawGUI(eMOIRUOU_TITLE, StartX + 10, StartY);
	StartY = this->DrawRepeatGUI(eMOIRUOU_FRAME, StartX + 10, StartY + 15.0, 12);
	this->DrawGUI(eMOIRUOU_FOOTER, StartX + 10, StartY-35);

	gInterface.DrawGUI(eMOIRUOU_CLOSE, StartX + 100, StartY - 35);

	if (gInterface.IsWorkZone(eMOIRUOU_CLOSE))
	{
		int ScaleY = 30;
		if (gInterface.Data[eMOIRUOU_CLOSE].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawButton(eMOIRUOU_CLOSE, gInterface.Data[eMOIRUOU_CLOSE].X, gInterface.Data[eMOIRUOU_CLOSE].Y, 0, ScaleY);
	}
 
	this->DrawFormat(eGold, StartX + 18, this->Data[eMOIRUOU_MAIN].Y + 9, 210, 3, "hi");

	gInterface.DrawGUI(eMOIRUOU_DIV, StartX+10, gInterface.Data[eMOIRUOU_FOOTER].Y - 20);
	this->DrawFormat(eWhite, StartX + 30, this->Data[eMOIRUOU_MAIN].Y + 35, 200, 1, "hi1");
	this->DrawFormat(eWhite, StartX + 30, this->Data[eMOIRUOU_MAIN].Y + 45, 200, 1, "hi2");
	this->DrawFormat(eWhite, StartX + 30, this->Data[eMOIRUOU_MAIN].Y + 55, 200, 1, "hi3");
	this->DrawFormat(eAncient, StartX + 30, this->Data[eMOIRUOU_MAIN].Y + 65, 200, 1, "hi4");
	this->DrawFormat(eYellow, StartX + 30, this->Data[eMOIRUOU_MAIN].Y + 75, 200, 1, "hi5");

	gInterface.DrawGUI(eMOIRUOU_ZEN, StartX + 70, this->Data[eMOIRUOU_MAIN].Y + 90);
	if (gInterface.IsWorkZone(eMOIRUOU_ZEN))
	{
		int ScaleY = 30;
		if (gInterface.Data[eMOIRUOU_ZEN].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawButton(eMOIRUOU_ZEN, gInterface.Data[eMOIRUOU_ZEN].X, gInterface.Data[eMOIRUOU_ZEN].Y, 0, ScaleY);
	}
	gInterface.DrawFormat(eYellow, StartX + 70, this->Data[eMOIRUOU_ZEN].Y + 10, 106, 3, "hi6");
	
	//
	gInterface.DrawGUI(eMOIRUOU_WC, StartX + 70, this->Data[eMOIRUOU_MAIN].Y + 117);
	if (gInterface.IsWorkZone(eMOIRUOU_WC))
	{
		int ScaleY = 30;
		if (gInterface.Data[eMOIRUOU_WC].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawButton(eMOIRUOU_WC, gInterface.Data[eMOIRUOU_WC].X, gInterface.Data[eMOIRUOU_WC].Y, 0, ScaleY);
	}
	gInterface.DrawFormat(eAncient, StartX + 70, this->Data[eMOIRUOU_WC].Y + 10, 106, 3, "hi7");
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventMoiRuouWindow_Main(DWORD Event)
{
	this->EventMoiRuouWindow_Zen(Event);
	this->EventMoiRuouWindow_WC(Event);
	this->EventMoiRuouWindow_Close(Event);
	return true;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventMoiRuouWindow_Zen(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMOIRUOU_ZEN].EventTick);
	// ----
	if (!this->Data[eMOIRUOU_MAIN].OnShow || !IsWorkZone(eMOIRUOU_ZEN))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMOIRUOU_ZEN].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eMOIRUOU_ZEN].OnClick = false;
	// ----
	if (Delay < 1500)
	{
		return false;
	}
	// ----
	this->Data[eMOIRUOU_ZEN].EventTick = GetTickCount();

	UP_TUCHAN_REQ pRequest;
	pRequest.h.set(0xFB, 0x68, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);

	this->Data[eMOIRUOU_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool Interface::EventMoiRuouWindow_WC(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMOIRUOU_WC].EventTick);
	// ----
	if (!this->Data[eMOIRUOU_MAIN].OnShow || !IsWorkZone(eMOIRUOU_WC))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMOIRUOU_WC].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eMOIRUOU_WC].OnClick = false;
	// ----
	if (Delay < 1500)
	{
		return false;
	}
	// ----
	this->Data[eMOIRUOU_WC].EventTick = GetTickCount();

	UP_TUCHAN_REQ pRequest;
	pRequest.h.set(0xFB, 0x69, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);

	this->Data[eMOIRUOU_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------

bool Interface::EventMoiRuouWindow_Close(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[eMOIRUOU_CLOSE].EventTick);
	// ----
	if( !this->Data[eMOIRUOU_MAIN].OnShow || !IsWorkZone(eMOIRUOU_CLOSE) )
	{
		return false;
	}
	// ----
	if( Event == WM_LBUTTONDOWN )
	{
		this->Data[eMOIRUOU_CLOSE].OnClick = true;
		pSetCursorFocus = true;
		return true;
	}
	// ----
	this->Data[eMOIRUOU_CLOSE].OnClick = false;
	// ----
	if( Delay < 1500 )
	{
		return false;
	}
	// ----
	this->Data[eMOIRUOU_CLOSE].EventTick = GetTickCount();
	//this->CloseCTCPanelWindow();
	this->Data[eMOIRUOU_MAIN].Close();
	pSetCursorFocus = false;
	// ----
	return false;
}

void Interface::SwitchFenrir()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow) && !gInterface.CheckWindow(ObjWindow::Inventory))
	{

		if (MinimizarFenrir != 0)
		{
			MinimizarFenrir = 0;
		}
		else
		{
			MinimizarFenrir = 1;
		}
	}
}

void Interface::HideNameinCC()
{

	if (pMapNumber != 18 ||
		pMapNumber != 19 ||
		pMapNumber != 20 ||
		pMapNumber != 21 ||
		pMapNumber != 22 ||
		pMapNumber != 23 )
	{
			HideName = 1;
	}
}

#if(THANMA)
void DrawTMPoint() //<<< Draw Bang POint PK
{
	if (pMapNumber != gInterface.m_EventTMMap || gInterface.m_EventTMTimeCount == 0)
	{
		return;
	}
	//Test
	float ChieuRong = 250.0f;
	float ChieuDai = 10.0f;
	float ViTriX = ((int)pWinWidth / pWinHeightReal / 2) - (ChieuRong / 2);
	float ViTriY = 5;

	int DiemA = gInterface.m_TMScoreAcQuy;
	int DiemB = gInterface.m_TMScoreThienThan;
	float TyLeTGA = 0;

	if (gCentral.gDrawButton(ViTriX + ChieuRong + 10, 2 , 75, 12, gOther.TextVN_ThanMaChien[18]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		////===BXH
		gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glColor4f(0.79, 0.5467, 0.1264, 0.3);
	pDrawBarForm(ViTriX - 2, ViTriY - 2, ChieuRong + 4, ChieuDai + 4, 0.0, 0); //Nen Goc
	EnableAlphaTest(1);

	glColor4f(1.0, 0.0, 0.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, ChieuRong, ChieuDai, 0.0, 0); //Ac Quy
	EnableAlphaTest(1);

	if (DiemA == 0 && DiemB == 0)
	{
		TyLeTGA = ChieuRong / 2;
	}
	else
	{
		TyLeTGA = (ChieuRong * ((DiemA * 100) / (DiemA + DiemB))) / 100;
	}

	glColor4f(0.0, 0.5, 1.0, 0.7);
	pDrawBarForm(ViTriX, ViTriY, TyLeTGA, ChieuDai, 0.0, 0); //Thien Than
	EnableAlphaTest(1);
	pGLSupremo();

	//=== TInh Time Event
	if ((GetTickCount() - gInterface.mCalcTimeEventTick) > 1000)
	{
		if (gInterface.m_EventTMTimeCount > 0)
		{
			gInterface.m_EventTMTimeCount = gInterface.m_EventTMTimeCount - 1;
		}
		gInterface.mCalcTimeEventTick = GetTickCount();
	}
	char text1[120];
	int totalseconds;
	int hours;
	int minutes;
	int seconds;
	int days;

	totalseconds = gInterface.m_EventTMTimeCount;
	hours = totalseconds / 3600;
	minutes = (totalseconds / 60) % 60;
	seconds = totalseconds % 60;

	if (hours > 23)
	{
		days = hours / 24;
		wsprintf(text1, "%d day(s)+", days);
	}
	else
	{
		wsprintf(text1, "%02d:%02d", minutes, seconds);
	}
	//==Text
	HFONT FontTextTMPoint = CreateFontA(12.5, Main_Font_Width, 0, 0, 400, 0, 0, 0, 1u, 0, 0, 3u, 0, "Arial");

	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4 , 0xFFFFFFFF, 0x0, ChieuRong,0,3, "Time: %s", text1);
	//==Ben Trai
	CustomFont.Draw(FontTextTMPoint, ViTriX, ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gOther.TextVN_ThanMaChien[16],DiemA);
	//==Ben Phai
	CustomFont.Draw(FontTextTMPoint, ViTriX + (ChieuRong / 2), ViTriY + (ChieuDai / 2) - 4, 0xFFFFFFFF, 0x0, (ChieuRong / 2), 0, 3, "[%s] : %d", gOther.TextVN_ThanMaChien[17], DiemB);
	DeleteObject(FontTextTMPoint);
	return;
}
void DrawWindowNPCTM()
{
	if (!gInterface.Data[eWindowNPC_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 300.0;
	float CuaSoH = 250.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowNPC_ThanMaChien, gOther.TextVN_ThanMaChien[0]);
		if (gInterface.IsWorkZone(StartX, StartY, CuaSoW, CuaSoH)) // nếu chuột trong khu vực bảng shop thì ko click di chuyển nv
	{
		pSetCursorFocus = true;
	}
	else pSetCursorFocus = false;

	if (gCentral.gDrawButton(StartX+(CuaSoW/2)-(115/2), StartY+(CuaSoH-45), 115, 14, gOther.TextVN_ThanMaChien[1]) && (GetTickCount() - gInterface.Data[eWindowNPC_ThanMaChien].EventTick) > 300)
	{
		//==Tham Gia Than Ma
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xFF, 0x92, sizeof(pMsg));
		pMsg.ThaoTac = 1; 
		DataSend((LPBYTE)& pMsg, pMsg.header.size);
		gInterface.Data[eWindowNPC_ThanMaChien].OnShow ^= 1;
		////===BXH
		//gInterface.Data[eWindowBXH_ThanMaChien].OnShow ^= 1;
	}
	HFONT FontTextTMB = CreateFontA(13, Main_Font_Width, 0, 0, 700, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	HFONT FontTextTM = CreateFontA(13, Main_Font_Width, 0, 0, 400, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, 0x1, 0, 0, Main_Font_Quality, 0, "Tahoma");
	float TextStartY = StartY + 33;
	for (int ct = 0; ct < 14; ct++)
	{
		if (ct == 0 || ct == 1 || ct == 5 || ct == 11)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xFFDE26FF, 0x0, CuaSoW, 0, 1, gOther.TextVN_ThanMaChien[2 + ct]); //
		}
		else if (ct == 10)
		{
			CustomFont.Draw(FontTextTMB, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0x00FBFFFF, 0x0, CuaSoW, 0, 1, gOther.TextVN_ThanMaChien[2 + ct]); //
		}
		else {
			CustomFont.Draw(FontTextTM, (StartX + (CuaSoW / 10)) - 15, TextStartY + (12 * ct), 0xEBFFFBFF, 0x0, CuaSoW, 0, 1, gOther.TextVN_ThanMaChien[2 + ct]); //
		}

	}
	DeleteObject(FontTextTMB);
	DeleteObject(FontTextTM);
}
void DrawWindowBXHTM()
{
	if (!gInterface.Data[eWindowBXH_ThanMaChien].OnShow)
	{
		return;
	}
	float CuaSoW = 250.0;
	float CuaSoH = 200.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = 45.0;

	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindowBXH_ThanMaChien, gOther.TextVN_ThanMaChien[18]);



	//====================================
	CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Top"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Name"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Kill"); //
	CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 40, 0xFABB00FF, 0x0, CuaSoW / 4, 0, 3, "Team"); //
	DWORD ColorTextRank = 0xE0DFDCFF;

	for (int i = 0; i < gInterface.m_TMChienBXHC; i++)
	{
		if (i % 2)
		{
			ColorTextRank = 0xA3A3A3FF;
		}
		else {
			ColorTextRank = 0xE0DFDCFF;
		}
		if (i < 3) { ColorTextRank = 0xFFE240FF; }
		CustomFont.Draw(CustomFont.FontBold, StartX, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", i + 1); //
		CustomFont.Draw(CustomFont.FontBold, StartX + CuaSoW / 4, StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", gInterface.m_ThanMaChienBXH[i].Name); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 2), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%d", gInterface.m_ThanMaChienBXH[i].Kill); //
		CustomFont.Draw(CustomFont.FontBold, StartX + ((CuaSoW / 4) * 3), StartY + 55 + (i * 12), ColorTextRank, (i < 3) ? 0xFFE2400F : 0x0, CuaSoW / 4, 0, 3, "%s", (gInterface.m_ThanMaChienBXH[i].Team > 0)? gOther.TextVN_ThanMaChien[15+ gInterface.m_ThanMaChienBXH[i].Team]:"NULL"); //

	}
}
void Interface::DrawTMAllWindows()
{
	DrawTMPoint();
	DrawWindowNPCTM();
	DrawWindowBXHTM();
}
#endif

void Interface::OpenConfig2(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) )
		{
			return;
		}
	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 20 ))
		{
			pCloseWindow(pWindowThis(), 20 );
		}
		else 
		{
			pOpenWindow(pWindowThis(), 20 );
		}
	}

	PlayBuffer(25, 0, 0);
}
//tue add
void Interface::DrawShowIcon()
{
	if (this->Data[eMenu_MAIN].OnShow == true)
	{
		return;
	}

	if (gProtect.m_MainInfo.CustomInterfaceType >= 0)
	{
		if (gInterface.CheckWindow(ObjWindow::CashShop)
			|| gInterface.CheckWindow(ObjWindow::FriendList)
			|| gInterface.CheckWindow(ObjWindow::MoveList)
			|| gInterface.CheckWindow(ObjWindow::Party)
			|| gInterface.CheckWindow(ObjWindow::Quest)
			|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
			|| gInterface.CheckWindow(ObjWindow::Guild)
			|| gInterface.CheckWindow(ObjWindow::Trade)
			|| gInterface.CheckWindow(ObjWindow::Warehouse)
			|| gInterface.CheckWindow(ObjWindow::ChaosBox)
			|| gInterface.CheckWindow(ObjWindow::CommandWindow)
			|| gInterface.CheckWindow(ObjWindow::PetInfo)
			|| gInterface.CheckWindow(ObjWindow::Shop)
			|| gInterface.CheckWindow(ObjWindow::Inventory)
			|| gInterface.CheckWindow(ObjWindow::Store)
			|| gInterface.CheckWindow(ObjWindow::OtherStore)
			|| gInterface.CheckWindow(ObjWindow::Character)
			|| gInterface.CheckWindow(ObjWindow::DevilSquare)
			|| gInterface.CheckWindow(ObjWindow::BloodCastle)
			|| gInterface.CheckWindow(ObjWindow::CreateGuild)
			|| gInterface.CheckWindow(ObjWindow::GuardNPC)
			|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
			|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
			|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
			|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
			|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
			|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
			|| gInterface.CheckWindow(ObjWindow::HeroList)
			|| gInterface.CheckWindow(ObjWindow::ChatWindow)
			|| gInterface.CheckWindow(ObjWindow::FastMenu)
			|| gInterface.CheckWindow(ObjWindow::Options)
			|| gInterface.CheckWindow(ObjWindow::Help)
			|| gInterface.CheckWindow(ObjWindow::FastDial)
			|| gInterface.CheckWindow(ObjWindow::SkillTree)
			|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
			|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
			|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
			|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
			|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
			|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
			|| gInterface.CheckWindow(ObjWindow::CashShop)
			|| gInterface.CheckWindow(ObjWindow::Lugard)
			|| gInterface.CheckWindow(ObjWindow::QuestList1)
			|| gInterface.CheckWindow(ObjWindow::QuestList2)
			|| gInterface.CheckWindow(ObjWindow::Jerint)
			|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
			|| gInterface.CheckWindow(ObjWindow::GensInfo)
			|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
			|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
			|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
			|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
			|| gInterface.CheckWindow(ObjWindow::MuHelper)
			|| pMapNumber == 34
			|| pMapNumber == 30)
		{
			return;
		}


		if (pCheckMouseOver(540 + 35, 140, 40, 40))
		{
			if (*(BYTE*)0x8793386)
			{
				//RenderBitmap(0x4043, 180, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0);
				RenderBitmap(0x4043, 540 + 35, 140, 50, 50, 0, 0, 1.5, 1.0, 2, 1, 1.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(85), 0, 0, SW_SHOW);
					//tue fixx
					ShellExecute(NULL, "open", "https://www.facebook.com/profile.php?id=61565721511382", NULL, NULL, SW_SHOWNORMAL);

					gInterface.TimeInterface = GetTickCount();
				}

			}
			//else { RenderBitmap(0x4043, 180, 20, 31, 31, 0, 0, 1.0, 1.0, 1, 1, 0.0); }
			else { RenderBitmap(0x4043, 540 + 35, 140, 51, 51, 0, 0, 1.5, 1.0, 2, 1, 1.0); }
			//tue add fix nhan vat di chuyen khi click
			//pSetCursorFocus = true;
			if (!pSetCursorFocus)
			{
				pSetCursorFocus = true;
			}
			//-----
		}
		//else { RenderBitmap(0x4043, 180, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0); }
		else { RenderBitmap(0x4043, 540 + 35, 140, 50, 50, 0, 0, 1.5, 1.0, 2, 1, 1.0); }

		
		if (pCheckMouseOver(200, 20, 20, 20))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4044, 200, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0);
				PlayBuffer(25, 0, 0); 

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);
					//tue fixx
					ShellExecute(NULL, "open", "https://zalo.me/g/ggyzzf089", NULL, NULL, SW_SHOWNORMAL);

					gInterface.TimeInterface = GetTickCount();
				}

			}
			else { RenderBitmap(0x4044, 200, 20, 31, 31, 0, 0, 1.0, 1.0, 1, 1, 0.0); }
			//tue add fix nhan vat di chuyen khi click
			//pSetCursorFocus = true;
			if (!pSetCursorFocus)
			{
				pSetCursorFocus = true;
			}
			//-----
		}
		else { RenderBitmap(0x4044, 200, 20, 30, 30, 0, 0, 1.0, 1.0, 1, 1, 0.0); }

	}
	//if (gProtect.m_MainInfo.EnableNutThongTin == 1)
	if (1)
	{
		static float HieuX = 0.87;
		static float HieuY = 0.87;

		if (pCheckMouseOver(320, 2, 85, 15))
		{
			if (*(BYTE*)0x8793386)
			{
				RenderBitmap(0x4045, 320, 2, 50, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0);
				PlayBuffer(25, 0, 0);

				if (GetTickCount() >= gInterface.TimeInterface + 150)
				{
					//ShellExecute(0, 0, gCustomMessage.GetMessage(86), 0, 0, SW_SHOW);
					//tue fixx
					ShellExecute(NULL, "open", "https://mu-tue.com/home/vi", NULL, NULL, SW_SHOWNORMAL);
					//gNewsBoard.ReqOpenMain();

					gInterface.TimeInterface = GetTickCount();
				}

			}
			else {
				RenderBitmap(0x4045, 320, 2, 101, 16, 0, 0, HieuX, HieuY, 1, 1, 0.0);
			}
		}
		else {
			RenderBitmap(0x4045, 320, 2, 100, 15, 0, 0, HieuX, HieuY, 1, 1, 0.0);
		}

		CustomFont.Draw(CustomFont.FontNormal, 350, 5, eWhite, eRed, 0, 0, 3, "Thông Tin Server"); //Move Daily Reward - 70 lados - 60 arriba
	}
}
//Timer server
int Thongbao = 100;
int a = 10;
void Interface::DrawTimeUI()
{
	//	if(gProtect.m_MainInfo.CustomInterfaceType >= 0 && gProtect.m_MainInfo.CustomInterfaceType <= 2)
	//	{
	//		return;
	//	}


	//if (TimerBar == 0 
	//	|| (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) 
	//	|| this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)
	//	|| this->CheckWindow(ObjWindow::MoveList) || pMapNumber == 34 || pMapNumber == 30))
	//{
	//	return;
	//}

	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper)
		|| pMapNumber == 34
		|| pMapNumber == 30)

	{
		return;
	}





	//--
	//	this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y + 10);
	if (gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//this->DrawGUI(eTIME, this->Data[eTIME].X, this->Data[eTIME].Y + 10); //27
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		//this->DrawGUI(eTIME, this->Data[eTIME].X + 405, this->Data[eTIME].Y - 15);
	}
	// -----
	time_t TimeServer, TimeLocal;
	struct tm* ServerT, * LocalT;
	time(&TimeServer);
	time(&TimeLocal);
	// ----
	ServerT = gmtime(&TimeServer);
	// ----
	char ServerTimeName[25] = "Giờ Server:";
	char ServerTime[30];

	sprintf(ServerTime, "%2d:%02d:%02d", (ServerT->tm_hour + GMT) % 24, ServerT->tm_min, ServerT->tm_sec);

	// -----
	LocalT = localtime(&TimeLocal);
	// -----
	char LocalTimeName[25] = "Giờ PC:";
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);

	if (gProtect.m_MainInfo.CustomInterfaceType == 0 || gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		this->DrawFormat(eShinyGreen, this->Data[eTIME].X + 410, this->Data[eTIME].Y + 15, 50, 1, ServerTimeName);
		this->DrawFormat(eGold, this->Data[eTIME].X + 475, this->Data[eTIME].Y + 15, 100, 1, ServerTime);
		// ----
		//this->DrawFormat(eShinyGreen, this->Data[eTIME].X + 410, this->Data[eTIME].Y + 35, 50, 1, LocalTimeName);
		//this->DrawFormat(eGold, this->Data[eTIME].X + 475, this->Data[eTIME].Y + 35, 100, 1, LocalTime);

		this->DrawFormat(eOrange, 110, 380, 300, 1, gCustomMessage.GetMessage(97));
		this->DrawFormat(eExcellent, 110, 390, 300, 1, gCustomMessage.GetMessage(98));
		//this->DrawFormat(eBlue250, 110, 401, 300, 1, gCustomMessage.GetMessage(99));
		//this->DrawFormat(eYellow, 110, 415, 300, 1, gCustomMessage.GetMessage(100))

	}

}
//---
//tue add ATM box
bool Interface::SPKEventClick(DWORD Event)
{
	if (gInterface.Data[eMenu_MAIN].OnShow == false)
	{
		return false;
	}
	else
	{
		DWORD CurrentTick = GetTickCount();
		for (int i = 0; i < ButtonMenuSpk; i++)
		{
			DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1 + i].EventTick);
			if (gInterface.IsWorkZone(eMenu_OPT1 + i))
			{
				if (Event == WM_LBUTTONDOWN)
				{
					this->Data[eMenu_OPT1 + i].OnClick = true; return true;
				}
				this->Data[eMenu_OPT1 + i].OnClick = false;
				if (Delay < 500)
				{
					return false;
				}
				switch (eMenu_OPT1 + i)
				{
				//case eMenu_OPT1: gCETime.OpenWindow();					break;
				//case eMenu_OPT2: gNewVip.SendMenuButton();					break;
				//case eMenu_OPT3: gRanking.SendMenuButton();						break;
				//case eMenu_OPT4: gCustomCommandInfo.OpenCommandWindow();		break;
				//case eMenu_OPT5: gCustomJewelBank.OpenWindow();					break;
				//case eMenu_OPT6: gTuLuyen.SendMenuButton();						break;
				//case eMenu_OPT7: gPartySearch.SwitchPartySettingsWindowState();	break;
				//case eMenu_OPT8: gPartySearch.SendMenuButton();					break;
				//case eMenu_OPT9: gQuanHam.SendMenuButton();						break;
				//case eMenu_OPT10: gDanhHieu.SendMenuButton();					break;
				//case eMenu_OPT11: ThueFlag.OpenFlag();							break;
				//case eMenu_OPT12: G_SpkRelife.SendMenuButton();					break;
				//case eMenu_OPT13: gLuckySpin.SwitchLuckySpinWindowState();		break;
				//case eMenu_OPT14: gNewMocNap.OpenWindowMocNap();				break;
				//case eMenu_OPT15: gNewCashShop.OpenCustomShop();				break;
				//case eMenu_OPT16: gNewIntros.OpenWindowMocNap();				break;
				//case eMenu_OPT17: gTaiKhoan.OpenWindowsChangePass();			break;
				//case eMenu_OPT18: break;
				//case eMenu_OPT19: gResetChange.OpenResetChange();				break;
				//case eMenu_OPT20: gHonHoan.SendMenuButton();					break;
				default:
					break;
				}
				this->CloseMenuWindow();
				gInterface.Data[eMenu_OPT1 + i].EventTick = GetTickCount();
			}
		}
		return false;
	}
}

//----
